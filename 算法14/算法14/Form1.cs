using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 算法14
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        bool selectpt = false;
        List<Point> points = new List<Point>();
        
        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            if (selectpt != true) return;
            if (e.Button == MouseButtons.Left)
            {
                Point p = new Point(e.X, e.Y);
                points.Add(p);
            }
            if(e.Button == MouseButtons.Right)
            {
                Point p = points[0];
                points.Add(p);
            }
            Pen blue = new Pen(Color.Blue, 3);
            Graphics g = this.CreateGraphics();
            if(points.Count > 1)
            {
                for(int i = 0; i< points.Count - 1; i++)
                {
                    g.DrawLine(blue, points[i], points[i + 1]);
                }
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if (selectpt == false) selectpt = true;
            else selectpt = false;
        }
        List<Point> points1 = new List<Point>();
        private void button2_Click(object sender, EventArgs e)
        {
            if (points.Count == 0) MessageBox.Show("请先选点！", "提示！");
            else
            {
                Point p = new Point();
                p = points[0];
                points1.Add(p);
                for(int i = 1; i< points.Count - 1; i++)
                {
                    if(i % 2 == 0)
                    {
                        p = points[i];
                        points1.Add(p);
                    }
                }
                int n = points.Count;
                p = points[n - 1];
                points1.Add(p);
                Pen red = new Pen(Color.Red,3);
                Graphics g = this.CreateGraphics();
                g.DrawLines(red, points1.ToArray());
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            List<Point> points2 = new List<Point>();
            if (points.Count == 0) MessageBox.Show("请先选点！", "提示！");
            else
            {
                Point p = new Point();
                p = points[0];
                points2.Add(p);
                for (int i = 1; i < points.Count - 1; i++)
                {
                    double dis;
                    int count = points2.Count;
                    dis = ppdistance(points[i], points2[count - 1]);
                    if(dis > 150.000)
                    {
                        p = points[i];
                        points2.Add(p);
                    }
                }
                int n = points.Count;
                p = points[n - 1];
                points2.Add(p);
                Pen green = new Pen(Color.Green, 3);
                Graphics g = this.CreateGraphics();
                g.DrawLines(green, points2.ToArray());
            }
        }

        private double ppdistance(Point point1, Point point2)
        {
            double dis;
            dis = Math.Sqrt((point1.X - point2.X)* (point1.X - point2.X) + (point1.Y - point2.Y) * (point1.Y - point2.Y));
            return dis;
        }

        private void button4_Click(object sender, EventArgs e)
        {

            List<Point> points3 = new List<Point>();
            Point p = new Point();
            p = points[0];
            points3.Add(p);
            double dis = 50;
            int n;
            for (int i = 1; i < points.Count - 1; i++)
            {
                double dist;
                n = points3.Count;
                dist = f_distance(points[i],points3[n-1],points[i+1]);
                if (dist > dis)
                {
                    p = points[i];
                    points3.Add(p);
                }
            }
            n = points.Count;
            p = points[n - 1];
            points3.Add(p);
            Pen yellow = new Pen(Color.Yellow, 3);
            Graphics g = this.CreateGraphics();
            g.DrawLines(yellow, points3.ToArray());
        }

        private double f_distance(Point p1, Point p2, Point p3)
        {
            double dis;
            double temp1, temp2;
            temp1 = (p3.Y - p1.Y) * p2.X + (p1.X - p3.X) * p2.Y + (p3.X * p1.Y - p1.X * p3.Y);
            temp2 = Math.Sqrt((p1.X - p3.X)*(p1.X - p3.X) + (p1.Y - p3.Y)*(p1.Y - p3.Y));
            dis = temp1 / temp2;
            return dis;
        }
    }
}
