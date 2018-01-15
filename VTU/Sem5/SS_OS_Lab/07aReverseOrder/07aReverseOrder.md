###Aim:
Non-recursive shell script that accepts any number of arguments and prints them in the Reverse order, ( For example, if the script is named rargs, then executing rargs A B C should produce C B A on the standard output).

####Description:
<p> $#: Contains the total number of input arguments.</p>
<p>$@:Contains all the input arguments

<pre>#! /bin/bash
if [ $# -eq 0 ]
then
	echo "no arguments"
	exit
fi
echo "the total number of arguments are $#"
echo "the arguments are $*"
for i in $@
do 
	rev=$i" "$rev
done
echo "$rev" </pre>

####Output:
<pre>./7a.sh 2 7 5
5 7 2
