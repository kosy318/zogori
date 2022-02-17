var input = document.querySelector("input[type=file]");
var preview = document.querySelector(".preview");

input.addEventListener("change", updateFileDisplay);

function updateFileDisplay() {
    const sizeScore = document.querySelector(".size");
    while (preview.firstChild) {
        preview.removeChild(preview.firstChild);
        if(sizeScore.children[1] != undefined)
            sizeScore.removeChild(sizeScore.children[1]);
    }

    const curFile = input.files[0];
    if (curFile.length === 0) {
        const para = document.createElement("p");
        para.textContent = "No files currently selected for upload";
        preview.appendChild(para);
    } else {
        var para = document.createElement("p");
        para.textContent = `${curFile.name}`;
        preview.appendChild(para);

        para = document.createElement("p");
        para.textContent = `${returnFileSize(curFile.size)}`;
        sizeScore.appendChild(para);
    }
}

function returnFileSize(number) {
    if (number < 1024) {
        return number + "bytes";
    } else if (number >= 1024 && number < 1048576) {
        return (number / 1024).toFixed(1) + "KB";
    } else if (number >= 1048576) {
        return (number / 1048576).toFixed(1) + "MB";
    }
}
