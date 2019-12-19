abstract class Student
    {
        private String name;
        protected String ID;
        double grade;
        public int age;
        Student(String n,String i,double g,int a)
        {
            name = n;
            ID = i;
            grade = g;
            age = a;
        }
        abstract boolean isPassed(double grade);
    }
    class Grad extends Student
    {
        
        Grad(String name,String ID,double grade,int age)
        {
            super(name,ID,grade,age);
        }
        boolean isPassed(double grade)
        {
            if(grade>80.0)
                return true;
            else
                return false;
        }
    }
    class Undergrad extends Student
    {
        Undergrad(String name,String ID,double grade,int age)
        {
            super(name,ID,grade,age);
        }
        boolean isPassed(double grade)
        {
            if(grade>70.0)
                return true;
            else
                return false;
        }
    }

class testA3
{
	public static void main(String[] args) {
	    Grad g = new Grad("John","Q123",83.5,26);
	    Undergrad u = new Undergrad("Jack","W123",74.6,20);
	    if(g.isPassed(83.5))
	        System.out.println("Graduate Passed");
	    if(u.isPassed(74.6))
	        System.out.println("Undergraduate Passed");
	       
	}
}