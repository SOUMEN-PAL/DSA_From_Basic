--create a table of employee with the following fields emp id name dept and suitable afeilds

create DATABASE PEP;
use PEP;
CREATE TABLE employee(
    emp_id INT PRIMARY KEY,
    name VARCHAR(50),
    dept INT,
    age INT
);

-- create a department table with the following fields dept id dept name and the departments can have value CSE ECE Mech Civil

CREATE TABLE department(
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50)
);

-- add a foreign key to the employee table with the dept field referencing the dept id of the department table

ALTER TABLE employee
ADD FOREIGN KEY (dept) REFERENCES department(dept_id);

desc employee;
DESC department;

-- insert values into the department table with dept name cse , ECE , Mech<Civil

INSERT INTO department VALUES(1,'CSE');
INSERT INTO department VALUES(2,'ECE');
INSERT INTO department VALUES(3,'Mech');
INSERT INTO department VALUES(4,'Civil');


select dept_id,dept_name from department;

-- insert values into the employee table with emp id 1 name as 'A' dept as 'CSE' and age as 25 , then B then C with different age and dept

INSERT INTO employee VALUES(1,'A',1,25);
INSERT INTO employee VALUES(2,'B',2,26);
INSERT INTO employee VALUES(3,'C',3,27);

select * from employee;

-- add a new row in employee table with emp id 4 name as 'D' dept as 'Civil' and age as 28

INSERT INTO employee VALUES(5,'D',5,28);

-- so add a new DEPT in the department table as 'IT'

INSERT INTO department VALUES(5,'IT');

-- now add in employee table date of joining and its data type is DATE

ALTER TABLE employee
ADD date_of_joining DATE;

-- now add some different dates for all the existing employees

UPDATE employee SET date_of_joining = '2021-01-01' WHERE emp_id = 1;
UPDATE employee SET date_of_joining = '2021-01-02' WHERE emp_id = 2;
UPDATE employee SET date_of_joining = '2021-01-03' WHERE emp_id = 3;
UPDATE employee SET date_of_joining = '2021-01-04' WHERE emp_id = 4;
UPDATE employee SET date_of_joining = '2021-01-05' WHERE emp_id = 5;

SELECT * FROM employee;


-- now increase the size of varchar of name to 100 in employee table

ALTER TABLE employee
MODIFY name VARCHAR(100);

SELECT * FROM employee;


-- create a table student with rg no , Name , address , attendence and marks

CREATE TABLE student(
    rg_no INT PRIMARY KEY,
    name VARCHAR(50),
    address VARCHAR(100),
    attendence INT,
    marks INT
);

-- insert values into the student table with rg no 1 , 2, 3 4, 5, ,6 and Name A B C D E F and address with Guriugram, Noida, Delhi, Ghaziabad, Faridabad, Meerut and attendence and marks with 60,50,70,60,80,70,90,80,99,90,95,100 respectively.   

INSERT INTO student VALUES(1,'A','Gurugram',60,50);
INSERT INTO student VALUES(2,'B','Noida',70,60);
INSERT INTO student VALUES(3,'C','Delhi',80,70);
INSERT INTO student VALUES(4,'D','Ghaziabad',90,80);
INSERT INTO student VALUES(5,'E','Faridabad',99,90);
INSERT INTO student VALUES(6,'F','Meerut',95,100);

SELECT * FROM student;

SELECT rg_no , name FROM student WHERE attendence > 70;

--Students who live in delhi

SELECT rg_no , name FROM student WHERE address = 'Delhi';

--Students who lives in noida and attendence is greater than 40

SELECT rg_no , name FROM student WHERE address = 'Noida' AND attendence > 40;

-- name of students who lives in noida or delhi

SELECT name FROM student WHERE address = 'Noida' OR address = 'Delhi';

-- studens who live in cities other than delhi

SELECT * FROM student WHERE address != 'Delhi';

-- students who have attendence greater than 70 and less than 80 and marks less than 75

SELECT * FROM student WHERE attendence > 60 AND attendence < 80 AND marks < 75;

-- use between to do the same

SELECT * FROM student WHERE attendence BETWEEN 60 AND 80 AND marks < 75;

-- students who belog to noida having attendence 80 and marks between 80 to 90

SELECT * FROM student WHERE address = 'Noida' AND attendence = 80 AND marks BETWEEN 80 AND 90;

-- add a new attribute date of addmission in student table

ALTER TABLE student
ADD date_of_addmission DATE;

-- add some dates for the students

UPDATE student SET date_of_addmission = '2021-01-01' WHERE rg_no = 1;
UPDATE student SET date_of_addmission = '2021-01-02' WHERE rg_no = 2;
UPDATE student SET date_of_addmission = '2021-01-03' WHERE rg_no = 3;
UPDATE student SET date_of_addmission = '2021-01-04' WHERE rg_no = 4;
UPDATE student SET date_of_addmission = '2021-01-05' WHERE rg_no = 5;
UPDATE student SET date_of_addmission = '2021-01-06' WHERE rg_no = 6;

SELECT * FROM student;

-- increase the size of address to 200

ALTER TABLE student
MODIFY address VARCHAR(200);

SELECT * FROM student;


-- all the students from noida cahnge the date of addmisson to 13 may 2024

UPDATE student SET date_of_addmission = '2024-05-13' WHERE address = 'Noida';


-- address where the first letter is G

SELECT * FROM student WHERE address LIKE 'G%';

-- address ehre 4th cahracter is I

SELECT * FROM student WHERE address LIKE '___i%';

-- column name whch ad id in it

SELECT * FROM student WHERE name LIKE '%nc%';

-- find the names of students who lives out side delhi and having marks more than 75

SELECT name FROM student WHERE address != 'Delhi' AND marks > 75;



use PEP;

--print the students whose city name ends with I

SELECT * FROM student WHERE address LIKE '%i';

-- id lies between 3 - 7

SELECT * FROM student WHERE rg_no BETWEEN 3 AND 7;

--students not from noida

SELECT * FROM student WHERE address != 'Noida';

-- example  of aggregrate functions

SELECT COUNT(*) FROM student;

SELECT AVG(marks) FROM student;

SELECT SUM(marks) FROM student;

SELECT MAX(marks) FROM student;

SELECT MIN(marks) FROM student;

SELECT COUNT(DISTINCT address) FROM student;

SELECT COUNT(DISTINCT address) FROM student WHERE marks > 75;

SELECT COUNT(DISTINCT address) FROM student WHERE marks > 75 AND attendence > 70;

SELECT COUNT(DISTINCT address) FROM student WHERE marks > 75 OR attendence > 70;

SELECT COUNT(DISTINCT address) FROM student WHERE marks > 75 AND attendence > 70;

SELECT COUNT(DISTINCT address) FROM student WHERE marks > 75 AND attendence > 70 AND address = 'Noida';

SELECT COUNT(DISTINCT address) FROM student WHERE marks > 75 AND attendence > 70 AND address = 'Noida' OR address = 'Delhi';

SELECT COUNT(DISTINCT address) FROM student WHERE marks > 75 AND attendence > 70 AND address = 'Noida' AND address = 'Delhi';

SELECT COUNT(DISTINCT address) FROM student WHERE marks > 75 AND attendence > 70 AND address = 'Noida' AND address = 'Delhi' OR address = 'Ghaziabad';

--date of admission who has maximum marks

SELECT date_of_addmission FROM student WHERE marks = (SELECT MAX(marks) FROM student);

--detail of studen who have more than average marks

SELECT * FROM student WHERE marks > (SELECT AVG(marks) FROM student);



SELECT count(*) FROM student WHERE marks > (SELECT AVG(marks) FROM student);

--naem sof student less than max marks

SELECT name FROM student WHERE marks < (SELECT MAX(marks) FROM student);

-- name of student scored more than max marks in noida

SELECT name FROM student WHERE marks > (SELECT MAX(marks) FROM student) AND address = 'Noida';


--average marks of studens from Noida mathura and RAchi

SELECT AVG(marks) FROM student WHERE address = 'Noida' OR address = 'Mathura' OR address = 'Rachi';

--average marks of student who do not belong to amritsar

SELECT AVG(marks) FROM student WHERE address != 'Amritsar';

-- avg marks of student not from amritsar and having attendence more than 70

SELECT AVG(marks) FROM student WHERE address != 'Amritsar' AND attendence > 70;

--details of students who have koined after 2021

SELECT * FROM student WHERE date_of_addmission > '2021-01-01';

--Insert some values with address Jalandhar amritsar and mathura with random date of admission

INSERT INTO student VALUES(7,'G','Jalandhar',60,50,'2021-01-07');
INSERT INTO student VALUES(8,'H','Amritsar',70,60,'2021-01-08');
INSERT INTO student VALUES(9,'I','Mathura',80,70,'2021-01-09');


SELECT * FROM student;

-- add another attribute section in student table

ALTER TABLE student
ADD section VARCHAR(10);

-- add some values in section

UPDATE student SET section = 'A' WHERE rg_no = 1;
UPDATE student SET section = 'B' WHERE rg_no = 2;
UPDATE student SET section = 'B' WHERE rg_no = 3;
UPDATE student SET section = 'D' WHERE rg_no = 4;
UPDATE student SET section = 'A' WHERE rg_no = 5;
UPDATE student SET section = 'B' WHERE rg_no = 6;
UPDATE student SET section = 'G' WHERE rg_no = 7;
UPDATE student SET section = 'H' WHERE rg_no = 8;
UPDATE student SET section = 'I' WHERE rg_no = 9;

SELECT * FROM student;

-- select student from section b

SELECT * FROM student WHERE section = 'B';

--example of group by

SELECT address , COUNT(*) FROM student GROUP BY address;

--Groupby section

SELECT section , COUNT(*) FROM student GROUP BY section;

--name of sections where students have marks more than average marks

SELECT section FROM student WHERE marks > (SELECT AVG(marks) FROM student) GROUP BY section;

--names of student got more than average marks obtained among 3 sections



SELECT name FROM student WHERE marks > (SELECT AVG(marks) FROM student) GROUP BY name;

--no of student from different cities in each section

SELECT address , section , COUNT(*) FROM student GROUP BY address , section;

--who has maximum marks in each section

SELECT section , MAX(marks) FROM student GROUP BY section;


--max marks in each section this max marks is more than the average marks

SELECT section , MAX(marks) FROM student WHERE marks > (SELECT AVG(marks) FROM student) GROUP BY section;

--createa two table employee and department with the following fields EmpID , EmployeeName , DeptName and in Dapartment table DeptID , DeptName add EmpId as primary key and DeptId as foreign key

create DATABASE Company;
use Company;


CREATE TABLE employee(
    EmpID INT PRIMARY KEY,
    EmployeeName VARCHAR(50),
    DeptName INT
);

-- add foreign key of DeptName in employee table to DeptID in department table

CREATE TABLE department(
    DeptID INT PRIMARY KEY,
    DeptName VARCHAR(50)
);

ALTER TABLE employee
ADD FOREIGN KEY (DeptName) REFERENCES department(DeptID);


--insert values in department table with dept name as CSE , ECE , Mech , Civil

INSERT INTO department VALUES(1,'CSE');
INSERT INTO department VALUES(2,'ECE');
INSERT INTO department VALUES(3,'Mech');
INSERT INTO department VALUES(4,'Civil');

SELECT * FROM department;

--insert values in employee table with EmpID 1 , 2 , 3 , 4 , 5 , 6 and EmployeeName as A , B , C , D , E , F and DeptName as 1 , 2 , 3 , 4 , 1 , 2

INSERT INTO employee VALUES(1,'A',1);
INSERT INTO employee VALUES(2,'B',2);
INSERT INTO employee VALUES(3,'C',3);
INSERT INTO employee VALUES(4,'D',4);
INSERT INTO employee VALUES(5,'E',1);
INSERT INTO employee VALUES(6,'F',2);

SELECT * FROM employee;


--use cross join

SELECT * FROM employee CROSS JOIN department;

--use inner join

SELECT * FROM employee INNER JOIN department ON employee.DeptName = department.DeptID;

--use left join

SELECT * FROM employee LEFT JOIN department ON employee.DeptName = department.DeptID;

--use right join

SELECT * FROM employee RIGHT JOIN department ON employee.DeptName = department.DeptID;


--teacher teaching in cse and ECE department

SELECT * FROM employee WHERE DeptName = 1 OR DeptName = 2;

--working in CSE department

SELECT * FROM employee WHERE DeptName = 1;

SELECT employee.EmployeeName , department.DeptName FROM employee Right JOIN department ON employee.DeptName = department.DeptID;



CREATE DATABASE School;
use School;

DROP TABLE student;

--create a table student with following column name ID int , Name carchar , Section varchar , City varchar , MArks ans Int

CREATE TABLE student(
    ID INT PRIMARY KEY,
    Name VARCHAR(50),
    Section VARCHAR(10),
    City VARCHAR(50),
    Marks INT
);

--insert values in student table with ID 1 , 2 , 3 , 4 , 5 , 6 and Name A , B , C , D , E , F and Section A , B , C , D , A , B and City as Delhi , Noida , Ghaziabad , Faridabad , Meerut , Gurgaon and Marks as 60 , 70 , 80 , 90 , 100 , 95

INSERT INTO student VALUES(1,'A','A','Delhi',83);
INSERT INTO student VALUES(2,'B','B','Noida',84);
INSERT INTO student VALUES(3,'C','C','Ghaziabad',85);
INSERT INTO student VALUES(4,'D','D','Faridabad',86);
INSERT INTO student VALUES(5,'E','A','Meerut',87);
INSERT INTO student VALUES(6,'F','B','Gurgaon',89);
-- add few more

INSERT INTO student VALUES(7,'G','C','Mathura',95);
INSERT INTO student VALUES(8,'H','D','Agra',96);



SELECT * FROM student;


--average marks of the student who have more than the avergae marks

SELECT AVG(Marks) FROM student WHERE Marks > (SELECT AVG(Marks) FROM student);

--find out the city who has the maximum of the   average marks

SELECT City FROM student WHERE Marks = (SELECT MAX(Marks) FROM student WHERE Marks > (SELECT AVG(Marks) FROM student));         

--using group by

SELECT City
FROM student
GROUP BY City
HAVING AVG(Marks) = (
    SELECT MAX(avg_marks)
    FROM (
        SELECT AVG(Marks) AS avg_marks
        FROM student
        GROUP BY City
    ) AS subquery
);



--average marks of the students who obtained from Noida and Meerut