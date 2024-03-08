<?php
include "connectBdd.php";
// on récupère depuis le form: l'identreprise depuis la liste déroulante des entreprises 
// on télécharge le fichier contenant la photo

$sql="insert into contact(nom,mail,photo,identreprise) values (:nom,:mail,:photo,:identreprise)";
try{
    $destination="images/";
    $photo=$destination.$_FILES["fichier"]["name"];
    move_uploaded_file($_FILES["fichier"]["tmp_name"], $photo);
    
   $resultat = $cnx->prepare($sql); // on prépare la requête
   $nbLignes=$resultat->execute(array(":nom" => $_POST["nom"],":mail" => $_POST["mail"],":photo" => $photo,":identreprise" => $_POST["listeEntreprise"]));
   header("Location: index.php");
   } 
catch(PDOException $e) {   // gestion des erreurs
    echo"ERREUR PDO  " . $e->getMessage();
 }
?>
 