
.mode column
.headers on
.echo on

/*
Find the names and address of all subscribers who subscribe to all of the available services.
*/

BEGIN TRANSACTION;

select name, address from 
	(select portid, name, address, count(portid) as count 
		from service_subscribers natural join subscribers group by portid) 
		natural join (select count(scode) as count from services);

COMMIT;

/*

Empty Output
*/