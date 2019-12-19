class SIN extends Thread
{
    double x,r;
    SIN(double y)
    {
        x=y;
    }
    public void run()
    {
        r=Math.sin(x);
    }
}
class COS extends Thread
{
    double x,r;
    COS(double y)
    {
        x=y;
    }
    public void run()
    {
        r=Math.cos(x);
    }
}
class TAN extends Thread
{
    double x,r;
    TAN(double y)
    {
        x=y;
    }
    public void run()
    {
        r=Math.tan(x);
    }
}
class testb6
{
    public static void main(String[] args) {
        double x,y;
        x=(45.0/180)*Math.PI;
        TAN t=new TAN(x);
        COS c=new COS(x);
        SIN s=new SIN(x);
        t.start();
        c.start();
        s.start();
        try
        {
            t.join();
            c.join();
            s.join();
        }
        catch(Exception e)
        {

        }
        y=t.r+c.r+s.r;
        System.out.println("Answer is: "+y);
    }
}