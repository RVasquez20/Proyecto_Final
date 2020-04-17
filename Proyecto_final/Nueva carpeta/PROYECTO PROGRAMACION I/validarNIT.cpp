#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
using namespace std;

int main(){
    inicio:
  //  clrscr();
    bool real;
    string nit;
    cout<<"INGRESE NIT CON GUION: ";
    getline(cin, nit);
    fflush(stdin);
    //cout<<nit.substr(0,5)<<endl;
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
        cout<<"NIT INGRESADO NO CONTIENE GUION";
        getch();
        goto inicio;
    }
	char *token, *aux, *numnit;
	token=strtok(frase, "-");
	//cout<<token<<endl;
    int numval, tamnum;
	while(token != NULL && ver==true){
        aux=token;
		//cout<<token<<endl;
		token=strtok(NULL,"-");
		if(token==NULL){
			//cout<<aux;
			numval=atoi(aux);
		} else{
			//cout<<aux<<endl;
			numnit=aux;
			tamnum=strlen(aux);
		}
	}
	char digg[tamnum], digtemp;
	int ddiv, mmod,digitos[tamnum], numnumnit, base=10, num1;
	num1=atoi(numnit);
	//digtemp=*numnit;
	//cout<<endl<<numval<<endl<<numnit<<endl<<tamnum;
	for(int i=0; i<tamnum; i++){
        num1=numnit[i]- '0';
        digitos[i]=num1;
        //int ia = a - '0'
        //strcpy(digg,numnit);
        //digitos[i]=atoi(digg[i]);
	}
	//cout<<endl<<endl<<endl;
    int j=1, acum=0, mult, n1,n2,n3,n4, n5, codv, codigo;
    for(int i=tamnum-1; i>=0; i--){
        j++;
        mult=digitos[i]*j;
        //cout<<digitos[i]<<" * "<<j<<" = "<<mult<<endl ;
        acum=acum+mult;
    }
    //cout<<endl<<"\t\t"<<acum;
	n1=acum/11;
	n2=n1*11;
	n3=acum-n2;
	n4=n3/11;
	n5=n4*11;
	codv=n3-n5;
	codigo=11-codv;
	if(numval==codigo){
        cout<<"NIT CORRECTO";
        real=true;
	} else{
	    real=false;
        cout<<"NIT INCORRECTO";
        getch();
        goto inicio;
	}
	getch();

}
