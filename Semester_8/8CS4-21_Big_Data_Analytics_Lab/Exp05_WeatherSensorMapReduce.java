// Exp 5: MapReduce Mining Semi-Structured Weather Sensor Logs (Year -> Max Temp)
import java.io.IOException;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;

public class Exp05_WeatherSensorMapReduce {
    public static class WeatherMapper extends Mapper<LongWritable, Text, Text, IntWritable> {
        public void map(LongWritable key, Text value, Context ctx) throws IOException, InterruptedException {
            // Format: YYYY-MM-DD,CITY,TEMP_C
            String[] parts = value.toString().split(",");
            if (parts.length >= 3) {
                String year = parts[0].substring(0, 4);
                int temp = Integer.parseInt(parts[2].trim());
                ctx.write(new Text(year), new IntWritable(temp));
            }
        }
    }
    public static class MaxTempReducer extends Reducer<Text, IntWritable, Text, IntWritable> {
        public void reduce(Text key, Iterable<IntWritable> values, Context ctx) throws IOException, InterruptedException {
            int maxT = Integer.MIN_VALUE;
            for (IntWritable v : values) maxT = Math.max(maxT, v.get());
            ctx.write(key, new IntWritable(maxT));
        }
    }
}
