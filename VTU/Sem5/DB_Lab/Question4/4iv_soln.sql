SELECT a.aname FROM AUTHOR a,CATALOG c WHERE a.authorid=c.authorid AND
c.bookid IN (SELECT bookid FROM ORDER_DETAILS GROUP BY bookid HAVING
SUM(quantity)>=ALL(SELECT SUM(quantity) FROM ORDER_DETAILS GROUP BY bookid));
