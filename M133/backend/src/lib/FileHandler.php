<?php

namespace Enea;

class FileHandler {
    private $filename = '';
    private $current_file;

    function __construct($filename) {
        $this->filename = $filename;
        $this->open();
    }

    private function open() {
        $this->current_file = fopen($this->filename, 'r+') or die('Unable to open file');
    }

    public function read($reverse=false) {
        if($reverse) {
            return implode('', $this->read_reverse());
        } else {
            $file_size = filesize($this->filename);
            return fread( $this->current_file, $file_size);
        }
    }

    /**
     * Reads a files lines into an array
     */
    public function read2arr() {
        $out = array();

        while (!feof($this->current_file)) {
            array_push($out, fgets($this->current_file));
        }

        // move file ptr back to beginning, so others may use
        rewind( $this->current_file );

        return $out;
    }

    public function read_html($reverse=false) {
        if ($reverse) {
            $lines_arr = $this->read_reverse();
        } else {
            $lines_arr = $this->read2arr();
        }
        return implode( '<br>', $lines_arr );
    }

    public function read_html_list($additional_tag=NULL, $additional_atts=NULL, $reverse=false) {
        $out = "";
        $lines = $this->read2arr($reverse);

        $additional_atts = !empty($additional_atts) ? $additional_atts : '';
        $additional_tag = !empty($additional_tag) ? 
            ["<$additional_tag $additional_atts>", "</$additional_tag>"] : ['', ''];

        foreach ($lines as $line) {
            if ( !empty($line) && $line != "\n" ) {
                $out .= "<li>" .
                    ( $additional_atts != '' ? str_replace('%1', $line, $additional_tag[0]) : $additional_tag[0])
                . $line . $additional_tag[1] . "</li>";
            }
        }

        return $out;
    }

    public function read_reverse() {
        $lines_arr = $this->read2arr();
        return array_reverse($lines_arr);
    }

    public function writeln($line) {
        fseek($this->current_file, -1, SEEK_END);
        fwrite($this->current_file,  PHP_EOL . $line . PHP_EOL);
        rewind($this->current_file);
    }

    public function write( $new_content ) {

        // not directly modifying on handle
        // because didn't work
        fclose($this->current_file);

        $temp_f = fopen($this->filename, 'w');
        fwrite( $temp_f, $new_content );
        fclose($temp_f);

        $this->open();
    }

    function __destruct() {
        fclose($this->current_file);
    }
}