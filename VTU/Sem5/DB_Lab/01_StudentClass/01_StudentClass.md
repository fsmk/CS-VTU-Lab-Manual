#PROGRAM 1
###DESCRIPTION: The following relations keep track of students, their enrollment for classes along with faculty information.

<pre>	Student (snum: integer, sname: string, major: string, level: string, age: integer) 
	Class (name: string, meets at: string, room: string, d: integer) 
	Enrolled (snum: integer, cname: string) 
	Faculty (fid: integer, fname: string, deptid: integer)

NOTE :The meaning of these relations is straight forward.For example, Enrolled has one record per student-class pair such that the student is
enrolled in the class. Level is a two character code with 4 different values (example: Junior: JR etc)</pre> 


## QUERIES:
<pre> Write the following queries in SQL. No duplicates should be printed in any of the answers.

1: Find the names of all juniors (level=Jr) who are enrolled for class taught by professor Harshith.

2: Find the names of all classes that either meet in room128 or have 5 or more students enrolled.

3: Find the names of all students who are enrolled in two classes that meet at same time.

4: Find the names of faculty members who teach in every room in which some class is taught.

5: Find the names of the faculty members for whome the combined enrollment of the classes that they teach is less then five.



## CREATION:
<pre>mysql> create database student;
Query OK, 1 row affected (0.00 sec)</pre>

<pre>mysql> use flights;
Database changed

mysql> create table student(
	snum int,sname varchar(10),
	major varchar(2),
	level varchar(2),
	age int,primary key(snum));
Query OK, 0 rows affected (0.10 sec)

mysql> desc student;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| snum  | int(11)     | NO   | PRI | 0       |       |
| sname | varchar(10) | YES  |     | NULL    |       |
| major | varchar(2)  | YES  |     | NULL    |       |
| level | varchar(2)  | YES  |     | NULL    |       |
| age   | int(11)     | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
5 rows in set (0.01 sec)


mysql> create table faculty(
	fid int,fname varchar(20),
	deptid int,
	primary key(fid));
Query OK, 0 rows affected (0.08 sec)
mysql> desc faculty;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| fid    | int(11)     | NO   | PRI | 0       |       |
| fname  | varchar(20) | YES  |     | NULL    |       |
| deptid | int(11)     | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)


mysql> create table class(
	cname varchar(20),
	metts_at varchar(10),
	room varchar(10),
	fid int,
	primary key(cname),
	foreign key(fid) references faculty(fid));
Query OK, 0 rows affected (0.09 sec)

mysql> desc class;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| cname    | varchar(20) | NO   | PRI |         |       |
| meets_at | varchar(10) | YES  |     | NULL    |       |
| room     | varchar(10) | YES  |     | NULL    |       |
| fid      | int(11)     | YES  | MUL | NULL    |       |
+----------+-------------+------+-----+---------+-------+
4 rows in set (0.01 sec)



mysql> create table enrolled(
	snum int,
	cname varchar(20),
	primary key(snum,cname),
	foreign key(snum) references student(snum),
	foreign key(cname) references class(cname)); 
Query OK, 0 rows affected (0.12 sec)


mysql> desc enrolled;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| snum  | int(11)     | NO   | PRI | 0       |       |
| cname | varchar(20) | NO   | PRI |         |       |
+-------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)</pre>

##INSERTIONS:

<pre>mysql> insert into student values
    -> (1,'jhon','CS','Sr',19),
    -> (2,'smith