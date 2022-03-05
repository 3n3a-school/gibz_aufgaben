<?php

function ls($path=__DIR__) {
    $list = scandir($path);

    foreach ($list as $i => $list_el) {
        
    }

    return print_r($list, true);
} 

?>

<pre>
<?= ls("..") ?>
</pre>