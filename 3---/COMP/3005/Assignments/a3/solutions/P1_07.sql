
.mode column
.headers on
.echo on

/*
Write an SQL query that will produce in one table a list of all the acceptable trunks that can be used to route a call to the 416 area code, office code 334. This query should list the trunks in the order of preference.
*/

BEGIN TRANSACTION;

select distinct portid from
	(select * from 
		trunk_routes where (area="416") and (office="334") 
		
		union 
		
		select * from 
			trunk_routes where (area="416") and (office="000")
		
		union 
		
		select * from 
			trunk_routes where (area="000") and (office="000") 
			
		order by area desc, office desc);

COMMIT;

/*

portid    
----------
102       
106       
107 
*/