class NameException extends Exception
{
    NameException()
    {
        super("Name Cannot be a number!! ");
    }
}
class AgeException extends Exception
{
    AgeException()
    {
        super("Invalid Age Exception!!");
    }
    
}
class Employee
{
    int age;
    String name;
    Employee(int a,String n)
    {
        age=a;
        name=n;
    }
    
}
class testb5
{
    static boolean isnum(String s)
    {
        try
        {
            int n=Integer.parseInt(s);
            return true;
        }
        catch(Exception e)
        {
            return false;
        }
    }
    public static void main(String[] args) throws AgeException,NameException{
        String name=new String();
        int age;
        name="Eden";
        age=60;
        if(age>50)
        {
            try
            {
                throw new AgeException();
            }
            catch(Exception e)
            {
                System.out.println(e.getMessage());
                
            }
            
        }
        else if(isnum(name))
        {
            throw new NameException();
        }
        else
        {
            Employee e=new Employee(age, name);
            System.out.println("Created Employee!! ");
        }
    }
}