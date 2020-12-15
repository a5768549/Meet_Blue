<?php

date_default_timezone_set("Asia/Taipei");
include('connect.php');

$sql = "SELECT * FROM `data`";
$result =$con->prepare($sql);
$result->execute();
$result2 = $result->fetchALL(PDO::FETCH_ASSOC);

echo json_encode($result2);