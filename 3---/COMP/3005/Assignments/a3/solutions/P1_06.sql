
.mode column
.headers on
.echo on

/*
 Produce a table that lists the most popular service (or services). That is, give the name of the service that has the most subscribers.
*/

BEGIN TRANSACTION;
select name from 
	(select name, max(count) as count from 
		(select services.service as name, count(distinct portid) as count from 
			service_subscribers join services on (scode=service_subscribers.service) 
			group by services.service));

COMMIT;

/*

name              
--------------
Message Answer 
*/