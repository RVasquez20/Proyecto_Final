using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Printing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BarcodeLib;
using System.Windows.Forms;

namespace CODIGO_DE_BARRAS
{   
    public partial class Form1 : Form
    {
        private Font printFont;
        public Form1()
        {
            InitializeComponent();
        }
private void button1_Click(object sender, EventArgs e)
        {
           

        }
        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            string variable = Path.GetDirectoryName(Application.ExecutablePath);
            variable = variable + "\\imprimir.txt";
            StreamReader leer = new StreamReader(@variable);
            string linea;
            linea = leer.ReadLine();
            BarcodeLib.Barcode Codigo = new BarcodeLib.Barcode();
            Codigo.IncludeLabel = true;
            panel1.BackgroundImage = Codigo.Encode(BarcodeLib.TYPE.CODE128, linea, Color.Black, Color.White, 200, 100);
        }
        private void button2_Click(object sender, EventArgs e)
        {
            
        }

        private void printDocument1_PrintPage(object sender, System.Drawing.Printing.PrintPageEventArgs e)
        {
            string variable = Path.GetDirectoryName(Application.ExecutablePath);
            variable = variable + "\\imprimir.txt";
           
            Bitmap bm = new Bitmap(panel1.BackgroundImage.Width, panel1.BackgroundImage.Height);
            printFont = new Font("Courier", 9);
            panel1.DrawToBitmap(bm, new Rectangle(0, 0, panel1.BackgroundImage.Width, panel1.BackgroundImage.Height));
            e.Graphics.DrawImage(bm, 0, 0);
            StreamReader leer = new StreamReader(@variable);
            string linea;
            int a=0;
            try
            {
                linea = leer.ReadLine();
                linea = leer.ReadLine();
                while (linea != null)
                {
                    a = a + 1;
                    if (a == 1)
                    {
                        e.Graphics.DrawString(linea + "\n", printFont, Brushes.Black, 30, 100);
                    }
                    if (a == 2)
                    {
                        e.Graphics.DrawString(linea + "\n", printFont, Brushes.Black, 70, 113);
                    }
                    linea = leer.ReadLine();
                }
            }
            catch
            {
                MessageBox.Show("ERROR");
            }
            bm.Dispose();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            StreamReader leer = new StreamReader(@"C:\Users\USUARIO\Desktop\PROYECTO PROGRAMACION I\imprimir.txt");
            string linea;
            try
            {
                linea = leer.ReadLine();
                while (linea!= null)
                {
                    linea = leer.ReadLine();
                }
            }
            catch
            {
                MessageBox.Show("ERROR");
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            if (printDialog1.ShowDialog() == DialogResult.OK)
            {
                printDocument1.Print();
            }
            this.Close();
        }
        private void pictureBox1_MouseHover(object sender, EventArgs e)
        {
            pictureBox1.Size = new Size(75, 76);
        }
        private void pictureBox1_MouseLeave(object sender, EventArgs e)
        {
            pictureBox1.Size = new Size(100, 101);
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
