package mypack;
public class Student 
{
    String usn;
    String dept;
    char[] grades=new char[3];
    double sgpa;
    public Student(String usn, String dept, char[] grades, double sgpa)
    {
        this.grades=grades;
        this.usn=usn;
        this.sgpa=sgpa;
        this.dept=dept;
    }
    public void display()
    {
        System.out.println("USN: "+usn+"\tDept: "+dept+"\tSGPA: "+sgpa+"\nGrade 1: "+grades[0]+"\tGrade 2: "+grades[1]+"\tGrade 3: "+grades[2]);
    }
package mypack;
public class Staff
{
    String id;
    String name;
    String des;
    String subj;
    public Staff(String id, String name, String des, String subj)
    {
        this.subj=subj;
        this.name=name;
        this.des=des;
        this.id=id;
    }
    public void display()
    {
        System.out.println("Name: "+name+"\tDesignation: "+des+"\tStaff id: "+id+"\tSubject: "+subj);
    }
}
import mypack.Student; 
import mypack.Staff; 
import java.util.*;
public class testa11
{
    public static void main(String[] args) 
    {
        char[] ch=new char[3];
        ch[0]='A';
        ch[1]='B';
        ch[2]='C';
        Student stu=new Student("123","CSE",ch,45.5);
        Staff staff=new Staff("22","Antonio","Primary School","Math");
        stu.display();
        staff.display();
    }
}