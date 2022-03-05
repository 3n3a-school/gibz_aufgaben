<?php

$date_input = array_key_exists('date', $_POST) ?
 date_create($_POST['date']) 
 : date_create();

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a072</title>
    <style>
        .main {
            display: flex;
            height: 95vh;
            justify-content: center;
            align-items: center;
            flex-direction: column;
        }

        form {
            display: flex;
            flex-direction: column;
            gap: 1em;
        }

        label {
            display: flex;
            flex-direction: column;
        }
    </style>
</head>
<body>
    <div class="main">
        <h1>Geburtsdatum Extraktor</h1>
        <h3>Sie wurden an einem <?= date_format($date_input, 'l') ?> geboren</h3>
        <form method="POST" action="./">
            <label>Geburtsdatum: <input type="date" name="date" value="<?= date_format($date_input, 'Y-m-d') ?>"></label>
            <button>Berechnen</button>
        </form>
    </div>
</body>
</html>