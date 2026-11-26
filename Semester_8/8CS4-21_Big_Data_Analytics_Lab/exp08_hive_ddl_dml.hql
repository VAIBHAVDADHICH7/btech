-- Exp 8: Apache Hive (Database, Table, View, Function, Index)
CREATE DATABASE IF NOT EXISTS bda_lab;
USE bda_lab;

CREATE TABLE IF NOT EXISTS sales (
    txn_id INT,
    city STRING,
    amount DOUBLE
) ROW FORMAT DELIMITED FIELDS TERMINATED BY ',' STORED AS TEXTFILE;

ALTER TABLE sales ADD COLUMNS (category STRING);

CREATE VIEW IF NOT EXISTS high_value_sales AS
SELECT city, SUM(amount) AS total_sales FROM sales GROUP BY city HAVING SUM(amount) > 10000;

SHOW FUNCTIONS;
DROP VIEW IF EXISTS high_value_sales;
