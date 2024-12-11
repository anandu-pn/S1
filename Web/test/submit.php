<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "nidal";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];
    $age = $_POST['age'];
    $password = $_POST['password'];
    $security_question = $_POST['security_question'];
    $security_answer = $_POST['security_answer'];
    $email = $_POST['email'];
    $languages = implode(", ", $_POST['languages']);
    $phone = $_POST['phone'];
    $cv = $_FILES['cv']['name'];
    $cv_tmp = $_FILES['cv']['tmp_name'];
    $cv_folder = "uploads/" . $cv;

    // Move uploaded file to the uploads directory
    if (move_uploaded_file($cv_tmp, $cv_folder)) {
        $sql = "INSERT INTO users (name, age, password, security_question, security_answer, email, languages, phone, cv)
                VALUES ('$name', '$age', '$password', '$security_question', '$security_answer', '$email', '$languages', '$phone', '$cv')";

        if ($conn->query($sql) === TRUE) {
            echo "New record created successfully";
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    } else {
        echo "Failed to upload file.";
    }
}

$conn->close();
?>
