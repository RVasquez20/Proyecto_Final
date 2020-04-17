#include<conio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <shellapi.h>
using namespace std;

struct Marcas{
    int id_marca;
    char marca[50];
};
struct Fecha{
    int dia;
    int mes;
    int anio;
};
struct Productos{
    int cod_producto;
    char producto[50];
    int id_marca;
    float precio_costo;
    float precio_venta;
    Fecha fecha;
};
void ver_productos();
int main(){
    ver_productos();
    int cp;
    cout<<"INGRESE 0 PARA PODER GENERAR UN CODIGO: ";
    cin>>cp;

    FILE* archivo = fopen("registros/productos.dat", "rb");

	int indice=0,pos=0,cod=0;
	Productos prod;
	fread ( &prod, sizeof(Productos), 1, archivo );
		do{
			if (prod.cod_producto == cp){
                ofstream archivo2;
                archivo2.open("IMPRIMIR/Codigo_barra/Codigo_barra/bin/Debug/imprimir.txt",ios::out);
                if(archivo2.fail()){
                    cout<<"no es posible abrir el archivo";
                    getch();
                    exit(1);
                }
                else {
                    fflush(stdin);
                    archivo2<<prod.cod_producto<<endl<<prod.producto<<" marca ";
                    FILE* archivoma = fopen("registros/marcas.dat", "rb");
                    Marcas marc;
                    fread ( &marc, sizeof(Marcas), 1, archivoma );
                    do{
                        if (prod.id_marca==marc.id_marca){
                            archivo2<<marc.marca<<endl;
                        }
                        fread ( &marc, sizeof(Marcas), 1, archivoma );
                    } while (feof(archivoma) == 0);
                    fclose(archivoma);
                    archivo2<< fixed << setprecision(2)<<prod.precio_venta;
                    //getch();
                }
                archivo2.close();
			}

            fread ( &prod, sizeof(Productos), 1, archivo );
            indice += 1;
		} while (feof( archivo ) == 0);

	fclose(archivo);
	system("start IMPRIMIR/Codigo_barra/Codigo_barra/bin/Debug/Codigo_barra.exe");
	//system("start C:/Users/USUARIO/Desktop/PROYECTO PROGRAMACION I/IMPRIMIR/CODIGO DE BARRAS/CODIGO DE BARRAS/bin/Debug/CODIGO DE BARRAS.exe");
	system("PAUSE");
	remove("IMPRIMIR/Codigo_barra/Codigo_barra/bin/Debug/imprimir.txt");

    getch();
}
void ver_productos(){
    system("cls");
	FILE* archivo = fopen("registros/productos.dat", "rb");
	Productos prod;
	int registro=0;
	fread ( &prod, sizeof(Productos), 1, archivo );
    cout<<"__________________________________________________________________________"<<endl;
	cout << "COD" <<" | "<< "NOMBRE"<<" | "<< "ID_MARCA" <<" | "<< "PRECIO COSTO"<<" | "<< "PRECIO VENTA" <<" | "<< "FECHA (dd/mm/aaaa)"<<endl;
	do{
		cout<<"____________________________________________________________________"<<endl;
		cout << prod.cod_producto <<" | "<< prod.producto<<" | "<< prod.id_marca <<" | ";
        printf("%.2f | %.2f",prod.precio_costo,prod.precio_venta);
        cout<<" | ("<< prod.fecha.dia<<"/"<< prod.fecha.mes<<"/"<< prod.fecha.anio<<")"<<endl;
		fread ( &prod, sizeof(Productos), 1, archivo );
		registro += 1;
	} while (feof( archivo ) == 0);

    cout<<endl;
	fclose(archivo);
}
