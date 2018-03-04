<?php

include 'constants.inc';
include 'sistema.inc';
include 'directoris.inc';
include 'arxius.inc';

if ($_SERVER['REQUEST_METHOD'] == 'POST' && !empty($_POST['input_cmd'])) {
    session_start();
    $inputTaken = $_POST['input_cmd'];
    $arrInput = explode(' ', trim($inputTaken));

    switch ($arrInput[0]) {
        case 'help':
            $commands = Array("mkdir -DIRECTORI- -> Crea un nou directori", "rm -d -DIRECTORI- -> Esborra un directori",
                "mv -d -DIRECTORI- -DESTI- -> Mou un directori a un desti", "cp -d -DIRECTORI- -> Copia un directori a un desti",
                "find -FITXER- -RUTA- -> Indica si el fitxer està dins d'un directori", "stats -FITXER- -> Estadístiques sobre un fitxer",
                "rm -f -FITXER- -> Esborra un fitxer", "mv -f -FITXER- -DESTI- -> Mou un fitxer a un directori",
                "cp -f -FITXER- -> Copia un fitxer a un directori", "vim -FITXER- -CONTINGUT- -> Crea un fitxer amb contingut o modifica si ja existeix", "sha1 -FITXER- -> Hash sha1 d'un fitxer",
                "md5 -FITXER- -> Hash md5 d'un fitxer", "ls -DIRECTORI- -> Llista tots els directoris inclosos dins d'un directori",
                "pwd -> Retorna la ruta actual", "stats -FITXER- -> Retorna estadístiques d'un fitxer"
            );

            $_SESSION['output'] = $commands;
            break;
        case 'mkdir':
            $_SESSION['output'] = crea_directori($arrInput[1]);
            break;
        case 'rm':
            if ($arrInput[1] == '-d') {
                $removed = esborra_directori($arrInput[2]);
            } else if ($arrInput[1] == '-f') {
                //TODO
            } else {
                $removed = "Utilitza paràmetres vàlids";
            }

            $_SESSION['output'] = $removed;
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

    header('Location: consola.php');
}