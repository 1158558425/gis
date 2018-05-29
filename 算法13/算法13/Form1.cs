using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 算法13
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //定义画笔
            Pen mypen = new Pen(Color.Blue, 3);
            Graphics g = this.CreateGraphics();
            g.Clear(Color.White);


            double PI = 3.1415926535897;
            double x0 = Convert.ToDouble(textBox1.Text), y0 = Convert.ToDouble(textBox3.Text), R = Convert.ToDouble(textBox2.Text);
            List<Point> points = new List<Point>();
            Point p = new Point();
            p.X = Convert.ToInt32(x0);
            p.Y = Convert.ToInt32(y0);
            double ANG1 = 0;
            double ANG2 = 800*PI;
            double AG1 = 0.01745 * ANG1;
            double AG2 = 0.01745 * ANG2;
            double temp1 = Math.Abs(AG2 - AG1);
            double temp2 = Math.Acos(1 - 1.018 / R);
            double N = temp1 / temp2 + 1;
            double DA = (AG2 - AG1) / N;
            for(int i = 0;i<N; i++)
            {
                double W = AG1 + i * DA;
                p.X =Convert.ToInt32( x0 + R * Math.Cos(W));
                p.Y = Convert.ToInt32(y0 + R * Math.Sin(W));
                points.Add(p);
            }
            g.DrawPolygon(mypen, points.ToArray());
        }
    }
}
