//const { execFile } = require('child_process');
const { exec } = require('child_process');
const express  = require('express');
const router   = express.Router();
const multer   = require('multer');

const upload = multer({ dest: 'uploadedFiles/' });

//child process module
//const fread = require('child_process').execFile;
const fread = require('child_process').exec;


router.get('/', function(req,res){
  res.render('upload');
});

//file upload post
router.post('/uploadFile', upload.single('attachment'), function(req,res){
   //exec file and callback result page
   //const fread = execFile('fileReadLoc.exe',[`uploadedFiles/${req.file.filename}`],function(error,stdout,stderr){
    const fread = exec(`./testfile uploadedFiles/${req.file.filename}`,function(error,stdout,stderr){
      console.log(error, stdout, stderr);
      res.render('result', { output:stdout });
  })

});

module.exports = router;
