<?php

include"connectBdd.php";
$pemail=$_POST["mail"];
$sql="SELECT* FROM ADMIN where mail =:mail and mdpasse=:mdpasse";
try{
    $resultat=$cnx->prepare($sql);
    $resultat->execute(array(":pemail"=>$pemail, ":mdpasse" =>$_POST["pass"]));
    $tabloResultat=$resultat->fetch(PDO::FETCH_ASSOC);
    if(empty($tabloResultat)){
        header("Location: formCnx.php");

    }
    else {
        $_SESSION["nom"]=$tabloResultat["nom"];
        header("Location: index.php");

    }
}
catch(PDOException $e){echo"ERREUR PDO".$e->getMessage();
}
?>