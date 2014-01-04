SELECT a.authorid,aname,price,title,year FROM AUTHOR a,CATALOG c
WHERE a.authorid=c.authorid
AND year>2000
AND price>(SELECT avg(price) FROM CATALOG)
AND a.authorid IN (SELECT authorid FROM CATALOG GROUP BY authorid HAVING count(authorid)>=1);
