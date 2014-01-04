CREATE VIEW BANKVIEW AS(
  SELECT DISTINCT customername,b.branchname,branchcity
  FROM DEPOSITOR d,ACCOUNT a,BRANCH b
  WHERE d.accno=a.accno AND a.branchname=b.branchname AND b.branchcity='Bangalore');

SELECT customername 
FROM BANKVIEW
GROUP BY customername
HAVING count(customername)=(
SELECT count(*)
FROM BRANCH
WHERE branchcity='Bangalore');

