<?php

// Help: https://www.w3schools.com/php/php_file_create.asp

require_once __DIR__ . "/../lib/FileHandler.php";
$fh = new \Enea\FileHandler("test.txt");

if (array_key_exists('input', $_POST)) {
    $fh->writeln($_POST['input']);
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a081</title>
    <style>
        .main {
            display: flex;
            height: 95vh;
            justify-content: center;
            align-items: center;
            flex-direction: column;
        }

        pre code {
            display: block;
            background: none;
            white-space: pre;
            -webkit-overflow-scrolling: touch;
            overflow-x: scroll;
            max-width: 100%;
            min-width: 100px;
            padding: 0;
        }
    </style>
</head>
<body>
    <div class="main">
        <h1>Add text to file by Pressing Button</h1>
        <form action="./" method="POST">
            <input type="textarea" name="input">
            <button>Submit</button>
        </form>
        <pre>
            <code>
<?= $fh->read(true) ?>
            </code>
        </pre>
    </div>
</body>
</html>