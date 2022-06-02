const fs = require("fs");
const express = require("express");
const multer = require("multer");
const bodyParser = require("body-parser");

const { request } = require("http");
const router = express.Router();

// 파일이름 저장을 위해 사용될 storage 변수
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

// const { execFile } = require("child_process");
// const fread = require("child_process").execFile;
const { exec } = require("child_process");
const fread = require("child_process").exec;

router.get("/", function (req, res) {
    res.render("upload");
});

router.get("/error_report", function (req, res) {
    res.render("error_report");
});

router.get("/about", function (req, res) {
    res.render("about");
});

//파일 업로드 (파일이름유지)
router.post(
    "/uploadFileWithOriginalFilename",
    uploadWithOriginalFilename.array("attachment"),
    function (req, res) {
        //exec file and callback result page
        // const fread = execFile("main.exe",[`uploadedFiles/${req.file.filename}`],function(error,stdout,stderr){
        let language = req.body.language;
        let fileNumber = req.files.length;
        console.log("fileNumber  : ", fileNumber);
        let execString = "python3 metrics/main.py " + language;
        if (language == "c/c++") {
            for (let i = 0; i < fileNumber; i++) {
                execString =
                    execString + " uploadedFiles/" + req.files[i].filename;
            }
            console.log("command string  : ", execString);
            const fread = exec(execString, function (error, stdout, stderr) {
                console.log("Error  : ", error);
                console.log("stderr : ", stderr);
                console.log("language : ", language);
                res.render("result", {
                    output: stdout,
                    filesize: req.files[0].size,
                    filename: req.files[0].filename,
                });
                for (let i = 0; i < fileNumber; i++) {
                    fs.unlinkSync(`uploadedFiles/${req.files[i].filename}`);
                }
            });
        } else if (language == "python") {
            if (req.file.filename.search(/\.py/) < 0) {
                fs.unlinkSync(`uploadedFiles/${req.files[0].filename}`);
                res.render("alert", { error: "잘못된 파일 형식입니다" });
            } else {
                execString =
                    execString + `uploadedFiles/${req.files[0].filename}`;
                const fread = exec(
                    execString,
                    function (error, stdout, stderr) {
                        fs.unlinkSync(`uploadedFiles/${req.files[0].filename}`);
                        console.log("Error  : ", error);
                        console.log("stderr : ", stderr);
                        console.log("language : ", language);
                        res.render("result", {
                            output: stdout,
                            filesize: req.files[0].size,
                            filename: req.files[0].filename,
                        });
                    }
                );
            }
        }
    }
);

module.exports = router;
