<?php
include "connectBdd.php";
// on récupère depuis le formModif: l'id depuis la liste déroulante des contacts et nouvelemail
$sql="update contact set mail = :pmail where id = :pid";
// on exécute la requête
try{
   $resultat = $cnx->prepare($sql); // on prépare la requête
   $nbLignes=$resultat->execute(array(":pmail" => $_POST["nouvelemail"],":pid" => $_POST["listeContacts"]));
   echo $nbLignes. " ligne mise à jour";
   } 
catch(PDOException $e) {   // gestion des erreurs
    echo"ERREUR PDO  " . $e->getMessage();
 }
?>
