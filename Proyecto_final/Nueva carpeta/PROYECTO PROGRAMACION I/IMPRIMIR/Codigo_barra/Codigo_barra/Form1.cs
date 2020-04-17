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

namespace Codigo_barra
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            BarcodeLib.Barcode Codigo = new BarcodeLib.Barcode();
            Codigo.IncludeLabel = true;
            Panel_resultado.BackgroundImage = Codigo.Encode(BarcodeLib.TYPE.CODE39, Txtcodigo.Text, Color.Black, Color.White, 400, 100);
            btnguardar.Enabled = true;
        }

        private void btnguardar_Click(object sender, EventArgs e)
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
        }
    }
}
