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
        case 'mkdir':
            $_SESSION['output'] = crea_directori($arrInput[1]);
            break;
        case 'rm':
            if ($arrInput[1] == '-d') {
                $removed = esborra_directori($arrInput[2]);
            } else if ($arrInput[1] == '-f') {
                $removed = esborra_fitxer($arrInput[2]);
            } else {
                $removed = "Utilitza paràmetres vàlids";
            }

            $_SESSION['output'] = $removed;
            break;
        case 'mv':
            if ($arrInput[1] == '-d') {
                $moved = mou_directori($arrInput[2], $arrInput[3]);
            } else if ($arrInput[1] == '-f') {
                $moved = mou_fitxer($arrInput[2], $arrInput[3]);
            } else {
                $moved = "Utilitza paràmetres vàlids";
            }

            $_SESSION['output'] = $moved;
            break;
        case 'cp':
            if ($arrInput[1] == '-d') {
                $copied = copia_directori($arrInput[2], $arrInput[3]);
            } else if ($arrInput[1] == '-f') {
                $copied = copia_fitxer($arrInput[2], $arrInput[3]);
            } else {
                $copied = "Utilitza paràmetres vàlids";
            }

            $_SESSION['output'] = $copied;
            break;
        case 'find':
            $_SESSION['output'] = find_fitxer($arrInput[1], $arrInput[2]);
            break;
        case 'stats':
            $_SESSION['output'] = stats_fitxer($arrInput[1]);
            break;
        case 'vim':
            $_SESSION['output'] = crea_modifica_fitxer($arrInput[1], $arrInput[2]);
            break;
        case 'sha1':
            $_SESSION['output'] = our_sha1($arrInput[1]);
            break;
        case 'md5':
            $_SESSION['output'] = our_md5($arrInput[1]);
            break;
        case 'ls':
            $_SESSION['output'] = llistat($arrInput[1]);
            break;
        case 'pwd':
            $_SESSION['output'] = ruta();
            break;
        case 'free':
            $_SESSION['output'] = stats_sistema();
            break;
        case 'clear':
            $_SESSION['output'] = "";
            break;
        case 'help':
            $commands = Array("mkdir -DIRECTORI- -> Crea un nou directori", "rm -d -DIRECTORI- -> Esborra un directori",
                "mv -d -DIRECTORI- -DESTI- -> Mou un directori a un desti", "cp -d -DIRECTORI- -> Copia un directori a un desti",
                "find -FITXER- -RUTA- -> Indica si el fitxer està dins d'un directori", "stats -FITXER- -> Estadístiques sobre un fitxer",
                "rm -f -FITXER- -> Esborra un fitxer", "mv -f -FITXER- -DESTI- -> Mou un fitxer a un directori",
                "cp -f -FITXER- -> Copia un fitxer a un directori", "vim -FITXER- -CONTINGUT- -> Crea un fitxer amb contingut o modifica si ja existeix", "sha1 -FITXER- -> Hash sha1 d'un fitxer",
                "md5 -FITXER- -> Hash md5 d'un fitxer", "ls -DIRECTORI- -> Llista tots els directoris inclosos dins d'un directori",
                "pwd -> Retorna la ruta actual", "stats -FITXER- -> Retorna estadístiques d'un fitxer", "clear -> Neteja la pantalla"
            );

            $_SESSION['output'] = $commands;
            break;
        default:
            $commands = Array("COMANDES DISPONIBLES", "mkdir -DIRECTORI- -> Crea un nou directori", "rm -d -DIRECTORI- -> Esborra un directori",
                "mv -d -DIRECTORI- -DESTI- -> Mou un directori a un desti", "cp -d -DIRECTORI- -> Copia un directori a un desti",
                "find -FITXER- -RUTA- -> Indica si el fitxer està dins d'un directori", "stats -FITXER- -> Estadístiques sobre un fitxer",
                "rm -f -FITXER- -> Esborra un fitxer", "mv -f -FITXER- -DESTI- -> Mou un fitxer a un directori",
                "cp -f -FITXER- -> Copia un fitxer a un directori", "vim -FITXER- -CONTINGUT- -> Crea un fitxer amb contingut o modifica si ja existeix", "sha1 -FITXER- -> Hash sha1 d'un fitxer",
                "md5 -FITXER- -> Hash md5 d'un fitxer", "ls -DIRECTORI- -> Llista tots els directoris inclosos dins d'un directori",
                "pwd -> Retorna la ruta actual", "stats -FITXER- -> Retorna estadístiques d'un fitxer", "clear -> Neteja la pantalla"
            );

            $_SESSION['output'] = $commands;
            break;
    }

    header('Location: consola.php');
}