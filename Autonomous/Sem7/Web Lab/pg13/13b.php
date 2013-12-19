<?php

// Receiving form data from POST request
$name = $_GET ['name'];

//Connecting to MySQL database
mysql_connect("localhost", "root", "mysqlmypass");

//Selecting the database: equivalent to writing 'use php13;' on mysql prompt
mysql_select_db("php13");

//Retrieving all rows from the table 'stu'
$result = mysql_db_query("php13", "SELECT * from stu where name='$name';");
echo "<table border='1'>";
echo "<tr><th>Name</th><th>Address 1</th><th>Address 2</th><th>Email</th></tr>";
$num = mysql_num_rows($result);
for ($i = 0; $i < $num; $i++) {
	// Obtaining data field by field for each column using for loop
	$n = mysql_result($result, $i, 'name');
	$a1 = mysql_result($result, $i, 'add1');
	$a2 = mysql_result($result, $i, 'add2');
	$e = mysql_result($result, $i, 'email');

	// Displaying as a table row
	echo "<tr><td>" . $n . "</td><td>" . $a1 . "</td><td>" . $a2 . "</td><td>" . $e . "</td></tr>";

	/* Alternatively */
	// $arr = mysql_fetch_row($result);
	// echo "<tr><td>" . $arr[0] . "</td><td>" . $arr[1] . "</td><td>" . $arr[2] . "</td><td>" . $arr[3] . "</td></tr>";
}
echo "</table>";
?>
