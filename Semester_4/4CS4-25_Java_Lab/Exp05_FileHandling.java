// Exp 5: Java File I/O Streams
import java.io.*;

public class Exp05_FileHandling {
    public static void main(String[] args) throws IOException {
        String file = "java_lab_io.txt";
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(file))) {
            bw.write("Core Java File Handling\nSemester IV - 4CS4-25\n");
        }
        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = br.readLine()) != null) System.out.println(line);
        }
    }
}
