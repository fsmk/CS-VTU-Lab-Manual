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

<pre>mysql> create database student;
Query OK, 1 row affected (0.00 sec)</pre>

<pre>mysql> use student;
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

###INSERTIONS:

<pre>mysql> insert into student values
    -> (1,'jhon','CS','Sr',19),
    -> (2,'smith','CS','Jr',20),
    -> (3,'jacob','CV','Sr',20),
    -> (4,'tom','CS','Jr',20),
    -> (5,'sid','CS','Jr',20),
    -> (6,'harry','CS','Sr',21)
Query OK, 2 rows affected (0.04 sec)

mysql> select *from student;
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


mysql> insert into faculty values
    ->(11,'Harshith',1000),
    ->(12,'Mohan',1000),
    ->(13,'Kumar',1001),
    ->(14,'Shobha',1002),
    ->(15,'Shan',1000);
Query OK, 1 row affected (0.03 sec)

mysql> select *from faculty;
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



mysql> insert into class values
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



mysql> insert into enrolled values
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


mysql> select *from enrolled;

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

<pre>mysql> select distinct s.sname
	from student s,class c,faculty f,enrolled e
	where  s.snum=e.snum      and
	       e.cname=c.cname    and
       	       s.level='jr'       and
	       f.fname='Harshith' and
	       f.fid=c.fid;
+-------+
| sname |
+-------+
| tom   |
+-------+
1 row in set (0.00 sec)

Description : Query checks whether the students are enrolled for the class and the level of the students is 'Jr', then it extracts the name of the student who is enrolled for the class whose fid in table class correspomds to the fid of professor Harshith.</pre>


###Query 2: Find the names of all classes that either meet in room128 or have 5 or more students enrolled.

<pre>mysql> select distinct cname
	from class
	where room='room128'
	or
	cname in (select e.cname from enrolled e group by e.cname having count(*)>=5);
+---------+
| cname   |
+---------+
| class10 |
| class5  |
+---------+
2 rows in set (0.00 sec)

Description : Query results displays the class names that either have room number as room128 or it selects the cname from table enrolled and "group by e.cname having count(*)>=5" statement meaning that cname where number of students enrolled for that class is greater than or equal to five.</pre>


###Query 3: Find the names of all students who are enrolled in two classes that meet at same time.

<pre>mysql> select distinct s.sname
	from student s
	where s.snum in (select e1.snum
				from enrolled e1,enrolled e2,class c1,class c2
				where e1.snum=e2.snum   and
				e1.cname<>e2.cname      and
		  	        e1.cname=c1.cname       and
			        e2.cname=c2.cname       and
			        c1.meets_at=c2.meets_at  );
+-------+
| sname |
+-------+
| jacob |
+-------+
1 row in set (0.00 sec)

Description : Outer part of the query extraxts the name of the students from table student. The inner part of the query fetches the snum of the student, the student is enrolled to two different classes c1.cname and c2.cname, these two classes meets at the name time.</pre>



###Query 4: Find the names of faculty members who teach in every room in which some class is taught.

<pre>mysql> select f.fname,f.fid from faculty f
     	where f.fid in ( select fid from class
			  group by fid having count(*)=(select count(distinct room) from class) );


+--------+-----+
| fname  | fid |
+--------+-----+
| Shobha |  14 |
+--------+-----+
1 row in set (0.00 sec)

Description : The outer part of the query fetches the name and id of the facuty from table faculty of the fid obtained from the inner query.The inner query fetches the fid that has count of number of rooms taught equal to the number of distinct rooms in which some class is taught.</pre>



###Query 5: Find the names of the faculty members for whome the combined enrollment of the classes that they teach is less then five.

<pre>mysql>  select distinct f.fname
	from faculty f
	where f.fid in (  select c.fid
			  from class c, enrolled e
			  where c.cname = e.cname group by c.cname having count(c.cname)< 5 );</pre>
<pre>+----------+
| fname    |
+----------+
| Harshith |
| Mohan    |
| Shobha   |
+----------+
3 rows in set (0.01 sec)

Description : The outer query fetches the name of the faculty for fid obtained from the inner query . The inner query selects the fid from class for the class name cname that is enrolled and the statement "e.cname group by c.cname having count(c.cname) < 5" means that the classwhich has enrollment less than five will be selected.</pre>



