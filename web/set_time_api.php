<?php

date_default_timezone_set("Asia/Taipei");
include('connect.php');
$data = json_decode(file_get_contents('php://input'),true);

$sql = "UPDATE `data` set `time1_name` = ? WHERE `ID` = 1";
$result =$con->prepare($sql);
$result->execute([$data[0]]);

$sql = "UPDATE `data` set `time2_name` = ? WHERE `ID` = 1";
$result =$con->prepare($sql);
$result->execute([$data[1]]);

$sql = "UPDATE `data` set `time3_name` = ? WHERE `ID` = 1";
$result =$con->prepare($sql);
$result->execute([$data[2]]);

$sql = "UPDATE `data` set `time1_time` = ? WHERE `ID` = 1";
$result =$con->prepare($sql);
$result->execute([$data[3]]);

$sql = "UPDATE `data` set `time2_time` = ? WHERE `ID` = 1";
$result =$con->prepare($sql);
$result->execute([$data[4]]);

$sql = "UPDATE `data` set `time3_time` = ? WHERE `ID` = 1";
$result =$con->prepare($sql);
$result->execute([$data[5]]);