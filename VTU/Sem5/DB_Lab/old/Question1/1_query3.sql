SELECT DISTINCT s.sname 
FROM STUDENT s 
WHERE s.snum IN(
	SELECT e1.snum 
	FROM ENROLLED e1, ENROLLED e2, CLASS c1, CLASS c2 
	WHERE e1.snum = e2.snum AND e1.cname <> e2.cname AND e1.cname = c1.cname AND e2.cname = c2.cname AND c1.meets_at = c2.meets_at
);

