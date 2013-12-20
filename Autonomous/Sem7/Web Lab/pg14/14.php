<?php

// Receiving form data from POST request
$acs = $_POST ['acs'];
$title = $_POST['title'];
$author = $_POST['author'];
$edi = $_POST['edi'];
$pub = $_POST['pub'];

//Connecting to MySQL database
mysql_connect("localhost", "root", "mysqlmypass");

//Selecting the database: equivalent to writing 'use php13;' on mysql prompt
mysql_select_db("php14");

//Inserting values obtained from user
mysql_db_query("php14", "INSERT INTO bkinfo values('$acs', '$title', '$author', '$edi', '$pub')");

//Retrieving all rows from the table 'stu'
$result = mysql_db_query("php14", "SELECT * from bkinfo;");
echo "<table border='1'>";
echo "<tr><th> Accesion Number </th><th> Title </th><th> Author </th><th> Editor </th><th> Publisher </th></tr>";

$num = mysql_num_rows($result);
for ($i = 0; $i < $num; $i++) {
	// Obtaining data field by field for each column using for loop
	$acs = mysql_result($result, $i, 'acs');
	$title = mysql_result($result, $i, 'title');
	$author = mysql_result($result, $i, 'author');
	$edi = mysql_result($result, $i, 'edi');
	$pub = mysql_result($result, $i, 'pub');

	// Displaying as a table row
	echo "<tr><td>" . $acs . "</td><td>" . $title . "</td><td>" . $author . "</td><td>" . $edi . "</td><td>" . $pub . "</td></tr>";

	/* Alternatively */
	// $arr = mysql_fetch_row($result);
	// echo "<tr><td>" . $arr[0] . "</td><td>" . $arr[1] . "</td><td>" . $arr[2] . "</td><td>" . $arr[3] . "</td></tr>";
}
echo "</table>";
?>
