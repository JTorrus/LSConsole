<?php

function llistat($dir){
    if (is_dir($dir)){
        foreach (scandir($dir) as $item) {
            echo $item;
            echo "<br>";
        }
    }else{
        echo "El nom introduit no pertany a directori";
    }
}

function ruta(){
    echo getcwd();
}

function stats_sistema(){

}