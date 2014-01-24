SELECT a.aid, f.fno, a.aname
FROM AIRCRAFT a, FLIGHTS f
WHERE f.src = "BLR" AND f.dest ="DEL" AND f.fno = a.fno;
