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
                <form action="vueville.php" method="POST">
                    <select name="listeVille">
                        <?php
                        $sql="SELECT distinct ville FROM entreprise";// on écrit la requête sous forme de chaine de caractères
                        try{
                            $resultat = $cnx->query($sql); //// on exécute la requête qui renvoie un curseur (pointeur sur le jeu d'enregistrements)
                            $tabloResultat=$resultat->fetchAll(PDO::FETCH_ASSOC);// on lit le contenu du curseur $résultat récupéré dans un tableau associatif
                            foreach($tabloResultat as $ligne)   {
                                echo "<option value='".$ligne["ville"]."'>".$ligne["ville"]."</option>";
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
            </div>
        </div>
    </div>
</section>
<?php include 'pieddepage.html';?>
</body>
</html>


