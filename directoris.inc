<?php

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
                    return "$dir no és un directori, utilitza la comanda rm -f per això";
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
    if ($dir != null && $rutadesti != null) {
        rename($dir, $rutadesti . DIRECTORY_SEPARATOR . $dir);
        return true;
    } else {
        return false;
    }
}

function copia_directori($dir, $rutadesti)
{
    if ($dir != null && $rutadesti != null) {
        copy($dir, $rutadesti . DIRECTORY_SEPARATOR . $dir);
        return true;
    } else {
        return false;
    }
}