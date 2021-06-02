BEGIN TRANSACTION;

DELETE FROM cds WHERE contributer = '101143403';

INSERT INTO cds VALUES('101143403CD1','Christmas Interpretations','Boys II Men','Jheryl Busby and Michael Bivins',1993,'101143403');
INSERT INTO cds VALUES('101143403CD2','A LaFace Family Christmas','various artists','Antonio "L.A." Reid and Kenny "Babyface" Edmonds',1993,'101143403');

DELETE FROM songs WHERE contributer = '101143403';

INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Let it Snow','Brian McKnight and Wanya Morris','101143403CD1',1,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Share Love','Nathan Morris','101143403CD1',2,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('You''re Not Alone','Shawn Stockman','101143403CD1',3,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('A Joyous Song','Shawn Stockman','101143403CD1',4,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Why Christmas','Wanya Morris','101143403CD1',5,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Cold December Nights','Michael McCary and Shawn Stockman','101143403CD1',6,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Do They Know','Nathan Morris','101143403CD1',7,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Who Would Have Thought','Brian McKnight and Wanya Morris','101143403CD1',8,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Silent Night','F. Gruber and J. Mohr','101143403CD1',9,'101143403');

INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Silver Bells','Raymond B. Evans and  James Livingston','101143403CD2',1,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Christmas Song, The','Mel Torme and Robert Wells','101143403CD2',2,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Sleigh Ride','Leroy Anderson and Mitchell Parrish','101143403CD2',3,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Player''s Ball','Outkast and Organized Noize','101143403CD2',4,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Interlude: Joy All Day','Tim Thomas and Ted Bishop','101143403CD2',5,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Have Yourself A Merry Little Christmas','Ralph Blane and Hugh Martin','101143403CD2',6,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('This Christmas','Donny Hathaway and Nadine McKinnor','101143403CD2',8,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Merry Christmas My Dear','Darryl Simmons','101143403CD2',9,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('Interlude: Christmas To Here','Tim Thomas and Ted Bishop','101143403CD2',10,'101143403');
INSERT INTO songs (title, composer, cd_id, track, contributer) VALUES('All I Want For Christmas','Organized Noise, Brandon Bennett, Marquez Ethridge, Lisa Lopez','101143403CD2',7,'101143403');

END TRANSACTION;