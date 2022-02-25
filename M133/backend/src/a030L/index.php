<?php

function outputNames($names = array()) {
    $out = "";

    foreach ($names as $name) {
        $out .= sprintf("<li>%s</li>", $name);
    }
    return $out;
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a030L</title>
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
        <h1>List of Names</h1>
        <ul>
            <?= outputNames(["Fred", "Pual", "Pascal"]); ?>
        </ul>
    </div>
</body>
</html>