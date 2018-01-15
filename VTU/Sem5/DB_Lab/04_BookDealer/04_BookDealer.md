## PROGRAM 4
### DESCRIPTION:
The following tables are maintained by a book dealer.

* AUTHOR (author-id:int, name:string, city:string, country:string)
* PUBLISHER (publisher-id:int, name:string, city:string, country:string)
* CATALOG (book-id:int, title:string, author-id:int, publisher-id:int,
* Category-id:int, year:int, price:int)
* CATEGORY (category-id:int, description:string)
* ORDER-DETAILS (order-no:int, book-id:int, quantity:int)

### Queries:

Write each of the following queries in SQL.

1. Create the above tables by properly specifying the primary keys and the foreign keys.
2. Enter at least five tuples for each relation.



### Create:

<pre>mysql> CREATE DATABASE book_dealer;
Query OK, 1 row affected (0.00 sec)</pre>

<pre>mysql> use book_dealer;
Database changed
mysql> CREATE TABLE author1 (
      author1_id INT,
      author1_name VARCHAR(20),
      author1_city VARCHAR(20),
      author1_country VARCHAR(20),
      PRIMARY KEY(author1_id));
Query OK, 0 rows affected (0.11 sec)

mysql> DESC author1;
+-----------------+-------------+------+-----+---------+-------+
| Field           | Type        | Null | Key | Default | Extra |
+-----------------+-------------+------+-----+---------+-------+
| author1_id      | int(11)     | NO   | PRI | 0       |       |
| author1_name    | varchar(20) | YES  |     | NULL    |       |
| author1_city    | varchar(20) | YES  |     | NULL    |       |
| author1_country | varchar(20) | YES  |     | NULL    |       |
+-----------------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> CREATE TABLE publisher1 (
      publisher1_id INT,
      publisher1_name VARCHAR(20),
      publisher1_city VARCHAR(20),
      publisher1_country VARCHAR(20),
      PRIMARY KEY(publisher1_id));
Query OK, 0 rows affected (0.15 sec)

mysql> DESC publisher1;
+--------------------+-------------+------+-----+---------+-------+
| Field              | Type        | Null | Key | Default | Extra |
+--------------------+-------------+------+-----+---------+-------+
| publisher1_id      | int(11)     | NO   | PRI | 0       |       |
| publisher1_name    | varchar(20) | YES  |     | NULL    |       |
| publisher1_city    | varchar(20) | YES  |     | NULL    |       |
| publisher1_country | varchar(20) | YES  |     | NULL    |       |
+--------------------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> CREATE TABLE category1 (
      category_id INT,
      description VARCHAR(30),
      PRIMARY KEY(category_id) );
Query OK, 0 rows affected (0.14 sec)

mysql> DESC category1;
+-------------+-------------+------+-----+---------+-------+
| Field       | Type        | Null | Key | Default | Extra |
+-------------+-------------+------+-----+---------+-------+
| category_id | int(11)     | NO   | PRI | 0       |       |
| description | varchar(30) | YES  |     | NULL    |       |
+-------------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

mysql> CREATE TABLE catalogue1(
      book_id INT,
      book_title VARCHAR(30),
      author1_id INT,
      publisher1_id INT,
      category_id INT,
      year INT,
      price INT,
      PRIMARY KEY(book_id),
      FOREIGN KEY(author1_id) REFERENCES author1(author1_id),
      FOREIGN KEY(publisher1_id) REFERENCES publisher1(publisher1_id),
      FOREIGN KEY(category_id) REFERENCES category1(category_id) );
Query OK, 0 rows affected (0.47 sec)

mysql> DESC catalogue1;
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

mysql> CREATE TABLE orderdetails1(
      order_id INT,
      book_id INT,
      quantity INT,
      PRIMARY KEY(order_id),
      FOREIGN KEY(book_id) REFERENCES catalogue1(book_id));
Query OK, 0 rows affected (0.12 sec)

mysql> DESC orderdetails1;
+----------+---------+------+-----+---------+-------+
| Field    | Type    | Null | Key | Default | Extra |
+----------+---------+------+-----+---------+-------+
| order_id | int(11) | NO   | PRI | 0       |       |
| book_id  | int(11) | YES  | MUL | NULL    |       |
| quantity | int(11) | YES  |     | NULL    |       |
+----------+---------+------+-----+---------+-------+
3 rows in set (0.00 sec)
</pre>

### INSERTIONS:

<pre>
mysql> INSERT INTO author1 (author1_id,author1_name,author1_city,author1_country) VALUES
          (1001,'JK Rowling','London','England'),
          (1002,'Chetan Bhagat','Mumbai','India'),
          (1003,'John McCarthy','Chicago','USA'),
          (1004,'Dan Brown','California','USA') ;

Query OK, 4 rows affected (0.08 sec)
Records: 4  Duplicates: 0  Warnings: 0</pre>
<pre>
mysql> SELECT * FROM author1;
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
mysql> INSERT INTO publisher1 (publisher1_id,publisher1_name,publisher1_city,publisher1_country) VALUES
          (2001,'Bloomsbury','London','England'),
          (2002,'Scholastic','Washington','USA'),
          (2003,'Pearson','London','England'),
          (2004,'Rupa','Delhi','India') ;
Query OK, 4 rows affected (0.06 sec)
Records: 4  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM publisher1;
+---------------+-----------------+-----------------+--------------------+
| publisher1_id | publisher1_name | publisher1_city | publisher1_country |
+---------------+-----------------+-----------------+--------------------+
|          2001 | Bloomsbury      | London          | England            |
|          2002 | Scholastic      | Washington      | USA                |
|          2003 | Pearson         | London          | England            |
|          2004 | Rupa            | Delhi           | India              |
+---------------+-----------------+-----------------+--------------------+
4 rows in set (0.00 sec)</pre>

<pre>mysql> INSERT INTO category1 (category_id,description) VALUES
          (3001,'Fiction'),
          (3002,'Non-Fiction'),
          (3003,'thriller'),
          (3004,'action'),
          (3005,'fiction') ;
Query OK, 5 rows affected (0.04 sec)
Records: 5  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM category1;
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

<pre>mysql> INSERT INTO catalogue1 VALUES (book_id,book_title,author1_id,publisher1_id,category_id,year,price)
          (4001,'HP and Goblet Of Fire',1001,2001,3001,2002,600),
          (4002,'HP and Order Of Phoenix',1001,2002,3001,2005,650),
          (4003,'Two States',1002,2004,3001,2009,65),
          (4004,'3 Mistakes of my life',1002,2004,3001,2007,55),
          (4005,'Da Vinci Code',1004,2003,3001,2004,450),
          (4006,'Angels and Demons',1004,2003,3001,2003,350),
          (4007,'Artificial Intelligence',1003,2002,3002,1970,500) ;
Query OK, 7 rows affected (0.36 sec)
Records: 7  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM catalogue1;
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
mysql> INSERT INTO orderdetails1 (order_id,book_id,quantity) VALUES
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

mysql> SELECT * FROM orderdetails1;
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

### QUERIES:

### 3: Give the details of the authors who have 2 or more books in the catalog and the price of the books is greater than the  average price of the books in the catalog and the year of  publication is after 2000

<pre>mysql> SELECT * FROM author1
          WHERE author1_id IN
          (SELECT author1_id FROM catalogue1 WHERE
          year>2000 AND price>
          (SELECT AVG(price) FROM catalogue1)
          GROUP BY author1_id HAVING COUNT(*)>1);

OR

mysql> SELECT * FROM author1
               WHERE author1_id IN
               (SELECT author1_id FROM catalogue1 WHERE
               year>2000 AND price>
               (SELECT AVG(price) FROM catalogue1)
               GROUP BY author1_id HAVING COUNT(*)>1);

Description:
(select avg(price) from catalogue1):-it select the average price of the books from catalogue1. it acts as an input to the outer query which selects the author id from catalogue1 which are published after 2000 and the price of books is greater than the average price of the books.this acts as an input to the outer most query which displays the author1 details of the values which satisfy the inner queries.
+------------+--------------+--------------+-----------------+
| author1_id | author1_name | author1_city | author1_country |
+------------+--------------+--------------+-----------------+
|       1001 | JK Rowling   | London       | England         |
+------------+--------------+--------------+-----------------+
1 row in set (0.00 sec))</pre>

### 4: Find the author1 of the book which has maximum sales.

mysql> SELECT author1_name
           FROM author1 a,catalogue1 c
           WHERE a.author1_id=c.author1_id
           AND book_id IN
           (SELECT book_id FROM orderdetails1
           WHERE quantity= (SELECT MAX(quantity)
           FROM orderdetails1));

OR

mysql>  SELECT a.author1_name
		FROM author1 a,catalogue1 c
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

<pre>mysql> UPDATE catalogue1 SET price=1.1*price
          WHERE publisher1_id IN
          (SELECT publisher1_id FROM publisher1 WHERE
         publisher1_name='pearson');
Query OK, 2 rows affected (0.41 sec)
Rows matched: 2  Changed: 2  Warnings: 0

Description:
This query is used to update the price of the books by 10% which are published by a specific author. Here we have considered pearson as the author.

mysql> SELECT * FROM catalogue1;
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


