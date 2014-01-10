#! /usr/bin/perl

use CGI ':standard';
use CGI::Carp qw(warningsToBrowser);

@coins = (
	"There is no pain, you are receding", 
	"A distance ship smokes on the horizon", 
	"You are only coming through in waves",
	"Your lips move, but I can't hear what you're saying",
	"I have become comfortably numb");

$range = 5;

# Picking a random number from 0 to $range
# Random numbers can be decimals, and hence need to be converted to int
# This is because only integers can be valid indexes for arrays
$random_number=int(rand($range)); 

if(param)
{
	print header();
	# Set the title in the title bar, the background color and the text color.
	print start_html(-title=>"username",-bgcolor=>"pink",-text=>"blue");
	
	# Store users input
	$cmd = param("name");

	# Printing users name and the random phrase
	# Random phrase is picked by using the random integer we created

	# Display in bold
	print b("hello $cmd,$coins[$random_number]"),br(); 

	# Back button
	print start_form();
	print submit(-value=>"back");

	# End form and html
	print end_form();
	print end_html();
}
else
{
	print header();
	print start_html(-title => "Enter user name", -bgcolor => "red", -text => "black");
	print start_form(),
		textfield(-name=>"name",-value=>" "), #for user input - the name of the user
		submit(-name => "submit", -value => "submit"), #submit button
		reset();
	print end_form();
	print end_html();
}