DELETE FROM STUDENT;
INSERT INTO STUDENT VALUES('CS1001','Spandana','Computer Science','19831101');
INSERT INTO STUDENT VALUES('CS1002','Sinchana','Computer Science','19830315');
INSERT INTO STUDENT VALUES('CS1003','Chethana','Computer Science','19850101');
INSERT INTO STUDENT VALUES('EC2001','Swaroop','Electronics','19840508');
INSERT INTO STUDENT VALUES('EC2002','Sourav','Electronics','19830315');
INSERT INTO STUDENT VALUES('BT3001','Dharshan','Biotechnology','19840625');

INSERT INTO COURSE VALUES('101','Programming in C','Computer Science');
INSERT INTO COURSE VALUES('102','Data Structures','Computer Science');
INSERT INTO COURSE VALUES('103','Microprocessors','Computer Science');
INSERT INTO COURSE VALUES('104','System Software','Computer Science');
INSERT INTO COURSE VALUES('105','Database Systems','Computer Science');
INSERT INTO COURSE VALUES('201','Electronic Circuits','Electronics');
INSERT INTO COURSE VALUES('202','Signals and Systems','Electronics');
INSERT INTO COURSE VALUES('203','Communication Media','Electronics');
INSERT INTO COURSE VALUES('301','Biochemistry','Biotechnolgy');

INSERT INTO ENROL VALUES('CS1001','101','5','85');
INSERT INTO ENROL VALUES('CS1001','102','5','65');
INSERT INTO ENROL VALUES('CS1002','103','6','50');
INSERT INTO ENROL VALUES('CS1002','104','6','95');
INSERT INTO ENROL VALUES('CS1003','105','7','90');
INSERT INTO ENROL VALUES('CS1003','201','7','80');
INSERT INTO ENROL VALUES('EC2001','201','5','95');
INSERT INTO ENROL VALUES('EC2001','202','5','85');
INSERT INTO ENROL VALUES('EC2002','203','7','90');
INSERT INTO ENROL VALUES('EC2002','101','7','80');
INSERT INTO ENROL VALUES('BT3001','301','5','75');

INSERT INTO TEXT VALUES('1011','Let Us C','BPB Publications','Y.Kantekar');
INSERT INTO TEXT VALUES('1012','Programming in ANSI-C','Tata McGraw Hill','E.BalguruSwamy');
INSERT INTO TEXT VALUES('1021','Data Structures Using C  ','Pearson Education','Tenenbaum');
INSERT INTO TEXT VALUES('1031','The Intel Microprocessors','Pearson Education','B.B. Brey');
INSERT INTO TEXT VALUES('1041','System Software-Concepts ','Pearson Education','L.L. Beck');
INSERT INTO TEXT VALUES('1051','Fundametals of DB Systems','Pearson Education','Elamsri and Navathe');
INSERT INTO TEXT VALUES('1052','Oracle-9i Complete Reference','Tata McGraw Hill','Loney and Koch');
INSERT INTO TEXT VALUES('2011','Electronic Circits','McGraw Hill','Unknown');
INSERT INTO TEXT VALUES('2012','Solid Electronics ','McGraw Hill','Well Known');
INSERT INTO TEXT VALUES('2021','Signals and Systems','McGraw Hill','Anamika');
INSERT INTO TEXT VALUES('2031','Communiction Systems','McGraw Hill','Guess Me');
INSERT INTO TEXT VALUES('3011','Biochemistry','Pearson Education','The Great');


INSERT INTO BOOK_ADOPTION VALUES('101','5','1011');
INSERT INTO BOOK_ADOPTION VALUES('102','5','1021');
INSERT INTO BOOK_ADOPTION VALUES('103','6','1031');
INSERT INTO BOOK_ADOPTION VALUES('104','6','1041');
INSERT INTO BOOK_ADOPTION VALUES('105','5','1051');
INSERT INTO BOOK_ADOPTION VALUES('105','5','1052');
INSERT INTO BOOK_ADOPTION VALUES('101','7','1012');
INSERT INTO BOOK_ADOPTION VALUES('201','7','2012');
INSERT INTO BOOK_ADOPTION VALUES('201','5','2011');
INSERT INTO BOOK_ADOPTION VALUES('202','5','2021');
INSERT INTO BOOK_ADOPTION VALUES('203','7','2031');
INSERT INTO BOOK_ADOPTION VALUES('301','5','3011');
