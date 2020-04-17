#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
using namespace std;
const char *nombre_archivo1 = "registros/auxi.dat";
const char *nombre_archivo3 = "registros/auxi2.dat";
const char *nombre_archivo2 = "registros/productos.dat";
const char *nombre_archivo4 = "registros/marcas.dat";
void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);
}


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
void ingresar_productos();
void confirmar_productos();
void guardar_productos();
void ver_productos();
void ver_marcas();
void eliminar_registro();
void modificar_registro();
int main(){
    char preg;
	do{
		system("cls");
		ver_productos();
		cout<<"\n\n\n\t\t\t\tMENU\n";
		cout<<"\t\t\t1. AGREGAR REGISTROS\n";
		cout<<"\t\t\t2. ELIMINAR REGISTROS\n";
		cout<<"\t\t\t3. MODIFICAR REGISTROS\n";
		cout<<"\t\t\t4. VER MARCAS\n";
		cout<<"\t\t\t5. SALIR\n\t\t\t\t";

		preg=getch();
		switch(preg){
			case '1': ingresar_productos();getch(); remove(nombre_archivo1); break;
			case '2': eliminar_registro(); break;
			case '3': modificar_registro(); break;
			case '4': ver_marcas(); getch(); break;
			case '5': exit(1); break;
			default: cout<<"\n\t\t\t OPCION INVALIDA\n";
		}
	}while(preg!='5');
    getch();
    return 0;
}
void ingresar_productos(){
    system("cls");
	char continuar, idm[200], idmm[200];
	bool comp=true, comp2=true, commp=true, commp2=true;
	FILE* archivo = fopen(nombre_archivo1, "w+b");
    FILE* archivo2 = fopen(nombre_archivo2, "rb");

        int a=0;
		Productos prod;
		Marcas marcas;
        string nombre_prod;
		do{
            //clrscr();
			fflush(stdin);
            do{
                comp=true, comp2=true;
                cout<<endl<<"INGRESE CODIGO DE PRODUCTO: ";
                cin>>idm;
                for(int j=0; j<(strlen(idm)); j++){
                    if(isdigit(idm[j])==0){
                        comp=false;
                    }
                }
                if(comp==false ){
                    cout<<"\t\t\tCODIGO INVALIDO"<<endl;
                }
                fread ( &prod, sizeof(Productos), 1, archivo2 );
                do{
                    if (atoi(idm)==prod.cod_producto){
                        comp2=false;
                    }
                    fread ( &prod, sizeof(Productos), 1, archivo2 );
                } while (feof(archivo2) == 0);
                if(comp2==false ){
                    cout<<"\t\t\tCODIGO YA REGISTRADO";
                }
            }while(comp==false || comp2==false);

            prod.cod_producto=atoi(idm);
            cin.ignore();

            cout<<"INGRESE EL NOMBRE DEL PRODUCTO: ";
            getline(cin,nombre_prod);
            strcpy(prod.producto, nombre_prod.c_str());
            //MARCAS
            do{
                FILE* archivoma = fopen("registros/marcas.dat", "rb");
                commp=true, commp2=false;
                cout<<endl<<"INGRESE ID MARCA: ";
                cin>>idmm;
                for(int j=0; j<(strlen(idmm)); j++){
                    if(isdigit(idmm[j])==0){
                        commp=false;
                    }
                }
                if(commp==false ){
                    cout<<"\t\t\tID IVALIDO"<<endl;
                }
                fread ( &marcas, sizeof(Marcas), 1, archivoma );
                do{
                    if (atoi(idmm)==marcas.id_marca){
                        commp2=true;
                        //cout<<"\t\t\t\t"<<marcas.id_marca<<endl;
                    }
                    fread ( &marcas, sizeof(Marcas), 1, archivoma );
                } while (feof(archivoma) == 0);
                if(commp2==false ){
                    cout<<"\t\t\tID MARCA NO REGISTRADO"<<endl;
                }
            }while(commp==false || commp2==false);
            prod.id_marca=atoi(idmm);

            cout<<"INGRESE PRECIO DE COMPRA: ";
            cin>>prod.precio_costo;

            cout<<"INGRESE PRECIO DE VENTA: ";
            cin>>prod.precio_venta;

            cout<<"INGRESE FECHA DE INGRESO: (dd/mm/aaaa)"<<endl;
            do{
                cout<<"\tDIA: ";
                cin>>prod.fecha.dia;
            }while(prod.fecha.dia>30 || prod.fecha.dia<0);
            do{
                cout<<"\tMES: ";
                cin>>prod.fecha.mes;
            }while(prod.fecha.mes<0 || prod.fecha.mes>12);
            do{
                cout<<"\tANIO: ";
                cin>>prod.fecha.anio;
            }while(prod.fecha.anio>2020 || prod.fecha.anio<2010);
            fwrite( &prod, sizeof(Productos), 1, archivo );
            cout<<"DESEA AGREGAR OTRO PRODUCTO s/n : ";
            continuar=getch();
		} while((continuar=='s') || (continuar=='S') );
	fclose(archivo);
    fclose(archivo2);
    confirmar_productos();
}
void confirmar_productos(){
	system("cls");
	char pp;
	FILE* archivo = fopen(nombre_archivo1, "rb");
	Productos prod;
    int registro=0;
	fread ( &prod, sizeof(Productos), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "COD" <<"|"<< "NOMBRE"<<" | "<< "ID_MARCA" <<" | "<<"PRECIO COSTO"<<" | "<< "PRECIO VENTA" <<"|"<< "FECHA (dd/mm/aaaa)"<<endl;
	do{
		cout<<"____________________________________________________________________"<<endl;
		cout << prod.cod_producto <<" | "<< prod.producto<<" | "<< prod.id_marca <<" | ";
        printf("%.2f | %.2f",prod.precio_costo,prod.precio_venta);
        cout<<" | ("<< prod.fecha.dia<<"/"<< prod.fecha.mes<<"/"<< prod.fecha.anio<<")"<<endl;
		fread ( &prod, sizeof(Productos), 1, archivo );
		registro += 1;
	} while (feof( archivo ) == 0);
    do{
        pp='s';
        //if(pp!='s' || pp!='S'){ cout<<"\t\t\tOPCION INVALIDA"<<endl;}
        cout<<endl<<endl<<"DESEA GUARDAR LAS MARCAS INGRESADAS: (S/N): ";
        //cin>>pp;
        pp=getch();
    }while(pp!='s' && pp!='n');
    if(pp=='s' || pp=='S')  guardar_productos();
    else remove(nombre_archivo1);

	fclose(archivo);
}
void guardar_productos(){
    system("cls");
	FILE* archivo = fopen(nombre_archivo1, "rb");
	FILE* orig = fopen(nombre_archivo2, "ab"); // ab
	//FILE* elim = fopen("elim.dat", "ab"); // ab

	char nom[50];
	int indice=0,pos=0,cod=0, enco=false, nuum=0, numel=0;
	fflush(stdin);
	Productos prod;
		fread ( &prod, sizeof(Productos), 1, archivo );
		do{
			    //fread ( &estudiante, sizeof(Estudiante), 1, archivo );
            fwrite( &prod, sizeof(Productos), 1, orig );
            fflush(stdin);
            fread ( &prod, sizeof(Productos), 1, archivo );
            nuum=nuum+1;
    	} while (feof(archivo) == 0);

	fclose(archivo);
	fclose(orig);
	//fclose(elim);
	remove("registros/auxi.dat");
   system("cls");
    int a=100, ac=0,ac2=0;
    ani1:
    ac2=ac2+1;

    for(int ter=0;ter<=10;ter++){
        gotoxy(27,6);cout<<"Guardando";
        Sleep(a);
        gotoxy(36+ac,6); cout<<".";
        ac=ac+1;
    }
    //clrscr();
    gotoxy(27,6);cout<<"GUARDADO        ";

	//remove("elim.dat");
	getch();
}
void ver_marcas(){
    system("cls");
	FILE* archivo = fopen(nombre_archivo4, "rb");
	Marcas marcas;
	int registro=0;
	fread ( &marcas, sizeof(Marcas), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "ID" <<"|"<< "NOMBRE"<<endl;
	do{
		cout<<"____________________________________________________________________"<<endl;
		cout << marcas.id_marca <<" | "<< marcas.marca<<endl;
		fread ( &marcas, sizeof(Marcas), 1, archivo );
		registro += 1;
	} while (feof( archivo ) == 0);
    cout<<endl;
	fclose(archivo);
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

void eliminar_registro(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo2, "rb");
	FILE* aux = fopen(nombre_archivo3, "w+b");
    bool comp=true;
	char nom[50], idm[200];
	int indice=0,pos=0,cod=0, enco=false, nuum=0, numel=0;
	ver_productos();
	//cin>>cod;
	do{
        comp=true;
        cout<<"INGRESE ID A ELIMINAR: ";
        cin>>idm;
        for(int j=0; j<(strlen(idm)); j++){
            if(isdigit(idm[j])==0){
                comp=false;
            }
        }
        if(comp==false ){
            cout<<"ID IVALIDO"<<endl;
        }
    }while(comp==false );
    cod=atoi(idm);

	fflush(stdin);
	Productos prod;
		fread ( &prod, sizeof(Productos), 1, archivo );
		do{
			if (cod!=prod.cod_producto){
                fwrite( &prod, sizeof(Productos), 1, aux );
				fflush(stdin);
            } else{
                enco=true;
                cout<<"Registro Eliminado"<<endl;
                cout<<endl;
			}
			fread ( &prod, sizeof(Productos), 1, archivo );
            nuum=nuum+1;
    	} while (feof(archivo) == 0);
    	if(enco==false){
    		cout<<"\nNO SE ENCONTRO REGISTRO CON ESE NOMBRE\n\n";
		}
	fclose(archivo);
	fclose(aux);
	//fclose(elim);
	remove(nombre_archivo2);
	//remove("elim.dat");
	rename(nombre_archivo3, nombre_archivo2);
	system("PAUSE");
}
void modificar_registro(){
	system("cls");
	char continuar, idmm[200];
	bool comp=true, comp1=true, comp2=true, commp1=true, commp2=true, commp=true;
    int a=0;
    Marcas marcas;
    string nombre_prod;
    FILE* archivo2 = fopen(nombre_archivo3, "w+b");
    FILE* archivo = fopen(nombre_archivo2, "rb");

	char nom[50], n1, idm[200];
	int indice=0,pos=0,cod=0, enco=false, nuum=0, numel=0;
	ver_productos();
	//cin>>cod;
	do{
        comp=true;
        cout<<"INGRESE ID A MODIFICAR: ";
        cin>>idm;
        for(int j=0; j<(strlen(idm)); j++){
            if(isdigit(idm[j])==0){
                comp=false;
            }
        }
        if(comp==false ){
            cout<<"ID INVALIDO"<<endl;
        }
    }while(comp==false );
    cod=atoi(idm);
	fflush(stdin);
	Productos prod;
		fread ( &prod, sizeof(Productos), 1, archivo );
		do{
			if (cod==prod.cod_producto){
                enco=true;
                cout<<"INGRESE CAMPO A MODIFICAR\n";
				cout<<"1. CODIGO\n";
				cout<<"2. NOMBRE\n";
				cout<<"3. ID MARCA\n";
				cout<<"4. PRECIO COSTO\n";
				cout<<"5. PRECIO VENTA\n";
				cout<<"6. FECHA\n";
				n1=getch();
				switch(n1){
					case '1':{
						do{
                            comp=true, comp2=true;
                            cout<<endl<<"INGRESE CODIGO DE PRODUCTO: ";
                            cin>>idm;
                            for(int j=0; j<(strlen(idm)); j++){
                                if(isdigit(idm[j])==0){
                                    comp=false;
                                }
                            }
                            if(comp==false ){
                                cout<<"\t\t\tCODIGO IVALIDO"<<endl;
                            }
                            fread ( &prod, sizeof(Productos), 1, archivo2 );
                            do{
                                if (atoi(idm)==prod.cod_producto){
                                    comp2=false;
                                }
                                fread ( &prod, sizeof(Productos), 1, archivo2 );
                            } while (feof(archivo2) == 0);
                            if(comp2==false ){
                                cout<<"\t\t\tCODIGO YA REGISTRADO";
                            }
                        }while(comp==false || comp2==false);
                        prod.cod_producto=atoi(idm);
                        cin.ignore();
						break;
					}
					case '2':{
						cout<<"INGRESE EL NOMBRE DEL PRODUCTO: ";
                        getline(cin,nombre_prod);
                        strcpy(prod.producto, nombre_prod.c_str());
						break;
					}
					case '3':{
					    do{
                            FILE* archivoma = fopen("registros/marcas.dat", "rb");
                            commp=true, commp2=false;
                            cout<<endl<<"INGRESE ID MARCA: ";
                            cin>>idmm;
                            for(int j=0; j<(strlen(idmm)); j++){
                                if(isdigit(idmm[j])==0){
                                    commp=false;
                                }
                            }
                            if(commp==false ){
                                cout<<"\t\t\tID IVALIDO"<<endl;
                            }
                            fread ( &marcas, sizeof(Marcas), 1, archivoma );
                            do{
                                if (atoi(idmm)==marcas.id_marca){
                                    commp2=true;
                                    //cout<<"\t\t\t\t"<<marcas.id_marca<<endl;
                                }
                                fread ( &marcas, sizeof(Marcas), 1, archivoma );
                            } while (feof(archivoma) == 0);
                            if(commp2==false ){
                                cout<<"\t\t\tID MARCA NO REGISTRADO"<<endl;
                            }
                        }while(commp==false || commp2==false);
                        prod.id_marca=atoi(idmm);
						//cin>>prod.producto;
        				//cin.ignore();
						break;
					}
					case '4':{
                        cout<<"INGRESE PRECIO DE COMPRA: ";
                        cin>>prod.precio_costo;
                        break;
					}
                    case '5':{
                        cout<<"INGRESE PRECIO DE VENTA: ";
                        cin>>prod.precio_venta;
                        break;
					}
                    case '6':{
                        cout<<"INGRESE FECHA DE INGRESO: (dd/mm/aaaa)"<<endl;
                        do{
                            cout<<"\tDIA: ";
                            cin>>prod.fecha.dia;
                        }while(prod.fecha.dia>30 || prod.fecha.dia<0);
                        do{
                            cout<<"\tMES: ";
                            cin>>prod.fecha.mes;
                        }while(prod.fecha.mes<0 || prod.fecha.mes>12);
                        do{
                            cout<<"\tANIO: ";
                            cin>>prod.fecha.anio;
                        }while(prod.fecha.anio>2018 || prod.fecha.anio<2010);
                        break;
					}
					default:{
						cout<<"Ingrese opcion valida";
						break;
					}
				}
				cout<<endl;
			}
			fwrite( &prod, sizeof(Productos), 1, archivo2 );
			fread ( &prod, sizeof(Productos), 1, archivo );
            nuum=nuum+1;
    	} while (feof(archivo) == 0);
    	if(enco==false){
    		cout<<"\nNO SE ENCONTRO REGISTRO CON ESE CODIGO\n\n";
		}
	fclose(archivo);
	fclose(archivo2);
	//fclose(elim);
	remove(nombre_archivo2);
	//remove("elim.dat");
	rename(nombre_archivo3, nombre_archivo2);
	system("PAUSE");
}
