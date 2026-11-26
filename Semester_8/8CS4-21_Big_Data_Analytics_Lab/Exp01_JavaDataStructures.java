// Exp 1: LinkedList, Stack, Queue, Set, and Map in Java
import java.util.*;

public class Exp01_JavaDataStructures {
    public static void main(String[] args) {
        LinkedList<String> ll = new LinkedList<>(Arrays.asList("Hadoop", "Spark"));
        Stack<Integer> st = new Stack<>(); st.push(10); st.push(20);
        Queue<String> q = new LinkedList<>(); q.add("Job1"); q.add("Job2");
        Set<String> set = new HashSet<>(Arrays.asList("HDFS", "YARN", "HDFS"));
        Map<String, Integer> map = new HashMap<>(); map.put("Hive", 1); map.put("Pig", 2);

        System.out.println("LinkedList: " + ll);
        System.out.println("Stack pop : " + st.pop());
        System.out.println("Queue poll: " + q.poll());
        System.out.println("Set       : " + set);
        System.out.println("Map       : " + map);
    }
}
