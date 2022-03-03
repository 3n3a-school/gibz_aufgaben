<?php

$file_to_check = "random.txt";
$file_md5 = "f6eabdbd598c982f8cb691ce7dc04c3d"; // get with `md5sum`
$file_ok = false;

if (md5_file($file_to_check) == $file_md5) {
    $file_ok = true;
} else {
    $file_ok = false;
}

$file_status = $file_ok ? "File ok" : "File tampered with";

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a060</title>
    <style>
        .main {
            display: flex;
            height: 95vh;
            justify-content: center;
            align-items: center;
            flex-direction: column;
        }
    </style>
</head>
<body>
    <div class="main">
        <h1>File Checker</h1>
        <?= $file_status ?>
    </div>
</body>
</html>