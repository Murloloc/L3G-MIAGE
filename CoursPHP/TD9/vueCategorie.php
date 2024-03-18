<?php
include "entete.php";
// Connexion à la BDD, instanciation de l’objet $cnx
include "connectBdd.php";
?>
<div class="container">
    <div class="row">
        <div class="col-sm-4">
            <img src="images/" width=80 height=80>
        </div>
        <div class="col-sm-8">
            <h3> Albums par catégorie </h3>
            <?php
            $sql = "SELECT * FROM album where numgenre=" . $_GET["num"];// on écrit la requête sous forme de chaine de caractères
            $i = 0;
            try {
                $resultat = $cnx->query($sql); //// on exécute la requête qui renvoie un curseur (pointeur sur le jeu d'enregistrements)
                $tabloResultat = $resultat->fetchAll(PDO::FETCH_ASSOC);// on lit le contenu du curseur $résultat récupéré dans un tableau associatif
                foreach ($tabloResultat as $ligne) {
                    echo "<p>" . $ligne["titre"] . "<br>" . "</p>";
                    //echo " <img  src=" . $ligne["images"] . " width=50 >";
                    $i++;
                }

                echo "<br>Nombre de contacts : " . $i;
                $resultat->closeCursor();       // on ferme le curseur des résultats
            } catch (PDOException $e) {   // gestion des erreurs
                echo "ERREUR PDO  " . $e->getMessage();
            }
            ?>
        </div>
    </div>
</div>
</section>
<?php include 'pieddepage.html'; ?>
</body>
</html>
