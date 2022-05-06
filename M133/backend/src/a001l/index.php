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
    <link rel="stylesheet" href="./style.css" type="text/css">
</head>
<body>
    <div class="dir-container">
        <h2>File List</h2>
        <?= tree_view_html(ls($default_path)) ?>
    </div>
    <div class="file-view">

    </div>
    <script src="./script.js"></script>
</body>
</html>
