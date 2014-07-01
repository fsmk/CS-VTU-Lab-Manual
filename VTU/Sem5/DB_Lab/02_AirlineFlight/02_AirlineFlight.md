##PROGRAM 2
###DESCRIPTION:
The following relations keep track of airline flight information:

* FLIGHTS (no:integer,from:string,to:string,distance:integer,departs:time,arrives:time,price:real)
* AIRCRAFT (aid:integer,aname:string,cruisingrange:integer)
* CERTIFIED (eid:integer,aid:integer)
* EMPLOYEES (eid:integer,ename:string,salary:integer)

NOTE that the EMPLOYEES relation describes pilots and other kinds of employees as well;Every pilot is certified for some aircraft,and only pilots are certified to fly.

###Queries:

<pre>Write each of the following queries in SQL.

1. Find the names of aircraft such that all pilots certified to operate them have salaries more than Rs 80,000.
2. For each pilot who is certified for more than three aircrafts,find the eid and the maximum cruisingrange of the aircraft for which he/she is certified.
3. Find the names of all pilots whose salary is less than the price of the cheapest route from Bangalore to Frankfurt.
4. For all aircrafts with cruisingrange over 1000 kms,find the name of the aircraft and the average salary of all pilots certified for this aircraft.
5. Find the names of pilots certified for some Boeing aircraft.
6. Find the aid's of all aircraft that can be used on routes from Bangalore to Delhi.
</pre>

###Create:
<pre>
mysql> create database flights;
Query OK, 1 row affected (0.00 sec)
</pre>
<pre>
mysql> use flights;
Database changed
mysql> create table flight(
    -> no int,
    -> frm varchar(20),
    -> too varchar(20),
    -> distance int,
    -> departs varchar(20),
    -> arrives varchar(20),
    -> price real,
    -> primary key (no) );
Query OK, 0 rows affected (0.17 sec)</pre>
<pre>
mysql> desc flight;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| no       | int(11)     | NO   | PRI | 0       |       |
| frm      | varchar(20) | YES  |     | NULL    |       |
| too      | varchar(20) | YES  |     | NULL    |       |
| distance | int(11)     | YES  |     | NULL    |       |
| departs  | varchar(20) | YES  |     | NULL    |       |
| arrives  | varchar(20) | YES  |     | NULL    |       |
| price    | double      | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
7 rows in set (0.00 sec)
</pre>
<pre>
mysql> create table aircraft(
    -> aid int,
    -> aname varchar(20),
    -> cruisingrange int,
    -> primary key (aid) );
Query OK, 0 rows affected (0.19 sec)
</pre>
<pre>
mysql> desc aircraft;
+---------------+-------------+------+-----+---------+-------+
| Field         | Type        | Null | Key | Default | Extra |
+---------------+-------------+------+-----+---------+-------+
| aid           | int(11)     | NO   | PRI | 0       |       |
| aname         | varchar(20) | YES  |     | NULL    |       |
| cruisingrange | int(11)     | YES  |     | NULL    |       |
+---------------+-------------+------+-----+---------+-------+
3 rows in set (0.01 sec)
</pre>
<pre>
mysql> create table employees(
    -> eid int,
    -> ename varchar(20),
    -> salary int,
    -> primary key (eid) );
Query OK, 0 rows affected (0.29 sec)
</pre>
<pre>
mysql> desc employees;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| eid    | int(11)     | NO   | PRI | 0       |       |
| ename  | varchar(20) | YES  |     | NULL    |       |
| salary | int(11)     | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)
</pre>
<pre>
mysql> create table certified(
    -> eid int,
    -> aid int,
    -> primary key (eid,aid),
    -> foreign key (eid) references employees (eid),
    -> foreign key (aid) references aircraft (aid) );
Query OK, 0 rows affected (0.43 sec)
</pre>
<pre>
mysql> desc certified;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| eid   | int(11) | NO   | PRI | 0       |       |
| aid   | int(11) | NO   | PRI | 0       |       |
+-------+---------+------+-----+---------+-------+
2 rows in set (0.00 sec)
</pre>

###Insertion:
<pre>mysql> insert into flight values (1,'Bangalore','Mangalore',360,'10:45:00','12:00:00',10000),(2,'Bangalore','Delhi',5000,'12:15:00','04:30:00',25000),(3,'Bangalore','Mumbai',3500,'02:15:00','05:25:00',30000),(4,'Delhi','Mumbai',4500,'10:15:00','12:05:00',35000),(5,'Delhi','Frankfurt',18000,'07:15:00','05:30:00',90000),(6,'Bangalore','Frankfurt',19500,'10:00:00','07:45:00',95000),(7,'Bangalore','Frankfurt',17000,'12:00:00','06:30:00',99000);
Query OK, 7 rows affected (0.06 sec)
Records: 7  Duplicates: 0  Warnings: 0
</pre>
<pre>
mysql> select * from flight;
+----+-----------+-----------+----------+----------+----------+-------+
| no | frm       | too       | distance | departs  | arrives  | price |
+----+-----------+-----------+----------+----------+----------+-------+
|  1 | Bangalore | Mangalore |      360 | 10:45:00 | 12:00:00 | 10000 |
|  2 | Bangalore | Delhi     |     5000 | 12:15:00 | 04:30:00 | 25000 |
|  3 | Bangalore | Mumbai    |     3500 | 02:15:00 | 05:25:00 | 30000 |
|  4 | Delhi     | Mumbai    |     4500 | 10:15:00 | 12:05:00 | 35000 |
|  5 | Delhi     | Frankfurt |    18000 | 07:15:00 | 05:30:00 | 90000 |
|  6 | Bangalore | Frankfurt |    19500 | 10:00:00 | 07:45:00 | 95000 |
|  7 | Bangalore | Frankfurt |    17000 | 12:00:00 | 06:30:00 | 99000 |
+----+-----------+-----------+----------+----------+----------+-------+
7 rows in set (0.00 sec)
</pre>
<pre>
mysql> insert into aircraft values (123,'Airbus',1000),(302,'Boeing',5000),(306,'Jet01',5000),(378,'Airbus380',8000),(456,'Aircraft',500),(789,'Aircraft02',800),(951,'Aircraft03',1000);
Query OK, 7 rows affected (0.07 sec)
Records: 7  Duplicates: 0  Warnings: 0

mysql> select * from aircraft;
+-----+------------+---------------+
| aid | aname      | cruisingrange |
+-----+------------+---------------+
| 123 | Airbus     |          1000 |
| 302 | Boeing     |          5000 |
| 306 | Jet01      |          5000 |
| 378 | Airbus380  |          8000 |
| 456 | Aircraft   |           500 |
| 789 | Aircraft02 |           800 |
| 951 | Aircraft03 |          1000 |
+-----+------------+---------------+
7 rows in set (0.00 sec)
</pre>
<pre>
mysql> insert into employees values(1,'Ajay',30000),(2,'Ajith',85000),(3,'Arnab',50000),(4,'Harry',45000),(5,'Ron',90000),(6,'Josh',75000),(7,'Ram',100000);
Query OK, 7 rows affected (0.29 sec)
Records: 7  Duplicates: 0  Warnings: 0
</pre>
<pre>
mysql> select * from employees;
+-----+-------+--------+
| eid | ename | salary |
+-----+-------+--------+
|   1 | Ajay  |  30000 |
|   2 | Ajith |  85000 |
|   3 | Arnab |  50000 |
|   4 | Harry |  45000 |
|   5 | Ron   |  90000 |
|   6 | Josh  |  75000 |
|   7 | Ram   | 100000 |
+-----+-------+--------+
7 rows in set (0.00 sec)
</pre>
<pre>
mysql> insert into certified values (1,123),(2,123),(1,302),(5,302),(7,302),(1,306),(2,306),(1,378),(2,378),(4,378),(6,456),(3,456),(5,789),(6,789),(3,951),(1,951),(1,789);
Query OK, 17 rows affected (0.30 sec)
Records: 17  Duplicates: 0  Warnings: 0
</pre>
<pre>
mysql> select * from certified;
+-----+-----+
| eid | aid |
+-----+-----+
|   1 | 123 |
|   2 | 123 |
|   1 | 302 |
|   5 | 302 |
|   7 | 302 |
|   1 | 306 |
|   2 | 306 |
|   1 | 378 |
|   2 | 378 |
|   4 | 378 |
|   3 | 456 |
|   6 | 456 |
|   1 | 789 |
|   5 | 789 |
|   6 | 789 |
|   1 | 951 |
|   3 | 951 |
+-----+-----+
17 rows in set (0.00 sec)
</pre>

###Queries:
###1.Find the names of aircraft such that all pilots certified to operate them have salaries more than Rs 80,000.
<pre>
mysql> select distinct a.aname
    -> from aircraft a,certified c,employees e
    -> where a.aid=c.aid
    -> and c.eid=e.eid
    -> and not exists
    -> (select *
    -> from employees e1
    -> where e1.eid=e.eid
    -> and e1.salary<80000);
+------------+
| aname      |
+------------+
| Airbus     |
| Boeing     |
| Jet01      |
| Airbus380  |
| Aircraft02 |
+------------+
5 rows in set (0.00 sec)
</pre>

###2.For each pilot who is certified for more than three aircrafts,find the eid and the maximum cruisingrange of the aircraft for which he/she is certified.
<pre>
mysql> select c.eid,max(cruisingrange)
    -> from certified c,aircraft a
    -> where c.aid=a.aid
    -> group by c.eid
    -> having count(*)>3;
+-----+--------------------+
| eid | max(cruisingrange) |
+-----+--------------------+
|   1 |               8000 |
+-----+--------------------+
1 row in set (0.00 sec)
</pre>

###3.Find the names of all pilots whose salary is less than the price of the cheapest route from Bangalore to Frankfurt.
<pre>
mysql> select distinct e.ename
    -> from employees e
    -> where e.salary<
    -> (select min(f.price)
    -> from flight f
    -> where f.frm='Bangalore'
    -> and f.too='Frankfurt');
+-------+
| ename |
+-------+
| Ajay  |
| Ajith |
| Arnab |
| Harry |
| Ron   |
| Josh  |
+-------+
6 rows in set (0.00 sec)
</pre>

###4.For all aircrafts with cruisingrange over 1000 kms,find the name of the aircraft and the average salary of all pilots certified for this aircraft.
<pre>
mysql> select a.aid,a.aname,avg(e.salary)
    -> from aircraft a,certified c,employees e
    -> where a.aid=c.aid
    -> and c.eid=e.eid
    -> and a.cruisingrange>1000
    -> group by a.aid,a.aname;
+-----+-----------+---------------+
| aid | aname     | avg(e.salary) |
+-----+-----------+---------------+
| 302 | Boeing    |    73333.3333 |
| 306 | Jet01     |    57500.0000 |
| 378 | Airbus380 |    53333.3333 |
+-----+-----------+---------------+
3 rows in set (0.01 sec)
</pre>

###5.Find the names of pilots certified for some Boeing aircraft.
<pre>
mysql> select distinct e.ename
    -> from employees e,aircraft a,certified c
    -> where e.eid=c.eid
    -> and c.aid=a.aid
    -> and a.aname='Boeing';
+-------+
| ename |
+-------+
| Ajay  |
| Ron   |
| Ram   |
+-------+
3 rows in set (0.00 sec)
</pre>

###6.Find the aid's of all aircraft that can be used on routes from Bangalore to Delhi.
<pre>
mysql> select a.aid
    -> from aircraft a
    -> where a.cruisingrange>
    -> (select min(f.distance)
    -> from flight f
    -> where f.frm='Bangalore'
    -> and f.too='Delhi');
+-----+
| aid |
+-----+
| 378 |
+-----+
1 row in set (0.00 sec)
</pre>
