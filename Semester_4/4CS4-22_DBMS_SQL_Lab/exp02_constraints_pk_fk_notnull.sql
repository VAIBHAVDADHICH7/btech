-- Exp 2: Apply PRIMARY KEY, FOREIGN KEY, NOT NULL, UNIQUE, CHECK Constraints
CREATE TABLE Departments (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50) NOT NULL UNIQUE,
    building VARCHAR(50) NOT NULL
);

CREATE TABLE Students (
    student_id INT PRIMARY KEY,
    full_name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    dept_id INT NOT NULL,
    cgpa DECIMAL(4,2) CHECK (cgpa BETWEEN 0.00 AND 10.00),
    FOREIGN KEY (dept_id) REFERENCES Departments(dept_id)
);
