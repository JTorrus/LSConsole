<?php

include_once 'sistema.inc';

function crea_directori($dir)
{
    $currentDir = HOME . DIRECTORY_SEPARATOR . $dir;

    if ($dir != null) {
        if (!file_exists($currentDir)) {
            if (mkdir($currentDir)) {
                return "Carpeta $dir creada correctament";
            } else {
                return "Hi ha hagut un problema amb la creació de la carpeta";
            }
        } else {
            return "La carpeta $dir ja existeix";
        }
    } else {
        return "Especifica un nom per a la carpeta";
    }
}

function esborra_directori($dir)
{
    $currentDir = HOME . DIRECTORY_SEPARATOR . $dir;

    if ($dir != null) {
        if (file_exists($currentDir)) {
            $files = scandir($currentDir);
            if (empty($files)) {
                if (is_dir($currentDir)) {
                    if (rmdir($currentDir)) {
                        return "La carpeta $dir s'ha esborrat correctament";
                    }
                } else {
                    return "$dir és un fitxer, utilitza la comanda rm -f per esborrar-ho";
                }
            } else {
                foreach ($files as $current) {
                    $actualFile = $currentDir . DIRECTORY_SEPARATOR . $current;

                    if ($actualFile != "." && $actualFile != "..") {
                        if (is_dir($actualFile)) {
                            esborra_directori($actualFile);
                        } else {
                            unlink($actualFile);
                        }
                    }
                }

                if (rmdir($currentDir)) {
                    return "La carpeta $dir s'ha esborrat correctament";
                }
            }
        } else {
            return "La carpeta $dir no existeix";
        }
    } else {
        return "Especifica un nom per a la carpeta";
    }
}

function mou_directori($dir, $rutadesti)
{
    $currentDir = HOME . DIRECTORY_SEPARATOR . $dir;
    $destiny = HOME . DIRECTORY_SEPARATOR . $rutadesti;

    if ($dir != null && $rutadesti != null) {
        if (file_exists($currentDir)) {
            if (rename($currentDir, $destiny)) {
                return "S'ha mogut la carpeta $dir a $rutadesti correctament";
            } else {
                return "Hi ha hagut un problema movent la carpeta $dir a $rutadesti";
            }
        } else {
            return "La carpeta $dir no existeix";
        }
    } else {
        return "Especifica els paràmetres per a les carpetes";
    }
}

function copia_directori($dir, $rutadesti)
{
    $currentDir = HOME . DIRECTORY_SEPARATOR . $dir;
    $destiny = HOME . DIRECTORY_SEPARATOR . $rutadesti;

    if ($dir != null && $rutadesti != null) {
        if (is_dir($currentDir)) {
            $files = scandir($currentDir);
            $filesToCopy = Array();

            foreach ($files as $item) {
                if ($item != "." && $item != "..") {
                    array_push($filesToCopy, copia_fitxer($currentDir . DIRECTORY_SEPARATOR . $item, $destiny . DIRECTORY_SEPARATOR . $item));
                }
            }

            return $filesToCopy;
        } else {
            return "$dir no és un directori";
        }
    } else {
        return "Especifica els paràmetres per a les carpetes";
    }
}