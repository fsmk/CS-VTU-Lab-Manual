





##PROGRAM 1
###DESCRIPTION: 
The following relations keep track of students, their enrollment for classes along with faculty information.

* Student (snum: integer, sname: string, major: string, level: string, age: integer) 
* Class (name: string, meets at: string, room: string, d: integer) 
* Enrolled (snum: integer, cname: string) 
* Faculty (fid: integer, fname: string, deptid: integer)

NOTE: The meaning of these relations is straight forward.For example, Enrolled has one record per student-class pair such that the student is
enrolled in the class. Level is a two character code with 4 different values (example: Junior: JR etc)


##Queries:

Write the following queries in SQL. No duplicates should be printed in any of the answers.

1. Find the names of all juniors (level=Jr) who are enrolled for class taught by professor Harshith.

2. Find the names of all classes that either meet in room128 or have 5 or more students enrolled.

3. Find the names of all students who are enrolled in two classes that meet at same time.

4. Find the names of faculty members who teach in every room in which some class is taught.

5. Find the names of the faculty members for whome the combined enrollment of the classes that they teach is less then five.



##Create:

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

##QUERIES:
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









##PROGRAM 4 
###DESCRIPTION:
The following tables are maintained by a book dealer.

* AUTHOR (author-id:int, name:string, city:string, country:string)
* PUBLISHER (publisher-id:int, name:string, city:string, country:string)
* CATALOG (book-id:int, title:string, author-id:int, publisher-id:int,
* Category-id:int, year:int, price:int)
* CATEGORY (category-id:int, description:string)
* ORDER-DETAILS (order-no:int, book-id:int, quantity:int)

##Queries:

<pre>Write each of the following queries in SQL.

1. Create the above tables by properly specifying the primary keys and the foreign keys.
2. Enter at least five tuples for each relation.
3. Give the details of the authors who have 2 or more books in the 
catalog and the price of the books is greater than the average price of 
the books in the catalog and the year of publication is after 2000.
4. Find the author of the book which has maximum sales.
5. Demonstrate how you increase the price of books published by a specific 
publisher by 10%.
6. Generate suitable reports.
7. Create suitable front end for querying and displaying the results.</pre>

###QUERY (i): Create the above tables by properly specifying the primary keys and the foreign keys.

###CREATION:
<pre>mysql> create database book_dealer;
Query OK, 1 row affected (0.00 sec)</pre>

<pre>mysql> use book_dealer;
Database changed
mysql> create table author1 (
      author1_id int, 
      author1_name varchar(20),
      author1_city varchar(20),
      author1_country varchar(20),
      primary key(author1_id));
Query OK, 0 rows affected (0.11 sec)

mysql> desc author1;
+-----------------+-------------+------+-----+---------+-------+
| Field           | Type        | Null | Key | Default | Extra |
+-----------------+-------------+------+-----+---------+-------+
| author1_id      | int(11)     | NO   | PRI | 0       |       |
| author1_name    | varchar(20) | YES  |     | NULL    |       |
| author1_city    | varchar(20) | YES  |     | NULL    |       |
| author1_country | varchar(20) | YES  |     | NULL    |       |
+-----------------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> create table publisher1 (
      publisher1_id int, 
      publisher1_name varchar(20),
      publisher1_city varchar(20),
      publisher1_country varchar(20),
      primary key(publisher1_id));
Query OK, 0 rows affected (0.15 sec)

mysql> desc publisher1;
+--------------------+-------------+------+-----+---------+-------+
| Field              | Type        | Null | Key | Default | Extra |
+--------------------+-------------+------+-----+---------+-------+
| publisher1_id      | int(11)     | NO   | PRI | 0       |       |
| publisher1_name    | varchar(20) | YES  |     | NULL    |       |
| publisher1_city    | varchar(20) | YES  |     | NULL    |       |
| publisher1_country | varchar(20) | YES  |     | NULL    |       |
+--------------------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> create table category1 (
      category_id int,
      description varchar(30),
      primary key(category_id) );
Query OK, 0 rows affected (0.14 sec)

mysql> desc category1;
+-------------+-------------+------+-----+---------+-------+
| Field       | Type        | Null | Key | Default | Extra |
+-------------+-------------+------+-----+---------+-------+
| category_id | int(11)     | NO   | PRI | 0       |       |
| description | varchar(30) | YES  |     | NULL    |       |
+-------------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

mysql> desc category1;
+-------------+-------------+------+-----+---------+-------+
| Field       | Type        | Null | Key | Default | Extra |
+-------------+-------------+------+-----+---------+-------+
| category_id | int(11)     | NO   | PRI | 0       |       |
| description | varchar(30) | YES  |     | NULL    |       |
+-------------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)


mysql> create table catalogue1(
      book_id int,
      book_title varchar(30),
      author1_id int,
      publisher1_id int,
      category_id int,
      year int,
      price int,
      primary key(book_id),
      foreign key(author1_id) references author1(author1_id),
      foreign key(publisher1_id) references publisher1(publisher1_id),
      foreign key(category_id) references category1(category_id) );
Query OK, 0 rows affected (0.47 sec)

mysql> desc catalogue1;
+---------------+-------------+------+-----+---------+-------+
| Field         | Type        | Null | Key | Default | Extra |
+---------------+-------------+------+-----+---------+-------+
| book_id       | int(11)     | NO   | PRI | 0       |       |
| book_title    | varchar(30) | YES  |     | NULL    |       |
| author1_id    | int(11)     | YES  | MUL | NULL    |       |
| publisher1_id | int(11)     | YES  | MUL | NULL    |       |
| category_id   | int(11)     | YES  | MUL | NULL    |       |
| year          | int(11)     | YES  |     | NULL    |       |
| price         | int(11)     | YES  |     | NULL    |       |
+---------------+-------------+------+-----+---------+-------+
7 rows in set (0.00 sec)



mysql> create table orderdetails1(
      order_id int,
      book_id int,
      quantity int,
      primary key(order_id),
      foreign key(book_id) references catalogue1(book_id));
Query OK, 0 rows affected (0.12 sec)

mysql> desc orderdetails1;
+----------+---------+------+-----+---------+-------+
| Field    | Type    | Null | Key | Default | Extra |
+----------+---------+------+-----+---------+-------+
| order_id | int(11) | NO   | PRI | 0       |       |
| book_id  | int(11) | YES  | MUL | NULL    |       |
| quantity | int(11) | YES  |     | NULL    |       |
+----------+---------+------+-----+---------+-------+
3 rows in set (0.00 sec)
</pre> 

###QUERY (ii): Enter at least five tuples for each relation.

###INSERTIONS:
<pre>mysql> insert into author1 values
          (1001,'JK Rowling','London','England'),
          (1002,'Chetan Bhagat','Mumbai','India'),
          (1003,'John McCarthy','Chicago','USA'),
          (1004,'Dan Brown','California','USA') ;

Query OK, 4 rows affected (0.08 sec)
Records: 4  Duplicates: 0  Warnings: 0
</pre><pre>
mysql> select * from author1;
+------------+---------------+--------------+-----------------+
| author1_id | author1_name  | author1_city | author1_country |
+------------+---------------+--------------+-----------------+
|       1001 | JK Rowling    | London       | England         |
|       1002 | Chetan Bhagat | Mumbai       | India           |
|       1003 | John McCarthy | Chicago      | USA             |
|       1004 | Dan Brown     | California   | USA             |
+------------+---------------+--------------+-----------------+
4 rows in set (0.01 sec)
</pre><pre>
mysql> insert into publisher1 values
          (2001,'Bloomsbury','London','England'),
          (2002,'Scholastic','Washington','USA'),
          (2003,'Pearson','London','England'),
          (2004,'Rupa','Delhi','India') ;
Query OK, 4 rows affected (0.06 sec)
Records: 4  Duplicates: 0  Warnings: 0
</pre><pre>
mysql> select * from publisher1;
+---------------+-----------------+-----------------+--------------------+
| publisher1_id | publisher1_name | publisher1_city | publisher1_country |
+---------------+-----------------+-----------------+--------------------+
|          2001 | Bloomsbury      | London          | England            |
|          2002 | Scholastic      | Washington      | USA                |
|          2003 | Pearson         | London          | England            |
|          2004 | Rupa            | Delhi           | India              |
+---------------+-----------------+-----------------+--------------------+
4 rows in set (0.00 sec)
mysql> insert into category1 values
          (3001,'Fiction'),
          (3002,'Non-Fiction'),
           (3003,'thriller'),
     (3004,'action'),
     (3005,'fiction') ;
Query OK, 5 rows affected (0.04 sec)
Records: 5  Duplicates: 0  Warnings: 0
</pre><pre>
mysql> select * from category1;
+-------------+-------------+
| category_id | description |
+-------------+-------------+
|        3001 | Fiction     |
|        3002 | Non-Fiction |
|        3003 | thriller    |
|        3004 | action      |
|        3005 | fiction     |
+-------------+-------------+
5 rows in set (0.00 sec)
</pre><pre>
mysql> insert into catalogue1 values
          (4001,'HP and Goblet Of Fire',1001,2001,3001,2002,600),
          (4002,'HP and Order Of Phoenix',1001,2002,3001,2005,650),
          (4003,'Two States',1002,2004,3001,2009,65),
          (4004,'3 Mistakes of my life',1002,2004,3001,2007,55),
          (4005,'Da Vinci Code',1004,2003,3001,2004,450),
          (4006,'Angels and Demons',1004,2003,3001,2003,350),
          (4007,'Artificial Intelligence',1003,2002,3002,1970,500) ;
Query OK, 7 rows affected (0.36 sec)
Records: 7  Duplicates: 0  Warnings: 0
</pre><pre>
mysql> select * from catalogue1;
+---------+-------------------------+------------+---------------+-------------+------+-------+
| book_id | book_title              | author1_id | publisher1_id | category_id | year | price |
+---------+-------------------------+------------+---------------+-------------+------+-------+
|    4001 | HP and Goblet Of Fire   |       1001 |          2001 |        3001 | 2002 |   600 |
|    4002 | HP and Order Of Phoenix |       1001 |          2002 |        3001 | 2005 |   650 |
|    4003 | Two States              |       1002 |          2004 |        3001 | 2009 |    65 |
|    4004 | 3 Mistakes of my life   |       1002 |          2004 |        3001 | 2007 |    55 |
|    4005 | Da Vinci Code           |       1004 |          2003 |        3001 | 2004 |   450 |
|    4006 | Angels and Demons       |       1004 |          2003 |        3001 | 2003 |   350 |
|    4007 | Artificial Intelligence |       1003 |          2002 |        3002 | 1970 |   500 |
+---------+-------------------------+------------+---------------+-------------+------+-------+
7 rows in set (0.00 sec)
</pre><pre>
mysql> insert into orderdetails1 values
          (5001,4001,5),
          (5002,4002,7),
          (5003,4003,15),
          (5004,4004,11),
          (5005,4005,9),
          (5006,4006,8),
          (5007,4007,2),
          (5008,4004,3) ;
Query OK, 8 rows affected (0.47 sec)
Records: 8  Duplicates: 0  Warnings: 0
</pre><pre>
mysql> select * from orderdetails1;
+----------+---------+----------+
| order_id | book_id | quantity |
+----------+---------+----------+
|     5001 |    4001 |        5 |
|     5002 |    4002 |        7 |
|     5003 |    4003 |       15 |
|     5004 |    4004 |       11 |
|     5005 |    4005 |        9 |
|     5006 |    4006 |        8 |
|     5007 |    4007 |        2 |
|     5008 |    4004 |        3 |
+----------+---------+----------+
8 rows in set (0.00 sec)</pre>

### QUERY (iii): Give the details of the authors who have 2 or more books in the catalog and the price of the books is greater than the  average price of the books in the catalog and the year of  publication is after 2000

<pre>mysql> select * from author1
          where author1_id in
          (select author1_id from catalogue1 where
          year>2000 and price>
          (select avg(price) from catalogue1)
          group by author1_id having count(*)>1);

OR

mysql> select * from author1
               where author1_id in
               (select author1_id from catalogue1 where
               year>2000 and price>
               (select avg(price) from catalogue1)
               group by author1_id having count(*)>1);

Description:
(select avg(price) from catalogue1):-it select the average price of the books from catalogue1. it acts as an input to the outer query which selects the author id from catalogue1 which are published after 2000 and the price of books is greater than the average price of the books.this acts as an input to the outer most query which displays the author1 details of the values which satisfy the inner queries. 
+------------+--------------+--------------+-----------------+
| author1_id | author1_name | author1_city | author1_country |
+------------+--------------+--------------+-----------------+
|       1001 | JK Rowling   | London       | England         |
+------------+--------------+--------------+-----------------+
1 row in set (0.00 sec))</pre>

### QUERY (iv): Find the author1 of the book which has maximum sales.

<pre>
mysql> select author1_name
           from author1 a,catalogue1 c
           where a.author1_id=c.author1_id
           and book_id in
           (select book_id from orderdetails1 
           where quantity= (select max(quantity) 
           from orderdetails1));

OR

mysql> SELECT a.author1_name FROM author1 a,catalogue1 c
     WHERE a.author1_id=c.author1_id AND
     c.book_id IN (SELECT book_id 
     FROM orderdetails1 
     GROUP BY book_id HAVING
     SUM(quantity)>=ALL(SELECT SUM(quantity) 
     FROM orderdetails1 GROUP BY book_id));

Description:
(select max(quantity) from orderdetails1):-it selects the maximum quantity of books from the orderdetails1 which acts as the input to its outer query which selects the book_id from the orderdetails where the quantity is equal to the selected maximum quantity. This acts as the input to the outer most query which displays the author name where the book id satisfies the inner query.
+---------------+
| author1_name  |
+---------------+
| Chetan Bhagat |
+---------------+
1 row in set (0.00 sec)
1 row in set (0.00 sec)</pre>

### QUERY (v): Demonstrate how you increase the price of books published by a specific publisher1  by 10%.

<pre>ysql> update catalogue1 set price=1.1*price
          where publisher1_id in
          (select publisher1_id from publisher1 where 
         publisher1_name='pearson');
Query OK, 2 rows affected (0.41 sec)
Rows matched: 2  Changed: 2  Warnings: 0

Description:
This query is used to update the price of the books by 10% which are published by a specific author. Here we have considered pearson as the author.

mysql> select * from catalogue1;
+---------+-------------------------+------------+---------------+-------------+------+-------+
| book_id | book_title              | author1_id | publisher1_id | category_id | year | price |
+---------+-------------------------+------------+---------------+-------------+------+-------+
|    4001 | HP and Goblet Of Fire   |       1001 |          2001 |        3001 | 2002 |   600 |
|    4002 | HP and Order Of Phoenix |       1001 |          2002 |        3001 | 2005 |   650 |
|    4003 | Two States              |       1002 |          2004 |        3001 | 2009 |    65 |
|    4004 | 3 Mistakes of my life   |       1002 |          2004 |        3001 | 2007 |    55 |
|    4005 | Da Vinci Code           |       1004 |          2003 |        3001 | 2004 |   495 |
|    4006 | Angels and Demons       |       1004 |          2003 |        3001 | 2003 |   385 |
|    4007 | Artificial Intelligence |       1003 |          2002 |        3002 | 1970 |   500 |
+---------+-------------------------+------------+---------------+-------------+------+-------+
7 rows in set (0.00 sec)

</pre>








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






##PROGRAM 4 
###DESCRIPTION:
The following tables are maintained by a book dealer.

* AUTHOR (author-id:int, name:string, city:string, country:string)
* PUBLISHER (publisher-id:int, name:string, city:string, country:string)
* CATALOG (book-id:int, title:string, author-id:int, publisher-id:int,
* Category-id:int, year:int, price:int)
* CATEGORY (category-id:int, description:string)
* ORDER-DETAILS (order-no:int, book-id:int, quantity:int)

##Queries:

Write each of the following queries in SQL.

1. Create the above tables by properly specifying the primary keys and the foreign keys.
2. Enter at least five tuples for each relation.



##Create:

<pre>mysql> create database book_dealer;
Query OK, 1 row affected (0.00 sec)</pre>

<pre>mysql> use book_dealer;
Database changed
mysql> create table author1 (
      author1_id int, 
      author1_name varchar(20),
      author1_city varchar(20),
      author1_country varchar(20),
      primary key(author1_id));
Query OK, 0 rows affected (0.11 sec)

mysql> desc author1;
+-----------------+-------------+------+-----+---------+-------+
| Field           | Type        | Null | Key | Default | Extra |
+-----------------+-------------+------+-----+---------+-------+
| author1_id      | int(11)     | NO   | PRI | 0       |       |
| author1_name    | varchar(20) | YES  |     | NULL    |       |
| author1_city    | varchar(20) | YES  |     | NULL    |       |
| author1_country | varchar(20) | YES  |     | NULL    |       |
+-----------------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> create table publisher1 (
      publisher1_id int, 
      publisher1_name varchar(20),
      publisher1_city varchar(20),
      publisher1_country varchar(20),
      primary key(publisher1_id));
Query OK, 0 rows affected (0.15 sec)

mysql> desc publisher1;
+--------------------+-------------+------+-----+---------+-------+
| Field              | Type        | Null | Key | Default | Extra |
+--------------------+-------------+------+-----+---------+-------+
| publisher1_id      | int(11)     | NO   | PRI | 0       |       |
| publisher1_name    | varchar(20) | YES  |     | NULL    |       |
| publisher1_city    | varchar(20) | YES  |     | NULL    |       |
| publisher1_country | varchar(20) | YES  |     | NULL    |       |
+--------------------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> create table category1 (
      category_id int,
      description varchar(30),
      primary key(category_id) );
Query OK, 0 rows affected (0.14 sec)

mysql> desc category1;
+-------------+-------------+------+-----+---------+-------+
| Field       | Type        | Null | Key | Default | Extra |
+-------------+-------------+------+-----+---------+-------+
| category_id | int(11)     | NO   | PRI | 0       |       |
| description | varchar(30) | YES  |     | NULL    |       |
+-------------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

mysql> create table catalogue1(
      book_id int,
      book_title varchar(30),
      author1_id int,
      publisher1_id int,
      category_id int,
      year int,
      price int,
      primary key(book_id),
      foreign key(author1_id) references author1(author1_id),
      foreign key(publisher1_id) references publisher1(publisher1_id),
      foreign key(category_id) references category1(category_id) );
Query OK, 0 rows affected (0.47 sec)

mysql> desc catalogue1;
+---------------+-------------+------+-----+---------+-------+
| Field         | Type        | Null | Key | Default | Extra |
+---------------+-------------+------+-----+---------+-------+
| book_id       | int(11)     | NO   | PRI | 0       |       |
| book_title    | varchar(30) | YES  |     | NULL    |       |
| author1_id    | int(11)     | YES  | MUL | NULL    |       |
| publisher1_id | int(11)     | YES  | MUL | NULL    |       |
| category_id   | int(11)     | YES  | MUL | NULL    |       |
| year          | int(11)     | YES  |     | NULL    |       |
| price         | int(11)     | YES  |     | NULL    |       |
+---------------+-------------+------+-----+---------+-------+
7 rows in set (0.00 sec)

mysql> create table orderdetails1(
      order_id int,
      book_id int,
      quantity int,
      primary key(order_id),
      foreign key(book_id) references catalogue1(book_id));
Query OK, 0 rows affected (0.12 sec)

mysql> desc orderdetails1;
+----------+---------+------+-----+---------+-------+
| Field    | Type    | Null | Key | Default | Extra |
+----------+---------+------+-----+---------+-------+
| order_id | int(11) | NO   | PRI | 0       |       |
| book_id  | int(11) | YES  | MUL | NULL    |       |
| quantity | int(11) | YES  |     | NULL    |       |
+----------+---------+------+-----+---------+-------+
3 rows in set (0.00 sec)
</pre> 

##INSERTIONS:

<pre>
mysql> insert into author1 values
          (1001,'JK Rowling','London','England'),
          (1002,'Chetan Bhagat','Mumbai','India'),
          (1003,'John McCarthy','Chicago','USA'),
          (1004,'Dan Brown','California','USA') ;

Query OK, 4 rows affected (0.08 sec)
Records: 4  Duplicates: 0  Warnings: 0</pre>
<pre>
mysql> select * from author1;
+------------+---------------+--------------+-----------------+
| author1_id | author1_name  | author1_city | author1_country |
+------------+---------------+--------------+-----------------+
|       1001 | JK Rowling    | London       | England         |
|       1002 | Chetan Bhagat | Mumbai       | India           |
|       1003 | John McCarthy | Chicago      | USA             |
|       1004 | Dan Brown     | California   | USA             |
+------------+---------------+--------------+-----------------+
4 rows in set (0.01 sec)</pre>

<pre>
mysql> insert into publisher1 values
          (2001,'Bloomsbury','London','England'),
          (2002,'Scholastic','Washington','USA'),
          (2003,'Pearson','London','England'),
          (2004,'Rupa','Delhi','India') ;
Query OK, 4 rows affected (0.06 sec)
Records: 4  Duplicates: 0  Warnings: 0

mysql> select * from publisher1;
+---------------+-----------------+-----------------+--------------------+
| publisher1_id | publisher1_name | publisher1_city | publisher1_country |
+---------------+-----------------+-----------------+--------------------+
|          2001 | Bloomsbury      | London          | England            |
|          2002 | Scholastic      | Washington      | USA                |
|          2003 | Pearson         | London          | England            |
|          2004 | Rupa            | Delhi           | India              |
+---------------+-----------------+-----------------+--------------------+
4 rows in set (0.00 sec)</pre>

<pre>mysql> insert into category1 values
          (3001,'Fiction'),
          (3002,'Non-Fiction'),
          (3003,'thriller'),
          (3004,'action'),
          (3005,'fiction') ;
Query OK, 5 rows affected (0.04 sec)
Records: 5  Duplicates: 0  Warnings: 0

mysql> select * from category1;
+-------------+-------------+
| category_id | description |
+-------------+-------------+
|        3001 | Fiction     |
|        3002 | Non-Fiction |
|        3003 | thriller    |
|        3004 | action      |
|        3005 | fiction     |
+-------------+-------------+
5 rows in set (0.00 sec)</pre>

<pre>mysql> insert into catalogue1 values
          (4001,'HP and Goblet Of Fire',1001,2001,3001,2002,600),
          (4002,'HP and Order Of Phoenix',1001,2002,3001,2005,650),
          (4003,'Two States',1002,2004,3001,2009,65),
          (4004,'3 Mistakes of my life',1002,2004,3001,2007,55),
          (4005,'Da Vinci Code',1004,2003,3001,2004,450),
          (4006,'Angels and Demons',1004,2003,3001,2003,350),
          (4007,'Artificial Intelligence',1003,2002,3002,1970,500) ;
Query OK, 7 rows affected (0.36 sec)
Records: 7  Duplicates: 0  Warnings: 0

mysql> select * from catalogue1;
+---------+-------------------------+------------+---------------+-------------+------+-------+
| book_id | book_title              | author1_id | publisher1_id | category_id | year | price |
+---------+-------------------------+------------+---------------+-------------+------+-------+
|    4001 | HP and Goblet Of Fire   |       1001 |          2001 |        3001 | 2002 |   600 |
|    4002 | HP and Order Of Phoenix |       1001 |          2002 |        3001 | 2005 |   650 |
|    4003 | Two States              |       1002 |          2004 |        3001 | 2009 |    65 |
|    4004 | 3 Mistakes of my life   |       1002 |          2004 |        3001 | 2007 |    55 |
|    4005 | Da Vinci Code           |       1004 |          2003 |        3001 | 2004 |   450 |
|    4006 | Angels and Demons       |       1004 |          2003 |        3001 | 2003 |   350 |
|    4007 | Artificial Intelligence |       1003 |          2002 |        3002 | 1970 |   500 |
+---------+-------------------------+------------+---------------+-------------+------+-------+
7 rows in set (0.00 sec)</pre>

<pre>
mysql> insert into orderdetails1 values
          (5001,4001,5),
          (5002,4002,7),
          (5003,4003,15),
          (5004,4004,11),
          (5005,4005,9),
          (5006,4006,8),
          (5007,4007,2),
          (5008,4004,3) ;
Query OK, 8 rows affected (0.47 sec)
Records: 8  Duplicates: 0  Warnings: 0

mysql> select * from orderdetails1;
+----------+---------+----------+
| order_id | book_id | quantity |
+----------+---------+----------+
|     5001 |    4001 |        5 |
|     5002 |    4002 |        7 |
|     5003 |    4003 |       15 |
|     5004 |    4004 |       11 |
|     5005 |    4005 |        9 |
|     5006 |    4006 |        8 |
|     5007 |    4007 |        2 |
|     5008 |    4004 |        3 |
+----------+---------+----------+
8 rows in set (0.00 sec)</pre>

##QUERIES:

### 3: Give the details of the authors who have 2 or more books in the catalog and the price of the books is greater than the  average price of the books in the catalog and the year of  publication is after 2000

<pre>mysql> select * from author1
          where author1_id in
          (select author1_id from catalogue1 where
          year>2000 and price>
          (select avg(price) from catalogue1)
          group by author1_id having count(*)>1);

OR

mysql> select * from author1
               where author1_id in
               (select author1_id from catalogue1 where
               year>2000 and price>
               (select avg(price) from catalogue1)
               group by author1_id having count(*)>1);

Description:
(select avg(price) from catalogue1):-it select the average price of the books from catalogue1. it acts as an input to the outer query which selects the author id from catalogue1 which are published after 2000 and the price of books is greater than the average price of the books.this acts as an input to the outer most query which displays the author1 details of the values which satisfy the inner queries. 
+------------+--------------+--------------+-----------------+
| author1_id | author1_name | author1_city | author1_country |
+------------+--------------+--------------+-----------------+
|       1001 | JK Rowling   | London       | England         |
+------------+--------------+--------------+-----------------+
1 row in set (0.00 sec))</pre>

### 4: Find the author1 of the book which has maximum sales.

<pre>mysql> select c.eid,max(cruisingrange)
     from certified c,aircraft a
     where c.aid=a.aid
     group by c.eid
     having count(*)>3;
+-----+--------------------+
| eid | max(cruisingrange) |
+-----+--------------------+
|   1 |               8000 |
+-----+----------------
mysql> select author1_name
           from author1 a,catalogue1 c
           where a.author1_id=c.author1_id
           and book_id in
           (select book_id from orderdetails1 
           where quantity= (select max(quantity) 
           from orderdetails1));

OR

mysql> SELECT a.author1_name FROM author1 a,catalogue1 c
     WHERE a.author1_id=c.author1_id AND
     c.book_id IN (SELECT book_id 
     FROM orderdetails1 
     GROUP BY book_id HAVING
     SUM(quantity)>=ALL(SELECT SUM(quantity) 
     FROM orderdetails1 GROUP BY book_id));

Description:
(select max(quantity) from orderdetails1):-it selects the maximum quantity of books from the orderdetails1 which acts as the input to its outer query which selects the book_id from the orderdetails where the quantity is equal to the selected maximum quantity. This acts as the input to the outer most query which displays the author name where the book id satisfies the inner query.
+---------------+
| author1_name  |
+---------------+
| Chetan Bhagat |
+---------------+
1 row in set (0.00 sec)----+
1 row in set (0.00 sec)</pre>

### 5: Demonstrate how you increase the price of books published by a specific publisher1  by 10%.

<pre>mysql> update catalogue1 set price=1.1*price
          where publisher1_id in
          (select publisher1_id from publisher1 where 
         publisher1_name='pearson');
Query OK, 2 rows affected (0.41 sec)
Rows matched: 2  Changed: 2  Warnings: 0
Description:
This query is used to update the price of the books by 10% which are published by a specific author. Here we have considered pearson as the author.

mysql> select * from catalogue1;
+---------+-------------------------+------------+---------------+-------------+------+-------+
| book_id | book_title              | author1_id | publisher1_id | category_id | year | price |
+---------+-------------------------+------------+---------------+-------------+------+-------+
|    4001 | HP and Goblet Of Fire   |       1001 |          2001 |        3001 | 2002 |   600 |
|    4002 | HP and Order Of Phoenix |       1001 |          2002 |        3001 | 2005 |   650 |
|    4003 | Two States              |       1002 |          2004 |        3001 | 2009 |    65 |
|    4004 | 3 Mistakes of my life   |       1002 |          2004 |        3001 | 2007 |    55 |
|    4005 | Da Vinci Code           |       1004 |          2003 |        3001 | 2004 |   495 |
|    4006 | Angels and Demons       |       1004 |          2003 |        3001 | 2003 |   385 |
|    4007 | Artificial Intelligence |       1003 |          2002 |        3002 | 1970 |   500 |
+---------+-------------------------+------------+---------------+-------------+------+-------+
7 rows in set (0.00 sec)

</pre>








##PROGRAM 5
###DESCRIPTION:
The following relations keep track of a banking enterprise. 
  
* BRANCH(branch-name:string, branch-city:string, assets:real) 
* ACCOUNT(accno:int, branch-name:string, balance:real) 
* DEPOSITOR(customer-name:string, accno:int) 
* CUSTOMER(customer-name:string, customer-street:string, customer-city:string)    
* LOAN(loan-number:int, branch-name:string, amount:real) 
* BORROWER(customer-name:string, loan-number:int) 

##Queries:

Write each of the following queries in SQL.  

1. Create the above tables by properly specifying the primary keys and the foreign keys 
2. Enter at least five tuples for each relation.


##Create:

<pre>CREATE TABLE BRANCH
     ( branch_name VARCHAR(15),
       branch_city VARCHAR(15),
       assets NUMBER(10,2),
       PRIMARY KEY(branch_name)
     );

     CREATE TABLE ACCOUNT
     ( accno INTEGER(8),
       branch_name VARCHAR(15),
       balance NUMBER(10,2),
       PRIMARY KEY(accno),
       FOREIGN KEY(branch_name) REFERENCES BRANCH(branch_name)ON DELETE CASCADE
     );

    CREATE TABLE CUSTOMER
    ( customer_name VARCHAR(15),
      customer_street VARCHAR(15),
      customer_city VARCHAR(15),
      PRIMARY KEY(customer_name)
    );

    CREATE TABLE LOAN
    ( loan_number INTEGER(8),
      branc_hname VARCHAR(15),
      amount NUMBER(10,2),
      PRIMARY KEY(loan_number),
      FOREIGN KEY(branch_name) REFERENCES BRANCH(branch_name)
    );

    CREATE TABLE DEPOSITOR
    ( customer_name VARCHAR(15),
      accno INTEGER,
      PRIMARY KEY(customer_name, accno),
      FOREIGN KEY(customer_name) REFERENCES CUSTOMER(customer_name),
      FOREIGN KEY(accno) REFERENCES ACCOUNT(accno)
    );

    CREATE TABLE BORROWER
    ( customer_name  VARCHAR(15),
      loan_number INTEGER(8),
      PRIMARY KEY(customer_name, loan_number),
      FOREIGN KEY(customer_name) REFERENCES CUSTOMER(customer_name),
      FOREIGN KEY(loan_number) REFERENCES LOAN(loan_number)
    ); 


##INSERTIONS:

<pre>mysql> insert into branch values
    -> 		("b1","c1",10000),
    -> 		("b2","c2",20000),
    -> 		("b3","c3",30000),
    -> 		("b4","c4",40000),
    -> 		("b5","c5",50000);
Query OK, 5 rows affected (0.06 sec)
Records: 5  Duplicates: 0  Warnings:0</pre>

<pre>mysql> select * from branch;

+-------------+-------------+--------+
| branch_name | branch_city | assets |
+-------------+-------------+--------+
| b1          | c1          |  10000 |
| b2          | c2          |  20000 |
| b3          | c3          |  30000 |
| b4          | c4          |  40000 |
| b5          | c5          |  50000 |
+-------------+-------------+--------+
5 rows in set (0.00 sec)</pre>


<pre>mysql> insert into account values
    -> 		(12,"b1",3000),
    -> 		(22,"b2",4000),
    -> 		(32,"b3",5000),
    -> 		(42,"b4",6000),
    -> 		(52,"b5",7000);

Query OK, 5 rows affected (0.06 sec)
Records: 5  Duplicates: 0  Warnings: 0</pre>

<pre>mysql> select * from account;

+-------+-------------+---------+
| accno | branch_name | balance |
+-------+-------------+---------+
|    12 | b1          |    3000 |
|    22 | b2          |    4000 |
|    32 | b3          |    5000 |
|    42 | b4          |    6000 |
|    52 | b5          |    7000 |
+-------+-------------+---------+
5 rows in set (0.00 sec)</pre>


<pre>mysql> insert into customer values    
    -> 		("cust1","cstreet1","ccity1"),
    -> 		("cust2","cstreet2","ccity2"),
    -> 		("cust3","cstreet3","ccity3"),
    ->  	("cust4","cstreet4","ccity4"),
    ->  	("cust5","cstreet5","ccity5");

Query OK, 5 rows affected (0.07 sec)
Records: 5  Duplicates: 0  Warnings: 0</pre>


<pre>mysql> select * from customer;
+---------------+-----------------+---------------+
| customer_name | customer_street | customer_city |
+---------------+-----------------+---------------+
| cust1         | cstreet1        | ccity1        |
| cust2         | cstreet2        | ccity2        |
| cust3         | cstreet3        | ccity3        |
| cust4         | cstreet4        | ccity4        |
| cust5         | cstreet5        | ccity5        |
+---------------+-----------------+---------------+
5 rows in set (0.00 sec)</pre>


<pre>mysql> insert into depositor values
    -> 		("cust1",12),
    -> 		("cust2",22),
    -> 		("cust3",32),
    -> 		("cust4",42),
    -> 		("cust5",52);

Query OK, 5 rows affected (0.06 sec)
Records: 5  Duplicates: 0  Warnings: 0</pre>

<pre>mysql> select * from depositor;

+---------------+-------+
| customer_name | accno |
+---------------+-------+
| cust1         |    12 |
| cust2         |    22 |
| cust3         |    32 |
| cust4         |    42 |
| cust5         |    52 |
+---------------+-------+
5 rows in set (0.00 sec)</pre>


<pre>mysql> insert into values loan
    -> (10,"b1",10000),
    -> (20,"b2",20000),
    -> (30,"b3",30000),
    -> (40,"b4",40000),
    -> (50,"b5",50000);

Query OK, 5 rows affected (0.06 sec)
Records: 5  Duplicates: 0  Warnings: 0</pre>

<pre>mysql> select * from loan;

+-------------+-------------+--------+
| loan_number | branch_name | amount |
+-------------+-------------+--------+
|          10 | b1          |  10000 |
|          20 | b2          |  20000 |
|          30 | b3          |  30000 |
|          40 | b4          |  40000 |
|          50 | b5          |  50000 |
+-------------+-------------+--------+
5 rows in set (0.00 sec)</pre>


<pre>mysql> insert into borrower values
    -> ("cust1",10),
    -> ("cust2",20),
    -> ("cust3",30),
    -> ("cust4",40),
    -> ("cust5",50);

Query OK, 5 rows affected (0.05 sec)
Records: 5  Duplicates: 0  Warnings: 0</pre>

<pre>mysql> select * from borrower;

+---------------+-------------+
| customer_name | loan_number |
+---------------+-------------+
| cust1         |          10 |
| cust2         |          20 |
| cust3         |          30 |
| cust4         |          40 |
| cust5         |          50 |
+---------------+-------------+
5 rows in set (0.00 sec)</pre>

##QUERIES:

###iii. Find all the customers who have at least two accounts at the Main branch.

<pre>mysql> SELECT customer_name FROM depositor d,account a WHERE 
     d.accno=a.accno AND a.branch_name='Main' 
     GROUP BY d.customer_name HAVING COUNT(d.customer_name)&gt=2;

Empty set (0.00 sec)</pre>


<p>Note:Here we are getting empty set because in our 'account' table there is no  branch_name with value 'Main' and also there are no customer who has two accounts at the Main branch.So we have to either update the table or else add the proper tuples so that we can get the proper outputs.</p>


<p>updating can be done with the following commands.</p>

<pre>mysql> update account set branch_name='Main' where branch_name="b1";
mysql> update account set branch_name='Main' where branch_name="b2";
mysql> update account set customer_name='cust1' where customer_name="cust2";

+---------------+
| customer_name |
+---------------+
| cust1         |
+---------------+
1 row in set (0.00 sec)</pre>

<p>Description: The query is selecting the customer's name such that the account number associated with name is in both the account table and depositor table and also the name of the branch in the account table is 'Main' and then the tuples are being grouped by customer name in the depositor table and also the customer name having count atleast equal to 2 are being selected.</p>

### iv. Find all the customers who have an account at all the branches located in a specific city. 


<pre> mysql> SELECT d.customer_name FROM account a,branch b,depositor d WHERE
       b.branch_name=a.branch_name AND a.accno=d.accno AND b.branch_city='c3' 
       GROUP BY d.customer_name HAVING COUNT(distinct b.branch_name)=(select count(branch_name) from branch where branch_city='c3');

+---------------+
| customer_name |
+---------------+
| cust3         |
+---------------+
1 row in set (0.00 sec)</pre>

<p>Description: The query selects the customers from the the depositor table such that branch name is in both the branch table and also account table and the account number in the selected tuples is in both account table and in depositor table and also the name of the branch city is 'c3'. The selected tuples are gruoped by the customer name of the depositor table whose count should be equal to the count of the branch name in the branch table with brach city 'c3'.</p>

###v. Demonstrate how you delete all account tuples at every branch located in a specific city.

<pre>mysql> DELETE FROM account where branch_name IN(SELECT branch_name FROM branch WHERE branch_city='c5');

Query OK, 1 row affected (0.04 sec)

mysql>SELECT * FROM account;


+-------+-------------+---------+
| accno | branch_name | balance |
+-------+-------------+---------+
|    12 | b1          |    3000 |
|    22 | b2          |    4000 |
|    32 | b3          |    5000 |
|    42 | b4          |    6000 |
+-------+-------------+---------+
4 rows in set (0.00 sec)</pre>

<p>Description:The inner query "SELECT branch_name FROM branch WHERE branch_city='c5' " selects the branch names from the branch table where the branch city is c5. The selected tuples are given as input to the outer query which deletes the tuples with the selected branch names.</p>






#MySQL User guide

1. **How to install Mysql?**
     * **With internet connection:** 
	    1. **Using terminal:**

			 To install MySQL, run the following command from a terminal prompt: 
	
			<b>*sudo apt-get install mysql-server*</b>
       
			During the installation process you will be prompted to enter a password for the MySQL root user.
Once the installation is complete, the MySQL server should be started automatically. You can run the following command from a terminal prompt to check whether the MySQL server is running: 

			*<b>sudo netstat -tap | grep mysql</b>*

			When you run this command, you should see the following line or something similar: 

			*<b><pre>tcp   0   0 localhost:mysql       `*`:`*`        LISTEN 2556/mysqld</pre></b>*
			If the server is not running correctly, you can type the following command to start it: 

			*<b>sudo /etc/init.d/mysql restart</b>*

	     2. **Using Ubuntu software Center:**
		
			Open ubuntu softaware centre, type Mysql Server in search, Click Install.

	* **Offline installation:**
		1. **Using terminal: **

			a. Download or acquire the deb packages of mysql. 
http://dev.mysql.com/downloads/mysql/5.6.html
http://packages.ubuntu.com/quantal/multiarch-support

			b. Copy it in a empty folder.
		
			c. Go to to the empty folder path through terminal and type 
		
			*<b>Sudo dpkg -i *.deb</b>*
		
		2. **Using Ubuntu software Center:**

			a. Right click the deb package and click open through ubuntu software centre.




2. **To get Mysql Prompt in Terminal**

		Type the following command to get MySQL prompt :

			mysql -u root -p

			Enter the Mysql password 

			root123

			NOTE: mysql refers to command

			-u root -p refers to user root password
	
				>>login to MySQL as root user(u) with mysql password(p).



3. **Creation of Database and query execution.**
	1. You will get the MySQL prompt as shown below:

		![Alt text](DBScreenShots/1.png) 

	2. Database Object Creation:
		* To create Database 

			Create Database Student;

		* To Use Database

			use Student;

		* To view the databases

			show databases;

		![Alt text](DBScreenShots/2.png) 

	3. Table Creation: 
		
			create table student(snum int(4) primary key,sname varchar(10),major varchar(10),lev varchar(2),age int(2)); 

			create table faculty(fid int(4) primary key,fname varchar(10), deptid int(2)); 

			create table class(cname varchar(10) primary key,meetat varchar(10),room varchar(4), fid int(4) references faculty(fid)); 

			create table enrolled(snum int(4) references student(snum),cname varchar(10) references class(cname)); 

		![Alt text](DBScreenShots/3.png) 


	4. Inserting values into Table:

			insert into student values(121,'Agrawal','CSE','SR',21);

			insert into student values(119, 'Tony ', 'CSE', 'SR',21);

			insert into student values(122, ' Krishna ', 'CSE', 'JR',20);

		![Alt text](DBScreenShots/4.png) 


	5. to execute Query;

			To find the author1 of the book which has maximum sales:

			select author1_name from author1 a,catalogue1 c where a.author1_id=c.author1_id and book_id in (select book_id from orderdetails1 where quantity= (select max(quantity) from orderdetails1));

		![Alt text](DBScreenShots/5.png) 


	6. To get the tables information use DESC command.

		![Alt text](DBScreenShots/6.png) 

	7. Contents of the table can be viewed by using the command SELECT as follows:

		![Alt text](DBScreenShots/7.png) 

	8. In between if user wants to clear the screen of the terminal then press:
ctrl+l.

	9. To get any information about the commands used in the mysql use “help” command.
		Eg: help insert;
		help create;
	10. Type exit to exit from the MySQL prompt.

		Note 1 : MYSQL is a a case sensitive.
			Ex: “desc MEMBERS” is differ from “desc members”.

		![Alt text](DBScreenShots/8.png) 

		Note 2:



<p><TABLE border="1" width="75%" align="center">
    <TR>
        <TH COLSPAN=2>Handy MySQL Commands</TH>
    </TR>
    <TR>
        <TD>Description
        </TD>
        <TD>Command
        </TD>
    </TR>
    <TR>
        <TD>To login (from unix shell) use -h only if needed.
        </TD>
        <TD>[mysql dir]/bin/mysql -h hostname -u root -p</TD>
    </TR>
    <TR>
        <TD>Create a database on the sql server.
        </TD>
        <TD>create database [databasename];
        </TD>
    </TR>
    <TR>
        <TD>List all databases on the sql server.
        </TD>
        <TD>show databases;
        </TD>
    </TR>
    <TR>
        <TD>Switch to a database.
        </TD>
        <TD>use [db name];use [db name];use [db name];
        </TD>
    </TR>
    <TR>
        <TD>To see all the tables in
            the db.
        </TD>
        <TD>show tables;
        </TD>
    </TR>
    <TR>
        <TD>To see database's field
            formats.
        </TD>
        <TD>describe [tadescribe [table name];
        </TD>
    </TR>
    <TR>
        <TD>To delete a db.
        </TD>
        <TD>drop database [database
            name];
        </TD>
    </TR>
    <TR>
        <TD>To delete a table.
        </TD>
        <TD>drop table [table name];
        </TD>
    </TR>
    <TR>
        <TD>Show all data in a table.
        </TD>
        <TD>SELECT * FROM [table
            name];
        </TD>
    </TR>
    <TR>
        <TD>Returns the columns and
            column information pertaining to the designated table.
        </TD>
        <TD>show columns from [table
            name]; 
        </TD>
    </TR>
    <TR>
        <TD>Show certain selected rows
            with the value &quot;whatever&quot;.
        </TD>
        <TD>SELECT * FROM [table name]
            WHERE [field name] = &quot;whatever&quot;;          
            </TD>
    </TR>
    <TR>
        <TD>Show all records
            containing the name &quot;Bob&quot; AND the phone number
            '3444444'.
        </TD>
        <TD>SELECT * FROM [table name]
            WHERE name = &quot;Bob&quot; AND phone<em>number = '3444444'; 
        </TD>
    </TR>
    <TR>
        <TD>Show all records not
            containing the name &quot;Bob&quot; AND the phone number '3444444'
            order by the phone</em>number field.
        </TD>
        <TD>SELECT * FROM [table name]
            WHERE name != &quot;Bob&quot; AND phone<em>number = '3444444' order
            by phone</em>number; 
        </TD>
    </TR>
    <TR>
        <TD>Show all records starting
            with the letters 'bob' AND the phone number '3444444'.
        </TD>
        <TD>SELECT * FROM [table name]
            WHERE name like &quot;Bob%&quot; AND phone<em>number = '3444444'; 
        </TD>
    </TR>
    <TR>
        <TD>Use a regular expression
            to find records. Use &quot;REGEXP BINARY&quot; to force
            case-sensitivity. This finds any record beginning with a. 
        </TD>
        <TD>SELECT * FROM [table name]
            WHERE rec RLIKE &quot;^a$&quot;; 
        </TD>
    </TR>
    <TR>
        <TD>Show unique records.
        </TD>
        <TD>SELECT DISTINCT [column
            name] FROM [table name];
        </TD>
    </TR>
    <TR>
        <TD>Show selected records
            sorted in an ascending (asc) or descending (desc).
        </TD>
        <TD>SELECT [col1],[col2] FROM
            [table name] ORDER BY [col2] DESC;
        </TD>
    </TR>
    <TR>
        <TD>Count rows.
        </TD>
        <TD>SELECT COUNT(*) FROM
            [table name]; 
        </TD>
    </TR>
    <TR>
        <TD>Join tables on common
            columns.
        </TD>
        <TD>select
            lookup.illustrationid, lookup.personid,person.birthday from
            lookup<BR>left join person on
            lookup.personid=person.personid=statement to join birthday in
            person table with primary illustration id;
        </TD>
    </TR>
    <TR>
        <TD>Switch to the mysql db.
            Create a new user. 
        </TD>
        <TD>INSERT INTO [table name]
            (Host,User,Password) VALUES('%','user',PASSWORD('password'));
        </TD>
    </TR>
    <TR>
        <TD>Change a users
            password.(from unix shell).
        </TD>
        <TD>[mysql dir]/bin/mysqladmin
            -u root -h hostname.blah.org -p password 'new-password'
        </TD>
    </TR>
    <TR>
        <TD>Change a users
            password.(from MySQL prompt).
        </TD>
        <TD>SET PASSWORD FOR
            'user'@'hostname' = PASSWORD('passwordhere');
        </TD>
    </TR>
    <TR>
        <TD>Switch to mysql db.Give
            user privilages for a db.
        </TD>
        <TD>INSERT INTO [table name]
            (Host,Db,User,Select</em>priv,Insert<em>priv,Update</em>priv,Delete<em>priv,Create</em>priv,Drop<em>priv)
            VALUES ('%','db','user','Y','Y','Y','Y','Y','N');
        </TD>
    </TR>
    <TR>
        <TD>To update info already in
            a table.
        </TD>
        <TD>UPDATE [table name] SET
            Select</em>priv = 'Y',Insert<em>priv = 'Y',Update</em>priv = 'Y' where [field
            name] = 'user';
        </TD>
    </TR>
    <TR>
        <TD>Delete a row(s) from a
            table.
        </TD>
        <TD>DELETE from [table name]
            where [field name] = 'whatever';
        </TD>
    </TR>
    <TR>
        <TD>Update database
            permissions/privilages.
        </TD>
        <TD>FLUSH PRIVILEGES;
        </TD>
    </TR>
    <TR>
        <TD>Delete a column.
        </TD>
        <TD>alter table [table name]
            drop column [column name];
        </TD>
    </TR>
    <TR>
        <TD>Add a new column to db.
        </TD>
        <TD>alter table [table name]
            add column [new column name] varchar (20);      </TD>
    </TR>
    <TR>
        <TD>Change column name. 
        </TD>
        <TD>alter table [table name]
            change [old column name] [new column name] varchar (50); 
        </TD>
    </TR>
    <TR>
        <TD>Make a unique column so
            you get no dupes. 
        </TD>
        <TD>alter table [table name]
            add unique ([column name]); 
        </TD>
    </TR>
    <TR>
        <TD>Make a column bigger. 
        </TD>
        <TD>alter table [table name]
            modify [column name] VARCHAR(3); 
        </TD>
    </TR>
    <TR>
        <TD>Delete unique from table. 
        </TD>
        <TD>alter table [table name]
            drop index [colmn name]; 
        </TD>
    </TR>
    <TR>
        <TD>Load a CSV file into a
            table. 
        </TD>
        <TD>LOAD DATA INFILE
            '/tmp/filename.csv' replace INTO TABLE [table name] FIELDS
            TERMINATED BY ',' LINES TERMINATED BY '\n' (field1,field2,field3); </TD>
    </TR>
    <TR>
        <TD>Dump all databases for
            backup. Backup file is sql commands to recreate all db's. 
        </TD>
        <TD>[mysql dir]/bin/mysqldump
            -u root -ppassword --opt &gt;/tmp/alldatabases.sql 
        </TD>
    </TR>
    <TR>
        <TD>Dump one database for
            backup. 
        </TD>
        <TD>[mysql dir]/bin/mysqldump
            -u username -ppassword --databases databasename
            &gt;/tmp/databasename.sql 
        </TD>
    </TR>
    <TR>
        <TD>Dump a table from a
            database. 
        </TD>
        <TD>[mysql dir]/bin/mysqldump
            -c -u username -ppassword databasename tablename &gt;
            /tmp/databasename.tablename.sql 
        </TD>
    </TR>
    <TR>
        <TD>Restore database (or
            database table) from backup. 
        </TD>
        <TD>[mysql dir]/bin/mysql -u
            username -ppassword databasename &lt; /tmp/databasename.sql <br />
        </TD>
    </TR>
    <TR>
        <TD>Create Table Example 1. 
        </TD>
        <TD>CREATE TABLE [table name]
            (firstname VARCHAR(20), middleinitial VARCHAR(3), lastname
            VARCHAR(35),suffix VARCHAR(3),<BR>officeid VARCHAR(10),userid
            VARCHAR(15),username VARCHAR(8),email VARCHAR(35),phone
            VARCHAR(25), groups <BR>VARCHAR(15),datestamp DATE,timestamp
            time,pgpemail VARCHAR(255)); 
        </TD>
    </TR>
    <TR>
		  <TD>Create Table Example 2. 
        </TD>
        <TD>create table [table name]
            (personid int(50) not null auto_increment primary key,firstname
            varchar(35),middlename varchar(50),lastname varchar(50) default
            'bato'); <br />
        </TD>
    </TR>
</TABLE></p>




### Advantages of MySQL:
1. MySQL is the widely used open source database. MySQL is the backend database of most of the websites. 
2. As a Free Software(Free as in freedom), MySQL can be downloaded and used by the developer for free. 
3. MySQL is robust and it provides excellent performance due to usage of MyISAM. 
4. MySQL occupies very less disk space. 
5. MySQL can be easily installed in all major operating systems like Microsoft Windows, Linux, UNIX. 
6. MySQL can be easily learnt using the tutorials that are available on internet. We would recommend users to go through the Spoken Tutorial videos given below to get more information on MySQL.
7. MySQL is best suited for small and medium applications. 

###Resources

* Please go through the video tutorials on MySQL developed and released by **Spoken Tutorial Project**, an initiative of National Mission on Education through ICT, Government of India, to promote IT literacy through Open Source Software. Students can go through these video tutorials to get better understanding of the subject. The tutorials for MySQL can be downloaded from [here](http://files.spoken-tutorial.org/disc-source/php-mysql-english-hindi.zip). More info about the project can be found [here](http://spoken-tutorial.org/).

* The MySQL Handbook is also available in the mysql-doc-5.0 package. To install the package enter the following in a terminal: 
	*<b>sudo apt-get install mysql-doc-5.0</b>*
* The documentation is in HTML format, to view them enter file:///usr/share/doc/mysql-doc-5.0/refman-5.0-en.html-chapter/index.html in your browser's address bar. 

