<?php

function list_dirs($path) {
    $list=scandir($path);
    $dirs = [];
    foreach($list as $value){
        if($value!='..' &&  $value!="." && !is_file($path.'/'.$value) ){
            array_push($dirs, $value);
        }
    }

    return $dirs;
}

function create_html_list($array, $list_type = "ul") {
    $list_class = "list-none grid grid-cols-1 gap-1";
    $list_element_class = "p-3 rounded border-2 border-black flex gap-2 hover:bg-blue-600 hover:text-white";
    
    $output="<$list_type class=\"$list_class\">";
    
    foreach ($array as $e) {
        if (!stristr($e, 'a')) {
            break;
        }
        $output .= "<a class=\"text-blue-600 w-full h-full\" href=\"/$e/\">
        <li class=\"$list_element_class\">
        <svg xmlns=\"http://www.w3.org/2000/svg\" class=\"h-6 w-6\" fill=\"none\" viewBox=\"0 0 24 24\" stroke=\"currentColor\" stroke-width=\"2\">
        <path stroke-linecap=\"round\" stroke-linejoin=\"round\" d=\"M3 7v10a2 2 0 002 2h14a2 2 0 002-2V9a2 2 0 00-2-2h-6l-2-2H5a2 2 0 00-2 2z\" />
        </svg>
        $e</li>
        </a>";
    }

    $output .= "</$list_type>";
    return $output;
}