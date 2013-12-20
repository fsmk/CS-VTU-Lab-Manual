#!/usr/bin/perl

# Write a Perl program to insert name and age information entered by the user into a table 
#created using MySQL and to display the current contents of this table.


print "Content-Type: text/html","\n\n"; 
print "<html><title>Result of the insert operation </title>"; 
use CGI ':standard'; 
use DBI; 


#to connect to  data base interface with database name “vishal”….login ID as “root”..and password as #“ise123”… 
$dbh = DBI->connect("DBI:mysql:pppl","jeffrey","mypass");
$name = param("name");	#to  store value from HTML page text box “name”
$age = param("age");	#to store age from HTML page into a variable 
$qh = $dbh->prepare("insert into student values('$name','$age')");	# to insert the value into the table #created in the datbase 
$qh->execute() or print "error";				#interact with the data base and execute the query following it. 
$qh2 = $dbh->prepare("select * from student"); 	#to retrieve all data from table name “stud” $qh->execute(); 
$qh2->execute();
print "<table border size=1><tr><th>Name</th><th>Age</th></tr>";
while (($name, $age) = $qh2->fetchrow_array()) #to display data retrieve from database to the HTML page 
{
    print "<tr><td>$name</td><td>$age</td></ tr>";
} 
print "</table>"; 
$qh->finish();		#To inform that operation is finished 
$dbh->disconnect();	#close the connection to the database print"</HTML>";
