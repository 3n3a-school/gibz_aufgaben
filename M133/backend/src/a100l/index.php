<?php

session_start();

require_once("db.php");


function randColor() {
    $rand = array('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f');
    $color = '#'.$rand[rand(0,15)].$rand[rand(0,15)].$rand[rand(0,15)].$rand[rand(0,15)].$rand[rand(0,15)].$rand[rand(0,15)];
    return $color;
}

if (array_key_exists('name', $_POST) && array_key_exists('email', $_POST)) {
    $_SESSION['name'] = $_POST['name'];
    $_SESSION['email'] = $_POST['email'];
    $_SESSION['color'] = randColor();
}

if ( !array_key_exists('name', $_SESSION) || !array_key_exists('email', $_SESSION)
    || !array_key_exists('color', $_SESSION) ) {
    echo "<form action='./' method='POST'><label for='email'>Email</label><input type='email' name='email'>
    <label for='name'>Name</label><input type='name' name='name'>
    <button>Login</button>
    </form>";
    exit;
}

if (array_key_exists('msg', $_POST)) {
    add_msg($_SESSION['name'], $_SESSION['email'], $_POST['msg'], $_SESSION['color']);
    exit;
}

$html_msg = "";
foreach (array_reverse(get_all_msg()) as $msg) {
    $color = $msg['color'] ?? "lightgrey";
    $html_msg .= "<div><span class=\"meta\" style=\"background-color:$color;\">". $msg['name'] . ", " . date('h:i', (int)$msg['date']) . "</span> " . $msg['message'] . "</div>";
}

if (array_key_exists('gimme_msg', $_GET)) {
    echo $html_msg;
    exit;
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <!-- <meta http-equiv="refresh" content="5" /> -->
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

        .msg-container {
            bottom: 0;
            left: 0;
            right: 0;
            position: fixed;
            padding: 1em;
        }

        .create-msg {
            border: 1px solid black;
            border-radius: .5em;
            background-color: lightblue;
            padding: 1em;
        }
        
        .create-msg form {
            display: flex;
            gap: .5em;
            align-items: center;
        }
        input {
            padding: .5em .25em;
            flex-grow: 3;
        }

        button {
            padding: .5em 1em;
        }
    </style>
</head>
<body>
    <div class="board">
        <?= $html_msg ?>
    </div>
    <div class="msg-container">
        <div class="create-msg">
            <form action="./" method="POST" id="msg-form">
                <label for="msg">Message:</label>
                <input type="text" id="msg" name="msg" />
                <button>Send</button>
            </form>
        </div>
    </div>
    <script>
        async function fetchNewMsgs() {
            let res = await fetch("./?gimme_msg")
            let text = await res.text()
            return text
        }

        async function updateMessages() {
            let msg = await fetchNewMsgs()
            document.getElementsByClassName("board")[0].innerHTML = msg;
        }

        document.getElementById("msg-form").addEventListener('submit', (e) => {
            e.preventDefault();
            let msg_content = document.getElementById('msg').value;

            document.getElementById('msg').value = "";

            let formData = new FormData();
            formData.append("msg", msg_content);

            let request = new XMLHttpRequest();
            request.open("POST", "./");
            request.send(formData);

            updateMessages()
        })

        setInterval(() => {
            console.log("Reloaded page...")
            updateMessages()
        }, 5000);
    </script>
</body>
</html>