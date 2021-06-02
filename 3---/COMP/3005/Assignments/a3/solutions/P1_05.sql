
.mode column
.headers on
.echo on

/*
Find the names of all the subscribers who subscribe to at least three services.
*/

BEGIN TRANSACTION;

select name from 
	(select portid, name, address, count(portid) as count from 
		service_subscribers natural join subscribers group by portid) 
		where count >= 3;

COMMIT;

/*

name          
--------------
Michael Jordan
Joe Carter    
Homer Simpson 
Vince Carter  
Chris Pronger 
Frank Thomas  
Steve Sampras 
Matt Stajan  
*/