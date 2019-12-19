class convert8
{
    String a;
    void seta(String b)
    {
        a=b;
        a=a.toLowerCase();
        System.out.println(a);
        replacevowels();

    }
    void replacevowels()
    {
        int i,k;
        char b[]=new char[a.length()];
        b=a.toCharArray();

        for(i=0;i<a.length();i++)
        {
            if(b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u')
            {
                k=b[i];
                b[i]=(char)(k+1);
            }
        }
        System.out.println("The New String is : "+String.valueOf(b));
    }
    
}
class test8
{
    public static void main(String[] args) {
        String s=new String();
        s="Computer";
        convert8 c=new convert8();
        c.seta(s);
    }
}