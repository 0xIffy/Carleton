BEGIN TRANSACTION;

DROP TABLE IF EXISTS Employee;

CREATE TABLE Employee(
	fname text NOT NULL, 
	minit text,
	lname text NOT NULL,
	ssn integer primary key not null,
	bdate text NOT NULL,
	address text NOT NULL,
	sex text NOT NULL,
	salary integer NOT NULL,
	superssn integer,
	dno integer NOT NULL
);

DROP TABLE IF EXISTS Department;

CREATE TABLE Department(
	dname text NOT NULL, 
	dnumber integer primary key not null,
	mgrssn integer NOT NULL,
	mgrstardate text NOT NULL
);

DROP TABLE IF EXISTS Dept_Locations;

CREATE TABLE Dept_Locations(
	dnumber integer NOT NULL,
	dlocation text NOT NULL,
	primary key (dnumber, dlocation)
);

DROP TABLE IF EXISTS Project;

CREATE TABLE Project(
	pname text NOT NULL, 
	pnumber integer primary key not null,
	plocation text NOT NULL,
	dnum integer NOT NULL
);

DROP TABLE IF EXISTS Works_On;

CREATE TABLE Works_On(
	essn integer NOT NULL, 
	pno integer NOT NULL,
	hours real,
	primary key (essn, pno)
);


DROP TABLE IF EXISTS Dependent;

CREATE TABLE Dependent(
	essn integer NOT NULL, 
	dependent_name text NOT NULL,
	sex text NOT NULL,
	bdate text NOT NULL,
	relationship text NOT NULL,
	primary key (essn, dependent_name)
);

INSERT INTO Employee VALUES('John', 'B', 'Smith', 123456789, '9-Jan-55', '731 Fondern', 'M', 30000, 333445555, 5);
INSERT INTO Employee VALUES('Franklin', 'T', 'Wong', 333445555, '8-Dec-45', '638 Voss', 'M', 40000, 888665555, 5);
INSERT INTO Employee VALUES('Alicia', 'J', 'Zelaya', 999887777, '19-Jul-58', '3321 Castle', 'F', 25000, 987987987, 4);
INSERT INTO Employee VALUES('Jennifer', 'S', 'Wallace', 987654321, '20-Jun-31', '291 Berry', 'F', 43000, 888665555, 4);
INSERT INTO Employee VALUES('Ramesh', 'K', 'Narayan', 666884444, '15-Sep-52', '975 Fire Oak', 'M', 38000, 333445555, 5);
INSERT INTO Employee VALUES('Joyce', 'A', 'English', 435453453, '31-Jul-62', '5631 Rice', 'F', 25000, 333445555, 5);
INSERT INTO Employee VALUES('Ahmad', 'V', 'Jabber', 987987987, '29-Mar-59', '980 Dallas', 'M', 25000, 987654321, 4);
INSERT INTO Employee (fname, minit, lname, ssn, bdate, address, sex, salary, dno) VALUES('James', 'E', 'Borg', 888665555, '10-Nov-27', '450 Stone', 'M', 55000, 1);

INSERT INTO Department VALUES('Research', 5, 333445555, '22-May-78');
INSERT INTO Department VALUES('Administration', 4, 987654321, '1-Jan-85');
INSERT INTO Department VALUES('Headquarters', 1, 888665555, '19-Jun-71');

INSERT INTO Dept_Locations VALUES(1, 'Houston');
INSERT INTO Dept_Locations VALUES(2, 'Stafford');
INSERT INTO Dept_Locations VALUES(5, 'Bellaire');
INSERT INTO Dept_Locations VALUES(5, 'Sugarland');
INSERT INTO Dept_Locations VALUES(5, 'Houston');

INSERT INTO Works_On VALUES(123456789, 1, 32.50);
INSERT INTO Works_On VALUES(123456789, 2, 7.50);
INSERT INTO Works_On VALUES(666884444, 3, 40.00);
INSERT INTO Works_On VALUES(453453453, 1, 20.00);
INSERT INTO Works_On VALUES(453453453, 2, 20.00);
INSERT INTO Works_On VALUES(333445555, 2, 10.00);
INSERT INTO Works_On VALUES(333445555, 3, 10.00);
INSERT INTO Works_On VALUES(333445555, 10, 10.00);
INSERT INTO Works_On VALUES(333445555, 20, 10.00);
INSERT INTO Works_On VALUES(999887777, 30, 30.00);
INSERT INTO Works_On VALUES(999887777, 10, 10.00);
INSERT INTO Works_On VALUES(987987987, 10, 35.00);
INSERT INTO Works_On VALUES(987987987, 30, 5.00);
INSERT INTO Works_On VALUES(987654321, 30, 20.00);
INSERT INTO Works_On VALUES(987654321, 20, 15.00);
INSERT INTO Works_On VALUES(888665555, 20, NULL);

INSERT INTO Project VALUES('ProjectX', 1, 'Bellaire', 5);
INSERT INTO Project VALUES('ProjectY', 2, 'Sugarland', 5);
INSERT INTO Project VALUES('ProjectZ', 3, 'Houston', 5);
INSERT INTO Project VALUES('Computerization', 10, 'Stafford', 4);
INSERT INTO Project VALUES('Reorganization', 20, 'Houston', 1);
INSERT INTO Project VALUES('NewBenefits', 30, 'Stafford', 4);

INSERT INTO Dependent VALUES(333445555, 'Alice', 'F', '5-Apr-76', 'Daughter');
INSERT INTO Dependent VALUES(333445555, 'Theodore', 'M', '25-Oct-73', 'Son');
INSERT INTO Dependent VALUES(333445555, 'Joy', 'F', '3-May-48', 'Spouse');
INSERT INTO Dependent VALUES(987654321, 'Abner', 'M', '29-Feb-32', 'Spouse');
INSERT INTO Dependent VALUES(123456789, 'Michael', 'M', '1-Jan-78', 'Son');
INSERT INTO Dependent VALUES(123456789, 'Alice', 'F', '31-Jan-78', 'Daughter');
INSERT INTO Dependent VALUES(123456789, 'Elizabeth', 'F', '5-MAy-57', 'Spouse');

END TRANSACTION;