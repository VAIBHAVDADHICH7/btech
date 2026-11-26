// Exp 7: Mini-Application — Electricity Billing System
public class Exp07_MiniApp_ElectricityBilling {
    static double computeBill(int units) {
        if (units <= 100) return units * 4.5;
        if (units <= 300) return 100 * 4.5 + (units - 100) * 6.5;
        return 100 * 4.5 + 200 * 6.5 + (units - 300) * 8.0;
    }

    public static void main(String[] args) {
        int units = 350;
        System.out.printf("Consumer Units: %d | Total Bill: Rs. %.2f%n", units, computeBill(units));
    }
}
