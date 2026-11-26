-- Exp 11: Creating Users and Assigning Roles (DCL)
CREATE ROLE IF NOT EXISTS 'faculty_role', 'student_role';

GRANT SELECT, INSERT, UPDATE ON college_db.Students TO 'faculty_role';
GRANT SELECT ON college_db.HonorRollStudents TO 'student_role';

CREATE USER IF NOT EXISTS 'prof_mehta'@'localhost' IDENTIFIED BY 'StrongPass#123';
GRANT 'faculty_role' TO 'prof_mehta'@'localhost';
SET DEFAULT ROLE 'faculty_role' TO 'prof_mehta'@'localhost';
