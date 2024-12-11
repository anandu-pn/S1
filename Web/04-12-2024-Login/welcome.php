<?php
session_start();
echo  $_SESSION['username']," welcome";
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="" method="post">
        <input type="submit" value="LogOUT" name="logout">
    </form>
</body>
</html>
<?php
    if(isset($_POST['logout'])){
        echo "<script>alert ('{$_SESSION['username']} Logged out');
              window.location.href = 'login.php';</script>;</script>";
        session_destroy();
    }
?>