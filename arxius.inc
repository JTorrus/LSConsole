<?php

function find_fitxer($fitxer, $dir)
{
    $array = scandir($dir);

    foreach ($array as $fileToFind) {
        if (strtolower($fileToFind) == strtolower($fitxer)) {
            return true;
        }
    }

    return false;
}

function stats_fitxer($fitxer)
{
    if (file_exists($fitxer)) {
        echo stat($fitxer);
        return true;
    } else {
        return false;
    }
}

function esborra_fitxer($fitxer)
{
    if (file_exists($fitxer) && is_readable($fitxer)) {
        unlink($fitxer);
        return true;
    } else {
        return false;
    }
}

function mou_fitxer($fitxer, $rutadesti)
{
    if (file_exists($fitxer) && file_exists($rutadesti)) {
        rename($fitxer, $rutadesti . DIRECTORY_SEPARATOR . $fitxer);
        return true;
    } else {
        return false;
    }
}

function copia_fitxer($fitxer, $rutadesti)
{
    if (file_exists($fitxer) && file_exists($rutadesti)) {
        copy($fitxer, $rutadesti . DIRECTORY_SEPARATOR . $fitxer);
        return true;
    } else {
        return false;
    }
}

function crea_modifica_fitxer($fitxer, $contingut)
{
    if (!file_exists($fitxer) && empty($contingut)) {
        touch($fitxer);
        return true;
    } else if (!file_exists($fitxer) && !empty($contingut)) {
        touch($fitxer);
        $file = fopen($fitxer, "w");
        fwrite($file, $contingut);
        fclose($file);
        return true;
    } else if (file_exists($fitxer) && !empty($contingut)) {
        $file = fopen($fitxer, "w");
        fwrite($file, $contingut);
        fclose($file);
        return true;
    } else {
        return false;
    }
}

function our_sha1($fitxer){
    if (file_exists($fitxer)) {
        echo sha1($fitxer);
        return true;
    } else {
        return false;
    }
}

function our_md5($fitxer){
    if (file_exists($fitxer)) {
        echo md5($fitxer);
        return true;
    } else {
        return false;
    }
}