-- Exp 5: Aggregate Functions MAX, MIN, AVG, COUNT with GROUP BY & HAVING
SELECT dept_id,
       COUNT(*) AS total_students,
       MAX(cgpa) AS highest_cgpa,
       MIN(cgpa) AS lowest_cgpa,
       ROUND(AVG(cgpa), 2) AS avg_cgpa
FROM Students
GROUP BY dept_id
HAVING AVG(cgpa) >= 7.50;
