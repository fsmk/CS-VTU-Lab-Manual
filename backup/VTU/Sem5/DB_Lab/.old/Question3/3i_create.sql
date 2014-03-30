CREATE DATABASE COURSEADOPTION;
USE COURSEADOPTION;

CREATE TABLE IF NOT EXISTS STUDENT 
  ( regno  VARCHAR(9),
    sname  VARCHAR(15),
    major  VARCHAR(20),
    bdate  DATE,
	PRIMARY KEY(regno)
  );

CREATE TABLE IF NOT EXISTS COURSE
  ( courseno  INTEGER(9),
    cname  VARCHAR(20),
    dept   VARCHAR(20),
	PRIMARY KEY(courseno)
  );

CREATE TABLE IF NOT EXISTS ENROL
  ( regno  VARCHAR(9),
    courseno INTEGER(9),
    sem    INTEGER(9) ,
    marks  INTEGER(5),
	PRIMARY KEY(regno,courseno),
	FOREIGN KEY(regno) REFERENCES STUDENT(regno),
	FOREIGN KEY(courseno) REFERENCES COURSE(courseno)
  );

CREATE TABLE IF NOT EXISTS TEXT
  ( book_isbn  INTEGER(9),
    book_title  VARCHAR(30),
    publisher  VARCHAR(23),
    author   VARCHAR(27),
	PRIMARY KEY(book_isbn)
  );

CREATE TABLE IF NOT EXISTS BOOK_ADOPTION
  ( courseno  INTEGER(9) REFERENCES COURSE(courseno),
    book_isbn  INTEGER(9) REFERENCES TEXT(book_isbn),
	sem   INTEGER(9),
	PRIMARY KEY(courseno,book_isbn),
	FOREIGN KEY(courseno) REFERENCES COURSE(courseno),
	FOREIGN KEY(book_isbn) REFERENCES TEXT(book_isbn)
  );


