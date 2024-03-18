<?php
include "entete.php";
// Connexion à la BDD, instanciation de l’objet $cnx
include "connectBdd.php";  
?>
<div class="container">
<div class="row">
    <div class="col-sm-4">
       <img  src="images/logo.webp" width=80 height= 80 >
    </div>
    <div class="col-sm-8">
    <h3>Contacts par entreprise</h3>
            <table border="1" >
                <thead> <!-- En-tête du tableau -->
                <tr> <!—une ligne -->
                    <th>Raison sociale</th>
                    <th>Nom</th>
                    <th>Mail</th>
                </tr>
                </thead>
                <tbody>
                <?php
                $sql="SELECT C.*, raisonSociale, ville FROM contact C inner join entreprise E on C.idEntreprise=E.id order by raisonsociale"; 
                try{
                $resultat = $cnx->query($sql); //// on exécute la requête qui renvoie un curseur (pointeur sur le jeu d'enregistrements)
                $tabloResultat=$resultat->fetchAll(PDO::FETCH_ASSOC);// on lit le contenu du curseur $résultat récupéré dans un tableau associatif 
                foreach($tabloResultat as $ligne)   { 
                    echo "<tr>";
                    echo "<td>".$ligne["raisonSociale"]."</td>";
                    echo "<td>".$ligne["nom"]."</td>";
                    echo "<td>".$ligne["mail"]."</td>";
                    
                        echo "</tr>";
                    }
                $resultat->closeCursor();       // on ferme le curseur des résultats
                }
                catch(PDOException $e) {   // gestion des erreurs
                    echo"ERREUR PDO  " . $e->getMessage();
                }
             ?>
                </tbody>
            </table>
    </div>
</div>
</div>
</section>
<?php include 'pieddepage.html';?>
</body>
</html>

