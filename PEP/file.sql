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