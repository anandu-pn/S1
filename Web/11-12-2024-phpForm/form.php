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
        <label for="">Name</label>
        <input type="text" name="name"><br><br>
        <label for="">Adress</label>
        <input type="text" name="address"><br><br>
        <label for="">Age group:</label>
        <input type="radio" name="age" id="" value="18-25"><label for="">18-25</label>
        <input type="radio" name="age" id="" value="26-35"><label for="">26-35</label>
        <input type="radio" name="age" id="" value="36+"><label for="">36+</label><br><br>
        <label for="">Email</label>
        <input type="email" name="email" id=""><br><br>
        <label for="">Phone </label>
        <input type="text" name="phn"><br><br>

        <input type="reset" value="Reset">
        <input type="submit" name="sub"><br><br>
        </center>
    </form>
</body>
</html>
<?php
require 'connect.php';
if(isset($_POST['sub'])){
    $name=$_POST['name'];
$address=$_POST['address'];
$age=$_POST['age'];
$email=$_POST['email'];
$phone=$_POST['phn'];
echo "{$name},{$address},{$age},{$email},{$phone},";
if(isset($name) && isset($address) && isset($age) && isset($email) && isset($phone)){
    $data="INSERT INTO datadb (name,address,age,email,phone) VALUES ('$name', '$address', '$age', '$email','$phone')";
    $q=mysqli_query($conn,$data);
    if($q){
        session_start();
        $_SESSION['name'] = $name;
        echo "<script>alert('User successfully registered please note the id');
        window.location.href = 'page.php';</script>";
        //header('Location:details.php');
        exit();
    }
    else { echo "Error: " . mysqli_error($conn); }
}
else{
    echo "<script>alert('Fill all the fields in the page');</script>";
}
}
?>