<?php

$montant = $_POST["pu"]*$_POST["qte"];

if($_POST["tauxTva"]== 1)
    $tva = $montant*0.05;

else
    if ($_POST["tauxTva"]== 2)
        $tva = $montant*0.10;
    else
        $tva = $montant*0.20;

$ttc = $montant + $tva;
echo "Montant saisi :  " .$montant. "<br>";
echo "Montant TVA : " .$tva. "<br>";
echo "Montant TTC : " .$ttc. "<br>";
?>

