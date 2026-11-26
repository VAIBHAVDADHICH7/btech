#!/usr/bin/env bash
# Exp 3: HDFS File Management Tasks
hdfs dfs -mkdir -p /user/btech/input
hdfs dfs -put local_data.txt /user/btech/input/
hdfs dfs -ls /user/btech/input/
hdfs dfs -cat /user/btech/input/local_data.txt
hdfs dfs -get /user/btech/input/local_data.txt ./downloaded_data.txt
hdfs dfs -rm /user/btech/input/local_data.txt
