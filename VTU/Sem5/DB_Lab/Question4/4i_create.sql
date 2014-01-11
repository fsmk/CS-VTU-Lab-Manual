CREATE DATABASE BOOK;
USE BOOK;
CREATE TABLE IF NOT EXISTS AUTHOR
( authorid INTEGER(8),
  aname  VARCHAR(25),
  acity  VARCHAR(15),
  acountry VARCHAR(15),
  PRIMARY KEY(authorid)
);

CREATE TABLE IF NOT EXISTS PUBLISHER
( publisherid INTEGER(8),
  pname  VARCHAR(25),
  pcity  VARCHAR(15),
  pcountry VARCHAR(15),
  PRIMARY KEY(publisherid)
);

CREATE TABLE IF NOT EXISTS CATEGORY 
( categoryid INTEGER(8),
  description VARCHAR(25),
  PRIMARY KEY(categoryid)
);

CREATE TABLE IF NOT EXISTS CATALOG
( bookid INTEGER(8),
  title  VARCHAR(25),
  authorid INTEGER(8) ,
  publisherid INTEGER(8),
  categoryid INTEGER(8),
  year  INTEGER(4),
  price  DECIMAL(6,2),
  PRIMARY KEY(bookid),
  FOREIGN KEY(authorid) REFERENCES AUTHOR(authorid),
  FOREIGN KEY(publisherid) REFERENCES PUBLISHER(publisherid),
  FOREIGN KEY(categoryid) REFERENCES CATEGORY(categoryid)
);

CREATE TABLE IF NOT EXISTS ORDER_DETAILS
( orderno INTEGER(8),
  bookid INTEGER(8),
  quantity INTEGER(8),
  PRIMARY KEY(orderno),
  FOREIGN KEY(bookid) REFERENCES CATALOG(bookid)
);

