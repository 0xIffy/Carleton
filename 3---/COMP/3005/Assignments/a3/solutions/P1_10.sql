.mode column
.headers on
.echo on

/*
Produce a table that lists the name of all the service-subscribers that subscribe to at least all the same services as Jason Allison subscribes to but possibly others as well. 
*/

BEGIN TRANSACTION;

select distinct name from 
	(subscribers natural join service_subscribers) s 
	where not exists 
		(select service from 
			service_subscribers natural join subscribers where name="Jason Allison" 
			
		except 
			
		select service from 
			service_subscribers natural join subscribers where name = s.name);

COMMIT;

/*

name         
-------------
Homer Simpson
Jason Allison
Joe Carter   
Matt Stajan  
Michael Jordan
*/