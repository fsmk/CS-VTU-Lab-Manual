<?php 
session_start();			 
// A new session is created between the browser and server

session_register("count"); 
/**
* Session key value pairs are created
* It is used to create session variables
*/

$_SESSION["count"]++; 	
//each time the page is loaded, the count is incremented. 

echo "<p>the counter is now <b>$_SESSION[count]</b></p>" . "<p>reload this page to increment</p>";
// dot in php is the concatenation operator
?>
