package ProtectionProxy;

interface Drivable{
    void drive();
};


class Driver{
    protected Driver driver;
    public int age;
    public Driver(int age){
        this.age = age;
    }
};
class Car implements Drivable{
    protected Driver driver;
    public Car(Driver driver){
        this.driver = driver;
    }

    @Override
    public void drive() {
        System.out.println("Car beeing driven");
    }
};

class CarProxy extends Car{
    public CarProxy(Driver driver){
        super(driver);
    }
    @Override
    public void drive() {
        if(driver.age >= 16) super.drive();
        else System.out.println("Nope");
    }
}

class Demo{
    public static void main(String[] args) {
        Car car = new CarProxy(new Driver(18));
        Car car2=new CarProxy(new Driver(11));
        car.drive();
        car2.drive();
    }
}