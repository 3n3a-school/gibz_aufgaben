<?php

/**
 * Messaging Sytem according to pull principle
 * (Websockets would be push & pull)
 * - Client polls server every 5 sec for new messages
 * - If the messages have been updated, get sent to client
 */

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
    $isSelf =$msg['name'] == $_SESSION['name'] 
        && $msg['color'] == $_SESSION['color']
        && $msg['email'] == $_SESSION['email'];
    $color = $isSelf ? "lightblue" : ($msg['color'] ?? "lightgrey");
    $html_msg .= "<div".( $isSelf ? " class=\"self-msg\"" : "")."><span class=\"meta\" style=\"background-color:$color;\">". 
        ( $isSelf ? "You" : $msg['name'] )
        . ", " . date('h:i', (int)$msg['date']) . "</span> " . $msg['message'] . "</div>";
}

if (array_key_exists('gimme_msg', $_GET)) {
    // for less traffic, check if hashes of messages match
    if ( $_GET['gimme_msg'] == md5($html_msg) ) {
        http_response_code(304);
        exit;
    }
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
    <link rel="stylesheet" href="style.css" />
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
    <script src="https://cdnjs.cloudflare.com/ajax/libs/crypto-js/4.1.1/core.min.js" integrity="sha512-t8vdA86yKUE154D1VlNn78JbDkjv3HxdK/0MJDMBUXUjshuzRgET0ERp/0MAgYS+8YD9YmFwnz6+FWLz1gRZaw==" crossorigin="anonymous" referrerpolicy="no-referrer"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/crypto-js/4.1.1/md5.min.js" integrity="sha512-3sGbaDyhjGb+yxqvJKi/gl5zL4J7P5Yh4GXzq+E9puzlmVkIctjf4yP6LfijOUvtoBI3p9pLKia9crHsgYDTUQ==" crossorigin="anonymous" referrerpolicy="no-referrer"></script>
    <script src="script.js"></script>
</body>
</html>