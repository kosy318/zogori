const fs = require('fs');
const express = require("express");
const multer = require("multer");

//const { execFile } = require("child_process");
const { exec } = require("child_process");

const upload = multer({ dest: "uploadedFiles/" });
const router = express.Router();
//child process module
//const fread = require("child_process").execFile;
const fread = require("child_process").exec;

router.get("/", function (req, res) {
    res.render("upload");
});

//file upload post
router.post("/uploadFile", upload.single("attachment"), function (req, res) {
    //exec file and callback result page
    //const fread = execFile("main.exe",[`uploadedFiles/${req.file.filename}`],function(error,stdout,stderr){
    const fread = exec(`python3 zogori_for_test/main.py uploadedFiles/${req.file.filename}`,function(error,stdout,stderr){
        fs.unlinkSync(`uploadedFiles/${req.file.filename}`);
	    console.log("Error  : ", error);
	    console.log("stderr : ",stderr);
	    console.log("stdout : ", stdout);
        res.render("result", { output: stdout, filesize:req.file.size });
        }
    );
});

module.exports = router;
