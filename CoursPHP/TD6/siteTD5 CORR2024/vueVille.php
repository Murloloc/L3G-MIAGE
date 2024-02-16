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
                ?>
                <section>
                    <?php
                    $sql="SELECT contact.*, raisonSociale, ville FROM contact inner join entreprise on  idEntreprise= entreprise.id where ville = :ville";// on écrit la requête sous forme de chaine de caractères
                    $ville= $_POST["listeVille"];
                    $resultat = $cnx->prepare($sql);
                    $resultat->execute(array(":ville" => $ville));
                    try{
                        $tabloResultat=$resultat->fetchAll(PDO::FETCH_ASSOC);// on lit le contenu du curseur $résultat récupéré dans un tableau associatif
                        foreach($tabloResultat as $ligne)   {
                            echo $ligne["nom"]."<br>";
                            echo $ligne["mail"]."<br>";
                            echo $ligne["raisonSociale"]."<br>";
                            echo " <img  src=".$ligne["photo"]." width=50 >"."<br>";

                        }
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

