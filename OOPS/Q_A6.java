class Customer 
{
    int id;
    String name;
    int discount; 

    Customer(int id, String name, int discount) 
    {
        this.name = name;
        this.id = id;
        this.discount = discount;
    }

    public int getID() 
    {
        return id;
    }

    public String getName() 
    {
        return name;
    }

    public int getDiscount() 
    {
        return discount;
    }

    public void setDiscount(int discount) 
    {
        this.discount = discount;
    }

    public String toString() 
    {
        String s = name + "(" + id + ")";
        return s;
    }
}

class Invoice 
{
    int id;
    Customer customer;
    double amount;

    Invoice(int id, Customer customer, double amount) 
    {
        this.customer = new Customer(customer.id, customer.name, customer.discount);
        this.id = id;
        this.amount = amount;
    }

    public int getID() 
    {
        return id;
    }

    public Customer getCustomer() 
    {
        return customer;
    }

    public void setCustomer(Customer customer) 
    {
        this.customer = customer;
    }

    public double getAmount() 
    {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public String getCustomerName() 
    {
        return customer.name;
    }

    public double AmountAfterDiscount() 
    {
        return (amount - (double) (customer.discount / 100));
    }
}

public class testa6 
{
    public static void main(String[] args) 
    {
        Customer obj1 = new Customer(1, "KDS", 19);
        Invoice obj2 = new Invoice(1, obj1, 52.5);
        System.out.println("TESTING CUSTOMER CLASS: ");
        System.out.println(obj1.getID());
        obj1.setDiscount(29);
        System.out.println(obj1.getDiscount());
        System.out.println(obj1);
        System.out.println(obj1.getName());
        System.out.println("TESTING INVOICE CLASS: ");
        System.out.println(obj2.getID());
        System.out.println(obj2.getCustomerName());
        System.out.println(obj2.getCustomer());
        System.out.println(obj2.AmountAfterDiscount());

    }
}