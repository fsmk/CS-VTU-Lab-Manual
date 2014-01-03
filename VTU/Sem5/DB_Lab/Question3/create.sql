CREATE DATABASE COURSEADOPTION;
USE COURSEADOPTION;

CREATE TABLE IF NOT EXISTS STUDENT 
  ( regno  VARCHAR(9) PRIMARY KEY,
    sname  VARCHAR(15),
    major  VARCHAR(20),
    bdate  DATE
  );

CREATE TABLE IF NOT EXISTS COURSE
  ( courseno  INTEGER(9) PRIMARY KEY,
    cname  VARCHAR(20),
    dept   VARCHAR(20)
  );

CREATE TABLE IF NOT EXISTS ENROL
  ( regno  VARCHAR(9) REFERENCES STUDENT(regno),
    courseno INTEGER(9) REFERENCES COURSE(courseno),
    sem    INTEGER(9) ,
    marks  INTEGER(5)
  );

CREATE TABLE IF NOT EXISTS TEXT
  ( book_isbn  INTEGER(9) PRIMARY KEY,
    book_title  VARCHAR(30),
    publisher  VARCHAR(23),
    author   VARCHAR(27)
  );

CREATE TABLE IF NOT EXISTS BOOK_ADOPTION
  ( courseno  INTEGER(9) REFERENCES COURSE(courseno),
    sem   INTEGER(9),
    book_isbn  INTEGER(9) REFERENCES TEXT(book_isbn) 
  );


