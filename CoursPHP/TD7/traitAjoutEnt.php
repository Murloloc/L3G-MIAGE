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
                <?php
                try {
                    $sql="insert into entreprise(raisonSociale,ville) values(:raison,:ville)"; $resultat = $cnx->prepare($sql);
                    $raison = $_POST["raisonSociale"];
                    $ville = $_POST["ville"];
                    $nbLignes= $resultat->execute(array(":raison"=>$raison,":ville"=>$ville)); echo $nbLignes." ligne ajoutée";
                }
                catch(PDOException $e) { // gestion des erreurs
                    echo"ERREUR dans l'ajout  ".$e->getMessage();
                }

                ?>
            </div>
        </div>
    </div>
</section>
<?php include 'pieddepage.html';?>
</body>
</html>
