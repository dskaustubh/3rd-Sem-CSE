import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="testb2" width=400 height=400></applet>
*/
class testb2 extends Applet implements ActionListener
{
    Label l1,l2,l3;
    TextField t1,t2,t3;
    Button a,s,m,d;
    public void init()
    {
        l1=new Label("Enter 1st number! ");
        l2=new Label("ENter 2nd Number! ");
        add(l1);
        add(l2);
        a=new Button("+");
        s=new Button("-");
        m=new Button("*");
        d=new Button("/");
        add(a);
        add(s);
        add(m);
        add(d);
        a.addActionListener(this);
        s.addActionListener(this);
        m.addActionListener(this);
        d.addActionListener(this);
    }
    public void actionPerformed(ActionEvent ae)
    {
        String s=ae.getActionCommand();
        int x,y,r;
        x=Integer.parseInt(t1.getText());
        y=Integer.parseInt(t2.getText());
        if(s.equals("+"))
        {
            r=x+y;
        }
        else if(s.equals("-"))
        {
            r=x-y;
        }
        else if(s.equals("*"))
        {
            r=x*y;
        }
        else
        {
            r=x/y;
        }
        t3.setText(String.valueOf(r));
    }
}