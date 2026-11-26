-- Exp 4: INNER, LEFT, RIGHT, and CROSS Joins
SELECT s.student_id, s.full_name, d.dept_name
FROM Students s
INNER JOIN Departments d ON s.dept_id = d.dept_id;

SELECT s.student_id, s.full_name, d.dept_name
FROM Students s
LEFT JOIN Departments d ON s.dept_id = d.dept_id;

SELECT s.student_id, s.full_name, d.dept_name
FROM Students s
RIGHT JOIN Departments d ON s.dept_id = d.dept_id;
