CREATE DATABASE BANK;
USE BANK;
CREATE TABLE IF NOT EXISTS BRANCH
( branchname VARCHAR(15),
  branchcity VARCHAR(15),
  assets DECIMAL(10,2),
  PRIMARY KEY(branchname)
);

CREATE TABLE IF NOT EXISTS ACCOUNT
( accno  INTEGER(8),
  branchname VARCHAR(15),
  balance DECIMAL(10,2),
  PRIMARY KEY(accno),
  FOREIGN KEY(branchname) REFERENCES BRANCH(branchname)ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS CUSTOMER
( customername  VARCHAR(15), 
  customerstreet VARCHAR(15), 
  customercity  VARCHAR(15),
  PRIMARY KEY(customername)
);

CREATE TABLE IF NOT EXISTS LOAN
( loan_number INTEGER(8),
  branchname VARCHAR(15),
  amount DECIMAL(10,2),
  PRIMARY KEY(loan_number),
  FOREIGN KEY(branchname) REFERENCES BRANCH(branchname)

);

CREATE TABLE IF NOT EXISTS DEPOSITOR
( customername VARCHAR(15),
  accno  INTEGER,
  PRIMARY KEY(customername, accno),
  FOREIGN KEY(customername) REFERENCES CUSTOMER(customername),
  FOREIGN KEY(accno) REFERENCES ACCOUNT(accno)
);

CREATE TABLE IF NOT EXISTS BORROWER
( customername	VARCHAR(15),
  loan_number	INTEGER(8),
  PRIMARY KEY(customername, loan_number),
  FOREIGN KEY(customername) REFERENCES CUSTOMER(customername),
  FOREIGN KEY(loan_number) REFERENCES LOAN(loan_number)
);


