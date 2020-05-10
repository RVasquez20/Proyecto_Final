#include<librerias.h>
#include<time.h>
#include <fstream>
#include<ctype.h>
char CT = 203, LTI = 204, H = 205, CRUZ = 206, CB = 202, EIA = 201, EIB = 200, LTD = 185, V = 186, EDA = 187, EDB = 188;
#define ARAR cout << EIA << H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<< H<<H<< H<<EDA << endl;
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
char NIT[12];
char NombreCliente[50],DireccionCliente[50];
};
typedef Clientes Cliente;

struct Facturas{
int NoFactura;
char NITFactura[12];
struct fecha FechaFactura;
};
typedef Facturas Factura;

struct FacturasDetalle{
int *idProductos,NoFactura,IdFacturaDetalle;
double *PrecioVenta;
};
typedef FacturasDetalle FacturaDetalle;

//Variables Globales para la fecha y hora
time_t tSac = time(NULL);
struct tm* tmP = localtime(&tSac);
char opc;//opciones de funciones del do while
bool real=false;//Verificacion de nit
int IA=0;//Incremento Automatico XD
//Prototipos de Funciones Del Programa
void MenuPrincipal();
bool VerificadorDeNumeros(string);
void MenuMarcas();
void IngresoDeMarcas();
void MostrarMarcas();
void ModificarMarca();
void EliminarMarca();
void MenuInventario();
void IngresoProductos();
void MostrarProductos();
void ModificarProductos();
void EliminarProducto();
void MenuFacturas();
void Facture();
bool ValidacionNIT(string);
int Contador(int );
void ProductosAComprar();
void MenuBusquedaCliente();
void SearchWhitName();
void SearchClientWhitNIT();
void MenuBusquedaFactura();
void SearchWhitCorrelative();
void SearchFactureWhitNIT();
void MenuAyuda();
void mostrar();
void Actualizacion(int,int);
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
bool VerificadorDeNumeros(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
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
     cout << V << "                  4. Ayuda                        " << V << endl;
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
              getch();
               MenuPrincipal();
               break;
          }
          case '3':
          {
               MenuFacturas();
                    getch();
        MenuPrincipal();
               break;
          }
          case '4':
          {
               MenuAyuda();
               getch();
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
     string AUX;
     int AuxIdMarca;
     system("CLS");
     fflush(stdin);
     cout<<"Ingrese el Id de la marca"<<endl;
     getline(cin,AUX);
     if(VerificadorDeNumeros(AUX)){
          AuxIdMarca=atoi(AUX.c_str());
     }else{
     cout<<"Ingreso alguna letra Porfavor Ingrese solo numeros"<<endl;
     getch();
     system("CLS");
     goto loop;
     }
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
     Productos Producto;
     inicio:
fflush(stdin);
     Marcas Marca;
     FILE *ArchivoMarcas=fopen("Marcas.dat","r+b");
     int AuxIdMarca,existe=0,aux2;
     string AUX;
     system("CLS");
     fflush(stdin);
     MostrarMarcas();
     cout<<"Ingrese el Id de la marca que desea Modificar"<<endl;
     cin>>AUX;
     fflush(stdin);
     if(VerificadorDeNumeros(AUX)){
                fflush(stdin);
          AuxIdMarca=atoi(AUX.c_str());
     }else{
     cout<<"Ingreso alguna letra Porfavor Ingrese solo numeros"<<endl;
     getch();
     system("CLS");
     goto inicio;
     }
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
      fflush(stdin);
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
     Actualizacion(aux2,AuxIdMarca);
}
void Actualizacion(int idnew,int idold){
     int encontrado2=0,contador=0;
     Productos Producto;
     FILE *Products=fopen("Productos.dat","r+b");
     fread(&Producto,sizeof(Productos),1,Products);
     while(!feof(Products)){
     if(idold==Producto.idMarca){
          encontrado2=1;
          Producto.idMarca=idnew;
 int pos=ftell(Products)-sizeof(Productos);
     fseek(Products,pos,SEEK_SET);
           fwrite(&Producto,sizeof(Productos),1,Products);
           break;
     }
fread(&Producto,sizeof(Productos),1,Products);
     }
if(encontrado2==1){
     cout<<"Productos Actualizados Exitosamente"<<endl;
}

     fclose(Products);
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
          ModificarProductos();
          getch();
          MenuInventario();
               break;
          }
          case '4':
          {
               EliminarProducto();
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
              MenuInventario();
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
int Filas=6,FilasTotales=6,encontradomarca=0;
SetConsoleTitle("Listado De Productos");
Productos Producto;
 Marcas Marca;
 FILE *ArchivoMarcas=fopen("Marcas.dat","rb");
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
gotoxy(7,Filas);cout<<V;gotoxy(7,Filas);cout<<Producto.CodigoProducto;gotoxy(30,Filas);cout<<Producto.DescripcionProducto;
rewind(ArchivoMarcas);
fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
while(!feof(ArchivoMarcas)){
     if(Producto.idMarca==Marca.idMarca){
          gotoxy(46,Filas);cout<<Marca.NombreMarca;
          encontradomarca=1;
     }
     fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
}
if(encontradomarca==0){
   gotoxy(46,Filas);cout<<"Modificada!";
}


gotoxy(57,Filas);cout<<"Q."<<Producto.PrecioCosto;gotoxy(77,Filas);cout<<"Q."<<Producto.PrecioVenta;gotoxy(96,Filas);cout<<Producto.FechaDeIngreso.d<<"/"<<Producto.FechaDeIngreso.m<<"/"<<Producto.FechaDeIngreso.a<<endl;
    ++Filas;
    ++FilasTotales;
    fread(&Producto,sizeof(Productos),1,ArchivoProductos);
     }
fclose(ArchivoProductos);
fclose(ArchivoMarcas);
}
}
void ModificarProductos(){
char Eleccion;
 fflush(stdin);
 Productos Producto;
  Marcas Marca;
 FILE *ArchivoMarcas=fopen("Marcas.dat","rb");
 FILE *ArchivoProductos=fopen("Productos.dat","r+b");
 BusquedaParaModificar:
      system("CLS");
      MostrarProductos();
      rewind(ArchivoProductos);
      rewind(ArchivoMarcas);
 int AuxBusquedaCodigoProducto=0,EncontradoCodigoaModificar=0;
 cout<<"Ingrese el codigo del producto a modificar"<<endl;
 cin>>AuxBusquedaCodigoProducto;
  fflush(stdin);
 fread(&Producto,sizeof(Productos),1,ArchivoProductos);
     while(!feof(ArchivoProductos)){
     if(AuxBusquedaCodigoProducto==Producto.CodigoProducto){
               EncontradoCodigoaModificar=1;
     cout<<"Codigo: "<<Producto.CodigoProducto<<endl;
     cout<<"Producto: "<<Producto.DescripcionProducto<<endl;
     fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
     while(!feof(ArchivoMarcas)){
     if(Producto.idMarca==Marca.idMarca){
          cout<<"Id Marca: "<<Marca.NombreMarca<<endl;
     }
     fread(&Marca,sizeof(Marcas),1,ArchivoMarcas);
     }
     cout<<"Precio Costo : "<<Producto.PrecioCosto<<endl;
     cout<<"Precio Venta : "<<Producto.PrecioVenta<<endl;
     cout<<"Fecha de ingreso: "<<Producto.FechaDeIngreso.d<<"/"<<Producto.FechaDeIngreso.m<<"/"<<Producto.FechaDeIngreso.a<<endl;
cout<<endl;
cout<<"Este es el producto que desea modificar? S/N"<<endl;
cin>>Eleccion;
fflush(stdin);
if(Eleccion=='N'||Eleccion=='n'){
     goto BusquedaParaModificar;
}
  int pos=ftell(ArchivoProductos)-sizeof(Productos);
fflush(stdin);
codigoProducto:
 MostrarMarcas();
 int auxCodigoProducto,encontradoCodigoProducto=0,auxIdMarca;
 cout<<"Ingrese el codigo nuevo del producto"<<endl;
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
 fseek(ArchivoProductos,pos,SEEK_SET);
fflush(stdin);
 cout<<"Ingrese el nuevo nombre del producto"<<endl;
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
 fflush(stdin);
 cout<<"Modificado Exitosamente"<<endl;
 break;
     }
     fread(&Producto,sizeof(Productos),1,ArchivoProductos);

     }
     if(EncontradoCodigoaModificar==0){
          cout<<"Codigo No existente"<<endl;
          getch();
          goto BusquedaParaModificar;
     }

 fclose(ArchivoProductos);
  fclose(ArchivoMarcas);
}
void EliminarProducto(){
Productos Producto;
FILE *ArchivoProductos=fopen("Productos.dat","rb");
FILE *Temporal=fopen("Temporal.dat","w+b");
BusquedaDeCodigoParaEliminar:
     system("CLS");
     MostrarProductos();
     rewind(ArchivoProductos);
int EncontradoCodigo=0,AuxCodigoProducto=0;
cout<<"Ingrese el codigo del producto que desea eliminar"<<endl;
cin>>AuxCodigoProducto;
fflush(stdin);
fread(&Producto,sizeof(Productos),1,ArchivoProductos);
     while(!feof(ArchivoProductos)){
     if(AuxCodigoProducto==Producto.CodigoProducto){
          cout<<"Producto Eliminado Correctamente"<<endl;
          EncontradoCodigo=1;
          }else{
          fwrite(&Producto,sizeof(Productos),1,Temporal);
          fflush(stdin);
          }
          fread(&Producto,sizeof(Productos),1,ArchivoProductos);
     }
     if(EncontradoCodigo==0) {
          cout<<"No existe un Producto con ese codigo"<<endl;
          getch();
          goto BusquedaDeCodigoParaEliminar;
         }
fclose(ArchivoProductos);
fclose(Temporal);
remove("Productos.dat");
rename("Temporal.dat","Productos.dat");
}
void MenuFacturas(){
char opc;
     SetConsoleTitle("Menu Inventario");
     system("CLS");
         gotoxy(35, 7);
     ARAR;
     gotoxy(35, 8);
     cout << V << "             Menu Principal Facturacion           " << V << endl;
     gotoxy(35, 9);
     AREN;
     gotoxy(35, 10);
     cout << V << "              1. Compra nueva                     " << V << endl;
     gotoxy(35, 11);
     cout << V << "              2. Busqueda De Clientes             " << V << endl;
     gotoxy(35, 12);
     cout << V << "              3. Busqueda De Facturas             " << V << endl;
     gotoxy(35, 13);
     ARENBJ;
     gotoxy(35, 14);
     cout << V << "           <-- Regresar / ESC.)Salir              " << V << endl;
     gotoxy(35, 15);
     ABJ;
     gotoxy(35, 16);
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
               Facture();
               ProductosAComprar();
               //FacturaDetalle
               getch();
               MenuFacturas();
               break;
          }
          case '2':
          {
               MenuBusquedaCliente();
              getch();
              MenuFacturas();
               break;
          }
          case '3':
          {
          MenuBusquedaFactura();
          getch();
          MenuFacturas();
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
              MenuFacturas();
          }
          }
     }

}
bool ValidacionNIT(string nit){
        int tam=nit.size();
    bool ver;
    char frase[tam];
    strcpy(frase,nit.c_str());
    for(int i=0; i<tam; i++){
        if(frase[i]=='-'){
            ver=true;
        }
    }
    if(ver==false){
        gotoxy(1,25);cout<<"NIT INGRESADO NO CONTIENE GUION"<<endl;
        real=false;
        Facture();
    }
	char *token, *aux, *numnit;
	token=strtok(frase, "-");
	int numval, tamnum;
	while(token != NULL && ver==true){
        aux=token;
		token=strtok(NULL,"-");
		if(token==NULL){
            char k=*aux;
            if(k=='k'){ numval=10;}
			numval=atoi(aux);
		} else{
			numnit=aux;
			tamnum=strlen(aux);
		}
	}

	int  digitos[tamnum], num1;
	num1=atoi(numnit);
	for(int i=0; i<tamnum; i++){
        num1=numnit[i]- '0';
        digitos[i]=num1;
    }
	int j=1, acum=0, mult, n1,n2,n3,n4, n5, codv, codigo;
    for(int i=tamnum-1; i>=0; i--){
        j++;
        mult=digitos[i]*j;
        acum=acum+mult;
    }
    n1=acum/11;
	n2=n1*11;
	n3=acum-n2;
	n4=n3/11;
	n5=n4*11;
	codv=n3-n5;
	codigo=11-codv;
	if(numval==codigo){
        real=true;
	}
	if(numval!=codigo){
	    real=false;
	}
	return real;
}
void Facture(){
     Clientes Cliente;
     Facturas Factura;
     FILE *Clients=fopen("Clientes.dat","a+b");
     FILE *Temporal=fopen("Impresion.txt","w+");
     int EncontradoNit=0;
     string Auxnit;
     do{
system("CLS");
     cout<<"Ingrese El nit "<<endl;
     getline(cin,Auxnit);
     fflush(stdin);
     ValidacionNIT(Auxnit);

     }while(real==false);
fread(&Cliente,sizeof(Clientes),1,Clients);
while(!feof(Clients)){
if(strcmp(Auxnit.c_str(),Cliente.NIT)==0){
    EncontradoNit=1;
     IA=1;
    fflush(stdin);
    Factura.NoFactura=Contador(IA);
    FILE *Factures=fopen("Factura.dat","a+b");
    strcpy(Factura.NITFactura,Auxnit.c_str());
    Factura.FechaFactura.d=tmP->tm_mday;
    Factura.FechaFactura.m=tmP->tm_mon+1;
    Factura.FechaFactura.a=tmP->tm_year+1900;
    fwrite(&Factura,sizeof(Facturas),1,Factures);
    fclose(Factures);
    system("CLS");
    cout<<"No.Factura "<<Factura.NoFactura<<"\t Fecha : "<<Factura.FechaFactura.d<<"/"<<Factura.FechaFactura.m<<"/"<<Factura.FechaFactura.a<<endl;
    cout<<"NIT: "<<Factura.NITFactura<<endl;
    cout<<"Cliente: "<<Cliente.NombreCliente<<endl;
    cout<<"Direccion: "<<Cliente.DireccionCliente<<endl;
    cout<<"-------------------------------------------"<<endl;
    fprintf(Temporal,"No.Factura %d \tFecha: %d/%d/%d\n",Factura.NoFactura,Factura.FechaFactura.d,Factura.FechaFactura.m,Factura.FechaFactura.a);
    fprintf(Temporal,"NIT: %s\n",Factura.NITFactura);
    fprintf(Temporal,"Cliente: %s\n",Cliente.NombreCliente);
    fprintf(Temporal,"Direccion: %s\n",Cliente.DireccionCliente);
    fprintf(Temporal,"-------------------------------------------------\n");
}
fread(&Cliente,sizeof(Clientes),1,Clients);
}

if(EncontradoNit==0){
fflush(stdin);
IA=1;
cout<<"Ingrese el Nombre Completo del Cliente"<<endl;
cin.getline(Cliente.NombreCliente,50,'\n');
fflush(stdin);
cout<<"Ingrese la Direccion del cliente"<<endl;
cin.getline(Cliente.DireccionCliente,50,'\n');
fflush(stdin);
strcpy(Cliente.NIT,Auxnit.c_str());
fflush(stdin);
fwrite(&Cliente,sizeof(Clientes),1,Clients);
    fflush(stdin);
    Factura.NoFactura=Contador(IA);
    FILE *Factures=fopen("Factura.dat","a+b");
    strcpy(Factura.NITFactura,Auxnit.c_str());
    Factura.FechaFactura.d=tmP->tm_mday;
    Factura.FechaFactura.m=tmP->tm_mon+1;
    Factura.FechaFactura.a=tmP->tm_year+1900;
    fwrite(&Factura,sizeof(Facturas),1,Factures);
    fclose(Factures);
    system("CLS");
    cout<<"No.Factura "<<Factura.NoFactura<<"\t Fecha : "<<Factura.FechaFactura.d<<"/"<<Factura.FechaFactura.m<<"/"<<Factura.FechaFactura.a<<endl;
    cout<<"NIT: "<<Factura.NITFactura<<endl;
    cout<<"Cliente: "<<Cliente.NombreCliente<<endl;
    cout<<"Direccion: "<<Cliente.DireccionCliente<<endl;
    cout<<"-------------------------------------------"<<endl;
        fprintf(Temporal,"No.Factura %d \tFecha: %d%d%d\n",Factura.NoFactura,Factura.FechaFactura.d,Factura.FechaFactura.m,Factura.FechaFactura.a);
    fprintf(Temporal,"NIT: %s\n",Factura.NITFactura);
    fprintf(Temporal,"Cliente: %s\n",Cliente.NombreCliente);
    fprintf(Temporal,"Direccion: %s\n",Cliente.DireccionCliente);
    fprintf(Temporal,"-------------------------------------------------\n");
}

fclose(Clients);
fclose(Temporal);
}
int Contador(int valor){
     Facturas Factura;
     FILE *Factures=fopen("Factura.dat","a+b");
fread(&Factura,sizeof(Facturas),1,Factures);
    while(!feof(Factures)){
          valor=valor+1;
     fread(&Factura,sizeof(Facturas),1,Factures);
    }
     fclose(Factures);
     return valor;
}
void ProductosAComprar(){
FILE *Details=fopen("factura_detalle.dat","a+b");
FILE *Temporal=fopen("Impresion.txt","a+");
Facturas Factura;
Marcas Marca;
Productos Producto;
FacturasDetalle FacturaDetalle;
double subtotal=0;
int AuxCodigo=0,Contador2=0;
gotoxy(0,9);cout<<"No.\tCodigo Producto\tDescripcion\tSubtotal"<<endl;
fprintf(Temporal,"No.\tCodigo\tProducto\tDescripcion\tSubtotal\n");
FacturaDetalle.idProductos=new int[100];
FacturaDetalle.PrecioVenta=new double[100];
do{
int Cantidad=0;
gotoxy(0,8);cout<<"    ";
gotoxy(0,8);cin>>AuxCodigo;
fflush(stdin);
FILE *Products=fopen("Productos.dat","rb");
fread(&Producto,sizeof(Productos),1,Products);
while(!feof(Products)){
     if(AuxCodigo==Producto.CodigoProducto){
          Contador2++;
     Cantidad++;
     FacturaDetalle.idProductos[Cantidad]=AuxCodigo;
gotoxy(0,11+Contador2);cout<<Contador2<<"\t"<<Producto.CodigoProducto<<"\t"<<Producto.DescripcionProducto<<" Marca ";
fprintf(Temporal,"%d\t%d\t%s\t",Contador2,Producto.CodigoProducto,Producto.DescripcionProducto);
      FILE *Marcs=fopen("Marcas.dat","rb");
      fread(&Marca,sizeof(Marca),1,Marcs);
      while(!feof(Marcs)){
          if(Producto.idMarca==Marca.idMarca){
           cout<<Marca.NombreMarca;
           fprintf(Temporal,"Marca %s \t",Marca.NombreMarca);
          }
          fread(&Marca,sizeof(Marca),1,Marcs);
      }
      fclose(Marcs);
      cout<<"\t Q."<<Producto.PrecioVenta<<endl;
      FacturaDetalle.PrecioVenta[Cantidad]=Producto.PrecioVenta;
      fprintf(Temporal,"Q. %.2f \n",Producto.PrecioVenta);
      subtotal=subtotal+Producto.PrecioVenta;
      FacturaDetalle.IdFacturaDetalle=Contador(0);
      FacturaDetalle.NoFactura=Factura.NoFactura;
      fwrite(&FacturaDetalle,sizeof(FacturasDetalle),1,Details);
     }
     fread(&Producto,sizeof(Productos),1,Products);
}

fclose(Products);
}while(AuxCodigo!=0);
delete[]FacturaDetalle.idProductos;
delete[]FacturaDetalle.PrecioVenta;
gotoxy(0,8);cout<<"    ";
gotoxy(0,12+Contador2);cout<<"Total: Q."<<subtotal<<endl;
fprintf(Temporal,"Total: Q. %.2f",subtotal);
fclose(Details);
fclose(Temporal);
}
void MenuBusquedaCliente(){
char opc;
     SetConsoleTitle("Menu Busqueda Cliente");
     system("CLS");
         gotoxy(35, 7);
     ARAR;
     gotoxy(35, 8);
     cout << V << "             Menu De Busqueda de cliente          " << V << endl;
     gotoxy(35, 9);
     AREN;
     gotoxy(35, 10);
     cout << V << "              1. Por medio de Nombre              " << V << endl;
     gotoxy(35, 11);
     cout << V << "              2. Por Medio de nit                 " << V << endl;
     gotoxy(35, 12);
     ARENBJ;
     gotoxy(35, 13);
     cout << V << "           <-- Regresar / ESC.)Salir              " << V << endl;
     gotoxy(35, 14);
     ABJ;
     gotoxy(35, 15);
     opc = getch();
      if (opc == 8)
     {
          MenuFacturas();
     }
     else
     {
          switch (opc)
          {
          case '1':
          {
               SearchWhitName();
               getch();
               MenuBusquedaCliente();
               break;
          }
          case '2':
          {
              SearchClientWhitNIT();
              getch();
              MenuBusquedaCliente();
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
              MenuBusquedaCliente();
          }
          }
     }
}
void SearchWhitName(){
fflush(stdin);
Clientes Cliente;
FILE *Clients=fopen("Clientes.dat","rb");
string aux;
string nombre;
bool encontrado=false;
     if (Clients == NULL)
     {
          SetConsoleTitle("Error 002");
          cout << "Error 002" << endl;
          getch();
          MenuBusquedaCliente();
     }
     else
     {system("CLS");
     	fflush(stdin);
     	cout<<"Ingrese el nombre que busca"<<endl;
     	getline(cin,aux);
     	fflush(stdin);
          SetConsoleTitle("Registros");
	cout << "+--------------------------------------------------------------------------+" << endl;
          cout << "Nombre\t\tNIT\t\tDireccion" << endl;
          fread(&Cliente, sizeof(Clientes), 1, Clients);
          do
          {

          nombre=Cliente.NombreCliente;
          	fflush(stdin);
          	if(nombre.find(aux)!=string::npos){
     cout<<Cliente.NombreCliente<<"\t"<<Cliente.NIT<<"\t"<<Cliente.DireccionCliente<<endl;
			     cout << "+-------------------------------------------------------------------------+" << endl;
			  encontrado=true;
			 }
               fread(&Cliente, sizeof(Clientes), 1, Clients);
     }while(feof(Clients)==0);
     if(encontrado==false){
     	cout<<"No se encontro"<<endl;
	 }
     fclose(Clients);

}
}
void SearchClientWhitNIT(){
fflush(stdin);
Clientes Cliente;
FILE *Clients=fopen("Clientes.dat","rb");
bool encontrado=false;
string aux;
     if (Clients == NULL)
     {
          SetConsoleTitle("Error 002");
          cout << "Error 002" << endl;
          getch();
          MenuBusquedaCliente();
     }
     else
     {
          system("CLS");
     	fflush(stdin);
     	cout<<"Ingrese el NIT que busca"<<endl;
     	getline(cin,aux);
     	fflush(stdin);
          SetConsoleTitle("Registros");
	cout << "+--------------------------------------------------------------------------+" << endl;
          cout << "Nombre\t\tNIT\t\tDireccion" << endl;
          fread(&Cliente, sizeof(Clientes), 1, Clients);
          do
          {
          	fflush(stdin);
          	if(strcmp(aux.c_str(),Cliente.NIT)==0){
     cout<<Cliente.NombreCliente<<"\t"<<Cliente.NIT<<"\t"<<Cliente.DireccionCliente<<endl;
			     cout << "+-------------------------------------------------------------------------+" << endl;
			  encontrado=true;
			 }
               fread(&Cliente, sizeof(Clientes), 1, Clients);
     }while(feof(Clients)==0);
     if(encontrado==false){
     	cout<<"No se encontro"<<endl;
	 }
     fclose(Clients);

}
}
void MenuBusquedaFactura(){
char opc;
     SetConsoleTitle("Menu Busqueda Factura");
     system("CLS");
         gotoxy(35, 7);
     ARAR;
     gotoxy(35, 8);
     cout << V << "             Menu De Busqueda de Factura          " << V << endl;
     gotoxy(35, 9);
     AREN;
     gotoxy(35, 10);
     cout << V << "              1. Por medio de Correlativo         " << V << endl;
     gotoxy(35, 11);
     cout << V << "              2. Por Medio de nit                 " << V << endl;
     gotoxy(35, 12);
     ARENBJ;
     gotoxy(35, 13);
     cout << V << "           <-- Regresar / ESC.)Salir              " << V << endl;
     gotoxy(35, 14);
     ABJ;
     gotoxy(35, 15);
     opc = getch();
      if (opc == 8)
     {
          MenuFacturas();
     }
     else
     {
          switch (opc)
          {
          case '1':
          {
               SearchWhitCorrelative();
               getch();
               MenuBusquedaFactura();
               break;
          }
          case '2':
          {
              SearchFactureWhitNIT();
              getch();
              MenuBusquedaFactura();
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
              MenuBusquedaCliente();
          }
          }
     }
}
void SearchWhitCorrelative(){
fflush(stdin);
Facturas Factura;
FILE *Factures=fopen("Factura.dat","rb");
bool encontrado=false;
int aux=0;
     if (Factures == NULL)
     {
          SetConsoleTitle("Error 002");
          cout << "Error 002" << endl;
          getch();
          MenuBusquedaCliente();
     }
     else
     {
          system("CLS");
     	fflush(stdin);
     	cout<<"Ingrese el Correlativo que busca"<<endl;
     	cin>>aux;
     	fflush(stdin);
          SetConsoleTitle("Registros");
	cout << "+--------------------------------------------------------------------------+" << endl;
          cout << "No.Factura\t\t\tFecha\t\t\tNIT" << endl;
          fread(&Factura, sizeof(Facturas), 1, Factures);
          do
          {
          	fflush(stdin);
          	if(aux==Factura.NoFactura){
     cout<<Factura.NoFactura<<"\t"<<Factura.FechaFactura.d<<"/"<<Factura.FechaFactura.m<<"/"<<Factura.FechaFactura.a<<"\t"<<Factura.NITFactura<<endl;
			     cout << "+-------------------------------------------------------------------------+" << endl;
			  encontrado=true;
			 }
               fread(&Factura, sizeof(Facturas), 1, Factures);
     }while(feof(Factures)==0);
     if(encontrado==false){
     	cout<<"No se encontro"<<endl;
	 }
     fclose(Factures);

}
}
void SearchFactureWhitNIT(){
fflush(stdin);
Facturas Factura;
FILE *Facture=fopen("Factura.dat","rb");
bool encontrado=false;
string aux;
     if (Facture == NULL)
     {
          SetConsoleTitle("Error 002");
          cout << "Error 002" << endl;
          getch();
          MenuBusquedaFactura();
     }
     else
     {
          system("CLS");
     	fflush(stdin);
     	cout<<"Ingrese el NIT que busca"<<endl;
     	getline(cin,aux);
     	fflush(stdin);
          SetConsoleTitle("Registros");
	cout << "+--------------------------------------------------------------------------+" << endl;
          cout << "No.Factura\t\t\tFecha\t\t\tNIT" << endl;
          fread(&Factura, sizeof(Facturas), 1, Facture);
          do
          {
          	fflush(stdin);
          	if(strcmp(aux.c_str(),Factura.NITFactura)==0){
     cout<<Factura.NoFactura<<"\t"<<Factura.FechaFactura.d<<"/"<<Factura.FechaFactura.m<<"/"<<Factura.FechaFactura.a<<"\t"<<Factura.NITFactura<<endl;
			     cout << "+-------------------------------------------------------------------------+" << endl;
			  encontrado=true;
			 }
               fread(&Factura, sizeof(Facturas), 1, Facture);
     }while(feof(Facture)==0);
     if(encontrado==false){
     	cout<<"No se encontro"<<endl;
	 }
     fclose(Facture);

}
}

void MenuAyuda(){
char opc;
     SetConsoleTitle("Menu Ayuda");
     system("CLS");
         gotoxy(35, 7);
     ARAR;
     gotoxy(35, 8);
     cout << V << "             Menu De Ayuda al usuario             " << V << endl;
     gotoxy(35, 9);
     AREN;
     gotoxy(35, 10);
     cout << V << "              1. Errores                          " << V << endl;
     gotoxy(35, 11);
     cout << V << "              2. Manual De Usuario                " << V << endl;
     gotoxy(35, 12);
     ARENBJ;
     gotoxy(35, 13);
     cout << V << "           <-- Regresar / ESC.)Salir              " << V << endl;
     gotoxy(35, 14);
     ABJ;
     gotoxy(35, 15);
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

               getch();
               MenuAyuda();
               break;
          }
          case '2':
          {
              getch();
              MenuAyuda();
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
              MenuAyuda();
          }
          }
     }
}




/*void mostrar(){
     system("CLS");
     Facturas Factura;
     Clientes Cliente;
FILE *Facturation=fopen("Factura.dat","rb");
fread(&Factura,sizeof(Facturas),1,Facturation);
while(!feof(Facturation)){
cout<<Factura.NoFactura<<endl;
cout<<Factura.NITFactura<<endl;
cout<<Factura.FechaFactura.d<<"/"<<Factura.FechaFactura.m<<"/"<<Factura.FechaFactura.a<<endl;
fread(&Factura,sizeof(Facturas),1,Facturation);
}
cout<<"---------------------------------------------------"<<endl;
FILE *Clients=fopen("Clientes.dat","rb");
fread(&Cliente,sizeof(Clientes),1,Clients);
while(!feof(Clients)){
cout<<Cliente.NombreCliente<<endl;
cout<<Cliente.NIT<<endl;
cout<<Cliente.DireccionCliente<<endl;

fread(&Cliente,sizeof(Clientes),1,Clients);
}
fclose(Facturation);
fclose(Clients);

}

*/







