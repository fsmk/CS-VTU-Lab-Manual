<?php

$acs = $_POST['acs'];
$title = $_POST['title'];
$author = $_POST['author'];
$edi = $_POST['edi'];
$pub = $_POST['pub'];

//Connecting to MySQL database
mysql_connect("localhost", "root", "mysqlmypass");

//
mysql_select_db("php14");

//
//mysql_db_query("php14", "INSERT INTO bkinfo values('$acs', '$title', '$author', '$edi', '$pub');")

$res = mysql_db_query("php14", "SELECT * from bkinfo");

$num = mysql_num_rows($res);
echo "<table border='1'>";
echo "<tr><th>Name</th><th>Address 1</th><th>Address 2</th><th>Email</th></tr>";
for($i = 0; $i < $num; ++$i){
	$a = mysql_fetch_row($res);
	echo "<tr><td>" . $a[0] . "</td><td>" . $a[1] . "</td><td>" . $a[2] . "</td><td>" . $a[3] . "</td></tr>";
}
echo "</table>";