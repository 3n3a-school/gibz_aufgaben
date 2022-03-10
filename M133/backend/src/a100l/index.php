<?php

require_once("db.php");

if (array_key_exists('msg', $_POST)) {
    add_msg("enea", "enea@email.com", $_POST['msg']);
}

$html_msg = "";
foreach (get_all_msg() as $msg) {
    $html_msg .= "<div>". $msg['name'] . " " . $msg['email'] . " " . $msg['date'] . " " . $msg['message'] . "</div>";
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Messageboard</title>
    <style>
        .board {
            display: flex;
            flex-direction: column;
            gap: 1em;
        }

        .board div {
            padding: 1em;
            border-radius: .5em;
            border: 1px solid black;
        }
    </style>
</head>
<body>
    <div class="board">
        <?= $html_msg ?>
    </div>
    <div class="create-msg">
        <form action="./" method="POST">
            <label for="msg">Message:</label>
            <input type="text" name="msg" />
            <button>Send</button>
        </form>
    </div>
</body>
</html>