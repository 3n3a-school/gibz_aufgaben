<?php

$colors = [
    "red",
    "green",
    "orange",
    "purple",
    "blue"
];
$selected_color = array_key_exists("color", $_POST) ? (int)$_POST['color'] : null;
$color = !empty($selected_color) ?  $colors[$selected_color]: "white";
$err_msg = "Please select a color.";

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a041L</title>
    <style>
        body {
            background-color: <?= $color ?>;
        }
        .main {
            display: flex;
            height: 95vh;
            justify-content: center;
            align-items: center;
            flex-direction: column;
        }
        .err-msg {
            color: red;
            font-weight: bold;
        }
        form {
            display: flex;
            flex-direction: column;
        }
    </style>
</head>
<body>
    <div class="main">
        <h1>Pick Back Color</h1>
        <?= array_key_exists("color", $_POST) ? "" : "<p class=\"err-msg\">" . $err_msg . "</p>" ?>
        <form action="./" method="POST">
            <?php
                foreach ($colors as $i => $color) {
                    $is_checked = $selected_color == $i ? "checked": "";
                    echo "<span><input type=\"radio\" name=\"color\" value=\"$i\" $is_checked>$color</span>";
                }
            ?>
            <button>Send</button>
        </form>
    </div>
</body>
</html>