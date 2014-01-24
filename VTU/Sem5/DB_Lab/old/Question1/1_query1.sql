SELECT sname, slevel 
FROM STUDENT s, ENROLLED e, FACULTY f, CLASS c 
WHERE s.snum = e.snum AND s.slevel = 'JR' AND f.fname = 'vidya' AND c.fid = f.fid AND e.cname = c.cname;

