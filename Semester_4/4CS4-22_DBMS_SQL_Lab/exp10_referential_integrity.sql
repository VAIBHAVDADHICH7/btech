-- Exp 10: Referential Integrity (ON DELETE CASCADE / ON UPDATE CASCADE)
CREATE TABLE Enrollments (
    enroll_id INT PRIMARY KEY,
    student_id INT NOT NULL,
    course_code VARCHAR(10) NOT NULL,
    grade CHAR(2),
    FOREIGN KEY (student_id) REFERENCES Students(student_id)
        ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (course_code) REFERENCES Courses(course_code)
        ON DELETE RESTRICT ON UPDATE CASCADE
);
