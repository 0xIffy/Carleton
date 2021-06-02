.mode column
.headers on
.echo on

/*
Produce a table consisting of the names and addresses of the subscribers and their phone numbers.
*/

BEGIN TRANSACTION;

select name, address, areacode, officecode, stationcode from 
	subscribers natural join lines;

COMMIT;

/*

name         address       areacode    officecode  stationcode
-----------  ------------  ----------  ----------  -----------
Mats Sundin  45 Elgin St.  613         134         0001       
Jason Allis  46 Elgin St.  613         136         0002       
Eric Lindro  48 Elgin St.  613         156         0003       
Bryan MacCa  23 MacLeod S  613         220         0004       
Steve Nash   1129 Otterso  613         221         0005       
Michael Jor  1223 Carling  613         222         0006       
Roger Cleme  14 Hopewell   613         223         0007       
Jack Morris  23 Prince of  613         226         0008       
Roberto Alo  55 Moodie Dr  613         227         0009       
Joe Carter   18 Summerset  613         229         0010       
Wayne Grekz  45 Merviale.  613         310         0011       
George Bell  46 Colon By   613         322         0012       
Eric Staal   423 Riversid  613         333         0013       
Roy Hallada  23 Ogilvie R  613         334         0014       
Mario Lemie  1129 Bank Dr  613         389         0015       
Patrick Roy  1223 Greenba  613         457         0016       
Martin Brod  14 Baseline   613         489         0017       
Homer Simps  123 Prince o  613         523         0018       
Bart Simpso  155 Moodie D  613         568         0019       
Joe Johnson  21 Sussex Dr  613         578         0020       
Vince Carte  45 Hunt Club  613         623         0021       
Ed Belfour   46 Fisher St  613         645         0022       
Bobby Orr    48 Prince Ed  613         657         0023       
Bobby Hull   23 Wellingto  613         712         0024       
Gordie Howe  1129 Preston  613         728         0025       
Larry Bird   1223 Warden   613         798         0026       
Mark Messie  14 Finch Ave  416         219         0027       
Wade Redden  23 Steeles A  416         331         0028       
Sidney Cros  55 Sheppard   416         333         0029       
Peter Forsb  1 Kennedy Dr  416         334         0030       
Paul Kariya  45 Midland.   416         756         0031       
Rob Blake    12 19th Ave.  705         221         0032       
Chris Prong  48 16th Ave.  905         347         0033       
Gary Robert  23 John St.   905         657         0034       
Alex Mogily  1129 14th Av  905         819         0035       
Scott Gomez  1223 Montrea  819         223         0036       
Frank Thoma  14 Hull Ave.  819         227         0037       
Barry Bonds  23 Hood Rd.   705         221         0038       
Hank Aaron   55 Denison A  819         223         0039       
Babe Ruth    1 Old Kenned  819         227         0040       
Ted William  45 Birchmoun  905         347         0041       
Chris Bosh   46 Queens Av  905         657         0042       
Steve Sampr  448 St Clare  905         819         0043       
Kobe Bryan   23 Bayview S  416         219         0044       
Kevin Garne  59 Mike Myer  416         331         0045       
Larry Brown  99 Blue Jays  416         333         0046       
Brooke Shie  69 College A  416         334         0047       
Matt Stajan  50 LakeShore  416         756         0048       
Tie Domi     89 Spidina R  705         221         0049       
Tevor Kidd   30 McCowan A  819         227         0050 
*/
