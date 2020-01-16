import java.util.*;
import java.lang.*;

class Record 
{
    String[] name;
    int[] rank;

    Record(int num)
    {
        name = new String[num];
        rank = new int[num];
    }

    public void readval(Scanner sc) 
    {
        int i = 0;
        int n = rank.length;
        System.out.println("Enter the details: ");
        while (i < n) 
        {
            System.out.println("\nPerson " + (i + 1) + ": ");
            System.out.println("Name: ");
            name[i] = sc.next();
            System.out.println("Rank: ");
            rank[i] = sc.nextInt();
            i++;
        }
    }

    public void display()
    {
        int i = 0;
        int n = rank.length;
        System.out.println("\n");
        while (i < n) 
        {
            System.out.println("Name: " + name[i] + " Rank: " + rank[i]);
            i++;
        }
    }
}

class Rank extends Record 
{
    int index;

    Rank(int num) 
    {
        super(num);
        index = 0;
    }

    public void highest() 
    {
        int i = 0;
        int n = rank.length;
        int max = rank[0];
        while (i < n) 
        {
            if (max <= rank[i]) 
            {
                max = rank[i];
                index = i;
            }
            i++;
        }
    }

    public String toString() 
    {
        String s = "\nTOPMOST\nName: " + name[index] + " Rank: " + rank[index];
        return s;
    }
}

public class testa8
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of students: ");
        int n = sc.nextInt();
        Rank obj = new Rank(n);
        obj.readval(sc);
        obj.display();
        obj.highest();
        System.out.println(obj);
    }
}