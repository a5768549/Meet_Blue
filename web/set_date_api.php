<?php

date_default_timezone_set("Asia/Taipei");
include('connect.php');
$data = json_decode(file_get_contents('php://input'),true);

$sql = "UPDATE `data` set `clinic_name` = ? WHERE `ID` = 1";
$result =$con->prepare($sql);
$result->execute([$data[0]]);

$sql = "UPDATE `data` set `back_date` = ? WHERE `ID` = 1";
$result =$con->prepare($sql);
$result->execute([$data[1]]);