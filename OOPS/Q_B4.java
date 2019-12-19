import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="testmouse" width=400 height=400></applet>
*/
class testmouse extends Applet
{
    String msg="";
    public void init()
    {
        addMouseListener(new MouseAdapter(){
            public void mouseClicked(MouseEvent me)
            {
                msg="Welcome";
                repaint();
            }
            public void mouseReleased(MouseEvent me)
            {
                msg="GoodBye!!";
                repaint();
            }
        });
    }
    public void paint(Graphics g)
    {
        g.drawString(msg,getX(),getY());
    }
}