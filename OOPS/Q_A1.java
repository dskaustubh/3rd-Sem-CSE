import java.util.*;

abstract class Vehicle 
{
    boolean hashelmet;
    int year;

    abstract public void getData();

    abstract public void putData();
}

class Two extends Vehicle 
{
    private String brand;
    protected double cost;
    String engine;
    public String color;

    Two(boolean has, int yr) 
    {
        hashelmet = has;
        year = yr;
    }

    Two()
    {
        year = 0;
        hashelmet = true;
    }

    public void getData() 
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the data: ");
        System.out.println("Brand: ");
        brand = scan.next();
        System.out.println("Cost: ");
        cost = scan.nextDouble();
        System.out.println("Engine type: ");
        engine = scan.next();
        System.out.println("Color: ");
        color = scan.next();
    }

    public void putData() 
    {
        System.out.println("Brand: " + brand + "\tCost: " + cost + "\tEngine type: " + engine + "\tColor: " + color);
    }

}

final class Four extends Vehicle 
{
    Four(boolean has, int yr) 
    {
        hashelmet = has;
        year = yr;
    }

    Four() 
    {
        year = 0;
        hashelmet = true;
    }

    public void getData() 
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the data: ");
        System.out.println("Year of manufacture: ");
        year = scan.nextInt();
    }

    public void putData() 
    {
        System.out.println("Year of manufacture: " + year);
    }
}

class MyTwo extends Two 
{
    String owner;
    String c;
    double co;
    String eng;
    int y;
    boolean hh;

    MyTwo(String owner, Two obj) 
    {
        this.owner = owner;
        co = super.cost;
        y = super.year;
        hh = super.hashelmet;
        c = super.color;
        eng = super.engine;
    }
}

public class testa1 
{
    public static void main(String[] args) 
    {
        Two obj1 = new Two(true, 2001);
        Four obj2 = new Four(false, 1998);
        obj1.getData();
        obj2.getData();
        obj1.putData();
        obj2.putData();
        MyTwo obj3 = new MyTwo("Ramesh", obj1);
    }
}