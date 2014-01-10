Database programs (MySQL)
=========================
SQL commands to create and manipulate databases using MySQL.


1.Open the terminal by using “Alt+Ctrl+T” on keyboard.

2.Type the following command to get  MySQL prompt :
  mysql  -u  root  -p

3.Enter the password 
  root123

4.You will get the MySQL prompt.

5.To create any table, you need to choose any one databases, so  to know the databases that are created, use the command   show ,this command list-out the created databases.

6.New database can be  created by using:

  CREATE SCHEMA BANK;

  USE BANK;

  CREATE TABLE BRANCH(BNAME VARCHAR(10) PRIMARY KEY,CITY VARCHAR(10),ASSETS REAL);. 


7.USE  command is used to select the database for creating tables under that database.


8.To get the tables information use DESC command.


9.To insert values into the table: 
  INSERT INTO BRANCH VALUES('MAIN','BLR',2500000); 

10.Contents of the table can be viewed by using the command 
  SELECT * FROM TABLENAME;


11.In between if user wants to clear the screen of the terminal then press:
   ctrl+l.

12.To get any information about the commands used in the mysql use “help” command.
    Eg: help insert;
        help create;

13.Type exit to exit from the MySQL prompt.
