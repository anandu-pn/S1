<?php
//this file is used to connect php server with Mysql DB
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
//created a database with name formdb and it contain table datadb
//column of data db are id,name,address,age,email,phone -> id is primary key
?>
