-- Mini Project: Complete College Management System Schema & Reporting Queries
CREATE DATABASE IF NOT EXISTS cms_project;
USE cms_project;

CREATE TABLE Department (
    dept_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(80) NOT NULL UNIQUE
);

CREATE TABLE Faculty (
    faculty_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    dept_id INT NOT NULL,
    FOREIGN KEY (dept_id) REFERENCES Department(dept_id)
);

CREATE TABLE Student (
    student_id INT AUTO_INCREMENT PRIMARY KEY,
    roll_no VARCHAR(20) NOT NULL UNIQUE,
    name VARCHAR(100) NOT NULL,
    dept_id INT NOT NULL,
    semester INT CHECK (semester BETWEEN 1 AND 8),
    FOREIGN KEY (dept_id) REFERENCES Department(dept_id)
);

CREATE TABLE Course (
    course_id VARCHAR(12) PRIMARY KEY,
    title VARCHAR(100) NOT NULL,
    dept_id INT NOT NULL,
    faculty_id INT,
    credits INT DEFAULT 3,
    FOREIGN KEY (dept_id) REFERENCES Department(dept_id),
    FOREIGN KEY (faculty_id) REFERENCES Faculty(faculty_id)
);

CREATE TABLE Enrollment (
    student_id INT,
    course_id VARCHAR(12),
    marks DECIMAL(5,2) CHECK (marks BETWEEN 0 AND 100),
    PRIMARY KEY (student_id, course_id),
    FOREIGN KEY (student_id) REFERENCES Student(student_id) ON DELETE CASCADE,
    FOREIGN KEY (course_id) REFERENCES Course(course_id) ON DELETE CASCADE
);
