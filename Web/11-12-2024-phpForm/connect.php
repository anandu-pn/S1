<?php
$servername='localhost';
$username1 = "root";
$password1='';
$dbname='formdb';
$conn= new mysqli($servername,$username1,$password1,$dbname);
if($conn){
    echo "coonected succcess fully";
}
else{
    echo "db failed ";
}
?>
