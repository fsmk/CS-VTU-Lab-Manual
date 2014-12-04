###Aim:
Shell script that accepts two file names as arguments, checks if the permissions for these files are identical and if the permissions are identical, outputs the common permissions, otherwise outputs each file name followed by its permissions.

####Descrtiption:
<p>-ne:not equal to.</p>
<p>cut -c:command to cut the specified columns from the given input.</p>
<p> $#: Contains the total number of input arguments.</p>

####Code:
	#!/bin/sh
	if [ $# -ne 2 ]
	then
		echo "usage: sh 1.sh <file1> <file2>"
		exit
	fi
	file1="ls -l $1|cut -c 2-10"
	file2="ls -l $2|cut -c 2-10"
	if [ $perm1 = $perm2 ]
	then
		echo "Identical permissions:"
		echo $file1
	else
		echo "Different permissions:"
		echo $1 "permissions: " $file1
		echo $2 "permissions: " $file2
	fi

###Execute: sh 1.sh 1.c 1.sh


###Output:
	Different Permission:
	1.sh permissions: rw-rw-r--
	a.out permissions rwxrwxrwx
	
###Execute: ./1.sh a.out 1.sh
###Output:
	Identical permissions:
	rw-rw-r--