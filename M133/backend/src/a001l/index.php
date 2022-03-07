<?php

/**
 * Recursive directory listing for given path
 */
function ls($path=__DIR__) {
    $list = scandir($path);
    $out_list = [];

    foreach ($list as $i => $list_el) {
        if ( $list_el != "." && $list_el != ".." ) {
            $path_to_el = $path . '/' . $list_el;

            if ( is_dir($path_to_el) ) {
                $subdirs = ls($path_to_el);
                array_push($out_list, [
                    'name' => $list_el,
                    'dirs' => $subdirs
                ]);
            } else {
                // is file
                array_push($out_list, [
                    'name' => $list_el,
                ]);
            }
        }
    }

    return $out_list;
}

function tree_view_html($array) {
    $out = "<ul>";

    foreach ($array as $key => $value) {
        if (array_key_exists('dirs', $value)) {
            $out .= "<li> - ".$value['name'];
            $out .= tree_view_html($value['dirs']);
            $out .= "</li>";
        } else {
            $out .= "<li>".$value['name']."</li>";
        }
    }

    $out .= "</ul>";

    return $out;
}

?>

<pre>
<?= tree_view_html(ls("..")) ?>
</pre>