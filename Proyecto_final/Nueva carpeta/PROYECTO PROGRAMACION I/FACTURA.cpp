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
bool real;
int d, m, a, hh, mm;
typedef std::basic_ifstream<TCHAR> tifstream;
typedef std::basic_string<TCHAR> tstring;

using namespace std;

void Outtextxy(HDC hdc,int x,int y,tstring Msg){
    TextOut(hdc,x,y,Msg.c_str(),static_cast<int>(Msg.length()));
}
void ShowError(tstring strMsg){
MessageBox (NULL,strMsg.c_str(),TEXT("Imprimir"),MB_ICONERROR );
exit(1);
}
void ShowInformation(tstring strText)
{
MessageBox (NULL,strText.c_str(),TEXT("Imprimir"),MB_ICONINFORMATION);
}
void PrintFile(tifstream& f){
PRINTDLG pd;
DOCINFO di;
tstring strLine;
int y=300;

memset (&pd, 0, sizeof(PRINTDLG));
memset (&di, 0, sizeof(DOCINFO));

di.cbSize = sizeof(DOCINFO);
di.lpszDocName = TEXT("Imprimiendo");

pd.lStructSize = sizeof(PRINTDLG);
pd.Flags = PD_PAGENUMS | PD_RETURNDC;
pd.nFromPage = 1;
pd.nToPage = 1;
pd.nMinPage = 1;
pd.nMaxPage = 0xFFFF;


if(f.fail())
ShowError(TEXT("Error el archivo no se pudo abrir para lectura"));

if (PrintDlg (&pd)){
if (pd.hDC){
if (StartDoc (pd.hDC, &di) != SP_ERROR){
cout << "Imprimiendo...\nEspere un momento" << endl;
StartPage (pd.hDC);
while(!f.eof()){
getline(f,strLine);
//Settextstyle(DEFAULT_FONT,0,2);
Outtextxy(pd.hDC,500,y,strLine.c_str());
y+=100;
}
EndPage (pd.hDC);
EndDoc (pd.hDC);

}
else
ShowError(TEXT("Error: No se pudo comenzar a imprimir."));

}
else
ShowError(TEXT("Error: No se pudo crear el contexto de dispositivo"));

}
else
ShowInformation(TEXT("Se cancelo la impresion"));

ShowInformation(TEXT("Termino la impresion correctamente."));
}

struct Clientes{
    char nit[15];
    char nombre_cliente[50];
    char direccion[20];
};
struct Fecha_fac{
    int dia;
    int mes;
    int anio;
    int hora;
    int minu;
};
struct Factura{
    int num_fac;
    Fecha_fac fec;
    Clientes cli;
};
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
struct Codigo{
    int cod_producto;
};
void mostrar_fecha();
bool validar_nit(string);
int main(){
    mostrar_fecha();
    remove("imprimir_factura.txt");
    HDC hdc;
//VARIABLES PARA EL FUNCIONAMIENTO DEL PROGRAMA
    char nitt[15];
    int codp;
    string nomb, dir;
    bool encnit=false;
    Clientes clientes;
    do{
        gotoxy(1,2);cout<<"NIT: ";
        gotoxy(1,3);cout<<"CLIENTE: ";
        gotoxy(1,4);cout<<"DIRECCION: ";


        gotoxy(6,2);cin>>nitt;
        validar_nit(nitt);
    }while(real==false);

    int registro=0;
	FILE* archivo = fopen("registros/clientes.dat", "rb");
	fread ( &clientes, sizeof(Clientes), 1, archivo );
	do{
        if(strcmp(nitt, clientes.nit)==0){
            encnit=true;
            gotoxy(11,3);cout<<clientes.nombre_cliente<<endl;
            nomb=clientes.nombre_cliente;
            gotoxy(12,4);cout<<clientes.direccion<<endl;
            dir=clientes.direccion;
		}
        fread ( &clientes, sizeof(Clientes), 1, archivo );
		registro += 1;
	} while (feof( archivo ) == 0);

	fclose(archivo);
    if(encnit==false){
        FILE* archivo1 = fopen("registros/clientes.dat", "ab");
        //clientes.nit=nitt;
        strcpy(clientes.nit, nitt);
        fflush(stdin);
        gotoxy(11,3);getline(cin,nomb);
        strcpy(clientes.nombre_cliente, nomb.c_str());
        fflush(stdin);
        gotoxy(12,4);getline(cin,dir);
        strcpy(clientes.direccion, dir.c_str());
        fwrite( &clientes, sizeof(Clientes), 1, archivo1 );
        fclose(archivo1);
    }
    //FILE* archivo1 = fopen("factura.dat", "ab");
    Factura fac;
    ifstream archivolec;
    string conte;
    archivolec.open("registros/factura.dat", ios::in);
    int num=0;
    if(archivolec.fail()){
        cout<<"No fue posible abrir el archivo";
        exit(1);
    }
    else{
        while(archivolec.eof()==false){
            getline(archivolec, conte);
               num=num+1;
        }
    }
    //gotoxy(1,num+1); printf("    \n");
    archivolec.close();
    fac.num_fac=num;
    ofstream archivo2;
    archivo2.open("registros/factura.dat",ios::app);
    if(archivo2.fail()){
        cout<<"no es posible abrir el archivo";
        getch();
        exit(1);
    }
    else {
        fflush(stdin);
        archivo2<<"No. "<<fac.num_fac<<"     FECHA "<<d<<"/"<<m<<"/"<<a<<"     "<<hh<<":"<<mm
        <<"      NIT: "<<nitt<<endl;
    }
    archivo2.close();
    gotoxy(30,5);cout<<"INGRESE DATOS: "<<endl;

    float subtotal=0;
	int indice=0,pos=0,cod=0, id=0;
	//FILE* archivocom = fopen("productos_comprados.txt", "wb");
    ofstream archivo4;
    archivo4.open("imprimir_factura.txt",ios::out);
    if(archivo4.fail()){
        cout<<"no es posible abrir el archivo";
        getch();
        exit(1);
    }
    else {
        fflush(stdin);
        archivo4<<"No. Factura: "<<fac.num_fac<<"                              Fecha: "<<d<<"/"<<m<<"/"<<a<<endl;
        archivo4<<"Nit: "<<nitt<<endl;
        archivo4<<"Cliente: "<<nomb<<endl;
        archivo4<<"Direccion: "<<dir<<endl;
        archivo4<<endl<<"                    PRODUCTO"<<endl<<endl;
    }
    archivo4.close();
	do{
        //cout<<"INGRESE CODIGO DE PRODUCTO: ";
        cin>>codp;
        Productos prod;
        char marcaaa[50];
        FILE* archivoing = fopen("registros/productos.dat", "rb");
        Codigo codd;
        codd.cod_producto=codp;
        //fwrite( &codd, sizeof(Codigo), 1, archivocom );
        do{
            id=id+1;
            fread ( &prod, sizeof(Productos), 1, archivoing );
            if (prod.cod_producto == codp){
                //fread ( &prod, sizeof(Productos), 1, archivoing );
                cout <<"  " << prod.cod_producto <<"\t"<<prod.producto<<"  marca  ";

                FILE* archivoma = fopen("registros/marcas.dat", "rb");
                Marcas marc;
                fread ( &marc, sizeof(Marcas), 1, archivoma );
                    do{
                        if (prod.id_marca==marc.id_marca){
                            cout<<marc.marca;
                            strcpy(marcaaa,marc.marca);
                        }
                        fread ( &marc, sizeof(Marcas), 1, archivoma );
                    } while (feof(archivoma) == 0);
                fclose(archivoma);
                printf("   Q%.2f \n",prod.precio_venta);
                ofstream archivo3;
                archivo3.open("registros/detalle_factura.dat",ios::app);
                if(archivo3.fail()){
                    cout<<"no es posible abrir el archivo";
                    getch();
                    exit(1);
                }
                else {
                    fflush(stdin);
                    archivo3<<"ID DET. FAC "<<id<<"  No. FAC. "<<fac.num_fac<<"   ID PROD."<<prod.cod_producto<<"  Q"<<prod.precio_venta<<endl;
                }
                archivo3.close();
                ofstream archivo4;
                archivo4.open("imprimir_factura.txt",ios::app);
                if(archivo4.fail()){
                    cout<<"no es posible abrir el archivo";
                    getch();
                    exit(1);
                }
                else {
                    fflush(stdin);
                    archivo4<<prod.cod_producto<<"-"<<prod.producto<<" marca "<<marcaaa<<"                     Q";
                    archivo4<< fixed << setprecision(2)<<prod.precio_venta<<endl;
                }
                archivo4.close();
                subtotal=subtotal+prod.precio_venta;

            }
            fread ( &prod, sizeof(Productos), 1, archivoing );
            //indice += 1;
        } while (feof( archivoing ) == 0);
        //fseek ( archivoing,pos * sizeof(Productos), SEEK_SET );
        //fclose(archivocom);
        fclose(archivo);
        if(codp!=0){
            cout<<"___________________________________________________________________"<<endl;
            printf("\t\t\t\t SUBTOTAL: Q%.2f\n", subtotal);
            cout<<"___________________________________________________________________"<<endl;
        }
    }while(codp!=0);
        cout<<"___________________________________________________________________"<<endl;
        printf("\t\t\t\t TOTAL: Q%.2f\n", subtotal);
    archivo4.open("imprimir_factura.txt",ios::app);
    if(archivo4.fail()){
        cout<<"no es posible abrir el archivo";
        getch();
        exit(1);
    }
    else {
        fflush(stdin);
        archivo4<<"                                         ____________________"<<endl;
        archivo4<<"Total:                                       Q"<<subtotal<<endl<<endl;
        archivo4<<"GRACIAS POR SU COMPRA"<<endl;
    }
    archivo4.close();
    getch();
    ifstream in(("imprimir_factura.txt"));
    PrintFile(in);
    in.close();
    return 0;

}

void mostrar_fecha(){
    Fecha_fac fech;
    time_t tSac = time(NULL); // instante actual
    struct tm* tmP = localtime(&tSac);
    //cout << "hh:mm:ss " << tmP->tm_hour << ":" << tmP->tm_min << ":"<< tmP->tm_sec << endl;
    cout<<"\t\t\t\t\t\t\tFECHA: "<<tmP->tm_mday<<"/"<<tmP->tm_mon+1<<"/"<<tmP->tm_year+1900 <<endl<<endl;
    d=tmP->tm_mday;
    m=tmP->tm_mon+1;
    a=tmP->tm_year+1900;
    hh=tmP->tm_hour;
    mm=tmP->tm_min;
    //cout<<d<<"-"<<m+1<<"-"<<a+1900<<endl;
}
bool validar_nit(string nit){
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
        gotoxy(1,25);cout<<"NIT INGRESADO NO CONTIENE GUION      "<<endl;
        real=false;
        //goto inicio;
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
	char digg[tamnum], digtemp;
	int ddiv, mmod,digitos[tamnum], numnumnit, base=10, num1;
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
	} else{
	    real=false;
        gotoxy(6,2); cout<<"           ";

	}
	return real;
}
