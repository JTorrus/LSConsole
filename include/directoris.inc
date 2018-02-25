<?php

function crea_directori($dir){
    if ($dir != null){
        if (!file_exists($dir)){
            mkdir($dir);
            echo "Directori creat amb exit";
        }else{
            echo "El directori existeix";
        }
    }else {
        echo "Has d' insertar el nom del directori";
    }
}

function esborra_directori($dir){
    if ($dir != null){
        if (file_exists($dir)){
            rmdir($dir);
            echo "Directori esborrat amb exit";
        }else{
            echo "El directori no existeix";
        }
    }else {
        echo "Has d' insertar el nom del directori";
    }
}

function mou_directori($dir, $rutadesti){
    if ($dir != null && $rutadesti != null){
        rename($dir, "$rutadesti/$dir");
    }
}

function copia_directori($dir, $rutadesti){
    if ($dir != null && $rutadesti != null){
        copy($dir, $rutadesti/$dir);
    }
}