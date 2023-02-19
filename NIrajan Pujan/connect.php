<?php
$firstName = $_POST['firstName'];
$lastName = $_POST['lastName'];
$sex = $_POST['sex'];
$address = $_POST['address'];
$number = $_POST['number'];
$age = $_POST['age'];

// Database connection
$conn = new mysqli('localhost', 'root', '', 'patientlog');
if ($conn->connect_error) {
    echo "$conn->connect_error";
    die("Connection Failed : " . $conn->connect_error);
} else {
    $stmt = $conn->prepare("insert into patientdata(firstName, lastName, sex, address, number, age) values(?, ?, ?, ?, ?, ?)");
    $stmt->bind_param("ssssii", $firstName, $lastName, $sex, $address, $number, $age);
    $execval = $stmt->execute();
    echo $execval;
    echo "Registration successfully...";
    $stmt->close();
    $conn->close();
}