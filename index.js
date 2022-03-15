const express = require("express");
const app = express();
const fs = require("fs");

//ejs setting
app.set("view engine", "ejs");
app.use(express.static(__dirname + "/public"));

//Routes
app.use("/", require("./routes/main"));

//Port setting
var port = 3000;
app.listen(port, function () {
    var dir = "./uploadedFiles";
    if (!fs.existsSync(dir)) fs.mkdirSync(dir);
    console.log("server on! http://localhost:" + port);
});
