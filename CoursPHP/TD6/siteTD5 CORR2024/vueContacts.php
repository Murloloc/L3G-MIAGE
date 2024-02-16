<?php include 'entete.html';?>
<section>
    <div class="container" style="margin-top:30px">
        <div class="row">
            <div class="col-sm-4">
                <p> HTML CSS Bootstrap PHP et PDO...</p>
            </div>
            <div class="col-sm-8">
                <?php
                // Connexion à la BDD, instanciation de l’objet $cnx
                include "connectBdd.php";
                $sql="SELECT * FROM contact";// on écrit la requête sous forme de chaine de caractères
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
            </div>
        </div>
    </div>
</section>
<?php include 'pieddepage.html';?>
</body>
</html>


