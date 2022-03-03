<?php

function outputName($name = "bunny") {
    $name = array_key_exists("name", $_GET) ? $_GET["name"] : $name;
    return "My name is $name the bunny";
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a020</title>
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
        <?= outputName(); ?>

        <form action="./" method="GET">
            <input name="name" value="<?= array_key_exists("name", $_GET) ? $_GET["name"] : "" ?>" placeholder="Enter your name.. (we won't sell it, promise ;)" />
            <button>Send</button>
        </form>
    </div>
</body>
</html>