<?php

// Help: https://www.w3schools.com/php/php_file_create.asp

class FileHandler {
    private $filename = '';
    private $current_file;

    function __construct($filename) {
        $this->filename = $filename;
    }

    public function open() {
        $this->current_file = fopen($this->filename, 'w+') or die('Unable to open file');
    }

    public function read() {
        $file_size = filesize($this->filename);
        return fread( $this->current_file, $file_size);
    }

    function __destruct() {
        fclose($this->current_file);
    }
}

$fh = new FileHandler("test.txt");
$fh->open();

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
        <?= $fh->read() ?>
    </div>
</body>
</html>