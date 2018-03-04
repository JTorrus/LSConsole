<?php

function find_fitxer($fitxer, $dir)
{
    $currentDir = HOME . DIRECTORY_SEPARATOR . $dir;
    $files = scandir($currentDir);

    if ($fitxer != null && $dir != null) {
        foreach ($files as $fileToFind) {
            if (is_file($currentDir . DIRECTORY_SEPARATOR . $fileToFind)) {
                if (strtolower($fitxer) == strtolower($fileToFind)) {
                    return "El fitxer $fitxer s'ha trobat a $currentDir";
                }
            }
        }

        return "$fitxer no s'ha trobat";
    } else {
        return "Especifica els paràmetres per al fitxer i el directori";
    }
}

function stats_fitxer($fitxer)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (file_exists($currentFile)) {
            $fileStats = Array();
            $statsReturned = stat($currentFile);

            $userId = "ID de l'usuari propietari -> " . gmdate("d-m-Y H:i:s", $statsReturned['uid']);
            $groupId = "ID del grup propietari -> " . gmdate("d-m-Y H:i:s", $statsReturned['gid']);
            $accessDate = "Darrer accès -> " . gmdate("d-m-Y H:i:s", $statsReturned['atime']);
            $modifiedDate = "Darrera modificació -> " . gmdate("d-m-Y H:i:s", $statsReturned['mtime']);
            $sizeBytes = "Mida en bytes -> " . gmdate("d-m-Y H:i:s", $statsReturned['size']);

            array_push($fileStats, $userId, $groupId, $accessDate, $modifiedDate, $sizeBytes);

            return $fileStats;
        } else {
            return "L'arxiu $fitxer no existeix";
        }
    } else {
        return "Especifica un nom per al fitxer";
    }

}

function esborra_fitxer($fitxer)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (file_exists($currentFile)) {
            if (!is_dir($currentFile)) {
                if (unlink($currentFile)) {
                    return "$fitxer s'ha esborrat correctament";
                } else {
                    return "Hi ha hagut un problema esborrant $fitxer";
                }
            } else {
                return "$fitxer és un directori, utilitza la comanda rm -d per esborrar-ho";
            }
        } else {
            return "$fitxer no existeix";
        }
    } else {
        return "Especifica un nom per al fitxer a esborrar";
    }

}

function mou_fitxer($fitxer, $rutadesti)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;
    $destiny = HOME . DIRECTORY_SEPARATOR . $rutadesti;

    if ($fitxer != null && $rutadesti != null) {
        if (file_exists($currentFile)) {
            if (rename($currentFile, $destiny)) {
                return "El fitxer $fitxer s'ha mogut correctament a $rutadesti";
            } else {
                return "Hi ha hagut un problema movent $fitxer a $rutadesti";
            }
        } else {
            return "El fitxer $fitxer no existeix";
        }
    } else {
        return "Especifica els paràmetres per al fitxer i el directori";
    }
}

function copia_fitxer($fitxer, $rutadesti)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;
    $destiny = HOME . DIRECTORY_SEPARATOR . $rutadesti;

    if ($fitxer != null && $rutadesti != null) {
        if (file_exists($currentFile)) {
            if (is_dir($destiny)) {
                if (copy($fitxer, $rutadesti . DIRECTORY_SEPARATOR . $fitxer)) {
                    return "L'arxiu $fitxer s'ha copiat correctament a $rutadesti";
                } else {
                    return "Hi ha hagut un error copiant $fitxer a $rutadesti";
                }
            } else {
                return "$rutadesti no és un directori";
            }
        } else {
            return "El fitxer $fitxer no existeix";
        }
    } else {
        return "Especifica els paràmetres per al fitxer i el directori";
    }
}

function crea_modifica_fitxer($fitxer, $contingut)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null && $contingut != null) {
        if (!file_exists($currentFile) && empty($contingut)) {
            if (touch($currentFile)) {
                return "El fitxer $fitxer s'ha creat correctament";
            } else {
                return "Hi ha hagut un problema creant el fitxer $fitxer";
            }
        } else if (!file_exists($currentFile) && !empty($contingut)) {
            if (touch($currentFile)) {
                $file = fopen($currentFile, "w");
                fwrite($file, $contingut);
                fclose($file);
                return "El fitxer $fitxer s'ha creat correctament";
            } else {
                return "Hi ha hagut un problema creant el fitxer $fitxer";
            }
        } else if (file_exists($currentFile) && !empty($contingut)) {
            $file = fopen($currentFile, "w");
            fwrite($file, $contingut);
            fclose($file);
            return "El fitxer $fitxer s'ha modificat correctament";
        } else {
            return "El fitxer $fitxer no existeix";
        }
    } else {
        return "Especifica els paràmetres per al fitxer i el directori";
    }
}

function our_sha1($fitxer)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (file_exists($currentFile)) {
            if (is_file($currentFile)) {
                return sha1_file($currentFile);
            } else {
                return "$fitxer no és un fitxer";
            }
        } else {
            return "El fitxer $fitxer no existeix";
        }
    } else {
        return "Especifica un nom per al fitxer";
    }

}

function our_md5($fitxer)
{
    $currentFile = HOME . DIRECTORY_SEPARATOR . $fitxer;

    if ($fitxer != null) {
        if (file_exists($currentFile)) {
            if (is_file($currentFile)) {
                return md5_file($currentFile);
            } else {
                return "$fitxer no és un fitxer";
            }
        } else {
            return "El fitxer $fitxer no existeix";
        }
    } else {
        return "Especifica un nom per al fitxer";
    }
}