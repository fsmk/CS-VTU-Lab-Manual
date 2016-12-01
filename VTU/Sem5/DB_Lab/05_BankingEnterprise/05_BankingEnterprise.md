##PROGRAM 5
###DESCRIPTION:
The following relations keep track of a banking enterprise.

* BRANCH(branch-name:string, branch-city:string, assets:real)
* ACCOUNT(accno:int, branch-name:string, balance:real)
* DEPOSITOR(customer-name:string, accno:int)
* CUSTOMER(customer-name:string, customer-street:string, customer-city:string)
* LOAN(loan-number:int, branch-name:string, amount:real)
* BORROWER(customer-name:string, loan-number:int)

###Queries:

Write each of the following queries in SQL.

1. Create the above tables by properly specifying the primary keys and the foreign keys
2. Enter at least five tuples for each relation.


###Create:

<pre>CREATE TABLE branch
     ( branch_name VARCHAR(15),
       branch_city VARCHAR(15),
       assets NUMBER(10,2),
       PRIMARY KEY(branch_name)
     );

     CREATE TABLE account
     ( accno INTEGER(8),
       branch_name VARCHAR(15),
       balance NUMBER(10,2),
       PRIMARY KEY(accno),
       FOREIGN KEY(branch_name) REFERENCES branch(branch_name)ON DELETE CASCADE
     );

    CREATE TABLE customer
    ( customer_name VARCHAR(15),
      customer_street VARCHAR(15),
      customer_city VARCHAR(15),
      PRIMARY KEY(customer_name)
    );

    CREATE TABLE loan
    ( loan_number INTEGER(8),
      branch_name VARCHAR(15),
      amount NUMBER(10,2),
      PRIMARY KEY(loan_number),
      FOREIGN KEY(branch_name) REFERENCES branch(branch_name)
    );

    CREATE TABLE depositor
    ( customer_name VARCHAR(15),
      accno INTEGER,
      PRIMARY KEY(customer_name, accno),
      FOREIGN KEY(customer_name) REFERENCES customer(customer_name),
      FOREIGN KEY(accno) REFERENCES account(accno)
    );

    CREATE TABLE borrower
    ( customer_name  VARCHAR(15),
      loan_number INTEGER(8),
      PRIMARY KEY(customer_name, loan_number),
      FOREIGN KEY(customer_name) REFERENCES customer(customer_name),
      FOREIGN KEY(loan_number) REFERENCES loan(loan_number)
    );
</pre>

###INSERTIONS:

<pre>mysql> insert into branch (branch_name,branch_city,assets) values
    -> 		("b1","c1",10000),
    -> 		("b2","c2",20000),
    -> 		("b3","c3",30000),
    -> 		("b4","c4",40000),
    -> 		("b5","c5",50000);
Query OK, 5 rows affected (0.06 sec)
Records: 5  Duplicates: 0  Warnings:0</pre>

<pre>mysql> SELECT * FROM branch;

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


<pre>mysql> INSERT INTO account (accno,branch_name,balance) VALUES
    -> 		(12,"b1",3000),
    -> 		(22,"b2",4000),
    -> 		(32,"b3",5000),
    -> 		(42,"b4",6000),
    -> 		(52,"b5",7000);

Query OK, 5 rows affected (0.06 sec)
Records: 5  Duplicates: 0  Warnings: 0</pre>

<pre>mysql> SELECT * FROM account;

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


<pre>mysql> INSERT INTO customer (customer_name,customer_street,customer_city) VALUES
    -> 		("cust1","cstreet1","ccity1"),
    -> 		("cust2","cstreet2","ccity2"),
    -> 		("cust3","cstreet3","ccity3"),
    ->  	("cust4","cstreet4","ccity4"),
    ->  	("cust5","cstreet5","ccity5");

Query OK, 5 rows affected (0.07 sec)
Records: 5  Duplicates: 0  Warnings: 0</pre>


<pre>mysql> SELECT * FROM customer;
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


<pre>mysql> INSERT INTO depositor (customer_name,accno) VALUES
    -> 		("cust1",12),
    -> 		("cust2",22),
    -> 		("cust3",32),
    -> 		("cust4",42),
    -> 		("cust5",52);

Query OK, 5 rows affected (0.06 sec)
Records: 5  Duplicates: 0  Warnings: 0</pre>

<pre>mysql> SELECT * FROM depositor;

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


<pre>mysql> INSERT INTO loan (loan_number_branch_name,amount) VALUES
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


<pre>mysql> INSERT INTO borrower (customer_name,loan_number) VALUES
    -> ("cust1",10),
    -> ("cust2",20),
    -> ("cust3",30),
    -> ("cust4",40),
    -> ("cust5",50);

Query OK, 5 rows affected (0.05 sec)
Records: 5  Duplicates: 0  Warnings: 0</pre>

<pre>mysql> SELECT * FROM borrower;

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

###QUERIES:

###iii. Find all the customers who have at least two accounts at the Main branch.

<pre>mysql> SELECT customer_name
			FROM depositor d,account a
			WHERE d.accno=a.accno
			AND a.branch_name='Main'
		    GROUP BY d.customer_name
		    HAVING COUNT(d.customer_name)>=2;

Empty set (0.00 sec)</pre>


<p>Note:Here we are getting empty set because in our 'account' table there is no  branch_name with value 'Main' and also there are no customer who has two accounts at the Main branch.So we have to either update the table or else add the proper tuples so that we can get the proper outputs.</p>


<p>updating can be done with the following commands.</p>

<pre>mysql> UPDATE account SET branch_name='Main' WHERE branch_name="b1";
mysql> UPDATE account SET branch_name='Main' WHERE branch_name="b2";
mysql> UPDATE account SET customer_name='cust1' WHERE customer_name="cust2";

+---------------+
| customer_name |
+---------------+
| cust1         |
+---------------+
1 row in set (0.00 sec)</pre>

<p>Description: The query is selecting the customer's name such that the account number associated with name is in both the account table and depositor table and also the name of the branch in the account table is 'Main' and then the tuples are being grouped by customer name in the depositor table and also the customer name having count atleast equal to 2 are being selected.</p>

### iv. Find all the customers who have an account at all the branches located in a specific city.


<pre> mysql> SELECT d.customer_name
			 FROM account a,branch b,depositor d
			 WHERE b.branch_name=a.branch_name AND
			 a.accno=d.accno AND
			 b.branch_city='c3'
		     GROUP BY d.customer_name
		     HAVING COUNT(distinct b.branch_name)=(
		     	SELECT COUNT(branch_name)
		     	FROM branch
		     	WHERE branch_city='c3');

+---------------+
| customer_name |
+---------------+
| cust3         |
+---------------+
1 row in set (0.00 sec)</pre>

<p>Description: The query selects the customers from the the depositor table such that branch name is in both the branch table and also account table and the account number in the selected tuples is in both account table and in depositor table and also the name of the branch city is 'c3'. The selected tuples are gruoped by the customer name of the depositor table whose count should be equal to the count of the branch name in the branch table with brach city 'c3'.</p>

###v. Demonstrate how you delete all account tuples at every branch located in a specific city.

<pre>mysql> DELETE FROM account WHERE branch_name IN(SELECT branch_name FROM branch WHERE branch_city='c5');

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
