<?php

function llistat($dir)
{
    $currentDir = HOME . DIRECTORY_SEPARATOR . $dir;

    if ($dir != null) {
        if (is_dir($currentDir)) {
            return scandir($currentDir);
        } else {
            return "$dir no és cap directori";
        }
    } else {
        return scandir(HOME);
    }

}

function ruta()
{
    return getcwd();
}

function stats_sistema()
{
    $sysStats = Array();

    $diskTotal = disk_total_space(DIRECTORY_SEPARATOR);
    $diskFree = disk_free_space(DIRECTORY_SEPARATOR);

    $gbFree = number_format($diskFree / pow(10, 9), 2);

    $percFree = number_format($diskFree / $diskTotal * 100, 2);
    $storageFree = $gbFree . "Gb's lliures al disc --------------- " . $percFree . "%";

    $gbStored = number_format(($diskTotal - $diskFree) / pow(10, 9), 2);
    $percStored = number_format(($diskTotal - $diskFree) / $diskTotal * 100, 2);
    $storageFull = $gbStored . "Gb's omplerts al disc --------------- " . $percStored . "%";

    array_push($sysStats, $storageFree, $storageFull);
    return $sysStats;
}