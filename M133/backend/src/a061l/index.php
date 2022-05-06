<?php

session_start();

$visited_site = false;

if (array_key_exists('ip-addr', $_SESSION)) {
    if($_SESSION['ip-addr'] == $_SERVER["REMOTE_ADDR"]) {
        $visited_site = true;
    } else {
        $visited_site = false;
    }
}

$results = [
    "You already visited us :(",
    "Welcome to this awesome new website... :)"
];
$result_displayed = $visited_site ? $results[0] : $results[1];

$_SESSION['ip-addr'] = $_SERVER["REMOTE_ADDR"];
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a061</title>
    <style>
        .main {
            display: flex;
            height: 95vh;
            justify-content: center;
            align-items: center;
            flex-direction: column;
        }

        .locked-result {
            color: <?= $visited_site ? "red" : "white" ?>;
        }
    </style>
</head>
<body>
    <div class="main">
        <h1>Just another commonly visited site...</h1>
        <p class="locked-result"><?= $result_displayed ?></p>
    </div>
</body>
</html>