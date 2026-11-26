// Exp 4: String/StringBuffer and Exception Handling
public class Exp04_StringsAndExceptions {
    static void validateAge(int age) throws IllegalArgumentException {
        if (age < 18) throw new IllegalArgumentException("Age must be >= 18");
    }

    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("RTU");
        sb.append(" Java Lab").reverse();
        System.out.println("Reversed StringBuffer: " + sb);

        try {
            validateAge(16);
        } catch (IllegalArgumentException e) {
            System.out.println("Caught Exception: " + e.getMessage());
        } finally {
            System.out.println("Finally block executed.");
        }
    }
}
