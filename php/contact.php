<?php

session_start();

$dbhost = 'localhost';
$dbuser = 'root';
$dbpass = '';

$conn = mysqli_connect($dbhost, $dbuser, $dbpass);
mysqli_select_db($conn, 'cform');

$cname = $_POST['name'];
$cemail = $_POST['email'];
$cphone = $_POST['phone'];
$cmessage = $_POST['message'];

$query = "INSERT INTO contact_us(c_name, c_email, c_phone, c_message) VALUES('$cname','$cemail','$cphone','$cmessage')";
$result = mysqli_query($conn, $query);

header("location: ./index.html");
die()


?>
