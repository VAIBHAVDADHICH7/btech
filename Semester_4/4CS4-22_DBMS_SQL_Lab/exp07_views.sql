-- Exp 7: Creating and Querying Views
CREATE OR REPLACE VIEW HonorRollStudents AS
SELECT s.student_id, s.full_name, d.dept_name, s.cgpa
FROM Students s
JOIN Departments d ON s.dept_id = d.dept_id
WHERE s.cgpa >= 8.50;

SELECT * FROM HonorRollStudents ORDER BY cgpa DESC;
