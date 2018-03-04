<?php

function crea_directori($dir){
    if ($dir != null){
        if (!file_exists($dir)){
            mkdir($dir);
            return 1;
        }else{
            return 0;
        }
    }else {
        return -1;
    }
}

function esborra_directori($dir){
    if ($dir != null){
        if (file_exists($dir)){
            rmdir($dir);
            return 1;
        }else{
            return 0;
        }
    }else {
        return -1;
    }
}

function mou_directori($dir, $rutadesti){
    if ($dir != null && $rutadesti != null){
        rename($dir, $rutadesti.DIRECTORY_SEPARATOR.$dir);
        return true;
    } else {
        return false;
    }
}

function copia_directori($dir, $rutadesti){
    if ($dir != null && $rutadesti != null){
        copy($dir, $rutadesti.DIRECTORY_SEPARATOR.$dir);
        return true;
    } else {
        return false;
    }
}