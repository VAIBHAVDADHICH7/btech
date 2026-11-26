// Exp 1(e): Calculator Program (for Def-Use Graph & Coverage Analysis)
public class Exp01e_Calculator {
    public static double compute(double a, double b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/':
                if (b == 0) throw new ArithmeticException("Divide by zero");
                return a / b;
            default: throw new IllegalArgumentException("Unknown operator: " + op);
        }
    }
    public static void main(String[] args) {
        System.out.println("12 * 4 = " + compute(12, 4, '*'));
    }
}
