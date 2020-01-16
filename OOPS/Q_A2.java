import java.util.*;
abstract class Shape
{
    String color;
    boolean filled;
    Shape()
    {
        color = "Green";
        filled = true;
    }
    Shape(boolean filled, String color)
    {
        this.filled = filled;
        this.color = color;
    }
    public boolean isFILLED()
    {
        return filled;
    }
    public String getColor()
    {
        return color;
    }
    public void setColor()
    {
        Scanner scan = new Scanner(System.in);
        color = scan.next();
    }

    public String toString()
    {
        if (filled == true)
            return "A Shape with color " + color + " is filled";
        else
            return "A Shape with color " + color + " is not filled";
    }

    abstract public double getArea();
}

class Circle extends Shape
{
    double radius;
    double area;

    Circle(double radius, boolean filled, String color)
    {
        super(filled, color);
        this.radius = radius;
    }

    Circle(double radius) 
    {
        this.radius = radius;
    }

    public double getArea() 
    {
        return 3.14 * radius * radius;
    }
}
class Rectangle extends Shape
{
    public double width;
    public double length;

    Rectangle(double w, double l, boolean filled, String color)
    {
        super(filled, color);
        length = l;
        width = w;
    }

    Rectangle(double w, double l)
    {
        length = l;
        width = w;
    }

    Rectangle(double w)
    {
        width = w;
        length = w;
    }

    public double getArea()
    {
        return width * length;
    }
}

class Square extends Rectangle {
    Square(double s) {
        super(s); 
    }
}

class testa2
{
    public static void main(String[] args) 
    {
        Circle obj1 = new Circle(23.5, true, "BLACK");
        Rectangle obj2 = new Rectangle(12, 13.5, false, "PINK");
        Square obj3 = new Square(25);
        double g;
        boolean f;
        System.out.println(obj1);
        System.out.println(obj2);
        System.out.println(obj3);
        System.out.println("Circle area= " + obj1.getArea());
        System.out.println("Rectangle area= " + obj2.getArea());
        System.out.println("Square area= " + obj3.getArea());
    }
}