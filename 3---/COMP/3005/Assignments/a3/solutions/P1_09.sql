.mode column
.headers on
.echo on

/*
Do the same as question 1.7 but this time only include trunks that have at least one 'IDLE' channel. That is, write an SQL query that will produce in one table a list of all the acceptable trunks that can be used to route a call to the 416 area code, office code 334 have at least one idle channel.
*/

BEGIN TRANSACTION;

select distinct portid from
	(select portid, area, office from 
		trunk_routes natural join channels where (state="IDLE") and (area="416") and (office="334") 
		
		union 
		
		select portid, area, office from 
			trunk_routes natural join channels where (state="IDLE") and (area="416") and (office="000")
			
		union 
			
		select portid, area, office from 
			trunk_routes natural join channels where (state="IDLE") and (area="000") and (office="000") 
		
		order by area desc, office desc);

COMMIT;

/*

portid    
----------
102       
106       
107 
*/