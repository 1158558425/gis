using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 算法11
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();//定义一个图像
            g.DrawLine(Pens.Blue, 100.5F, 100.5F, 200.5F, 200.5F);
            g.DrawLine(Pens.Red, 200.5F, 200.5F, 500.5F, 200.5F);
            g.DrawLine(Pens.Purple, new Point(200, 200), new Point(300, 300));

            Pen RedPen = new Pen(Color.Plum, 5);
            g.DrawLine(RedPen, 400.5F, 100.5F, 200.5F, 200.5F);

            g.Clear(Color.Gray);
            Pen Green = new Pen(Color.Green, 5);
            Point p1 = new Point(100, 500);
            Point p2 = new Point(10, 50);
            g.DrawLine(Green, p1, p2);
            //Pen p1 = new(Brush)



        }

        private void DrawRect_Click(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            Pen RedPen = new Pen(Color.Red, 5);
            g.Clear(Color.Azure);
            g.DrawRectangle(RedPen, 0, 0, 300, 500);
            Pen bluepen = new Pen(Color.Blue, 1);
            g.DrawRectangle(bluepen, 3.5F,3.5F, 300.1F, 500.2F);
            Pen yellowPen = new Pen(Color.Yellow, 5);
            Rectangle R = new Rectangle(10, 10, 300, 500);
            g.DrawRectangle(bluepen, R);
            
           
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            Pen RedPen = new Pen(Color.Red, 2);
            g.Clear(Color.Azure);//用颜色清理屏幕
            g.DrawEllipse(RedPen, 200, 200, 500, 200);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            Pen RedPen = new Pen(Color.Red, 2);
            g.Clear(Color.Azure);
            PointF p1 = new PointF(200, 200);
            PointF p2 = new PointF(300, 200);
            PointF p3 = new PointF(200, 300);
            PointF p4 = new PointF(250, 350);
            PointF p5 = new PointF(300, 300);
            PointF[] points = { p1, p2, p3, p4, p5 };
            g.DrawPolygon(RedPen,points);
        }
    }
}
