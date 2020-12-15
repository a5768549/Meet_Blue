<?php

date_default_timezone_set("Asia/Taipei");
include('connect.php');

$sql = "SELECT * FROM `data`";
$result =$con->prepare($sql);
$result->execute();
$result2 = $result->fetchALL(PDO::FETCH_ASSOC);

$name1 = $result2[0]["time1_name"];
$name2 = $result2[0]["time2_name"];
$name3 = $result2[0]["time3_name"];
$name = [$name1,$name2,$name3];

$time1 = strtotime($result2[0]["time1_time"]);
$time2 = strtotime($result2[0]["time2_time"]);
$time3 = strtotime($result2[0]["time3_time"]);
$now = strtotime(date("G:i:s"));
$array = [$time1-$now, $time2-$now, $time3-$now];
sort($array);

for($i = 0;$i<count($array);$i++)
{
    if($array[$i] > 0)
    {
        echo $array[$i];
        return;
    }
}
echo 86400+$array[0];