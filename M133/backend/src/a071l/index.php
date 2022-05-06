<?php


$translations = array(
    'de' => array(
        'locale' => 'de_CH',
        'welcome_msg' => 'Willkommen',
        'time_desc' => 'Jetzige Zeit',
        'morning' => 'Guten Morgen',
        'afternoon' => 'Schönen Nachmittag',
        'evening' => 'Guten Abend'
    ),
    'fr' => array(
        'locale' => 'fr_FR',
        'welcome_msg' => 'Bienvenue',
        'time_desc' => 'Temps actuel',
        'morning' => 'Bonjour',
        'afternoon' => 'Bonne journée',
        'evening' => 'Bonne nuit'
    ),
    'it' => array(
        'locale' => 'it_IT',
        'welcome_msg' => 'Benvenuto',
        'time_desc' => 'Tempo corrente',
        'morning' => 'Buona giornata',
        'afternoon' => 'Buon giorno',
        'evening' => 'Buona notte'
    ),
    'en' => array(
        'locale' => 'en_US',
        'welcome_msg' => 'Welcome',
        'time_desc' => 'Current Time',
        'morning' => 'Good Morning',
        'afternoon' => 'Good day',
        'evening' => 'Good evening'
    )
);
    
$lang = array_key_exists( 'lang', $_GET) ? $_GET['lang'] : 'de';
$df = new IntlDateFormatter(
    $translations[$lang]['locale'],
    IntlDateFormatter::LONG,
    IntlDateFormatter::MEDIUM
);
$current_time_str = $df->format(date_create());
    
$time_sector = get_time_sector();
$current_welcome_message = $translations[$lang][$time_sector];


function get_time_sector() {
    $hours = (int)date('H');
    $time_sector = '';

    switch ($hours) {
        case $hours < 12:
            $time_sector = 'morning';
            break;
        
        case $hours < 18:
            $time_sector = 'afternoon';
            break;

        case $hours < 23 || $hours < 2:
            $time_sector = 'evening';
            break;
        
        default:
            $time_sector = 'morning';
            break;
    }

    return $time_sector;
}

?>

<!DOCTYPE html>
<html lang="<?= $lang ?>">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>a071</title>
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
    <div class="lang-switcher">
        <form id="lang-select-form" method="GET" action="./">
            <select id="lang-select" name="lang" >
                <?php
                    foreach ($translations as $lang_ => $strings) {
                        echo "<option value=\"$lang_\" ".($lang_ == $lang ? "selected" : "").">".ucfirst($lang_)."</option>";
                    }
                ?>
            </select>
        </form>
    </div>
    <div class="main">
        <h1><?= $translations[$lang]['welcome_msg'] ?></h1>
        <p><?= $translations[$lang]['time_desc'] ?>: <?= $current_time_str ?> | <?= $time_sector ?></p>
        <p><?= $current_welcome_message ?></p>
    </div>
    <script>
        document.getElementById('lang-select').addEventListener('change', function() {
            document.getElementById('lang-select-form').submit()
        })
    </script>
</body>
</html>