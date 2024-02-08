<?php
include "entete.html"; 
// Connexion à la BDD, instanciation de l’objet $cnx
include "connectBdd.php";
?>  
<form action="vueParGenre.php" method="POST">
	<select name="listeGenre">
		<?php		
		$sql="SELECT distinct libelle FROM genre";// on écrit la requête sous forme de chaine de caractères
		try{
			$resultat = $cnx->query($sql); //// on exécute la requête qui renvoie un curseur (pointeur sur le jeu d'enregistrements)
			$tabloResultat=$resultat->fetchAll(PDO::FETCH_ASSOC);// on lit le contenu du curseur $résultat récupéré dans un tableau associatif 
			foreach($tabloResultat as $ligne)   {
				echo "<option value='".$ligne["libelle"]."'>".$ligne["libelle"]."</option>";
			}
		}
		catch(PDOException $e) {   // gestion des erreurs
			echo"ERREUR PDO  " . $e->getMessage();
		}
		?>	 		
	</select>
	<p>
	<button type="submit" >Valider</button> 
	<button type="reset" >Effacer</button>
	</p>
</form>
</section>
<?php include 'pieddepage.html';?>
</body>
</html>

