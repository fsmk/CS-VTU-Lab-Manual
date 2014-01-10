<?php

// Receiving form data from POST request
$title = $_GET['title'];

//Connecting to MySQL database
mysql_connect("localhost", "root", "mysqlmypass");

//Selecting the database: equivalent to writing 'use php13;' on mysql prompt
mysql_select_db("php14");

//Retrieving all rows from the table 'stu'
$result = mysql_db_query("php14", "SELECT * from bkinfo where title='$title';");
echo "<table border='1'>";
echo "<tr><th>Accession Number</th><th>Title</th><th>Author</th><th>Editor</th><th>Publisher</th></tr>";
$num = mysql_num_rows($result);
for ($i = 0; $i < $num; $i++) {
	
	// Obtaining data field by field for each column using for loop
	$acs = mysql_result($result, $i, 'acs');
	$t = mysql_result($result, $i, 'title');
	$a = mysql_result($result, $i, 'author');
	$e = mysql_result($result, $i, 'edi');
	$p = mysql_result($result, $i, 'pub');

	// Displaying as a table row
	echo "<tr><td>" . $acs . "</td><td>" . $t . "</td><td>" . $a . "</td><td>" . $e . "</td><td>" . $p . "</td></tr>";

	/* Alternatively */
	// $arr = mysql_fetch_row($result);
	// echo "<tr><td>" . $arr[0] . "</td><td>" . $arr[1] . "</td><td>" . $arr[2] . "</td><td>" . $arr[3] . "</td></tr>";
}
echo "</table>";
?>
