<?php 

//info ==user, database
$servername = "localhost";
$username = "test123";
$password = "test123";
//database information
$databaseName = "aiotdb";
//connect dbms
$tableName = "";
$day = $_GET['day'];
// $month = str_split($month);

if(!empty($_GET['tableName']))
{
  $tableName = $_GET['tableName'];  
}

$con=mysqli_connect($servername, $username, $password,$databaseName);
mysqli_query($con,"SET CHARACTER SET 'utf8'");
//mysqli_query($conn,"SET SESSION collation_connection ='utf8_unicode_ci'");
if ($con->connect_error) {
    die("Too bad!!!! Connection failed: " . $con->connect_error);
} 
//echo "Connected successfully !!!! Yayaya.=======...";

//connect db
// Change database to "test"
mysqli_select_db($con,$tableName);

//select
//Query database for data
// INSERT INTO `wemos` (`measure_id`, `weight`, `date`) VALUES (NULL, '350', current_timestamp());
$min = $day." 00:00:00";
$max = $day." 23:59:59";
$result= mysqli_query($con,"SELECT CAST(weight AS INT), time FROM $tableName WHERE time BETWEEN '$min' AND '$max' order by time ASC");
//store matrix
$i=0;
while ($row = mysqli_fetch_array($result,MYSQLI_NUM))//MYSQL_NUM,MYSQL_BOTH
{
    $data[$i]=$row;
    $i++;
}

//echo result as json 
echo json_encode($data,JSON_UNESCAPED_UNICODE);

//close db
mysqli_close($con);

 ?>


