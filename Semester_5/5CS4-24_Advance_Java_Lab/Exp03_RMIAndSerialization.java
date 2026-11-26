// Module 3: RMI Remote Interface, Object Serialization & i18n
import java.rmi.*;
import java.rmi.server.*;
import java.io.*;
import java.util.*;

interface Adder extends Remote {
    int add(int a, int b) throws RemoteException;
}

class AdderImpl extends UnicastRemoteObject implements Adder {
    AdderImpl() throws RemoteException { super(); }
    public int add(int a, int b) { return a + b; }
}

class StudentDTO implements Serializable {
    private static final long serialVersionUID = 1L;
    String name; int sem;
    StudentDTO(String name, int sem) { this.name = name; this.sem = sem; }
}

public class Exp03_RMIAndSerialization {
    public static void main(String[] args) throws Exception {
        StudentDTO s = new StudentDTO("Aarav", 5);
        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        try (ObjectOutputStream oos = new ObjectOutputStream(bos)) { oos.writeObject(s); }
        try (ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(bos.toByteArray()))) {
            StudentDTO copy = (StudentDTO) ois.readObject();
            System.out.println("Deserialized: " + copy.name + " (Sem " + copy.sem + ")");
        }
        Locale loc = new Locale("en", "IN");
        System.out.println("Locale: " + loc.getDisplayCountry());
    }
}
