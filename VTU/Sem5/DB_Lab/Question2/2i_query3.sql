SELECT DISTINCT e.ename 
FROM EMPLOYEE e 
WHERE e.salary < (
	SELECT MIN(f.price) 
	FROM FLIGHTS f 
	WHERE f.src = "BLR" AND f.dest ="DEL"
);

UPDATE EMPLOYEE SET salary = (salary / 1000) 
WHERE eid IN(1,3,6,9,15);


SELECT DISTINCT e.ename 
FROM EMPLOYEE e 
WHERE e.salary < (
	SELECT MIN(f.price) 
	FROM FLIGHTS f 
	WHERE f.src = "BLR" AND f.dest ="DEL"
);

