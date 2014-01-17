SELECT DISTINCT f.fname 
FROM FACULTY f 
WHERE NOT EXISTS (
	SELECT c.room 
	FROM CLASS c 
	WHERE c.room NOT IN (
		SELECT c1.room 
		FROM CLASS c1
		WHERE c1.fid = f.fid
	)
);

