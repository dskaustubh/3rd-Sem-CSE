class testb12
{
    public static void main(String[] args) {
        Thread t1=new Thread();
        Thread t2=new Thread();
        Thread t3=new Thread();
        Thread t4=new Thread();
        Thread t5=new Thread();
        t1.setPriority(6);
        t2.setPriority(4);
        t3.setPriority(9);
        t4.setPriority(2);
        t5.setPriority(10);
        t1.start();
        System.out.println("isAlive(t1): "+t1.isAlive());
        t2.start();
        System.out.println("isAlive(t2): "+t2.isAlive());
        t3.start();
        try
        {
            t3.sleep(1500);
        }
        catch(Exception e)
        {
            System.out.println("Caught!");
        }
        System.out.println("isAlive(t3): "+t3.isAlive());
        t4.start();
        System.out.println("isAlive(t4): "+t4.isAlive());
        t5.start();
        try
        {
            t5.sleep(1500);
        }
        catch(Exception e)
        {
            System.out.println("Caught!");
        }
        System.out.println("isAlive(t5): "+t5.isAlive());
    

    }
}