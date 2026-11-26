-- Exp 1: Design Database and Create Tables (College Database)
CREATE DATABASE IF NOT EXISTS college_db;
USE college_db;

CREATE TABLE Departments (
    dept_id INT,
    dept_name VARCHAR(50),
    building VARCHAR(50)
);

CREATE TABLE Students (
    student_id INT,
    full_name VARCHAR(100),
    dept_id INT,
    cgpa DECIMAL(4,2),
    admission_year INT
);
