
.mode column
.headers on
.echo on

/*
Write an SQL query that would find if the line with phone number (613) 712-0024 is currently available to take a call because its channel is IDLE. Rev 1: That is, select the portid, directory number, and channel state of line (613) 712-0024.
*/

BEGIN TRANSACTION;

select portid, areacode, officecode, stationcode, state 
	from (channels natural join lines) 
	where (areacode="613") and (officecode="712") and (stationcode="0024");

COMMIT;

/*

portid      areacode    officecode  stationcode  state     
----------  ----------  ----------  -----------  ----------
24          613         712         0024         BUSY      
*/