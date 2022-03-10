<?php

require_once("db.php");

if (array_key_exists('name', $_POST) && array_key_exists('email', $_POST)) {
    $_SESSION['name'] = $_POST['name'];
    $_SESSION['email'] = $_POST['email'];
}

if ( !array_key_exists('name', $_SESSION) && !array_key_exists('email', $_SESSION) ) {
    echo "<form action='./' method='POST'><label for='email'>Email</label><input type='email' name='email'>
    <label for='name'>Name</label><input type='name' name='name'>
    <button>Login</button>
    </form>";
    exit;
}

if (array_key_exists('msg', $_POST)) {
    add_msg($_SESSION['name'], $_SESSION['email'], $_POST['msg']);
}

$html_msg = "";
foreach (array_reverse(get_all_msg()) as $msg) {
    $html_msg .= "<div><span class=\"meta\">". $msg['name'] . ", " . $msg['email'] . ", " . $msg['date'] . "</span> " . $msg['message'] . "</div>";
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

        .meta {
            padding: .2em;
            background-color: lightgray;
            border-radius: .25em;
        }

        .create-msg {
            bottom: 0;
            margin-bottom: 1em;
            position: sticky;
            border: 1px solid black;
            border-radius: .5em;
            background-color: lightblue;
            padding: 1em;
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