// Exp 1(a): Area and Perimeter of a Circle
public class Exp01a_CircleMetrics {
    public static double area(double r) {
        if (r < 0) throw new IllegalArgumentException("Negative radius");
        return Math.PI * r * r;
    }
    public static double perimeter(double r) {
        if (r < 0) throw new IllegalArgumentException("Negative radius");
        return 2 * Math.PI * r;
    }
    public static void main(String[] args) {
        System.out.printf("r=5 -> Area=%.2f, Perimeter=%.2f%n", area(5), perimeter(5));
    }
}
