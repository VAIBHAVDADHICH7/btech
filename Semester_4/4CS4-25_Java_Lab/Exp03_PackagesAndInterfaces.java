// Exp 3: Interfaces and Access Modifiers
interface Payable {
    double calculatePay();
}

class Contractor implements Payable {
    private final int hours;
    private final double rate;
    Contractor(int hours, double rate) { this.hours = hours; this.rate = rate; }
    @Override public double calculatePay() { return hours * rate; }
}

public class Exp03_PackagesAndInterfaces {
    public static void main(String[] args) {
        Payable p = new Contractor(40, 500.0);
        System.out.println("Total Pay: Rs." + p.calculatePay());
    }
}
