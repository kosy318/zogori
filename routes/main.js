const fs = require("fs");
const express = require("express");
const multer = require("multer");
const bodyParser = require("body-parser");
const { request } = require("http");

const router = express.Router();
const storage = multer.diskStorage({
    destination(req, file, cb) {
        cb(null, "uploadedFiles/");
    },
    filename(req, file, cb) {
        cb(null, `${Date.now()}__${file.originalname}`);
    },
});

const upload = multer({ dest: "uploadedFiles/" });
const uploadWithOriginalFilename = multer({ storage: storage });

const { exec } = require("child_process");
const fread = require("child_process").exec;

//



router.get("/", function (req, res) {
    res.render("upload");
});
router.get("/error_report", function (req, res) {
    res.render("error_report");
});
router.get("/about", function (req, res) {
    res.render("about");
});

//
router.post(
    "/uploadFileWithOriginalFilename",
    uploadWithOriginalFilename.array("attachment"),
    function (req, res) {
        let language = req.body.language;
        let fileNumber = req.files.length;
        console.log("fileNumber  : ", fileNumber);

        // file extension(language) check : c/c++ or python
        if (language == "c/c++") {
            let execString = "python3 metrics/main.py c/c++ ";
            for (let i = 0; i < fileNumber; i++) {
                execString =
                    execString + " uploadedFiles/" + req.files[i].filename;
            }

            console.log("command string  : ", execString);
            // execute elegacne metrics with command line string
            // get returned json string containing elegance values
            const fread = exec(execString, function (error, stdout, stderr) {
                console.log("Error  : ", error);
                console.log("stderr : ", stderr);
                console.log("language : ", language);
                let output = JSON.parse(stdout);
                res.render("result", {
                    output: output,
                    filesize: req.files[0].size,
                    filename: req.files[0].filename,
                });
                // delete files synchronously for storage save and security
                for (let i = 0; i < fileNumber; i++) {
                    fs.unlinkSync(`uploadedFiles/${req.files[i].filename}`);
                }
            });
        //python metric can accept only single source code file
        //can't make dnn model cause lack of python source code
        } else if (language == "python") {
            let execString = "python3 metrics/main.py py ";
            if (req.files[0].filename.search(/\.py/) < 0) {
                fs.unlinkSync(`uploadedFiles/${req.files[0].filename}`);
                res.render("alert", { error: "잘못된 파일 형식입니다" });
            } else {
                execString =
                    execString + " uploadedFiles/" + req.files[0].filename;
                const fread = exec(
                    execString,
                    function (error, stdout, stderr) {
                        console.log("Error  : ", error);
                        console.log("stderr : ", stderr);
                        console.log("language : ", language);
                        let output = JSON.parse(stdout);
                        res.render("result", {
                            output: output,
                            filesize: req.files[0].size,
                            filename: req.files[0].filename,
                        });
                        // delete files synchronously for storage save and security
                        fs.unlinkSync(`uploadedFiles/${req.files[0].filename}`);
                    }
                );
            }
        }
    }
);

module.exports = router;
