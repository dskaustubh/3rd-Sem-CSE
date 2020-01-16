package AdvMath;
import java.lang.Math;
public class Sum 
{
    public void sum(int x) 
    {
        System.out.println(Math.sin(x) + Math.cos(x) + Math.tan(x));
    }
}
package AdvMath;

public class Triples 
{
    public void display(int limit) 
    {
        int a, b, c = 0;
        int m = 2;
        while (c < limit) 
        {
            for (int n = 1; n < m; ++n) 
            {
                a = m * m - n * n;
                b = 2 * m * n;
                c = m * m + n * n;
                if (c > limit)
                    break;
                System.out.println(a + " " + b + " " + c);
            }
            m++;
        }
    }
}

import AdvMath.Sum;
import AdvMath.Triples;

public class testa12 
{
    public static void main(String[] args) 
    {
        Sum s = new Sum();
        s.sum(0);
        Triples t = new Triples();
        t.display(20);
    }
}
