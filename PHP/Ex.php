<?php
$nb=rand(1,1000);
while ($nb%5!=0){
    $nb=rand(1,1000);
}
echo "Le premier nb aleat multiple de 5 est ". $nb;
?>