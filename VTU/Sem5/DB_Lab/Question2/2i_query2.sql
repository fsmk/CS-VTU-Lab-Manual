SELECT c.eid, MAX(cruisingrange) 
FROM CERTIFIED c, AIRCRAFT a 
WHERE c.aid = a.aid GROUP BY c.eid HAVING count(*)>3;

