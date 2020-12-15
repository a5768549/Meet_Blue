<?php

date_default_timezone_set("Asia/Taipei");
include('connect.php');

$sql = "SELECT * FROM `data`";
$result =$con->prepare($sql);
$result->execute();
$result2 = $result->fetchALL(PDO::FETCH_ASSOC);

$date1=date_create();
$date2=date_create($result2[0]["back_date"]);
$diff=date_diff($date1,$date2);
$diff=$diff->format('%d')+1;
echo $diff;