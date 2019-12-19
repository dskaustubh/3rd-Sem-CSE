class mul
{
    synchronized void computetable(int n)
    {
        for(int i=1;i<=10;i++)
        {
            System.out.println(n+" * "+i+" = "+n*i);
            try
            {
                Thread.sleep(1000);
            }
            catch(Exception e)
            {
                System.out.println("Caught!");
            }
        }
    }
}
class callmul extends Thread
{
    mul m1;
    int n;
    callmul(mul m2,int v)
    {
        n=v;
        m1=m2;
    }
    public void run()
    {
        m1.computetable(n);
    }

}
class testb9
{
    public static void main(String[] args) {
        mul m1=new mul();
        callmul t1=new callmul(m1,5);
        callmul t2=new callmul(m1,7);
        t1.start();
        t2.start();
    }
}