<?php

$default_path = "..";

// simple file download enpoint
// ex: /?file=filename.ext&dl=1 --> downloads
if (array_key_exists('file', $_GET) && ! empty($_GET['file'])) {
    $filename = $_GET['file'];
    if(file_exists($filename)){

        //Get file type and set it as Content Type
        $finfo = finfo_open(FILEINFO_MIME_TYPE);
        header('Content-Type: ' . finfo_file($finfo, $filename));
        finfo_close($finfo);
    
        //Use Content-Disposition: attachment to specify the filename
        if (array_key_exists('dl', $_GET) && ! empty($_GET['dl']) && $_GET['dl'] == '1') {
            header('Content-Disposition: attachment; filename='.basename($filename));
        } else {
            header('Content-Disposition: filename='.basename($filename));
        }
    
        //No cache
        header('Expires: 0');
        header('Cache-Control: must-revalidate');
        header('Pragma: public');
    
        //Define file size
        header('Content-Length: ' . filesize($filename));
    
        // throws error when no buffer
        //ob_clean();
        flush();
        readfile($filename);
        exit;
    }
}

/**
 * Recursive directory listing for given path
 */
function ls($path=__DIR__) {
    $list = scandir($path);
    $out_list = [];

    foreach ($list as $i => $list_el) {
        if ( $list_el != "." && $list_el != ".." ) {
            $path_to_el = $path . '/' . $list_el;

            if ( is_dir($path_to_el) ) {
                $subdirs = ls($path_to_el);
                array_push($out_list, [
                    'name' => $list_el,
                    'dirs' => $subdirs,
                    'path' => realpath($path_to_el),
                ]);
            } else {
                // is file
                array_push($out_list, [
                    'name' => $list_el,
                    'path' => realpath($path_to_el),
                ]);
            }
        }
    }

    return $out_list;
}

function tree_view_html($array) {
    $out = "<div class=\"dir-listing\">";

    foreach ($array as $key => $value) {
        if (array_key_exists('dirs', $value)) {
            $out .= "<details><summary>".$value['name']."</summary>";
            $out .= tree_view_html($value['dirs']);
            $out .= "</details>";
        } else {
            $out .= "<div data-src=\"".$value['path']."\">".$value['name']."</div>";
        }
    }

    $out .= "</div>";

    return $out;
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>File Explorer</title>
    <link rel="stylesheet" href="./reset.css" type="text/css">
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Comic+Neue&family=Roboto+Mono&display=swap');

        :root {
            --list-pad: 1em;
            --default-border: none;
            --default-rounding: 7.5px;
            --white: #fff;
            --light-gray: rgba(243,244,246);
            --dark-gray: rgba(138, 138, 138, .2);
            --light-shadow: 0px 10px 15px -3px rgba(0,0,0,0.1);
        }

        html {
            font-family: 'Comic Neue', cursive;
            font-family: 'Roboto Mono', monospace;
        }

        body {
            display: grid;
            grid-template-columns: 1fr 3fr;
        }

        h2 {
            font-size: 2rem;
            padding-bottom: .5em;
        }

        pre {
            background: #f4f4f4;
            border: 1px solid #ddd;
            border-left: 3px solid #f36d33;
            color: #000;
            page-break-inside: avoid;
            font-family: monospace;
            font-size: 15px;
            line-height: 1.6;
            margin-bottom: 1.6em;
            max-width: 100%;
            overflow: auto;
            padding: 0 1.5em;
            display: block;
            word-wrap: break-word;
        }

        .file-view {
            background: var(--white);
        }

        .file-view img {
            width: 100%;
            height: auto;
            object-fit: contain;
        }

        .dir-container {
            background-color: var(--light-gray);
            height: 100%;
            padding: 2em;
        }

        .dir-listing {
            background-color: var(--light-gray);
            display: flex;
            flex-direction: column;
            gap: 1em;
        }

        .dir-listing > div {
            padding: var(--list-pad);
            border: var(--default-border);
            border-radius: var(--default-rounding);
            box-shadow: var(--light-shadow);
            background-color: var(--white);
        }

        .dir-listing details > summary, 
        .dir-listing details[open] > summary {
            box-shadow: var(--light-shadow);
            background: rgb(3, 94, 145);
            background: -moz-linear-gradient(
                90deg,
                rgba(3, 94, 145, 1) 0%,
                rgba(6, 131, 207, 1) 35%,
                rgba(0, 212, 255, 1) 100%
            );
            background: -webkit-linear-gradient(
                90deg,
                rgba(3, 94, 145, 1) 0%,
                rgba(6, 131, 207, 1) 35%,
                rgba(0, 212, 255, 1) 100%
            );
            background: linear-gradient(
                90deg,
                rgba(3, 94, 145, 1) 0%,
                rgba(6, 131, 207, 1) 35%,
                rgba(0, 212, 255, 1) 100%
            );
            filter: progid:DXImageTransform.Microsoft.gradient(startColorstr="#035e91",endColorstr="#00d4ff",GradientType=1);
        }

        .dir-listing details > summary {
            padding: var(--list-pad);
            border: var(--default-border);
            border-radius: var(--default-rounding);
            color: var(--white);
        }

        .dir-listing details[open] > summary {
            border-bottom-left-radius: 0;
            border-bottom-right-radius: 0;
        }

        .dir-listing details > div {
            padding: var(--list-pad);
            background-color: var(--light-gray);
            box-shadow: var(--light-shadow);
            border: 2px solid var(--dark-gray);
            border-bottom-left-radius: var(--default-rounding);
            border-bottom-right-radius: var(--default-rounding);
        }

        .dir-listing details > summary:focus {
            outline: none;
        }

        .dir-listing details > summary:hover {
            outline: none;
        }
    </style>
</head>
<body>
    <div class="dir-container">
        <h2>File List</h2>
        <?= tree_view_html(ls($default_path)) ?>
    </div>
    <div class="file-view">

    </div>
    <script>
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
                    <pre>
                    <code>
${await getTextContents(path)}
                    </code>
                    </pre>
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
    </script>
</body>
</html>
