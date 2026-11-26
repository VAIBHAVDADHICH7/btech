-- Exp 8: Creating and Testing Triggers
CREATE TABLE StudentAuditLog (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    student_id INT,
    old_cgpa DECIMAL(4,2),
    new_cgpa DECIMAL(4,2),
    changed_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

DELIMITER //
CREATE TRIGGER trg_student_cgpa_update
AFTER UPDATE ON Students
FOR EACH ROW
BEGIN
    IF OLD.cgpa <> NEW.cgpa THEN
        INSERT INTO StudentAuditLog(student_id, old_cgpa, new_cgpa)
        VALUES (NEW.student_id, OLD.cgpa, NEW.cgpa);
    END IF;
END //
DELIMITER ;
