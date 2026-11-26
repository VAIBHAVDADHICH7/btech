// Exp 1(f): Password Validation (Match + Strength Criteria)
public class Exp01f_PasswordValidator {
    public static boolean isValid(String p1, String p2) {
        if (p1 == null || !p1.equals(p2) || p1.length() < 8) return false;
        boolean hasUpper = false, hasDigit = false;
        for (char c : p1.toCharArray()) {
            if (Character.isUpperCase(c)) hasUpper = true;
            if (Character.isDigit(c)) hasDigit = true;
        }
        return hasUpper && hasDigit;
    }
    public static void main(String[] args) {
        System.out.println("Valid: " + isValid("Secure99", "Secure99"));
    }
}
