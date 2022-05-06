<?php

// Help: https://www.w3schools.com/php/php_file_create.asp

require_once __DIR__ . "/../lib/FileHandler.php";
$fh = new \Enea\FileHandler("test.txt");

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a080</title>
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
        <div><?= $fh->read_html() ?></div>
        <div><?= $fh->read() ?></div>
    </div>
</body>
</html>