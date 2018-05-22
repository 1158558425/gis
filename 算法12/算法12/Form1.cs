using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 算法12
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Pen mypen = new Pen(Color.Blue, 3);
            Graphics g = this.CreateGraphics();
            g.Clear(Color.White);

            double PI = 3.1415926535897;
            double x0 = Convert.ToDouble(textBox1.Text), y0 = Convert.ToDouble(textBox3.Text), R1 = Convert.ToDouble(textBox2.Text);
            double R2 = R1 * 0.38196;
            double ANG = PI / 2 - PI / 5;
            List<Point> points = new List<Point>();
            Point p = new Point();
            p.X = Convert.ToInt32(x0);
            p.Y = Convert.ToInt32(y0 + R1);
            points.Add(p);
            for(int i = 1; i < 10; i++)
            {
                if(i % 2 == 0)
                {
                    p.X = Convert.ToInt32(x0 + R1 * Math.Cos(ANG));
                    p.Y = Convert.ToInt32(y0 + R1 * Math.Sin(ANG));
                }
                else
                {
                    p.X = Convert.ToInt32(x0 + R2 * Math.Cos(ANG));
                    p.Y = Convert.ToInt32(y0 + R2 * Math.Sin(ANG));
                }
                points.Add(p);
                ANG -= PI / 5;
            }
            g.DrawPolygon(mypen, points.ToArray());
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Pen mypen = new Pen(Color.Blue, 3);
            Graphics g = this.CreateGraphics();
            g.Clear(Color.White);

            double PI = 3.1415926535897;
            double x0 = Convert.ToDouble(textBox1.Text), y0 = Convert.ToDouble(textBox3.Text), R1 = Convert.ToDouble(textBox2.Text);
            int N = 100;
            double ANG = PI / 2;
            double DW = 2 * PI / N;
            double W0 = 0.01745 * ANG - (PI + DW) / 2;
            List<Point> points = new List<Point>();
            Point p = new Point();
            for(int i = 0;i < N; i++)
            {
                double W = W0 + i * DW;
                p.X = Convert.ToInt32(x0 + R1 * Math.Cos(W));
                p.Y = Convert.ToInt32(y0 + R1 * Math.Sin(W));
                points.Add(p);
            }
            g.DrawPolygon(mypen, points.ToArray());
        }
    }
}
