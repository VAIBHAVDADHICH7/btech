// Exp 1(b): First Name & Last Name Matcher
public class Exp01b_NameMatcher {
    public static boolean matches(String first, String last, String expectedFull) {
        if (first == null || last == null || expectedFull == null) return false;
        return (first.trim() + " " + last.trim()).equalsIgnoreCase(expectedFull.trim());
    }
    public static void main(String[] args) {
        System.out.println("Match: " + matches("Vaibhav", "Dadhich", "vaibhav dadhich"));
    }
}
