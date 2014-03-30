SELECT DISTINCT e.ename 
FROM EMPLOYEE e, CERTIFIED c, AIRCRAFT a 
WHERE e.eid = c.eid AND c.aid = a.aid AND a.aname like "boeing%"

