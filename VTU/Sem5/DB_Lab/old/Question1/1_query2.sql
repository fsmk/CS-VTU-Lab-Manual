SELECT cname 
FROM CLASS 
WHERE cname IN(
	SELECT cname 
	FROM ENROLLED 
	GROUP BY cname 
	HAVING count(*) > 4
) OR cname IN(
	SELECT cname 
	FROM CLASS 
	WHERE room = '502'
);

