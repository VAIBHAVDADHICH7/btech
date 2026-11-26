-- Exp 9: Insertion, Updation, and Deletion Operations
INSERT INTO Departments (dept_id, dept_name, building) VALUES
(1, 'Computer Science', 'Block A'),
(2, 'Electronics', 'Block B');

INSERT INTO Students (student_id, full_name, email, dept_id, cgpa) VALUES
(101, 'Aarav Sharma', 'aarav@college.edu', 1, 8.90),
(102, 'Diya Verma', 'diya@college.edu', 1, 9.35),
(103, 'Kabir Joshi', 'kabir@college.edu', 2, 8.10);

UPDATE Students SET cgpa = 9.05 WHERE student_id = 101;
DELETE FROM Students WHERE student_id = 103;
