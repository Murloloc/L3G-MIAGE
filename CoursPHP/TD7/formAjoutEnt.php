<?php include 'entete.html';
include "connectBdd.php";
?>
<section>
    <div class="container" style="margin-top:30px">
        <div class="row">
            <div class="col-sm-4">
                <p> HTML CSS Bootstrap PHP et PDO...</p>
            </div>
            <div class="col-sm-8">
                <form action="traitAjoutEnt.php" method="post">
                    <h3> Ajout d'une entreprise </h3>
                    <label >Raison sociale : </label>
                    <input type="text" name="raisonSociale" size="40" /><br><br>
                    <label >Ville : </label>
                    <input type="text" name="ville" size="40" /><br><br>
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
