#! /usr/bin/perl

use CGI ':standard';
use CGI::Carp qw(warningsToBrowser);


######################################################################
# This program requires count.txt to be created before it.
# So create count.txt using gedit or any text editor and initialise
# it with zero
# After that give write permissions to all users. Else only the program
# itself will be able write into the file, not the browser
# 
# Command:
# chmod a+w count.txt
######################################################################


print header();

#Set the Title for the title bar and background color and text colour.
print start_html(-title=>"webpage counter",-bgcolor=>"black",-text=>"red");

#Open count.txt used to store the view count
open(FILE,'<count.txt');

#Read contents of the file count.txt. Thus $count now has count
$count=<FILE>;

#close the file as no more reading is left
close(FILE);

#increment the count whenever the page(file)is opened and closed.
$count++;

#open the file for writing
open(FILE,'>count.txt');

#write $count into the file
print FILE "$count";

#close the file
close(FILE);

#Display $count on the browser
print b("this page has been viewed $count times");

#Close html
print end_html();