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


