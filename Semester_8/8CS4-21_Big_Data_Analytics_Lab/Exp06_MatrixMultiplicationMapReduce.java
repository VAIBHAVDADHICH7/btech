// Exp 6: Matrix Multiplication in Hadoop MapReduce (A: MxN, B: NxP)
import java.io.IOException;
import java.util.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;

public class Exp06_MatrixMultiplicationMapReduce {
    public static class MatMapper extends Mapper<LongWritable, Text, Text, Text> {
        public void map(LongWritable key, Text value, Context ctx) throws IOException, InterruptedException {
            // Input: A,i,j,val or B,j,k,val (assuming 2x2 matrices)
            String[] p = value.toString().split(",");
            int M = 2, P = 2;
            if (p[0].equals("A")) {
                for (int k = 0; k < P; k++) ctx.write(new Text(p[1] + "," + k), new Text("A," + p[2] + "," + p[3]));
            } else {
                for (int i = 0; i < M; i++) ctx.write(new Text(i + "," + p[2]), new Text("B," + p[1] + "," + p[3]));
            }
        }
    }
    public static class MatReducer extends Reducer<Text, Text, Text, DoubleWritable> {
        public void reduce(Text key, Iterable<Text> values, Context ctx) throws IOException, InterruptedException {
            Map<Integer, Double> a = new HashMap<>(), b = new HashMap<>();
            for (Text t : values) {
                String[] p = t.toString().split(",");
                if (p[0].equals("A")) a.put(Integer.parseInt(p[1]), Double.parseDouble(p[2]));
                else b.put(Integer.parseInt(p[1]), Double.parseDouble(p[2]));
            }
            double sum = 0.0;
            for (int j : a.keySet()) sum += a.get(j) * b.getOrDefault(j, 0.0);
            ctx.write(key, new DoubleWritable(sum));
        }
    }
}
