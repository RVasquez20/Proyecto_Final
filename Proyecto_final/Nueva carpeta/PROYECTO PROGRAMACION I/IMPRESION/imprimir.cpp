#include <windows.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

typedef std::basic_ifstream<TCHAR> tifstream;
typedef std::basic_string<TCHAR> tstring;

void Outtextxy(HDC hdc,int x,int y,tstring Msg)
{
TextOut(hdc,x,y,Msg.c_str(),static_cast<int>(Msg.length()));
}

void ShowError(tstring strMsg)
{
MessageBox (NULL,strMsg.c_str(),TEXT("Imprimir"),MB_ICONERROR );
exit(1);
}
void ShowInformation(tstring strText)
{
MessageBox (NULL,strText.c_str(),TEXT("Imprimir"),MB_ICONINFORMATION);
}
void PrintFile(tifstream& f)
{
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

int main(int argc,char *argv[])
{

tifstream in(TEXT("texto.txt")); /* acá va escrito el nombre del archivo que quieres imprimir */
PrintFile(in);

in.close();
return 0;
}
