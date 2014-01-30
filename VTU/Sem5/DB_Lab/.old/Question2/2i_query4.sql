SELECT a.aname, AVG(e.salary) 
FROM AIRCRAFT a, EMPLOYEE e, CERTIFIED c 
WHERE e.eid = c.eid AND a.aid = c.aid AND a.cruisingrange > 1000 
GROUP BY a.aname;

