class Faculty 
{
    public String name;
    private int basic;
    public double salary;

    public Faculty(int basic, String name)
    {
        this.basic = basic;
        this.name = name;
    }

    public String getDetails() 
    {
        return (name + " " + getSalary());
    }

    public double getSalary() 
    {
        salary = basic;
        return (salary);
    }
}

class AssistantProfessor extends Faculty 
{
    public int DA;

    public AssistantProfessor(int da, int b, String s) 
    {
        super(b, s);
        DA = da;
    }

    public double getSalary() 
    {
        return (super.getSalary() + ((super.getSalary() * DA) / 100));
    }

    public String getDetails() 
    {
        return (name + " " + getSalary());
    }
}

class AssociateProfessor extends AssistantProfessor 
{
    public int MedAllowance;

    public AssociateProfessor(int ma, int da, int b, String s) 
    {
        super(da, b, s);
        MedAllowance = ma;
    }

    public double getSalary() 
    {
        return (super.getSalary() + MedAllowance);
    }

    public String getDetails() 
    {
        return (name + " " + getSalary());
    }
}

class Professor extends AssociateProfessor 
{
    public int OtherAllowance;

    public Professor(int oa, int ma, int da, int b, String s) 
    {
        super(ma, da, b, s);
        OtherAllowance = oa;
    }

    public double getSalary() 
    {
        return (super.getSalary() + (OtherAllowance * 0.01 * super.getSalary()));
    }

    public String getDetails() 
    {
        return (name + " " + getSalary());
    }
}

public class testa10 
{
    public static void main(String[] args) {
        Professor p = new Professor(5, 3, 2, 60000, "AAAA");
        System.out.println(p.getSalary());
        System.out.println(p.getDetails());
    }
}