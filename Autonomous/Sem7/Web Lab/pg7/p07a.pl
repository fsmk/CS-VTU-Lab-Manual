#!/usr/bin/perl

################################################################
# Server configuration is always stored in the $ENV variable
# In this program, we simpy access the required info from $ENV
################################################################

use CGI ':standard';
print "Content-type: text/html","\n\n";
print "<html>\n";
print "<head><title>About this Server</title><head>\n";
print "<body><h1>About this server</h1>","\n";
print"<hr>";
print "Server name :",$ENV{'SERVER_NAME'},"<br>";
print "Running on port :",$ENV{'SERVER_PORT'},"<br>";
print "Server software :",$ENV{'SERVER_SOFTWARE'},"<br>";
print "CGI-Revision :",$ENV{'GATEWAY_INTERFACE'},"<br>";
print "<hr>\n";
print "</body></html>\n";
