<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>

</body>
</html>
<?php
//this page will print data entered in the previous page in table
require 'connect.php';
session_start();
if(isset($_SESSION['name'])){
    $name=$_SESSION['name'];
    //this query fetch for row with name from db
    $data = "SELECT * FROM datadb WHERE name='$name'"; 
    $q = mysqli_query($conn, $data); 
    // Check if there are any results 
    if (mysqli_num_rows($q) > 0) { 
        // Output data of each row and print corresponding values of columns in each row
        while ($row = mysqli_fetch_assoc($q)) { 
            echo "ID:   {$row["id"]}   - Name: {$row["name"]}  - Phone: . {$row["phone"]} <br><table border='1px'>
        <tr>
            <th>ID</th><th>{$row["id"]}</th>
        </tr>
        <tr>
            <th>Name:</th><th>{$row["name"]}</th>
        </tr>
        <tr>
            <th>Adress</th><th>{$row["address"]}</th>
        </tr>
        <tr>
            <th>Age group</th><th>{$row["age"]}</th>
        </tr>
        <tr>
            <th>Email</th><th>{$row["email"]}</th>
        </tr>
        <tr>
            <th>Phone No:</th><th>{$row["phone"]}</th>
        </tr>
    </table>
            " ; } }
    else { echo "0 results";}
        }

?>