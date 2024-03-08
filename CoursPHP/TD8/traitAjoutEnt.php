<?php
include "connectBdd.php";
try {
    $sql="insert into entreprise(raisonSociale,ville) values(:raison,:ville)";
    $resultat = $cnx->prepare($sql);
    $raison = $_POST["raisonSociale"];
    $ville = $_POST["ville"];
    $nbLignes= $resultat->execute(array(":raison" => $raison,":ville" => $ville));
    header("Location: index.php");
}
    
catch(PDOException $e) {   // gestion des erreurs
    echo"ERREUR dans l'ajout  " . $e->getMessage();
}
?>
