# Dont' run this file as a bash script. Use it for command reference

/etc/init.d/mysqld start #if mysql isn't running
mysql -u root #if theres no password required to login
mysql -u root -p password #otherwise

# If mysql isn't on the PATH i.e. on running mysql you get 'command not found' error, do the following
cd /var/lib/mysql