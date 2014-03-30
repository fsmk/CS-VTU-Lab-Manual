SELECT customername FROM DEPOSITOR D,ACCOUNT A WHERE 
D.accno=A.accno AND A.branchname='Main'
GROUP BY D.customername HAVING COUNT(D.customername)>1;

