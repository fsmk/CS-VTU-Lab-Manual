#! /usr/bin/perl
use CGI ':standard'; 	

print "Content-Type: text/html\n\n";	
print start_html(-title => "Program 9", -bgcolor => "Black", -text => "White"); #sets the title and background color
($s,$m,$h) = localtime(); #to get the current time 
print br,br,"The current system time is $h:$m:$s";	 #equivalent to<br /><br /> of xhtml and print the time. 
print br,br,hr,"In words $h hours $m minutes $s seconds"; 
print end_html(); 		#ends the HTML document by printing the </BODY> and </HTML> tags. 