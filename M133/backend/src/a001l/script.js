let fv = document.getElementsByClassName('file-view')[0];
let dlUrl = "./?file="

document.querySelectorAll('div[data-src]').forEach(e => {
    e.addEventListener('click', function(e) {
        viewFile(e.target.dataset.src)
    })
});

async function getTextContents(url) {
    let res = await fetch(url)
    let txt = await res.text()
    txt = txt.replaceAll("<", "&lt;")
    txt = txt.replaceAll(">", "&gt;")
    return txt
}

async function viewFile(filename="test.txt") {
    let ext = filename.split(".")[1]
    let path = dlUrl + filename
    let path_dl = dlUrl + filename + '&dl=1'
    let out = "";
    switch (ext) {
        case 'css':
        case 'php':
        case 'js':
        case 'txt':
            out = `
            <pre><code>${await getTextContents(path)}</code></pre>
            `
            break;
    
        case 'pdf':
            out = `<object
                data="${path}"
                type="application/pdf"
                width="100%"
                height="100%"
            >
                <p>
                    Your browser does not support PDFs.
                    <a href="${path_dl}">Download the PDF</a>
                    .
                </p>
            </object>`
            break;
        
        case 'png':
        case 'jpg':
            out = `
            <img src="${path}" />
            `
            break;

        default:
            out = `
            <p>
                File Explorer doesn't support viewing this filetype.
                <a href="${path_dl}">Download the File</a>
                .
            </p>
            `
            break;
    }

    fv.innerHTML = out
}