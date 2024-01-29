<?php
$i = rand(29,30);
if ($i%3== 0 and $i%5 == 0)
{
    echo "le nombre est un multiple de 3 et 5";
}
else
{
    echo "le nombre n'est pas un multiple de 3 et de 5";
}

echo "<br>";

for($i=1; $i<11; $i++){
    echo $i." ".$i*5;
    echo "<br>";
}

$s = rand(0,100);
while($s%5 != 0)
{
    $s = rand(0,100);
}
echo "<br>";
echo $s;

echo "<br>";
$de=rand(1,6);
echo $de;
echo "<br>";
for($i=1; $de!=6; $i++){
    $de = rand(1,6);
}
echo $i;
echo"<br>";
echo $de;
echo "<br>";

$de1=rand(1,6);
$de2=rand(1,6);
while($de1!= 6 or $de2!=6)
{
    $de1 = rand(1,6);
    $de2 = rand(1,6);
}
echo $de1;
echo "<br>";
echo $de2;


?>
