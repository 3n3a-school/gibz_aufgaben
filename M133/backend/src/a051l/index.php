<?php

$was_button_pressed = array_key_exists('button_pressed', $_POST) && !empty($_POST['button_pressed']) ? $_POST['button_pressed'] == "1" : false;

$lottozahlen = "";

if($was_button_pressed) {
    $lottozahlen .= "<h3>Lottozahlen</h3><ul>";
    $already_chosen = [];
    
    for ($i=0; $i < 6; $i++) { 
        $random_number = null;
        
        do {
            $random_number = random_int(1, 49);
        } while (in_array($random_number, $already_chosen));
        
        array_push($already_chosen, $random_number);
        $lottozahlen .= "<li>".$random_number."</li>";
    }

    $lottozahlen .= "</ul>";
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a051</title>
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
        <h1>Zufällige Lottozahlen</h1>
        <form method="POST" action="./">
            <button name="button_pressed" value="1">Zahlen generieren</button>
        </form>
        <?= $lottozahlen ?>
    </div>
</body>
</html>