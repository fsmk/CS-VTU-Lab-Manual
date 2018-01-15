## PROGRAM 2
## DESCRIPTION:
The following relations keep track of airline flight information:

* FLIGHTS (no:integer,from:string,to:string,distance:integer,departs:time,arrives:time,price:real)
* AIRCRAFT (aid:integer,aname:string,cruisingrange:integer)
* CERTIFIED (eid:integer,aid:integer)
* EMPLOYEES (eid:integer,ename:string,salary:integer)

NOTE that the EMPLOYEES relation describes pilots and other kinds of employees as well;Every pilot is certified for some aircraft,and only pilots are certified to fly.

## Queries:

<pre>Write each of the following queries in SQL.

1. Find the names of aircraft such that all pilots certified to operate them have salaries more than Rs 80,000.
2. For each pilot who is certified for more than three aircrafts,find the eid and the maximum cruisingrange of the aircraft for which he/she is certified.
3. Find the names of all pilots whose salary is less than the price of the cheapest route from Bangalore to Frankfurt.
4. For all aircrafts with cruisingrange over 1000 kms,find the name of the aircraft and the average salary of all pilots certified for this aircraft.
5. Find the names of pilots certified for some Boeing aircraft.
6. Find the aid's of all aircraft that can be used on routes from Bangalore to Delhi.
</pre>

## Create:
<pre>
mysql> CREATE DATABASE flights;
Query OK, 1 row affected (0.00 sec)
</pre>
<pre>
mysql> USE flights;
Database changed
mysql> CREATE TABLE flight(
    -> no INT,
    -> frm VARCHAR(20),
    -> too VARCHAR(20),
    -> distance INT,
    -> departs VARCHAR(20),
    -> arrives VARCHAR(20),
    -> price REAL,
    -> PRIMARY KEY (no) );
Query OK, 0 rows affected (0.17 sec)</pre>
<pre>
mysql> DESC flight;
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
mysql> CREATE TABLE aircraft(
    -> aid INT,
    -> aname VARCHAR(20),
    -> cruisingrange INT,
    -> PRIMARY KEY (aid) );
Query OK, 0 rows affected (0.19 sec)
</pre>
<pre>
mysql> DESC aircraft;
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
mysql> CREATE TABLE employees(
    -> eid INT,
    -> ename VARCHAR(20),
    -> salary INT,
    -> PRIMARY KEY (eid) );
Query OK, 0 rows affected (0.29 sec)
</pre>
<pre>
mysql> DESC employees;
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
mysql> CREATE TABLE certified(
    -> eid INT,
    -> aid INT,
    -> PRIMARY KEY (eid,aid),
    -> FOREIGN KEY (eid) REFERENCES employees (eid),
    -> FOREIGN KEY (aid) REFERENCES aircraft (aid) );
Query OK, 0 rows affected (0.43 sec)
</pre>
<pre>
mysql> DESC certified;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| eid   | int(11) | NO   | PRI | 0       |       |
| aid   | int(11) | NO   | PRI | 0       |       |
+-------+---------+------+-----+---------+-------+
2 rows in set (0.00 sec)
</pre>

## Insertion:
<pre>mysql> INSERT INTO flight (no,frm,too,distance,departs,arrives,price) VALUES 
            (1,'Bangalore','Mangalore',360,'10:45:00','12:00:00',10000),
            (2,'Bangalore','Delhi',5000,'12:15:00','04:30:00',25000),
            (3,'Bangalore','Mumbai',3500,'02:15:00','05:25:00',30000),
            (4,'Delhi','Mumbai',4500,'10:15:00','12:05:00',35000),
            (5,'Delhi','Frankfurt',18000,'07:15:00','05:30:00',90000),
            (6,'Bangalore','Frankfurt',19500,'10:00:00','07:45:00',95000),
            (7,'Bangalore','Frankfurt',17000,'12:00:00','06:30:00',99000);

Query OK, 7 rows affected (0.06 sec)
Records: 7  Duplicates: 0  Warnings: 0
</pre>
<pre>
mysql> SELECT * FROM flight;
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
mysql> INSERT INTO aircraft (aid,aname,cruisingrange) values 
        (123,'Airbus',1000),
        (302,'Boeing',5000),
        (306,'Jet01',5000),
        (378,'Airbus380',8000),
        (456,'Aircraft',500),
        (789,'Aircraft02',800),
        (951,'Aircraft03',1000);

Query OK, 7 rows affected (0.07 sec)
Records: 7  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM aircraft;
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
mysql> INSERT INTO employees (eid,ename,salary) VALUES
        (1,'Ajay',30000),
        (2,'Ajith',85000),
        (3,'Arnab',50000),
        (4,'Harry',45000),
        (5,'Ron',90000),
        (6,'Josh',75000),
        (7,'Ram',100000);

Query OK, 7 rows affected (0.29 sec)
Records: 7  Duplicates: 0  Warnings: 0
</pre>
<pre>
mysql> SELECT * FROM employees;
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
mysql> INSERT INTO certified (edit,aid) VALUES
        (1,123),
        (2,123),
        (1,302),
        (5,302),
        (7,302),
        (1,306),
        (2,306),
        (1,378),
        (2,378),
        (4,378),
        (6,456),
        (3,456),
        (5,789),
        (6,789),
        (3,951),
        (1,951),
        (1,789);

Query OK, 17 rows affected (0.30 sec)
Records: 17  Duplicates: 0  Warnings: 0
</pre>
<pre>
mysql> SELECT * FROM certified;
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

## Queries:
###1.Find the names of aircraft such that all pilots certified to operate them have salaries more than Rs 80,000.
<pre>
mysql> SELECT DISTINCT a.aname
    -> FROM aircraft a,certified c,employees e
    -> WHERE a.aid=c.aid
    -> AND c.eid=e.eid
    -> AND NOT EXISTS
    -> (SELECT *
    -> FROM employees e1
    -> WHERE e1.eid=e.eid
    -> AND e1.salary<80000);
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
mysql> SELECT c.eid,MAX(cruisingrange)
    -> FROM certified c,aircraft a
    -> WHERE c.aid=a.aid
    -> GROUP BY c.eid
    -> HAVING COUNT(*)>3;
+-----+--------------------+
| eid | max(cruisingrange) |
+-----+--------------------+
|   1 |               8000 |
+-----+--------------------+
1 row in set (0.00 sec)
</pre>

###3.Find the names of all pilots whose salary is less than the price of the cheapest route from Bangalore to Frankfurt.
<pre>
mysql> SELECT DISTINCT e.ename
    -> FROM employees e
    -> WHERE e.salary<
    -> (SELECT MIN(f.price)
    -> FROM flight f
    -> WHERE f.frm='Bangalore'
    -> AND f.too='Frankfurt');
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
mysql> SELECT a.aid,a.aname,AVG(e.salary)
    -> FROM aircraft a,certified c,employees e
    -> WHERE a.aid=c.aid
    -> AND c.eid=e.eid
    -> AND a.cruisingrange>1000
    -> GROUP BY a.aid,a.aname;
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
mysql> SELECT distinct e.ename
    -> FROM employees e,aircraft a,certified c
    -> WHERE e.eid=c.eid
    -> AND c.aid=a.aid
    -> AND a.aname='Boeing';
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
mysql> SELECT a.aid
    -> FROM aircraft a
    -> WHERE a.cruisingrange>
    -> (SELECT MIN(f.distance)
    -> FROM flight f
    -> WHERE f.frm='Bangalore'
    -> AND f.too='Delhi');
+-----+
| aid |
+-----+
| 378 |
+-----+
1 row in set (0.00 sec)
</pre>
