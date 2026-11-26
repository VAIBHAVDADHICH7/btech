-- Exp 3: ALTER, UPDATE, and DELETE Operations
ALTER TABLE Students ADD COLUMN phone VARCHAR(15);
ALTER TABLE Students MODIFY COLUMN full_name VARCHAR(120) NOT NULL;

UPDATE Students SET cgpa = 9.25 WHERE student_id = 101;
DELETE FROM Students WHERE student_id = 109;
