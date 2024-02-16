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
                <div class="container">
                    <table border="1" >
                        <caption>Contacts professionnels</caption>
                        <thead> <!-- En-tête du tableau -->
                        <tr> <!—une ligne -->
                            <th>Nom</th>
                            <th>Mail</th>
                            <th>Raison sociale</th>
                        </tr>
                        </thead>
                        <tbody>
                        <?php
                        $sql="SELECT contact.*, raisonSociale, ville FROM contact inner join entreprise on  idEntreprise= entreprise.id ";// on écrit la requête sous forme de chaine de caractères
                        try{
                            $resultat = $cnx->query($sql); //// on exécute la requête qui renvoie un curseur (pointeur sur le jeu d'enregistrements)
                            $tabloResultat=$resultat->fetchAll(PDO::FETCH_ASSOC);// on lit le contenu du curseur $résultat récupéré dans un tableau associatif
                            foreach($tabloResultat as $ligne)   {
                                echo "<tr>";
                                echo "<td>".$ligne["nom"]."</td>";
                                echo "<td>".$ligne["mail"]."</td>";
                                echo "<td>".$ligne["raisonSociale"]."</td>";
                                echo "</tr>";
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



