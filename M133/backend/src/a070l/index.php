<?php

$df = new IntlDateFormatter(
    'de_CH',
    IntlDateFormatter::LONG,
    IntlDateFormatter::MEDIUM
);

// Zeitrechner

$time_now = date_create("now");
$set_time = date_create("2022-04-20");
$time_diff = (array)date_diff($time_now, $set_time);

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a070</title>
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
        <h1>Zeitrechner</h1>
        <p>Jetzt ist der <?= $df->format($time_now) ?></p>
        <p>Eingestellte Zeit: <?= $df->format($set_time) ?></p>
        <p>Time diff (sec): <?= $time_diff['days'] * 24 * 60 * 60 ?></p>
    </div>
</body>
</html>