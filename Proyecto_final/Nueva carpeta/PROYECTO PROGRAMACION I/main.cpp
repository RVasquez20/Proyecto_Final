#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;
void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);
}

int main(){
        char pp;

    do {
        system("cls");
        //clrscr();
        system("cls");
        system("color 7E");
        printf("\n\n\n\n\n\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("\n\t\t\t²          MENU          ²");
        printf("\n\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²\n\n\n");
        printf("\t\t    ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");
        printf("\t\t    ²²  1. ADIMISTRAR MARCAS          ²²\n");
        printf("\t\t    ²²  2. ADMINISTRAR PRODUCTOS      ²²\n");
        printf("\t\t    ²²  3. IMPRIMIR CODIGO DE BARRAS  ²²\n");
        printf("\t\t    ²²  4. GENERAR FACTURA            ²²\n");
        printf("\t\t    ²²                                ²²\n");
        printf("\t\t    ²²                                ²²\n");
        printf("\t\t    ²²  5. Salir                      ²²\n");
        printf("\t\t    ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        //scanf("%s", &pp);
        pp=getch();
        system("color 7C");
        switch(pp){
            case '1': system("start marcas.exe");break;
            case '2': system("start productos.exe"); break;
            case '3': system("start imprimir.exe"); break;
            case '4': system("start FACTURA.exe");break;
            case '5':{
                system("color 7C");
                gotoxy(30,7);cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²"<<endl;
                gotoxy(30,8);cout<<"²²       FINALIZANDO     ²²"<<endl;
                gotoxy(30,9);cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²"<<endl;
                gotoxy(30,10);cout<<"²²                       ²²"<<endl;
                gotoxy(30,11);cout<<"²²                       ²²"<<endl;
                gotoxy(30,12);cout<<"²²                       ²²"<<endl;
                gotoxy(30,13);cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²"<<endl;
                int ter=0;
                for(ter>0;ter<=17;ter++){
                Sleep(90);
                gotoxy(33+ter,11);cout<<"²°°"<<endl;
                 }
                 exit(0);
            }
            default: gotoxy(30,9);printf("OPCION INVALIDA\n\n\n\n\t\t");Sleep(500);break;
        }
    }while(pp!='5');

    getch();
}
