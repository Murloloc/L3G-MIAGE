<?php
echo "Nom : ".$_POST["nom"]."<br>";
echo "Prenom : ".$_POST["prenom"]."<br>";
echo "Mail : ".$_POST["e-mail"]."<br>";
echo "Etablissement : ".$_POST["etablissement"]."<br>";
echo "Ville : ".$_POST["ville"]."<br>";
echo "Département : ". $_POST["listeDep"]."<br>" ;

echo "Votre type d'emploi : ". $_POST["profession"]."<br>" ;
if(!empty($_POST["choix"]))
{
    echo "Les loisirs saisis sont :<br/>";
    foreach($_POST["choix"] as $val)
    {
        echo $val."<br>";
    }
}
echo "Votre projet de site web : ".  $_POST["zoneTexte"]."<br>" ;
?>