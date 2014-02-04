#! /bin/bash
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
echo "$rev"

