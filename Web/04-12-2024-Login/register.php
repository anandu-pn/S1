<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="" method="post">
        <center>
        <label for="">user name</label>
        <input type="text" name="username"><br>
        <label for="">Passoword:</label>
        <input type="password" name="pass"><br>
        <label for="">ReType password:</label>
        <input type="password" name="repass"><br>
        <label for="">Email</label>
        <input type="email" name="email" id=""><br>
        <label for="">Phone </label>
        <input type="text" name="phn"><br>
        <input type="submit" name="sub"></center>
    </form>
</body>
</html>
<?php
require 'connect.php';
if(isset($_POST['sub'])){
    $user=$_POST['username'];
$pass=$_POST['pass'];
$repass=$_POST['repass'];
$email=$_POST['email'];
$phone=$_POST['phn'];
echo "{$user},{$pass},{$repass},{$email},{$phone},";
if($pass==$repass){
    $data="INSERT INTO userdb (name,password,email,phone) VALUES ('$user', '$pass', '$email', '$phone')";
    $q=mysqli_query($conn,$data);
    if($q){
        echo "<script>alert('User successfully registered. Please login.');
        window.location.href = 'login.php';</script>";
        //header('Location:login.php');
        exit();
    }
    else { echo "Error: " . mysqli_error($conn); }
}
else{
    echo "<script>alert('password do not match re enter password');</script>";
}
}
?>