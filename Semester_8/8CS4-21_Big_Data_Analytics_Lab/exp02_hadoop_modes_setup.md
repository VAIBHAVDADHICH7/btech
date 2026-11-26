# Exp 2: Hadoop Installation & Three Operating Modes
1. **Standalone (Local) Mode**: Default configuration; runs as a single Java process without HDFS daemons.
2. **Pseudo-Distributed Mode**: Single node running NameNode, DataNode, ResourceManager, NodeManager (`core-site.xml`: `fs.defaultFS=hdfs://localhost:9000`, `hdfs-site.xml`: `dfs.replication=1`).
3. **Fully-Distributed Mode**: Multi-node cluster with dedicated master/workers listed in `$HADOOP_HOME/etc/hadoop/workers`.
