UPDATE CATALOG SET price=(1.10*price) WHERE publisherid =
(SELECT publisherid FROM PUBLISHER WHERE pname ='Pearson Education');
