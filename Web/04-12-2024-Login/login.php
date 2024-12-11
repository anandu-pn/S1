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
        <input type="submit" name="sub"></center>
    </form>
</body>
</html>
<?php
require 'connect.php';
if(isset($_POST['sub'])){
    if(($_POST['username']) && $_POST['username'] != NULL && isset($_POST['pass']) && $_POST['pass'] != NULL)
    {
    $user=$_POST['username'];
    $pass=$_POST['pass'];
    
    $data="SELECT * FROM userdb WHERE name='$user' AND password='$pass'";
    $q=mysqli_query($conn,$data);
    $result=mysqli_num_rows($q);
    if($result){
        session_start(); 
        $_SESSION['username'] = $user;
        echo "<script>alert('login successfull reDirecting');
        window.location.href = 'welcome.php';</script>";
        //header('Location:login.php');
        exit();
    }
    else { echo "password or username incorrect or Error:" . mysqli_error($conn); }
    }

    
    else{
        echo "<script>alert('Enter valid password and username');
            window.location.href = 'login.php';</script>";
    }
}


?>