// Exp 1(c): Quadratic Equation Solver (a*x^2 + b*x + c = 0)
public class Exp01c_QuadraticSolver {
    public static String solve(double a, double b, double c) {
        if (a == 0) return "Not a quadratic equation";
        double d = b * b - 4 * a * c;
        if (d > 0) return String.format("Real & Distinct: %.2f, %.2f", (-b + Math.sqrt(d))/(2*a), (-b - Math.sqrt(d))/(2*a));
        if (d == 0) return String.format("Real & Equal: %.2f", -b / (2 * a));
        return "Complex Roots";
    }
    public static void main(String[] args) {
        System.out.println(solve(1, -5, 6));
    }
}
