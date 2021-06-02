
.mode column
.headers on
.echo on

/*
List the names of all the subscribers who are originators of a call to someone who is also a subscriber on the same switch (i.e. a line to line call)
*/

BEGIN TRANSACTION;

select name from 
	(select orig as portid from (
		(select call_id from lines join calls on (calls.orig = portid) 
		
		INTERSECT 
		
		select call_id from lines join calls on (calls.term = portid)) 
	natural join calls)) 
natural join subscribers;

COMMIT;

/*

name       
-----------
Mats Sundin
Jason Allis
Homer Simps
Michael Jor
Ed Belfour
*/