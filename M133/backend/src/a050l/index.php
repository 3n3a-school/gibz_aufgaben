<?php

$input_number = array_key_exists('zahl', $_POST) && !empty($_POST['zahl']) ? $_POST['zahl'] : null;

function umrechnung($number) {
    $binary_number = decbin($number);
    $hex_number = dechex($number);

    $out = "
    <p>
    Umrechnung der Dezimalzahl $number:</p><p>
    ins Binärsystem: $binary_number</p><p>
    ins Hexadezimalsystem: $hex_number</p><p>
    </p>
    ";
    return $out;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a050</title>
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
        <h1>umrechnung in bin und hex</h1>
        <form method="POST" action="./">
            <label>Dezimalzahl: <input type="number" name="zahl"></label>
            <button>Submit</button>
        </form>
        <?= umrechnung($input_number) ?>
    </div>
</body>
</html>