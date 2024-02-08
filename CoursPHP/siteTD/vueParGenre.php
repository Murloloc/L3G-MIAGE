<?php
include "entete.html";
// Connexion à la BDD, instanciation de l’objet $cnx
include "connectBdd.php";
?>
<section>
    <?php
    $sql="SELECT * from album A inner join genre G on A.num=G.num where libelle = :libelle";// on écrit la requête sous forme de chaine de caractères
    $libelle= $_POST["listeGenre"];
    $resultat = $cnx->prepare($sql);
    $resultat->execute(array(":libelle" => $libelle));
    try{
        $tabloResultat=$resultat->fetchAll(PDO::FETCH_ASSOC);// on lit le contenu du curseur $résultat récupéré dans un tableau associatif
        foreach($tabloResultat as $ligne)   {
            echo $ligne["num"]."<br>";
            echo $ligne["titre"]."<br>";
            echo $ligne["libelle"]."<br>";
        }
        $resultat->closeCursor();       // on ferme le curseur des résultats
    }
    catch(PDOException $e) {   // gestion des erreurs
        echo"ERREUR PDO  " . $e->getMessage();
    }
    ?>
</section>
<?php include 'pieddepage.html';?>
</body>
</html>
