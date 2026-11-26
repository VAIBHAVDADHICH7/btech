-- Exp 7: Apache Pig Latin Script (Filter, Group, Join, Project, Sort)
students = LOAD '/user/btech/students.csv' USING PigStorage(',') AS (id:int, name:chararray, dept_id:int, cgpa:float);
depts    = LOAD '/user/btech/depts.csv'    USING PigStorage(',') AS (dept_id:int, dept_name:chararray);

high_cgpa = FILTER students BY cgpa >= 8.0;
joined    = JOIN high_cgpa BY dept_id, depts BY dept_id;
projected = FOREACH joined GENERATE high_cgpa::name AS name, depts::dept_name AS dept, high_cgpa::cgpa AS cgpa;
sorted    = ORDER projected BY cgpa DESC;
grouped   = GROUP sorted BY dept;
DUMP sorted;
