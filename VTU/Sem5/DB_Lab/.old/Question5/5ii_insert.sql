insert into  BRANCH values ('Main', 'Bangalore', null); 
insert into  BRANCH values ('Jayanagar',  'Bangalore', null); 
insert into  BRANCH values ('Ramanagar',  'Bangalore', null); 
insert into  BRANCH values ('Vidyanagar', 'Davangere', null); 
insert into  BRANCH values ('Vijaynagar', 'Davangere', null); 

insert into  CUSTOMER values ('Sania Mirza',  'MG Rd', 'Bangalore'); 
insert into  CUSTOMER values ('Rahul Dravid', 'Jayanagar', 'Bangalore'); 
insert into  CUSTOMER values ('Anil  Kumble', 'Ramanagar', 'Bangalore'); 
insert into  CUSTOMER values ('Sourav Ganguly',  'MCCABlock', 'DVG'); 
insert into  CUSTOMER values ('Sachin Tendlkar', 'Vidyanagar','DVG'); 

insert into ACCOUNT values( 1001, 'Main', 10500);
insert into ACCOUNT values( 1002, 'Main', 5500 );
insert into ACCOUNT values( 2001, 'Jayanagar', 6000);
insert into ACCOUNT values( 3001, 'Ramanagar', 7000);
insert into ACCOUNT values( 4001, 'Vidyanagar', 8000);
insert into ACCOUNT values( 5001, 'Vijaynagar', 10000);
insert into ACCOUNT values( 5002, 'Vidyanagar', 5000);
insert into ACCOUNT values( 2002, 'Main', 500 );
insert into ACCOUNT values( 2003, 'Main', 4500 );
insert into ACCOUNT values( 2004, 'Ramanagar', 4000 );
insert into ACCOUNT values( 3002, 'Main', 3000);

insert into DEPOSITOR values( 'Sania Mirza', 1001);
insert into DEPOSITOR values( 'Sania Mirza', 1002);
insert into DEPOSITOR values( 'Rahul Dravid', 2001);
insert into DEPOSITOR values( 'Rahul Dravid', 2002);
insert into DEPOSITOR values( 'Rahul Dravid', 2003);
insert into DEPOSITOR values( 'Rahul Dravid', 2004);
insert into DEPOSITOR values( 'Anil  Kumble', 3001);
insert into DEPOSITOR values( 'Sourav Ganguly', 4001);
insert into DEPOSITOR values( 'Sachin Tendlkar', 5001);
insert into DEPOSITOR values( 'Sachin Tendlkar', 5002);
insert into DEPOSITOR values( 'Anil  Kumble', 3002);

insert into LOAN values( 101, 'Main', 1000);
insert into LOAN values( 201, 'Main', 2000);
insert into LOAN values( 301, 'Ramanagar', 2000);
insert into LOAN values( 501, 'Vijaynagar', 1000);
insert into LOAN values( 202, 'Jayanagar', 3000);
insert into LOAN values( 502, 'Vidyanagar',1000);

insert into BORROWER values( 'Sania Mirza',  101);
insert into BORROWER values( 'Rahul Dravid', 201);
insert into BORROWER values( 'Anil  Kumble', 301);
insert into BORROWER values( 'Sachin Tendlkar', 501);
insert into BORROWER values( 'Rahul Dravid',   202);
insert into BORROWER values( 'Sachin Tendlkar',502);

