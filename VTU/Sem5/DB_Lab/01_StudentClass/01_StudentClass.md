##PROGRAM 1
###DESCRIPTION:
The following relations keep track of students, their enrollment for classes along with faculty information.

* Student (snum: integer, sname: string, major: string, level: string, age: integer)
* Class (name: string, meets at: string, room: string, d: integer)
* Enrolled (snum: integer, cname: string)
* Faculty (fid: integer, fname: string, deptid: integer)

NOTE: The meaning of these relations is straight forward.For example, Enrolled has one record per student-class pair such that the student is
enrolled in the class. Level is a two character code with 4 different values (example: Junior: JR etc)
###Queries:

Write the following queries in SQL. No duplicates should be printed in any of the answers.

1. Find the names of all juniors (level=Jr) who are enrolled for class taught by professor Harshith.

2. Find the names of all classes that either meet in room128 or have 5 or more students enrolled.

3. Find the names of all students who are enrolled in two classes that meet at same time.

4. Find the names of faculty members who teach in every room in which some class is taught.

5. Find the names of the faculty members for whome the combined enrollment of the classes that they teach is less then five.



###Create:

<pre>mysql> CREATE DATABASE student;
Query OK, 1 row affected (0.00 sec)</pre>

<pre>mysql> USE student;
Database changed

mysql> CREATE TABLE student(
	snum INT,
	sname VARCHAR(10),
	major VARCHAR(2),
	level VARCHAR(2),
	age int,primary key(snum));
Query OK, 0 rows affected (0.10 sec)

mysql> DESC student;
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


mysql> CREATE TABLE faculty(
	fid INT,fname VARCHAR(20),
	deptid INT,
	PRIMARY KEY(fid));
Query OK, 0 rows affected (0.08 sec)
mysql> DESC faculty;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| fid    | int(11)     | NO   | PRI | 0       |       |
| fname  | varchar(20) | YES  |     | NULL    |       |
| deptid | int(11)     | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)


mysql> CREATE TABLE class(
	cname VARCHAR(20),
	metts_at VARCHAR(10),
	room VARCHAR(10),
	fid INT,
	PRIMARY KEY(cname),
	FOREIGN KEY(fid) REFERENCES faculty(fid));
Query OK, 0 rows affected (0.09 sec)

mysql> DESC class;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| cname    | varchar(20) | NO   | PRI |         |       |
| meets_at | varchar(10) | YES  |     | NULL    |       |
| room     | varchar(10) | YES  |     | NULL    |       |
| fid      | int(11)     | YES  | MUL | NULL    |       |
+----------+-------------+------+-----+---------+-------+
4 rows in set (0.01 sec)



mysql> CREATE TABLE enrolled(
	snum INT,
	cname VARCHAR(20),
	PRIMARY KEY(snum,cname),
	FOREIGN KEY(snum) REFERENCES student(snum),
	FOREIGN KEY(cname) REFERENCES class(cname));
Query OK, 0 rows affected (0.12 sec)


mysql> DESC enrolled;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| snum  | int(11)     | NO   | PRI | 0       |       |
| cname | varchar(20) | NO   | PRI |         |       |
+-------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)</pre>

###INSERTIONS:

<pre>mysql> INSERT INTO student (snum,sname,major,level,age) VALUES
    -> (1,'jhon','CS','Sr',19),
    -> (2,'smith','CS','Jr',20),
    -> (3,'jacob','CV','Sr',20),
    -> (4,'tom','CS','Jr',20),
    -> (5,'sid','CS','Jr',20),
    -> (6,'harry','CS','Sr',21)
Query OK, 2 rows affected (0.04 sec)

mysql> SELECT * FROM student;
+------+-------+-------+-------+------+
| snum | sname | major | level | age  |
+------+-------+-------+-------+------+
|    1 | jhon  | CS    | Sr    |   19 |
|    2 | smith | CS    | Jr    |   20 |
|    3 | jacob | CV    | Sr    |   20 |
|    4 | tom   | CS    | Jr    |   20 |
|    5 | sid   | CS    | Jr    |   20 |
|    6 | Harry | CS    | Sr    |   21 |
+------+-------+-------+-------+------+
6 rows in set (0.00 sec)


mysql> INSERT INTO faculty (fid,fname, deptid) VALUES
    ->(11,'Harshith',1000),
    ->(12,'Mohan',1000),
    ->(13,'Kumar',1001),
    ->(14,'Shobha',1002),
    ->(15,'Shan',1000);
Query OK, 1 row affected (0.03 sec)

mysql> SELECT * FROM faculty;
+-----+----------+--------+
| fid | fname    | deptid |
+-----+----------+--------+
|  11 | Harshith |   1000 |
|  12 | Mohan    |   1000 |
|  13 | Kumar    |   1001 |
|  14 | Shobha   |   1002 |
|  15 | Shan     |   1000 |
+-----+----------+--------+
5 rows in set (0.00 sec)



mysql> INSERT INTO class (cname,meets_at,room,fid) VALUES
    -> ('class1','noon','room1',14),
    -> ('class10','morning','room128',14),
    -> ('class2','morning','room2',12),
    -> ('class3','morning','room3',11),
    -> ('class4','evening','room4',14),
    -> ('class5','night','room3',15),
    -> ('class6','morning','room2',14),
    -> ('class7','morning','room3',14);
Query OK, 8 rows affected (0.05 sec)
Records: 8  Duplicates: 0  Warnings: 0

+---------+----------+---------+------+
| cname   | meets_at | room    | fid  |
+---------+----------+---------+------+
| class1  | noon     | room1   |   14 |
| class10 | morning  | room128 |   14 |
| class2  | morning  | room2   |   12 |
| class3  | morning  | room3   |   11 |
| class4  | evening  | room4   |   14 |
| class5  | night    | room3   |   15 |
| class6  | morning  | room2   |   14 |
| class7  | morning  | room3   |   14 |
+---------+----------+---------+------+
8 rows in set (0.00 sec)



mysql> INSERT INTO enrolled (snum,cname) VALUES
    -> (1,'class1'),
    -> (2,'class1'),
    -> (3,'class3'),
    -> (4,'class3'),
    -> (3,'class3'),
    -> (5,'class4');
    -> (1,'class5');
    -> (2,'class5');
    -> (3,'class5');
    -> (4,'class5');
    -> (5,'class5');
    -> (6,'class5');

Query OK, 12 rows affected (0.03 sec)


mysql> SELECT * FROM enrolled;

+------+--------+
| snum | cname  |
+------+--------+
|    1 | class1 |
|    2 | class1 |
|    3 | class2 |
|    3 | class3 |
|    4 | class3 |
|    5 | class4 |
|    1 | class5 |
|    2 | class5 |
|    3 | class5 |
|    4 | class5 |
|    5 | class5 |
|    6 | class5 |
+------+--------+
12 rows in set (0.00 sec)</pre>

###QUERIES:
###Query 1: Find the names of all juniors (level=Jr) who are enrolled for class taught by professor Harshith.

<pre>mysql> SELECT DISTINCT s.sname
	FROM student s,class c,faculty f,enrolled e
	WHERE  s.snum=e.snum      AND
	       e.cname=c.cname    AND
       	   s.level='jr'   AND
	       f.fname='Harshith' AND
	       f.fid=c.fid;
+-------+
| sname |
+-------+
| tom   |
+-------+
1 row in set (0.00 sec)

Description : Query checks whether the students are enrolled for the class and the level of the students is 'Jr', then it extracts the name of the student who is enrolled for the class whose fid in table class correspomds to the fid of professor Harshith.</pre>


###Query 2: Find the names of all classes that either meet in room128 or have 5 or more students enrolled.

<pre>mysql> SELECT DISTINCT cname
	FROM class
	WHERE room='room128'
	OR
	cname IN (SELECT e.cname FROM enrolled e GROUP BY e.cname HAVING COUNT(*)>=5);
+---------+
| cname   |
+---------+
| class10 |
| class5  |
+---------+
2 rows in set (0.00 sec)

Description : Query results displays the class names that either have room number as room128 or it selects the cname from table enrolled and "group by e.cname having count(*)>=5" statement meaning that cname where number of students enrolled for that class is greater than or equal to five.</pre>


###Query 3: Find the names of all students who are enrolled in two classes that meet at same time.

<pre>mysql> SELECT DISTINCT s.sname
	FROM student s
	WHERE s.snum IN (SELECT e1.snum
				FROM enrolled e1,enrolled e2,class c1,class c2
				WHERE e1.snum=e2.snum   AND
				e1.cname<>e2.cname      AND
		  	        e1.cname=c1.cname       AND
			        e2.cname=c2.cname       AND
			        c1.meets_at=c2.meets_at  );
+-------+
| sname |
+-------+
| jacob |
+-------+
1 row in set (0.00 sec)

Description : Outer part of the query extraxts the name of the students from table student. The inner part of the query fetches the snum of the student, the student is enrolled to two different classes c1.cname and c2.cname, these two classes meets at the name time.</pre>



###Query 4: Find the names of faculty members who teach in every room in which some class is taught.

<pre>mysql> SELECT f.fname,f.fid
			FROM faculty f
	     	WHERE f.fid in ( SELECT fid FROM class
			GROUP BY fid HAVING COUNT(*)=(SELECT COUNT(DISTINCT room) FROM class) );


+--------+-----+
| fname  | fid |
+--------+-----+
| Shobha |  14 |
+--------+-----+
1 row in set (0.00 sec)

Description : The outer part of the query fetches the name and id of the facuty from table faculty of the fid obtained from the inner query.The inner query fetches the fid that has count of number of rooms taught equal to the number of distinct rooms in which some class is taught.</pre>



###Query 5: Find the names of the faculty members for whome the combined enrollment of the classes that they teach is less then five.

<pre>mysql>  SELECT DISTINCT f.fname
	FROM faculty f
	WHERE f.fid IN (  SELECT c.fid
			  FROM class c, enrolled e
			  WHERE c.cname = e.cname GROUP BY c.cname HAVING COUNT(c.cname)< 5 );</pre>
<pre>+----------+
| fname    |
+----------+
| Harshith |
| Mohan    |
| Shobha   |
+----------+
3 rows in set (0.01 sec)

Description : The outer query fetches the name of the faculty for fid obtained from the inner query . The inner query selects the fid from class for the class name cname that is enrolled and the statement "e.cname group by c.cname having count(c.cname) < 5" means that the classwhich has enrollment less than five will be selected.</pre>



