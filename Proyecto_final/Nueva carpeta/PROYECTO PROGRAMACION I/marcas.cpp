#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
using namespace std;
const char *nombre_archivo1 = "registros/auxi.dat";
const char *nombre_archivo3 = "registros/auxi2.dat";
const char *nombre_archivo2 = "registros/marcas.dat";

struct Marcas{
    int id_marca;
    char marca[50];
};
void ingresar_marcas();
void confirmar_marcas();
void guardar_marcas();
void ver_marcas();
void eliminar_registro();
void modificar_registro();
int main(){
    char preg;
	do{
		system("cls");
		ver_marcas();
		cout<<"\n\n\n\t\t\t\tMENU\n";
		cout<<"\t\t\t1. AGREGAR REGISTROS\n";
		cout<<"\t\t\t2. ELIMINAR REGISTROS\n";
		cout<<"\t\t\t3. MODIFICAR REGISTROS\n";
		cout<<"\t\t\t4. SALIR\n\t\t\t\t";

		preg=getch();
		switch(preg){
			case '1': ingresar_marcas();getch(); remove(nombre_archivo1); break;
			case '2': eliminar_registro(); break;
			case '3': modificar_registro(); break;
			case '4': exit(1); break;
			default: cout<<"\n\t\t\t OPCION INVALIDA\n";
		}
	}while(preg!='4');
    getch();
    return 0;
}
void ingresar_marcas(){
    system("cls");
	char continuar, idm[200];
	bool comp=true, comp2=true;
	FILE* archivo = fopen(nombre_archivo1, "a+b");
    FILE* archivo2 = fopen(nombre_archivo2, "rb");
        int a=0;
		Marcas marcas;
        string nombre_marca;
		do{
			fflush(stdin);
            do{
                comp=true, comp2=true;
                cout<<endl<<"INGRESE ID MARCA: ";
                cin>>idm;
                for(int j=0; j<(strlen(idm)); j++){
                    if(isdigit(idm[j])==0){
                        comp=false;
                    }
                }
                if(comp==false ){
                    cout<<"\t\t\tID IVALIDO"<<endl;
                }
                fread ( &marcas, sizeof(Marcas), 1, archivo2 );
                do{
                    if (atoi(idm)==marcas.id_marca){
                        comp2=false;
                        cout<<"\t\t\t\t"<<marcas.id_marca<<endl;
                    }
                    fread ( &marcas, sizeof(Marcas), 1, archivo2 );
                } while (feof(archivo2) == 0);
                if(comp2==false ){
                    cout<<"\t\t\tID YA REGISTRADO";
                }
            }while(comp==false || comp2==false);

            marcas.id_marca=atoi(idm);
            cin.ignore();
            cout<<"INGRESE EL NOMBRE DE LA MARCA: ";
            getline(cin,nombre_marca);
            strcpy(marcas.marca, nombre_marca.c_str());

            fwrite( &marcas, sizeof(Marcas), 1, archivo );

            cout<<"Desea Agregar otro Nombre s/n : ";
            continuar=getch();
		} while((continuar=='s') || (continuar=='S') );
	fclose(archivo);
    fclose(archivo2);
    confirmar_marcas();
}
void confirmar_marcas(){
	system("cls");
	char pp;
	FILE* archivo = fopen(nombre_archivo1, "rb");
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
    do{
        if(pp!='s' && pp!='S'){ cout<<"\t\t\tOPCION INVALIDA"<<endl;}
        cout<<endl<<endl<<"DESEA GUARDAR LAS MARCAS INGRESADAS: (S/N): ";
        pp=getch();
    }while((pp!='s' && pp!='S') && (pp!='n' && pp!='N'));
    if(pp=='s' || pp=='S')  guardar_marcas();
    if(pp=='n' || pp=='N') remove(nombre_archivo1);

	fclose(archivo);
}
void guardar_marcas(){
    system("cls");
	FILE* archivo = fopen(nombre_archivo1, "rb");
	FILE* orig = fopen(nombre_archivo2, "ab"); // ab
	//FILE* elim = fopen("elim.dat", "ab"); // ab

	char nom[50];
	int indice=0,pos=0,cod=0, enco=false, nuum=0, numel=0;
	fflush(stdin);
	Marcas marcas;
		fread ( &marcas, sizeof(Marcas), 1, archivo );
		do{
			    //fread ( &estudiante, sizeof(Estudiante), 1, archivo );
            fwrite( &marcas, sizeof(Marcas), 1, orig );
            fflush(stdin);
            fread ( &marcas, sizeof(Marcas), 1, archivo );
            nuum=nuum+1;
    	} while (feof(archivo) == 0);

	fclose(archivo);
	fclose(orig);
	//fclose(elim);
	remove(nombre_archivo1);
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
    clrscr();
    gotoxy(27,6);cout<<"GUARDADO        ";

	//remove("elim.dat");
	getch();
}
void ver_marcas(){
    system("cls");
	FILE* archivo = fopen(nombre_archivo2, "rb");
	Marcas marcas;
	int registro=0;
	fread ( &marcas, sizeof(Marcas), 1, archivo );
	cout<<"             _____________________________________________________"<<endl;
	cout << "              ID" <<"          |        "<< "NOMBRE"<<endl;
	do{
		cout<<"             _____________________________________________________";
		cout <<endl<<"              "<< marcas.id_marca <<"        ";
		printf("%c",179);
		cout<<"    "<< marcas.marca<<endl;
		fread ( &marcas, sizeof(Marcas), 1, archivo );
		registro += 1;
	} while (feof( archivo ) == 0);
    cout<<"             _____________________________________________________"<<endl;
    for(int i=0; i<(registro*2)+2; i++){
        gotoxy(13,2+i); printf("%c",179);
        gotoxy(67,2+i); printf("%c",179);
    }

    cout<<endl;
	fclose(archivo);
}
void eliminar_registro(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo2, "rb");
	FILE* aux = fopen(nombre_archivo3, "ab");
    bool comp=true;
	char nom[50], idm[200];
	int indice=0,pos=0,cod=0, enco=false, nuum=0, numel=0;
	ver_marcas();
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
	Marcas marcas;
		fread ( &marcas, sizeof(Marcas), 1, archivo );
		do{
			if (cod!=marcas.id_marca){
                fwrite( &marcas, sizeof(Marcas), 1, aux );
				fflush(stdin);
            } else{
                enco=true;
                cout<<"Registro Eliminado"<<endl;
                cout<<endl;
			}
			fread ( &marcas, sizeof(Marcas), 1, archivo );
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
	FILE* archivo = fopen(nombre_archivo2, "rb");
	FILE* aux = fopen(nombre_archivo3, "ab"); // ab
	char nom[50], n1, idm[200];
	bool comp=true;
	int indice=0,pos=0,cod=0, enco=false, nuum=0, numel=0;
	ver_marcas();
	//cin>>cod;
	do{
        comp=true;
        cout<<endl<<endl<<"INGRESE ID A MODIFICAR: ";
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
	Marcas marcas;
		fread ( &marcas, sizeof(Marcas), 1, archivo );
		do{
			if (cod==marcas.id_marca){
                enco=true;
                cout<<"INGRESE CAMPO A MODIFICAR\n";
				cout<<"1. ID\n";
				cout<<"2. NOMBRE\n";

				n1=getch();
				switch(n1){
					case '1':{
						cout<<"INGRESE NUEVO ID: ";
						cin>>marcas.id_marca;
        				cin.ignore();
						break;
					}
					case '2':{
						cout<<"INGRESE NUEVO NOMBRE: ";
						cin>>marcas.marca;
        				cin.ignore();
						break;
					}
					default:{
						cout<<"Ingrese opcion valida";
						break;
					}
				}
				cout<<endl;
			}
			fwrite( &marcas, sizeof(Marcas), 1, aux );
			fread ( &marcas, sizeof(Marcas), 1, archivo );
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
