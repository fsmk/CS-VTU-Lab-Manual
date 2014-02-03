##PROGRAM 3
###DESCRIPTION:
Consider the following database of student enrollment in courses &
books adopted for each course.

* STUDENT (regno: string, name: string, major: string, bdate:date)
* COURSE (course #:int, cname:string, dept:string)
* ENROLL ( regno:string, course#:int, sem:int, marks:int)
* BOOK_ADOPTION (course# :int, sem:int, book-ISBN:int)
* TEXT (book-ISBN:int, book-title:string, publisher:string, author:string)

##Queries:

1. Create the above tables by properly specifying the primary keys and 
the foreign keys.
2. Enter at least five tuples for each relation.
3. Demonstrate how you add a new text book to the database and make 
this book be adopted by some department.
4. Produce a list of text books (include Course #, Book-ISBN, Book-title) 
in the alphabetical order for courses offered by the ‘CS’ department that 
use more than two books.
5. List any department that has all its adopted books published by a 
specific publisher.
6. Generate suitable reports.
7. Create suitable front end for querying and displaying the results.

##Create:
<pre>
mysql> create database books;
Query OK, 1 row affected (0.01 sec)
</pre>
<pre>
mysql> use books;
Database changed
mysql> create table student(
     regno varchar(15),
     name varchar(20),
     major varchar(20),
     bdate date,
     primary key (regno) );
Query OK, 0 rows affected (0.12 sec)
</pre>
<pre>
mysql> desc student;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| regno | varchar(15) | NO   | PRI |         |       |
| name  | varchar(20) | YES  |     | NULL    |       |
| major | varchar(20) | YES  |     | NULL    |       |
| bdate | date        | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
4 rows in set (0.01 sec)
</pre>
<pre>
mysql> create table course(
     courseno int,
     cname varchar(20),
     dept varchar(20),
     primary key (courseno) );
Query OK, 0 rows affected (0.12 sec)
</pre>
<pre>
mysql> desc course;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| courseno | int(11)     | NO   | PRI | 0       |       |
| cname    | varchar(20) | YES  |     | NULL    |       |
| dept     | varchar(20) | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)
</pre>
<pre>
mysql> create table enroll(
     regno varchar(15),
     courseno int,
     sem int(3),
     marks int(4),
     primary key (regno,courseno),
     foreign key (regno) references student (regno),
     foreign key (courseno) references course (courseno) );
Query OK, 0 rows affected (0.19 sec)
</pre>
<pre>
mysql> desc enroll;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| regno    | varchar(15) | NO   | PRI |         |       |
| courseno | int(11)     | NO   | PRI | 0       |       |
| sem      | int(3)      | YES  |     | NULL    |       |
| marks    | int(4)      | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)
</pre>
<pre>
mysql> create table text(
     book_isbn int(5),
     book_title varchar(20),
     publisher varchar(20),
     author varchar(20),
     primary key (book_isbn) );
Query OK, 0 rows affected (0.15 sec)
</pre>
<pre>
mysql> desc text;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| book_isbn  | int(5)      | NO   | PRI | 0       |       |
| book_title | varchar(20) | YES  |     | NULL    |       |
| publisher  | varchar(20) | YES  |     | NULL    |       |
| author     | varchar(20) | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)
</pre>
<pre>
mysql> create table book_adoption(
     courseno int,
     sem int(3),
     book_isbn int(5),
     primary key (courseno,book_isbn),
     foreign key (courseno) references course (courseno),
     foreign key (book_isbn) references text(book_isbn) );
Query OK, 0 rows affected (0.17 sec)
</pre>
<pre>
mysql> desc book_adoption;
+-----------+---------+------+-----+---------+-------+
| Field     | Type    | Null | Key | Default | Extra |
+-----------+---------+------+-----+---------+-------+
| courseno  | int(11) | NO   | PRI | 0       |       |
| sem       | int(3)  | YES  |     | NULL    |       |
| book_isbn | int(5)  | NO   | PRI | 0       |       |
+-----------+---------+------+-----+---------+-------+
3 rows in set (0.00 sec)
</pre>
##Insertion:
<pre>mysql> insert into student values ('1pe11cs001','a','sr',19931230);
Query OK, 1 row affected (0.05 sec)
</pre>
<pre>
mysql> insert into student values ('1pe11cs002','b','sr','19930924'),('1pe11cs003','c','sr','19931127'),('1pe11cs004','d','sr','19930413'),('1pe11cs005','e','jr','19940824');
Query OK, 4 rows affected (0.07 sec)
Records: 4  Duplicates: 0  Warnings: 0
</pre>
<pre>
mysql> select * from student;
+------------+------+-------+------------+
| regno      | name | major | bdate      |
+------------+------+-------+------------+
| 1pe11cs001 | a    | sr    | 1993-12-30 |
| 1pe11cs002 | b    | sr    | 1993-09-24 |
| 1pe11cs003 | c    | sr    | 1993-11-27 |
| 1pe11cs004 | d    | sr    | 1993-04-13 |
| 1pe11cs005 | e    | jr    | 1994-08-24 |
+------------+------+-------+------------+
5 rows in set (0.01 sec)
</pre>
<pre>
mysql> insert into course values (111,'OS','CSE'),(112,'EC','CSE'),(113,'SS','ISE'),(114,'DBMS','CSE'),(115,'SIGNALS','ECE');
Query OK, 5 rows affected (0.06 sec)
Records: 5  Duplicates: 0  Warnings: 0
</pre>
<pre>
mysql> select * from course;
+----------+---------+------+
| courseno | cname   | dept |
+----------+---------+------+
|      111 | OS      | CSE  |
|      112 | EC      | CSE  |
|      113 | SS      | ISE  |
|      114 | DBMS    | CSE  |
|      115 | SIGNALS | ECE  |
+----------+---------+------+
5 rows in set (0.00 sec)
</pre>
<pre>
mysql> insert into text values (10,'DATABASE SYSTEMS','PEARSON','SCHIELD'),(900,'OPERATING SYS','PEARSON','LELAND'),(901,'CIRCUITS','HALL INDIA','BOB'),(902,'SYSTEM SOFTWARE','PETERSON','JACOB'),(903,'SCHEDULING','PEARSON','PATIL'),(904,'DATABASE SYSTEMS','PEARSON','JACOB'),(905,'DATABASE MANAGER','PEARSON','BOB'),(906,'SIGNALS','HALL INDIA','SUMIT');
Query OK, 8 rows affected (0.06 sec)
Records: 8  Duplicates: 0  Warnings: 0
</pre>
<pre>
mysql> select * from text;
+-----------+------------------+------------+---------+
| book_isbn | book_title       | publisher  | author  |
+-----------+------------------+------------+---------+
|        10 | DATABASE SYSTEMS | PEARSON    | SCHIELD |
|       900 | OPERATING SYS    | PEARSON    | LELAND  |
|       901 | CIRCUITS         | HALL INDIA | BOB     |
|       902 | SYSTEM SOFTWARE  | PETERSON   | JACOB   |
|       903 | SCHEDULING       | PEARSON    | PATIL   |
|       904 | DATABASE SYSTEMS | PEARSON    | JACOB   |
|       905 | DATABASE MANAGER | PEARSON    | BOB     |
|       906 | SIGNALS          | HALL INDIA | SUMIT   |
+-----------+------------------+------------+---------+
8 rows in set (0.00 sec)
</pre>
<pre>
mysql> insert into enroll values ('1pe11cs001',115,3,100),('1pe11cs002',114,5,100),('1pe11cs003',113,5,100),('1pe11cs004',111,5,100),('1pe11cs005',112,3,100);
Query OK, 5 rows affected (0.08 sec)
Records: 5  Duplicates: 0  Warnings: 0
</pre>
<pre>
mysql> select * from enroll;
+------------+----------+------+-------+
| regno      | courseno | sem  | marks |
+------------+----------+------+-------+
| 1pe11cs001 |      115 |    3 |   100 |
| 1pe11cs002 |      114 |    5 |   100 |
| 1pe11cs003 |      113 |    5 |   100 |
| 1pe11cs004 |      111 |    5 |   100 |
| 1pe11cs005 |      112 |    3 |   100 |
+------------+----------+------+-------+
5 rows in set (0.00 sec)
</pre>
<pre>
mysql> insert into book_adoption values 
(111,5,900),
(111,5,903),
(111,5,904),
(112,3,901),
(113,3,10),
(114,5,905),
(113,5,902),
(115,3,906);
Query OK, 8 rows affected (0.06 sec)
Records: 8  Duplicates: 0  Warnings: 0
</pre>
<pre>
mysql> select * from book_adoption;
+----------+------+-----------+
| courseno | sem  | book_isbn |
+----------+------+-----------+
|      111 |    5 |       900 |
|      111 |    5 |       903 |
|      111 |    5 |       904 |
|      112 |    3 |       901 |
|      113 |    3 |        10 |
|      113 |    5 |       902 |
|      114 |    5 |       905 |
|      115 |    3 |       906 |
+----------+------+-----------+
8 rows in set (0.00 sec).
</pre>
##Queries:
###4. Produce a list of text books (include Course #, Book-ISBN, Book-title) in the alphabetical order for courses offered by the ‘CS’ department that use more than two books.
<pre>
mysql> select c.courseno,t.book_isbn,t.book_title
     from course c,book_adoption ba,text t
     where c.courseno=ba.courseno
     and ba.book_isbn=t.book_isbn
     and c.dept='CSE'
     and 2<(
     select count(book_isbn)
     from book_adoption b
     where c.courseno=b.courseno)
     order by t.book_title;
+----------+-----------+------------------+
| courseno | book_isbn | book_title       |
+----------+-----------+------------------+
|      111 |       904 | DATABASE SYSTEMS |
|      111 |       900 | OPERATING SYS    |
|      111 |       903 | SCHEDULING       |
+----------+-----------+------------------+
3 rows in set (0.01 sec)
</pre>
###5. List any department that has all its adopted books published by a specific publisher.
<pre>
mysql> select distinct c.dept
     from course c
     where c.dept in
     ( select c.dept
     from course c,book_adoption b,text t
     where c.courseno=b.courseno
     and t.book_isbn=b.book_isbn
     and t.publisher='PEARSON')
     and c.dept not in
     (select c.dept
     from course c,book_adoption b,text t
     where c.courseno=b.courseno
     and t.book_isbn=b.book_isbn
     and t.publisher!='PEARSON');
+------+
| dept |
+------+
| CSE  |
+------+
1 row in set (0.00 sec).

</pre>
