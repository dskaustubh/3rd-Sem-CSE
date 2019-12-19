class triangle
{
    void checktriangle(int a,int b,int c)
    {
        if((a<(b+c))&&(b<(a+c))&&(c<(b+a)))
        {
            calcarea(a,b,c);
        }
        else
        {
            System.out.println("Not a valid Triangle");
        }
    }
    void calcarea(int a,int b,int c)
    {
        System.out.println("Valid Triangle");
        double s=(a+b+c)/2;
        double area=Math.sqrt(s*(s-a)*(s-b)*(s-c));
        System.out.println("Area is: "+area);
    }
}
class test
{
    public static void main(String[] args) {
        triangle t=new triangle();
        t.checktriangle(3, 4, 5);
    }
}