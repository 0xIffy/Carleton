BEGIN TRANSACTION;

DROP TABLE IF EXISTS cds;
DROP TABLE IF EXISTS songs;

CREATE TABLE cdsTemp(
      cd_id text primary key not null, --cd unique id
      title text NOT NULL, --title of CD
      artist text NOT NULL, --artist whose CD it is or "various artists"
      producer text default NULL,
      year integer,
      contributer text --student number who contirbuted the data
      );

CREATE TABLE songsTemp(
      song_id integer primary key not null, --auto incrementing key
      title text NOT NULL, --title of song
      composer text NOT NULL, --person or persons who wrote the song
      cd_id text NOT NULL, --cd this song appears on
      track integer NOT NULL, --track number of the song
      contributer text --student number who contirbuted the data
      );

COMMIT;

.read myTunes_Abdelghny.sql

BEGIN TRANSACTION;

insert into cdsTemp select * from cds;
insert into songsTemp (title,composer,cd_id,track,contributer) select title,composer,cd_id,track,contributer from songs;
DROP TABLE IF EXISTS cds;
DROP TABLE IF EXISTS songs;

COMMIT;

.read myTunes_Ali.sql

BEGIN TRANSACTION;

insert into cdsTemp select * from cds;
insert into songsTemp (title,composer,cd_id,track,contributer) select title,composer,cd_id,track,contributer from songs;
DROP TABLE IF EXISTS cds;
DROP TABLE IF EXISTS songs;

COMMIT;

.read myTunes_Fatemeh.sql

BEGIN TRANSACTION;

insert into cdsTemp select * from cds;
insert into songsTemp (title,composer,cd_id,track,contributer) select title,composer,cd_id,track,contributer from songs;
DROP TABLE IF EXISTS cds;
DROP TABLE IF EXISTS songs;

COMMIT;

.read myTunes_Monica.sql

BEGIN TRANSACTION;

insert into cdsTemp select * from cds;
insert into songsTemp (title,composer,cd_id,track,contributer) select title,composer,cd_id,track,contributer from songs;
DROP TABLE IF EXISTS cds;
DROP TABLE IF EXISTS songs;

COMMIT;

.read myTunes_Rezieh.sql

BEGIN TRANSACTION;

insert into cdsTemp select * from cds;
insert into songsTemp (title,composer,cd_id,track,contributer) select title,composer,cd_id,track,contributer from songs;
DROP TABLE IF EXISTS cds;
DROP TABLE IF EXISTS songs;

COMMIT;

.read myTunes_Saman.sql

BEGIN TRANSACTION;

insert into cdsTemp select * from cds;
insert into songsTemp (title,composer,cd_id,track,contributer) select title,composer,cd_id,track,contributer from songs;
DROP TABLE IF EXISTS cds;
DROP TABLE IF EXISTS songs;


CREATE TABLE cds(
      cd_id text primary key not null, --cd unique id
      title text NOT NULL, --title of CD
      artist text NOT NULL, --artist whose CD it is or "various artists"
      producer text default NULL,
      year integer,
      contributer text --student number who contirbuted the data
      );

CREATE TABLE songs(
      song_id integer primary key not null, --auto incrementing key
      title text NOT NULL, --title of song
      composer text NOT NULL, --person or persons who wrote the song
      cd_id text NOT NULL, --cd this song appears on
      track integer NOT NULL, --track number of the song
      contributer text --student number who contirbuted the data
      );

insert into cds select * from cdsTemp;
insert into songs select * from songsTemp;
DROP TABLE IF EXISTS cdsTemp;
DROP TABLE IF EXISTS songsTemp;

COMMIT;