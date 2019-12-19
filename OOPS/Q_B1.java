class AT extends Thread
{
    public void run()
    {
        for(int i=1;i<6;i=i+2)
        {
            System.out.println("From A: "+i);
        }
    } 
}
class BT extends Thread
{
    int n,r=0;
    BT(int n)
    {
        this.n=n;
    }
    public void run()
    {
        int num=n;
        while(num!=0)
        {
            num=num/10;
            r=r*10+num;
        }
        System.out.println("From B: "+r);
    }
}
class testb1
{
   public static void main(String[] args) {
      AT a=new AT();
      BT b=new BT(1234);
      a.start();
      b.start();
    }
}