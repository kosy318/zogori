const { execFile } = require('child_process');
const express  = require('express');
const router   = express.Router();
const multer   = require('multer');

const upload = multer({ dest: 'uploadedFiles/' });
const fread = require('child_process').execFile;
router.get('/', function(req,res){
  res.render('upload');
});

router.post('/uploadFile', upload.single('attachment'), function(req,res){
  console.log(req.file.filename);
   const fread = execFile('fileReadLoc.exe',[`uploadedFiles/${req.file.filename}`],function(error,stdout,stderr){
    res.render('confirmation', { output:stdout });
  })

});

module.exports = router;
