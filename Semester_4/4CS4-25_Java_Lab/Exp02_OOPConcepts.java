// Exp 2: Classes, Constructors, Inheritance, super, final, Abstract Class
abstract class Vehicle {
    final String brand;
    Vehicle(String brand) { this.brand = brand; }
    abstract void start();
}

class Car extends Vehicle {
    Car(String brand) { super(brand); }
    @Override void start() { System.out.println(brand + " Car started."); }
    void honk() { System.out.println("Beep!"); }
    void honk(int times) { System.out.println("Beep x" + times); }
}

public class Exp02_OOPConcepts {
    public static void main(String[] args) {
        Car c = new Car("Tata");
        c.start();
        c.honk();
        c.honk(2);
    }
}
