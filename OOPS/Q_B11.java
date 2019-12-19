class convert
{
    String a;
    void seta(String b)
    {
        a=b;
        a=a.toUpperCase();
        System.out.println(a);
        countdouble();

    }
    void countdouble()
    {
        int i,c=0;
        char b[]=new char[a.length()];
        b=a.toCharArray();
        for(i=0;i<a.length()-1;i++)
        {
            if(b[i]==b[i+1])
            {
                c++;
            }
        }
        System.out.println("NUmber of Double letter sequences are: "+c);
    }
    
}
class check
{
    public static void main(String[] args) {
        String s=new String();
        s="SHE WAS FEEDING THE LITTLE RABBIT WITH AN APPLE";
        convert c=new convert();
        c.seta(s);
    }
}