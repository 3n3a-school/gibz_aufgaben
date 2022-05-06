<?php
$servername = $_ENV['DB_HOST'];
$port = $_ENV['DB_PORT'];
$dbname = $_ENV['DB_DB'];
$username = $_ENV['DB_USER'];
$password = $_ENV['DB_PASS'];

// sql to create table
$table = "CREATE TABLE IF NOT EXISTS msgboard (
  id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
  name VARCHAR(30) NOT NULL,
  email VARCHAR(50) NOT NULL,
  message VARCHAR(100) NOT NULL,
  color VARCHAR(20) NOT NULL,
  date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
  )";

// init db-connection and table
$conn = null;
try{
  global $conn;
  $conn = new PDO("mysql:host=$servername;port=$port;dbname=$dbname",$username,$password);
  $conn -> setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);
  $conn->exec($table);
} catch(PDOException $e){
  echo "Connection failed: " . $e -> getMessage();
}

function add_msg($name, $email, $msg, $color) {
  global $conn;
  $sql = "INSERT INTO msgboard (name, email, message, color) VALUES (?,?,?,?)";
  $conn->prepare($sql)->execute([$name, $email, $msg, $color]);
}

function get_all_msg() {
  global $conn;
  $sql = "SELECT id, name, email, message, date, color FROM msgboard";
  return $conn->query($sql)->fetchAll(PDO::FETCH_ASSOC);
}