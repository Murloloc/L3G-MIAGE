<?php

//include "entete.php";
// Connexion à la BDD, instanciation de l’objet $cnx
include "connectBdd.php";  
$sql="SELECT * FROM admin where mail=:mail and mdpasse=:mdpasse";
// on exécute la requête
try{
   $resultat = $cnx->prepare($sql); 
   $resultat->execute(array(":mail" => $_POST["mail"],":mdpasse" => $_POST["pass"]));
   $tabloResultat=$resultat->fetch(PDO::FETCH_ASSOC);
   //var_dump($tabloResultat);
   if (empty($tabloResultat)) {
       // erreur , on redirige vers la page de connexion - l'admin n'existe pas
         header("Location: formCnx.php"); 
   }
   else {
       // on mémorise le nom de l'admin dans une variable de session 
       $_SESSION["nom"]=$tabloResultat["nom"];
       header("Location: index.php");
        }
  
   } 
catch(PDOException $e) {   // gestion des erreurs
    echo"ERREUR PDO  " . $e->getMessage();
 }
?>