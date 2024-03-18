<?php
include "entete.php";
// Connexion à la BDD, instanciation de l’objet $cnx
include "connectBdd.php";  
?>
<section>
        <div class="container" style="margin-top:30px">
          <div class="row">
            <div class="col-sm-4">
			<img  src="images/logo.webp" width=80 height= 80 >
            </div>      
            <div class="col-sm-8">
			<form action="traitModif.php" method="POST">
			<h3> Modification d'un contact</h3>
				<select name="listeContacts"> 
				<?php		
				$sql="SELECT id,nom FROM contact";
				try{
					$resultat = $cnx->query($sql); 
					$tabloResultat=$resultat->fetchAll(PDO::FETCH_ASSOC);
						foreach($tabloResultat as $ligne)   {
						echo "<option value='".$ligne["id"]."'>".$ligne["nom"]."</option>";
						// Attention, on affiche le nom mais le value est l'id
					}
					echo "</select>";
				}
				catch(PDOException $e) {   // gestion des erreurs
						echo"ERREUR PDO  " . $e->getMessage();
				}
				?>
			<p><label for="EmailDemo">Nouvelle adresse mail :</label>
			<input type="email" class="form-control" name="nouvelemail" aria-describedby="emailHelp" placeholder="Entrer le nouvel email">
			</p>
				<p>
				<button type="submit" >Valider</button> 
				<button type="reset" >Effacer</button>
				</p>
			</form>
		</div>	
	</div>
</div>
</section>
<?php include 'pieddepage.html';?>
</body>
</html>

