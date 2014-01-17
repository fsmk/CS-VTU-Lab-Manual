SELECT DISTINCT f.fname 
FROM FACULTY f 
WHERE f.fid IN ( 
	SELECT c.fid 
	FROM CLASS c, ENROLLED e 
	WHERE c.cname = e.cname GROUP BY c.cname
	HAVING COUNT(c.cname) < 5
);

