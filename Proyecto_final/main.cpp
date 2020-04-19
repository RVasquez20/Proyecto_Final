#include<librerias.h>
#include<time.h>
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
typedef Marcas Marca;

struct fecha{
int d,m,a,hh,mm,ss;
};
typedef fecha Fechas;

struct Productos{
int CodigoProducto,idMarca;
char DescripcionProducto[100];
double PrecioCosto,PrecioVenta;
struct fecha FechaDeIngreso;
};
typedef Productos Producto;

struct Clientes{
int NIT;
char NombreCliente[50],DireccionCliente[50];
};
typedef Clientes Cliente;

struct Facturas{
int NoFactura,NITFactura;
};
typedef Facturas Factura;

struct FacturasDetalle{
int idProductos,NoFactura;
double PrecioVenta,Total;
};
typedef FacturasDetalle FacturaDetalle;


//Variables Globales para la fecha y hora
time_t tSac = time(NULL);
struct tm* tmP = localtime(&tSac);
char opc;//opciones de funciones del do while
//Prototipos de Funciones Del Programa
void MenuPrincipal();
void MenuMarcas();
void IngresoDeMarcas();
void MostrarMarcas();
void ModificarMarca();
void EliminarMarca();
void MenuInventario();
void IngresoProductos();
void MostrarProductos();
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
MenuPrincipal();
}
void MenuPrincipal(){
char opc;
     SetConsoleTitle("Menu Principal");
     system("CLS");
         gotoxy(35, 7);
     ARAR;
     gotoxy(35, 8);
     cout << V << "                 Menu Principal                   " << V << endl;
     gotoxy(35, 9);
     AREN;
     gotoxy(35, 10);
     cout << V << "                  1. Marcas                       " << V << endl;
     gotoxy(35, 11);
     cout << V << "                  2. Inventario                   " << V << endl;
     gotoxy(35, 12);
     cout << V << "                  3. Factura                      " << V << endl;
     gotoxy(35, 13);
     cout << V << "                  4. Pedidos                      " << V << endl;
     gotoxy(35, 14);
     ARENBJ;
     gotoxy(35, 15);
     cout << V << "                  ESC. Salir                      " << V << endl;
     gotoxy(35, 16);
     ABJ;
     gotoxy(35, 17);
     opc = getch();
          switch (opc)
          {
          case '1':
          {
               MenuMarcas();
               getch();
               MenuPrincipal();
               break;
          }
          case '2':
          {
              MenuInventario();
               break;
          }
          case '3':
          {
        MenuPrincipal();
               break;
          }
          case '4':
          {
        MenuPrincipal();
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
              MenuPrincipal();
          }
          }
     }
void MenuMarcas(){
char opc;
     SetConsoleTitle("Menu Marcas");
     system("CLS");
         gotoxy(35, 7);
     ARAR;
     gotoxy(35, 8);
     cout << V << "               Menu Principal Marcas              " << V << endl;
     gotoxy(35, 9);
     AREN;
     gotoxy(35, 10);
     cout << V << "              1. Ingresar Marcas                  " << V << endl;
     gotoxy(35, 11);
     cout << V << "              2. Mostrar Listado de Marcas        " << V << endl;
     gotoxy(35, 12);
     cout << V << "              3. Modificar Marca                  " << V << endl;
     gotoxy(35, 13);
     cout << V << "              4. Eliminar Marca                   " << V << endl;
     gotoxy(35, 14);
     ARENBJ;
     gotoxy(35, 15);
     cout << V << "           <-- Regresar / ESC.)Salir              " << V << endl;
     gotoxy(35, 16);
     ABJ;
     gotoxy(35, 17);
     opc = getch();
      if (opc == 8)
     {
          MenuPrincipal();
     }
     else
     {
          switch (opc)
          {
          case '1':
          {
               IngresoDeMarcas();
               getch();
               MenuMarcas();
               break;
          }
          case '2':
          {
              MostrarMarcas();
              getch();
              MenuMarcas();
               break;
          }
          case '3':
          {
          ModificarMarca();
          getch();
          MenuMarcas();
               break;
          }
          case '4':
          {
               EliminarMarca();
               getch();
               MenuMarcas();
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
              MenuMarcas();
          }
          }
     }


}
void IngresoDeMarcas(){
     fflush(stdin);
     Marcas Marca;
     char opc;
     FILE *ArchivoMarcas=fopen("Marcas.dat","a+b");
     loop:
     rewind(ArchivoMarcas);
     int AuxIdMarca;
     system("CLS");
     fflush(stdin);
     cout<<"Ingrese el Id de la marca"<<endl;
     cin>>AuxIdMarca;
     fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
          while(!feof(ArchivoMarcas)){
          if(AuxIdMarca==Marca.idMarca){
          cout<<"Id Ya Existente"<<endl;
          getch();
          goto loop;
          }
          fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
          }
          fflush(stdin);
          Marca.idMarca=AuxIdMarca;
     cout<<"Ingrese El Nombre De La Marca"<<endl;
     cin.getline(Marca.NombreMarca,50,'\n');
     fflush(stdin);
     fwrite(&Marca,sizeof(Marcas),1,ArchivoMarcas);
     cout<<"Desea Ingresar Otro Registro? (S/N)"<<endl;
     cin>>opc;
     if(opc=='S'||opc=='s'){
          goto loop;
     }
     cout<<"Guardado Exitosamente"<<endl;
     fclose(ArchivoMarcas);
}
void MostrarMarcas(){
system("CLS");
int Filas=6,FilasTotales=6;
SetConsoleTitle("Listado De Marcas");
Marcas Marca;
FILE *ArchivoMarcas=fopen("Marcas.dat","rb");
if(ArchivoMarcas==NULL){
     cout<<"Error 001"<<endl;
     getch();
     MenuMarcas();
}else{
system("CLS");
fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
gotoxy(10,3);cout << EIA << H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<CT<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<<EDA << endl;
gotoxy(10,4);cout<<V;gotoxy(30,4);cout<<"Id Marca";gotoxy(59,4);cout<<V;gotoxy(80,4);cout<<"Nombre";gotoxy(110,4);cout<<V<<endl;
gotoxy(10,5);separador;

     while(!feof(ArchivoMarcas)){
     gotoxy(10,Filas);cout<<V;gotoxy(32,Filas);cout<<Marca.idMarca;gotoxy(59,Filas);cout<<V;gotoxy(82,Filas);cout<<Marca.NombreMarca;gotoxy(110,Filas);cout<<V<<endl;
    ++Filas;
    ++FilasTotales;
    fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
     }
gotoxy(10,FilasTotales);cout << EIB<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<CB<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<<EDB << endl;;
fclose(ArchivoMarcas);
}
}
void ModificarMarca(){
fflush(stdin);
     Marcas Marca;
     FILE *ArchivoMarcas=fopen("Marcas.dat","r+b");
     int AuxIdMarca,existe=0,aux2;
     system("CLS");
     fflush(stdin);
     MostrarMarcas();
     cout<<"Ingrese el Id de la marca que desea Modificar"<<endl;
     cin>>AuxIdMarca;
     fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
          while(!feof(ArchivoMarcas)){
          if(AuxIdMarca==Marca.idMarca){
          cout<<"Id_Marca: "<<Marca.idMarca<<endl;
          cout<<"Nombre:    "<<Marca.NombreMarca<<endl<<endl;
          getch();
          int pos=ftell(ArchivoMarcas)-sizeof(Marcas);

          fflush(stdin);
          loop:
          system("CLS");

          cout<<"Ingrese el Id Nuevo"<<endl;
     cin>>aux2;
     rewind(ArchivoMarcas);
     fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
          while(!feof(ArchivoMarcas)){
          if(aux2==Marca.idMarca){
          cout<<"Id Ya Existente"<<endl;
          getch();
          goto loop;
          }
          fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
          }
          fflush(stdin);

          Marca.idMarca=aux2;
     fflush(stdin);
     fseek(ArchivoMarcas,pos,SEEK_SET);
     cout<<"Ingrese El Nombre Nuevo"<<endl;
     cin.getline(Marca.NombreMarca,50,'\n');
     fflush(stdin);
     fwrite(&Marca,sizeof(Marcas),1,ArchivoMarcas);
     cout<<"Modificado Exitosamente"<<endl;
     existe=1;
     break;

          }

          fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);

          }
         if(existe==0) {
          cout<<"No existe una marca con ese codigo"<<endl;
         }


     fclose(ArchivoMarcas);
}
void EliminarMarca(){
fflush(stdin);
     Marcas Marca;
     FILE *ArchivoMarcas=fopen("Marcas.dat","rb");
     FILE *Temporal=fopen("Temporal.dat","wb");
     int AuxIdMarca,existe=0;
     system("CLS");
     fflush(stdin);
     MostrarMarcas();
     cout<<"Ingrese el Id de la marca que desea Eliminar"<<endl;
     cin>>AuxIdMarca;
     fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
          while(!feof(ArchivoMarcas)){
          if(AuxIdMarca==Marca.idMarca){
          cout<<"Id_Marca: "<<Marca.idMarca<<endl;
          cout<<"Nombre:    "<<Marca.NombreMarca<<endl<<endl;
          existe=1;
          cout<<endl;
          cout<<"Marca Eliminada correctamente"<<endl;
          }else{
          fwrite(&Marca,sizeof(Marcas),1,Temporal);
          fflush(stdin);
          }


          fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);

          }
         if(existe==0) {
          cout<<"No existe una marca con ese codigo"<<endl;
         }

     fclose(Temporal);
     fclose(ArchivoMarcas);
     remove("Marcas.dat");
     rename("Temporal.dat","Marcas.dat");
}
void MenuInventario(){
char opc;
     SetConsoleTitle("Menu Inventario");
     system("CLS");
         gotoxy(35, 7);
     ARAR;
     gotoxy(35, 8);
     cout << V << "             Menu Principal Inventario            " << V << endl;
     gotoxy(35, 9);
     AREN;
     gotoxy(35, 10);
     cout << V << "              1. Ingresar Productos               " << V << endl;
     gotoxy(35, 11);
     cout << V << "              2. Mostrar Listado de Productos     " << V << endl;
     gotoxy(35, 12);
     cout << V << "              3. Modificar Productos              " << V << endl;
     gotoxy(35, 13);
     cout << V << "              4. Eliminar Productos               " << V << endl;
     gotoxy(35, 14);
     ARENBJ;
     gotoxy(35, 15);
     cout << V << "           <-- Regresar / ESC.)Salir              " << V << endl;
     gotoxy(35, 16);
     ABJ;
     gotoxy(35, 17);
     opc = getch();
      if (opc == 8)
     {
          MenuPrincipal();
     }
     else
     {
          switch (opc)
          {
          case '1':
          {
               IngresoProductos();
               getch();
               MenuInventario();
               break;
          }
          case '2':
          {
               MostrarProductos();
              getch();
              MenuInventario();
               break;
          }
          case '3':
          {

          getch();
          MenuInventario();
               break;
          }
          case '4':
          {

               getch();
               MenuInventario();
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
              MenuMarcas();
          }
          }
     }


}
void IngresoProductos(){
 fflush(stdin);
 Productos Producto;
 Marcas Marca;
 FILE *ArchivoMarcas=fopen("Marcas.dat","rb");
 FILE *ArchivoProductos=fopen("Productos.dat","a+b");
 InicioIngresoProductos:
 codigoProducto:
 MostrarMarcas();
 int auxCodigoProducto,encontradoCodigoProducto=0,auxIdMarca;
 cout<<"Ingrese el codigo del producto"<<endl;
 cin>>auxCodigoProducto;
 fflush(stdin);
 rewind(ArchivoProductos);
 fread(&Producto,sizeof(Productos),1,ArchivoProductos);
 do{
     if(auxCodigoProducto==Producto.CodigoProducto){
      encontradoCodigoProducto=1;
     }
     fread(&Producto,sizeof(Productos),1,ArchivoProductos);
 }while(!feof(ArchivoProductos));
 if(encontradoCodigoProducto==1){
     cout<<"Codigo Ya existente"<<endl;
     getch();
     goto codigoProducto;
 }
 fflush(stdin);
 Producto.CodigoProducto=auxCodigoProducto;
 fflush(stdin);
 cout<<"Ingrese el nombre del producto"<<endl;
 cin.getline(Producto.DescripcionProducto,100,'\n');
 fflush(stdin);
IdMarca:
     rewind(ArchivoMarcas);
      fflush(stdin);
int encontradoIdMarca=0;
 cout<<"Ingrese el id de la marca del producto"<<endl;
 cin>>auxIdMarca;
 fflush(stdin);
 fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
 do{
     if(auxIdMarca==Marca.idMarca){
          encontradoIdMarca=1;
     }
     fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
 }while(!feof(ArchivoMarcas));
 if(encontradoIdMarca==0){
     cout<<"No existe ninguna marca con se ID"<<endl;
     getch();
     goto IdMarca;
 }
 fflush(stdin);
 Producto.idMarca=auxIdMarca;
 fflush(stdin);
 cout<<"Ingrese precio venta de "<<Producto.DescripcionProducto<<endl;
 cin>>Producto.PrecioVenta;
 fflush(stdin);
cout<<"Ingrese precio Costo de "<<Producto.DescripcionProducto<<endl;
 cin>>Producto.PrecioCosto;
 fflush(stdin);
 int formatofecha=0;
 do{
     cout<<"Ingrese el dia que el producto ingreso"<<endl;
     cin>>Producto.FechaDeIngreso.d;
     fflush(stdin);
     cout<<"Ingrese el Mes que el producto ingreso"<<endl;
     cin>>Producto.FechaDeIngreso.m;
     fflush(stdin);
     cout<<"Ingrese el anio que el producto ingreso"<<endl;
     cin>>Producto.FechaDeIngreso.a;
     fflush(stdin);
     if((Producto.FechaDeIngreso.d>0&&Producto.FechaDeIngreso.d<32)&&(Producto.FechaDeIngreso.m>0&&Producto.FechaDeIngreso.m<13)&&(Producto.FechaDeIngreso.a>1999&&Producto.FechaDeIngreso.a<2101)){
          formatofecha=1;
     }else{
     cout<<"Formato Incorrecto(dd/mm/aaaa)"<<endl;
     }
 }while(formatofecha==0);
 fwrite(&Producto,sizeof(Productos),1,ArchivoProductos);
 cout<<"Desea Ingresar Otro Producto? (S/N)"<<endl;
 cin>>opc;
 if(opc=='s'||opc=='S'){
     goto InicioIngresoProductos;
 }
 fclose(ArchivoMarcas);
 fclose(ArchivoProductos);
}
void MostrarProductos(){
system("CLS");
int Filas=6,FilasTotales=6;
SetConsoleTitle("Listado De Productos");
Productos Producto;
FILE *ArchivoProductos=fopen("Productos.dat","rb");
if(ArchivoProductos==NULL){
     cout<<"Error 001"<<endl;
     getch();
     MenuInventario();
}else{
system("CLS");
fread(&Producto,sizeof(Productos),1,ArchivoProductos);
gotoxy(12,3);cout << EIA << H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<<endl;
gotoxy(7,4);cout<<V;gotoxy(7,4);cout<<"Cod.Producto";gotoxy(30,4);cout<<"Producto";gotoxy(46,4);cout<<"ID Marca";gotoxy(57,4);cout<<"Precio Costo";gotoxy(77,4);cout<<"Precio Venta";gotoxy(96,4);cout<<"Fecha.Ingreso";
gotoxy(1,5);cout<<endl;

     while(!feof(ArchivoProductos)){
gotoxy(7,Filas);cout<<V;gotoxy(7,Filas);cout<<Producto.CodigoProducto;gotoxy(30,Filas);cout<<Producto.DescripcionProducto;gotoxy(46,Filas);cout<<Producto.idMarca;gotoxy(57,Filas);cout<<"Q."<<Producto.PrecioCosto;gotoxy(77,Filas);cout<<"Q."<<Producto.PrecioVenta;gotoxy(96,Filas);cout<<Producto.FechaDeIngreso.d<<"/"<<Producto.FechaDeIngreso.m<<"/"<<Producto.FechaDeIngreso.a<<endl;
    ++Filas;
    ++FilasTotales;
    fread(&Producto,sizeof(Productos),1,ArchivoProductos);
     }

fclose(ArchivoProductos);
}
}
