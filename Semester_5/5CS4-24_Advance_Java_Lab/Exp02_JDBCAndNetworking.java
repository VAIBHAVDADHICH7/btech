// Module 2: JDBC Database Query & Java Socket Client Reference
import java.sql.*;
import java.net.*;
import java.io.*;

public class Exp02_JDBCAndNetworking {
    public static void queryStudents(String url, String user, String pass) throws SQLException {
        try (Connection con = DriverManager.getConnection(url, user, pass);
             PreparedStatement ps = con.prepareStatement("SELECT student_id, full_name FROM Students");
             ResultSet rs = ps.executeQuery()) {
            while (rs.next()) {
                System.out.println(rs.getInt(1) + ": " + rs.getString(2));
            }
        }
    }

    public static void fetchHttpHeader(String host, int port) throws IOException {
        try (Socket s = new Socket(host, port);
             PrintWriter out = new PrintWriter(s.getOutputStream(), true);
             BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()))) {
            out.println("HEAD / HTTP/1.1\r\nHost: " + host + "\r\nConnection: close\r\n");
            System.out.println(in.readLine());
        }
    }

    public static void main(String[] args) {
        System.out.println("Configure JDBC driver & DB URL to run queryStudents().");
    }
}
