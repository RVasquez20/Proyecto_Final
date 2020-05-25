using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using BarcodeLib;
using System.Drawing.Printing;
using System.IO;

namespace Codigo_barra
{
    public partial class Form1 : Form
    {
        private Font printFont;
        public Form1()
        {
            InitializeComponent();
        }

       /* private void btnguardar_Click(object sender, EventArgs e)
        {
            Image imgFinal = (Image)Panel_resultado.BackgroundImage.Clone();
            SaveFileDialog CajaDeDialogoGuardar = new SaveFileDialog();
            CajaDeDialogoGuardar.AddExtension = true;
            CajaDeDialogoGuardar.Filter = "Image PNG (*.png)|*.png";
            CajaDeDialogoGuardar.ShowDialog();
            if (!string.IsNullOrEmpty(CajaDeDialogoGuardar.FileName))
            {
                imgFinal.Save(CajaDeDialogoGuardar.FileName, System.Drawing.Imaging.ImageFormat.Png);
            }
            imgFinal.Dispose();
        }*/

        private void Panel_resultado_Paint(object sender, PaintEventArgs e)
        {
            string variable = Path.GetDirectoryName(Application.ExecutablePath);
            variable = variable + "\\imprimir.txt";
            StreamReader leer = new StreamReader(@variable);
            string linea;
            linea = leer.ReadLine();
            BarcodeLib.Barcode Codigo = new BarcodeLib.Barcode();
            Codigo.IncludeLabel = true;
            Panel_resultado.BackgroundImage = Codigo.Encode(BarcodeLib.TYPE.CODE39, linea, Color.Black, Color.White, 238, 100);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            /*   printDocument1 = new PrintDocument();
               PrinterSettings ps = new PrinterSettings();
               printDocument1.PrintPage += Imprimir;
               printDocument1.Print();
            if (printDialog1.ShowDialog() == DialogResult.OK)
            {
                printDocument1.Print();
            }
            this.Close();*/
        }

        private void Imprimir(Object sender, PrintPageEventArgs e)
        {
          // Font font = new Font("Arial",14,FontStyle.Regular, GraphicsUnit.Point);
            //e.Graphics.DrawString("Holaaaaa", font, Brushes.Black, new RectangleF(0, 10, 120, 20));
        }
        private void printDocument1_PrintPage(object sender, PrintPageEventArgs e)
        {
            string variable = Path.GetDirectoryName(Application.ExecutablePath);
            variable = variable + "\\imprimir.txt";

            Bitmap bm = new Bitmap(Panel_resultado.BackgroundImage.Width, Panel_resultado.BackgroundImage.Height);
            printFont = new Font("Courier", 9);
            Panel_resultado.DrawToBitmap(bm, new Rectangle(0, 0,Panel_resultado.BackgroundImage.Width, Panel_resultado.BackgroundImage.Height));
            e.Graphics.DrawImage(bm, 200, 50);
            StreamReader leer = new StreamReader(@variable);
            string linea;
            int a = 0;
            try
            {
                linea = leer.ReadLine();
                linea = leer.ReadLine();
                while (linea != null)
                {
                    a = a + 1;
                    if (a == 1)
                    {
                     //  e.Graphics.DrawString(linea + "\n", printFont, Brushes.Black, 150, 50);
                    }
                    if (a == 2)
                    {
                      //  e.Graphics.DrawString(linea + "\n", printFont, Brushes.Black, 150, 60);
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

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
