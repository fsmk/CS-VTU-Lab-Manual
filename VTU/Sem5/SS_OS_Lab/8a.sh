
#!/bin/sh

if [ $# -ne 2 ]
then
echo " please enter 2 arguments"
exit
fi
perm1=`ls -l $1|cut -c 1-10`
perm2=`ls -l $2|cut -c 1-10`
if [ $perm1 = $perm2 ]
then
echo "Permissions are same for both files"
echo "permissions are: $perm1"
exit
fi
str1=`ls -l $1|cut -c 2-4`
str2=`ls -l $2|cut -c 2-4`
if [ $str1 = $str2 ]
then
echo "Owner permissions are same: $str1 "
else
echo "Owner permissions are different"
echo " Permissions for file $1 : $str1 "
echo " Permissions for file $2 : $str2 "
fi 
str3=`ls -l $1|cut -c 5-7`
str4=`ls -l $2|cut -c 5-7`
if [ $str3 = $str4 ]
then
echo "Group permissions are same: $str3 "
else
echo "Group permissions are different"
echo " Permissions for file $1 : $str3 "
echo " Permissions for file $2 : $str4 "
fi 
str5=`ls -l $1|cut -c 8-10`
str6=`ls -l $2|cut -c 8-10`
if [ $str5 = $str6 ]
then
echo "Other's permissions are same: $str5 "
else
echo "Other's permissions are different"
echo " Permissions for file $1 : $str5 "
echo " Permissions for file $2 : $str6 "
fi 

