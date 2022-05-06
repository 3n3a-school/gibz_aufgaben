<?php 

$title = "PHP Farben Test";

$random_number = random_int(0, 255);
$color = "rgb($random_number, $random_number, $random_number)";

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?= $title ?></title>
    <style>
        body {
            background-color: <?= $color ?>;
        }

        .abs-center {
            display: flex;
            height: 95vh;
            justify-content: center;
            align-items: center;
        }
    </style>
</head>
<body>
    <div class="abs-center">
        <h1>Random Color</h1>
    </div>
</body>
</html>