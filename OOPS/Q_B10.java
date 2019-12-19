interface add
{
    int sum(int x,int y);
}
interface pro
{
    int mul(int x,int y);
}
class testb10
{
    public static void main(String[] args) {
        add a=(int x,int y)->
        {
            return x+y;
        };
        pro p=(int x,int y)->{
            return x*y;
        };
        System.out.println(a.sum(5,7));
        System.out.println(p.mul(5, 8));
    }
}