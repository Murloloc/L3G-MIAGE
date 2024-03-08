<?php
include "entete.php";
include "connectBdd.php";
?>
<section>
<div class="container" style="margin-top:30px">
  <div class="row">
    <div class="col-sm-4">
    <img  src="images/logo.webp" width=80 height= 80 >
    </div>
    <div class="col-sm-8">
        <form action="traitAjoutContact.php" method="post" enctype="multipart/form-data">
            <h3> Ajout d'un contact </h3>
            <label >Nom : </label>
            <input type="text" name="nom" size="40" /><br><br>
            <label >Mail : </label>
            <input type="text" name="mail" size="40" /><br><br>
            <label >Photo          : </label>
            <input type="file" name="fichier" size="40" accept=".jpg, .jpeg, .png"><br><br>
            Entreprise
            <select name="listeEntreprise"> 
				<?php		
				$sql="SELECT id, raisonsociale FROM entreprise";
				try{
					$resultat = $cnx->query($sql); 
					$tabloResultat=$resultat->fetchAll(PDO::FETCH_ASSOC);
						foreach($tabloResultat as $ligne)   {
						echo "<option value='".$ligne["id"]."'>".$ligne["raisonsociale"]."</option>";
						// Attention, on affiche la raison sociale mais le value est l'id
					}
					echo "</select>";
				}
				catch(PDOException $e) {   // gestion des erreurs
						echo"ERREUR PDO  " . $e->getMessage();
				}
				?>
                <br><br>
            <button type="submit" >Ajouter</button>
            <button type="reset" > Annuler</button>
        </form>
    </div>
</div>
</div>
</section>
<?php include 'pieddepage.html';?>
</body>
</html>