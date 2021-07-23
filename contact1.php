<?php
$name = $_POST['name'];
$email = $_POST['email'];
$phone = $_POST['phone'];
$message = $_POST['message'];
if (!empty($name) || !empty($email) ||  !empty($phone)  || !empty($message)){

    //create connection
    $conn = new mysqli("localhost", "root", "", "cform");
    if (mysqli_connect_error()) {
     die('Connect Error('. mysqli_connect_errno().')'.mysqli_connect_error());
    } else {
     $SELECT = "SELECT email from contact_us where email = ? limit 1";
     $INSERT = "INSERT into contact_us(name, email,  phone, message) values(?, ?, ?, ?, ?)";
     //Prepare statement
     $stmt = $conn->prepare($SELECT);
     $stmt->bind_param('s', $email);
     $stmt->execute();
     $stmt->bind_result($email);
     $stmt->store_result();
     $rnum = $stmt->num_rows;
     if ($rnum==0) {
      $stmt->close();
      $stmt = $conn->prepare($INSERT);
      $stmt->bind_param("ssis", $name,  $email, $phone, $message);
      $stmt->execute();
      echo "New record inserted sucessfully";
     } else {
      echo "Someone already register using this email";
     }
     $stmt->close();
     $conn->close();
    }
} else {
 echo "All fields are required";
 die();
}
?>

<?php
$name = $_POST['name'];
$phone = $_POST['phone'];
$email = $_POST['email'];
$message = $_POST['message'];
if (!empty($name) || !empty($email) ||  !empty($phone) || !empty($message)){

    //create connection
    $conn = new mysqli("localhost", "root", "", "cform");
    if (mysqli_connect_error()) {
     die('Connect Error('. mysqli_connect_errno().')'. mysqli_connect_error());
    } else {
     $SELECT = "SELECT email from contact_form where email = ? limit 1";
     $INSERT = "INSERT into contact_form (name, phone, email, message) values(?, ?, ?, ?)";
     //Prepare statement
     $stmt = $conn->prepare($SELECT);
     $stmt->bind_param('s', $email);
     $stmt->execute();
     $stmt->bind_result($email);
     $stmt->store_result();
     $rnum = $stmt->num_rows;
     if ($rnum==0) {
      $stmt->close();
      $stmt = $conn->prepare($INSERT);
      $stmt->bind_param("ssis", $name,  $phone, $email, $message);
      $stmt->execute();
      echo "New record inserted sucessfully";
     } else {
      echo "Someone already register using this email";
     }
     $stmt->close();
     $conn->close();
    }
} else {
 echo "All field are required";
 die();
}
?>