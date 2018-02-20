<?php

include '../include/sistema.inc';
include '../include/directoris.inc';
include '../include/arxius.inc';


//Directoris.inc Functions

function crea_directori($dir){
    if ($dir != null){
        mkdir($dir);
    }else {
        echo "Directory name is empty";
    }
}
