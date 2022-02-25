<?php

// PHP - Router: https://github.com/bramus/router
require __DIR__ . '/lib/Router.php';
$router = new \Bramus\Router\Router();

header('X-Powered-By: eServer');

$router->get('/', function() {
    $random_ass_text = "Hello there world" . date("Y-M-D");
    echo <<<EOF
<!doctype html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <script src="https://cdn.tailwindcss.com"></script>
</head>
<body>
  <h1 class="text-3xl font-bold underline">
    $random_ass_text
  </h1>
</body>
</html>
EOF;
});

$router->run();