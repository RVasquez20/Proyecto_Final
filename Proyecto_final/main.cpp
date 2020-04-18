#include<librerias.h>
char CT = 203, LTI = 204, H = 205, CRUZ = 206, CB = 202, EIA = 201, EIB = 200, LTD = 185, V = 186, EDA = 187, EDB = 188;
#define ARAR cout << EIA << H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<<EDA << endl;
#define AREN cout << LTI << H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<< LTD << endl;
#define ARENBJ  cout << LTI  << H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<<LTD<< endl;
#define ABJ cout << EIB  << H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<<EDB<< endl;
#define arriva cout << LTI << H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<CT<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<<LTD << endl;
#define separador cout << LTI << H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<CRUZ<< H<< H<< H<< H<< H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<< LTD << endl;
#define abajo cout << LTI  << H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<CB<< H<< H<< H<< H<< H<< H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<<LTD<< endl;
struct Marcas{
int idMarca;
char NombreMarca[50];
};
struct Productos{
int idProducto,idMarca;
char DescripcionProducto[100];
double PrecioCosto,PrecioVenta;
};
struct Clientes{
int NIT;
char NombreCliente[50],DireccionCliente[50];
};
struct Factura{
int NoFactura,NITFactura;
};
struct FacturaDetalle{
int idFacturaDetalle,idProductos,NoFactura;
double PrecioVenta,Total;
};


void Menu();

void Menu(){
char opc;
Productos Producto;
     SetConsoleTitle("Menu Principal");
     system("CLS");
         gotoxy(35, 7);
     ARAR;
     gotoxy(35, 8);
     cout << V << "                 Menu Principal                   " << V << endl;
     gotoxy(35, 9);
     AREN;
     gotoxy(35, 10);
     cout << V << "                 1)                         " << V << endl;
     gotoxy(35, 11);
     cout << V << "                 2)                     " << V << endl;
     gotoxy(35, 12);
     cout << V << "                 3)                       " << V << endl;
     gotoxy(35, 13);
     cout << V << "                 4)Dividir                        " << V << endl;
     gotoxy(35, 14);
     ARENBJ;
     gotoxy(35, 15);
     cout << V << "                 ESC.)Salir                       " << V << endl;
     gotoxy(35, 16);
     ABJ;
     gotoxy(35, 17);
     opc = getch();
          switch (opc)
          {
          case '1':
          {

               getch();
               Menu();
               break;
          }
          case '2':
          {
              Menu();
               break;
          }
          case '3':
          {
        Menu();
               break;
          }
          case '4':
          {
        Menu();
               break;
          }
          case 27:{
          exit(0);
          break;
          }
          default:
          {
               cout << "Opcion Incorreta elija de nuevo" << endl;
               getch();
              Menu();
          }
          }
     }

main(){
/*SetConsoleTitle("WEEKEND PLACE");
    system("color 09");
     gotoxy(40,10);cout << "Bienvenidos al Programa WEEKEND PLACE"<<endl;
     gotoxy(45,11);cout << "Hecho por: Rodrigo Vasquez"<<endl;
     gotoxy(50,12);cout << "RV.Enterprices"<<endl;
     cout<<endl;
     char a = 177, b = 219;
     cout << "\t\t\t\t";
     for (int i = 0; i <= 50; i++)
          cout << a;
     cout << "\r";
     cout << "\t\t\t\t";
     for (int i = 0; i <= 50; i++)
     {
          cout << b;
          Sleep(200);
     }
     system("CLS");
*/
Menu();
}
