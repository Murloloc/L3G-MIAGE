<?php
include "entete.html";
// Connexion à la BDD, instanciation de l’objet $cnx
include "connectBdd.php"; 
echo "<h2>Liste des contacts personnels: </h2>";
$sql="SELECT * FROM contact where idEntreprise is null";// on écrit la requête sous forme de chaine de caractères
$i=0;
try{
      $resultat = $cnx->query($sql); //// on exécute la requête qui renvoie un curseur (pointeur sur le jeu d'enregistrements)
      $tabloResultat=$resultat->fetchAll(PDO::FETCH_ASSOC);// on lit le contenu du curseur $résultat récupéré dans un tableau associatif 
      foreach($tabloResultat as $ligne)   { 
            echo "<p>".$ligne["nom"]."<br>".$ligne["mail"]."</p>";
            echo " <img  src=".$ligne["photo"]." width=50 >";        
            $i++;
      }
      echo "<br>Nombre de contacts : ".$i;
      $resultat->closeCursor();       // on ferme le curseur des résultats
      }
      catch(PDOException $e) {   // gestion des erreurs
         echo"ERREUR PDO  " . $e->getMessage();
      }
?>
</section>
<?php include 'pieddepage.html';?>
</body>
</html>