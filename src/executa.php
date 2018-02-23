<?php

include '../include/sistema.inc';
include '../include/directoris.inc';
include '../include/arxius.inc';

$inputTaken = $_POST['input_cmd'];
$arrInput = explode(' ', trim($inputTaken));

switch ($arrInput[0]) {
    case 'help':
        echo 'hola';
        break;
    case 'mkdir':
        break;
    case 'rm':
        break;
    case 'mv':
        break;
    case 'cp':
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
        break;
    case 'pwd':
        break;
    case 'free':
        break;
}
