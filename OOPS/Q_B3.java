import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="testb3" width=400 height=400></applet>
*/
class testb3 extends Applet
{
    public void init()
    {
        TextField t=new TextField();
        add(t);
        addKeyListener(new KeyAdapter(){
            int n=0;
            char k;
            public void keyTyped(KeyEvent ke)
            {
                int v;
                k=ke.getKeyChar();
                if(k=='R')
                {
                    showStatus(Integer.reverse(n));
                    n=0;
                }
                else
                {
                    v=Integer.parseInt(String.valueOf(k));
                    n=(n*10)+v;
                }

            }
        });
    }
}