<?php

$color = "#fefefe";
$creds = [
    "admin" => "admin",
    "user" => "1234"
];

function checkCreds($username, $password) {
    global $creds;
    if (array_key_exists($username, $creds) && $creds[$username] == $password) {
        return true;
    } else {
        return false;
    }
}

$auth_successful = false;

if (array_key_exists('username', $_POST) && array_key_exists('password', $_POST)) {
    $auth_successful = checkCreds($_POST["username"], $_POST["password"]);
} else {
    $auth_successful = false;
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a041L</title>
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Comic+Neue&display=swap');
        :root {
            --animation-time: 10s;
        }
        body {
            font-family: 'Comic Neue', cursive;
        }
        body, input, button, label {
            font-size: 1.25rem;
        }

        html {
            background: linear-gradient(to left, violet, indigo, blue, green, yellow, orange, red);
            background-size: 2800% 2800%;

            -webkit-animation: Rainbow var(--animation-time) ease infinite;
            -moz-animation: Rainbow var(--animation-time) ease infinite;
            animation: Rainbow var(--animation-time) ease infinite;
        }
        h1, p, label, input, button {
            color: rgb(255, 255, 255); 
            mix-blend-mode: difference;
            
        }
        @-webkit-keyframes Rainbow {
            0%{background-position:0% 50%}
            50%{background-position:100% 50%}
            100%{background-position:0% 50%}
        }
        @-moz-keyframes Rainbow {
            0%{background-position:0% 50%}
            50%{background-position:100% 50%}
            100%{background-position:0% 50%}
        }
        @keyframes Rainbow {
            0%{background-position:0% 50%}
            50%{background-position:100% 50%}
            100%{background-position:0% 50%}
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
            gap: .5em;
        }
        input {
            background-color: transparent;
            border: 3px solid rgb(255,255,255);
            padding: .5em .75em;
        }
        button {
            background-color: transparent;
            border: 3px solid rgb(255,255,255);
            padding: .5em .75em;
        }
        .field {
            display: flex;
            flex-direction: column;
        }
    </style>
</head>
<body>
    <div class="main">
        <?php $auth_successful ? 
        include("home.php") : 
        include("login.php"); ?>
    </div>
</body>
</html>