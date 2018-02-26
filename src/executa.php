<?php

include '../include/sistema.inc';
include '../include/directoris.inc';
include '../include/arxius.inc';

if ($_SERVER['REQUEST_METHOD'] == 'POST' && !empty($_POST['input_cmd'])) {
    session_start();
    $inputTaken = $_POST['input_cmd'];
    $arrInput = explode(' ', trim($inputTaken));

    switch ($arrInput[0]) {
        case 'help':
            $_SESSION['output'] = 'hola';
            header('Location: consola.php');
            break;
        case 'mkdir':
            crea_directori($arrInput[1]);
            break;
        case 'rm':
            esborra_directori($arrInput[1]);
            break;
        case 'mv':
            mou_directori($arrInput[1], $arrInput[2]);
            break;
        case 'cp':
            if (is_dir($arrInput[1]) && is_dir($arrInput[2])) {
                copia_directori($arrInput[1], $arrInput[2]);
            } elseif (is_file($arrInput[1]) && is_dir($arrInput[2])) {
                copia_fitxer($arrInput[1], $arrInput[2]);
            }
            break;
        case 'find':
            break;
        case 'stats':
            break;
        case 'vim':
            break;
        case 'sha1':
            break;
        case 'md5':
            break;
        case 'ls':
            llistat($arrInput[1]);
            break;
        case 'pwd':
            ruta();
            break;
        case 'free':
            break;
    }
}