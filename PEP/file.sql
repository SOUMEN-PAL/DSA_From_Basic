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

