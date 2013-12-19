<!-- Write a PHP program to store current date-time in a COOKIE 
and display the ‘Last visited on’ date-time on the web page upon reopening of the same page. -->
<?php
if(isset($_COOKIE['datee']))
{
	/***
	* If $_COOKIE['datee'] has been set, that means this page 
	* has been visited before. the server must have created this cookieData
	* the last time it visted this page
	*/
	$cookieData = $_COOKIE['datee'];
}

$todayh = getdate();

/***
* getdate() function returns teh current date and time in an associative array
* Extracting day, month, year, hours, mins seconds from this array
*/
$d = $todayh['mday'];
$m = $todayh['mon'];
$y =  $todayh['year'];

/* This can be skiped
$hr = $todayh['hours'];
$mi = $todayh['minutes'];
$sec = $todayh['seconds'];
*/

/*Creating a well formatted date string*/
$datestring = "$d - $m - $y"; //Instead of "$d - $m - $y, $hr : $mi : $sec"; bcoz its unnecessary
setcookie("datee", $datestring);
echo "<br> Hello! Last visted date: " . $cookieData . "<br>";
?> 
