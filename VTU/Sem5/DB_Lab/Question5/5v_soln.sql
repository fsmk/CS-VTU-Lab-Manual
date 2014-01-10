DELETE FROM ACCOUNT 
WHERE branchname IN (SELECT branchname
                     FROM BRANCH 
                     WHERE branchcity='Bangalore');

