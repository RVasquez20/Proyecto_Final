#include <librerias.h>
#include <time.h>
#include <fstream>
#include <ctype.h>
#include<iomanip>
#include "SerialClass.h"
char CT = 203, LTI = 204, H = 205, CRUZ = 206, CB = 202, TOPE = 201, EIA = 201, EIB = 200, LTD = 185, V = 186, EDA = 187, EDB = 188, P = 177;

#define HOR cout << H << H << H << H << H << H << H << H << H;
#define PUN cout << P << P << P << P << P << P << P << P << P << P;
#define VER cout << V;
#define separador2 cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
#define ARAR cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
#define AREN cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
#define ARENBJ cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
#define ABJ cout << EIB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDB << endl;
#define arriba cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
#define separador cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
#define abajo cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;

struct Marcas
{
    int idMarca;
    char NombreMarca[50];
};
typedef Marcas Marca;

struct fecha
{
    int d, m, a, hh, mm, ss;
};
typedef fecha Fechas;

struct Productos
{
    int CodigoProducto, idMarca;
    char DescripcionProducto[100];
    double PrecioCosto, PrecioVenta;
    struct fecha FechaDeIngreso;
};
typedef Productos Producto;

struct Clientes
{
    char NIT[12];
    char NombreCliente[50], DireccionCliente[50];
};
typedef Clientes Cliente;

struct Facturas
{
    int NoFactura;
    char NITFactura[12];
    struct fecha FechaFactura;
};
typedef Facturas Factura;

struct FacturasDetalle
{
    int *idProductos, NoFactura, IdFacturaDetalle;
    double *PrecioVenta;
};
typedef FacturasDetalle FacturaDetalle;

struct Supervisores
{
    char usuario[50],Pass[50],nombre[50],Dir[50];
    long long int DPI;
};
typedef Supervisores Datos;
//Arduino
Serial::Serial(const char *portName)
{

    this->connected = false;


    this->hSerial = CreateFile(portName,
                               GENERIC_READ | GENERIC_WRITE,
                               0,
                               NULL,
                               OPEN_EXISTING,
                               FILE_ATTRIBUTE_NORMAL,
                               NULL);


    if(this->hSerial==INVALID_HANDLE_VALUE)
    {

        if(GetLastError()==ERROR_FILE_NOT_FOUND)
        {

            //Imprime error si es necesario
            printf("ERROR: Handle was not attached. Reason: %s not available.\n", portName);

        }
        else
        {
            printf("ERROR!!!");
        }
    }
    else
    {

        DCB dcbSerialParams = {0};


        if (!GetCommState(this->hSerial, &dcbSerialParams))
        {

            printf("failed to get current serial parameters!");
        }
        else
        {

            dcbSerialParams.BaudRate=CBR_9600;
            dcbSerialParams.ByteSize=8;
            dcbSerialParams.StopBits=ONESTOPBIT;
            dcbSerialParams.Parity=NOPARITY;

            dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;


            if(!SetCommState(hSerial, &dcbSerialParams))
            {
                printf("ALERT: Could not set Serial Port parameters");
            }
            else
            {

                this->connected = true;

                PurgeComm(this->hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);

                Sleep(ARDUINO_WAIT_TIME);
            }
        }
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Serial::~Serial()
{

    if(this->connected)
    {

        this->connected = false;

        CloseHandle(this->hSerial);
    }
}

int Serial::ReadData(char *buffer, unsigned int nbChar)
{

    DWORD bytesRead;

    unsigned int toRead;


    ClearCommError(this->hSerial, &this->errors, &this->status);


    if(this->status.cbInQue>0)
    {

        if(this->status.cbInQue>nbChar)
        {
            toRead = nbChar;
        }
        else
        {
            toRead = this->status.cbInQue;
        }


        if(ReadFile(this->hSerial, buffer, toRead, &bytesRead, NULL) )
        {
            return bytesRead;
        }

    }

    return 0;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Serial::WriteData(const char *buffer, unsigned int nbChar)
{
    DWORD bytesSend;


    if(!WriteFile(this->hSerial, (void *)buffer, nbChar, &bytesSend, 0))
    {

        ClearCommError(this->hSerial, &this->errors, &this->status);

        return false;
    }
    else
        return true;
}

bool Serial::IsConnected()


{

    return this->connected;
}
//Variables Globales para la fecha y hora
time_t tSac = time(NULL);
struct tm *tmP = localtime(&tSac);
Serial* Puerto = new Serial("COM6");
char opc;          //opciones de funciones del do while
bool real = false; //Verificacion de nit
int IA = 0;        //Incremento Automatico XD
//Prototipos de Funciones Del Programa
void MenuPrincipal();
bool VerificadorDeNumeros(string);
void Minusculas(string &);
void MenuMarcas();
void IngresoDeMarcas();
void MostrarMarcas();
void ModificarMarca();
void EliminarMarca();
void MenuInventario();
void MenuIngresoProductos();
void IngresoProductos();
void MostrarProductos();
void BuscarProductos();
void SearchProductsForName();
void SearchProductsForCode();
void ModificarProductos();
void EliminarProducto();
void Codigo_barra();
void MenuFacturas();
void Facture();
bool ValidacionNIT(string);
int Contador(int);
void ProductosAComprar();
void MenuBusquedaCliente();
void SearchWhitName();
void SearchClientWhitNIT();
void MenuBusquedaFactura();
void SearchWhitCorrelative();
void SearchFactureWhitNIT();
void MenuAyuda();
void Actualizacion(int, int);
void Errores();
void login();
bool loginAdmins();
void MenuAdmin();
void Admin();
void MostrarSupervisores();
void EliminarSupervisores();
void generador(int );
void ImportacionCSV();
void creditos();
void ModoBanda();
void ApagarBanda();
void Clave(string,string,long long int);
main()
{

    system("color 0A");
    Puerto->WriteData("c",sizeof("c")-1);
    SetConsoleTitle("Supermercado UMG");
    ifstream Archivo;
    string contenido;
    Archivo.open("Source/background.txt",ios::in);
    while(!Archivo.eof())
    {
        getline(Archivo,contenido);
        cout<<contenido<<endl;
    }
    Archivo.close();

system("start Inicio.vbs");

    gotoxy(40,21);
    cout << "Bienvenidos al Programa Supermercado"<<endl;
    gotoxy(43,22);
    cout << "Hecho por Grupo Guido Van Rossum"<<endl;
    gotoxy(50,23);
    cout << "HAL9000 CORP"<<endl;
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
        Sleep(90);
    }
    system("CLS");


    MenuPrincipal();
}
bool VerificadorDeNumeros(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}
void MenuPrincipal()
{
    char opc;
    SetConsoleTitle("MENU PRINCIPAL");
    system("CLS");
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 1);
        HOR;
    }
    for (int a = 2; a <= 4; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 2);
        PUN;
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 3);
        PUN;
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 4);
        PUN;
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 5);
        HOR;
    }
    gotoxy(46, 3);
    cout << " M E N U   P R I N C I P A L ";
    for (int a = 2; a <= 4; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 1);
    cout << TOPE;
    gotoxy(110, 1);
    cout << EDA;
    gotoxy(9, 5);
    cout << EIB;
    gotoxy(110, 5);
    cout << EDB;

    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 7);
        HOR;
    }
    for (int a = 8; a <= 27; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 28);
        HOR;
    }
    for (int a = 8; a <= 27; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 7);
    cout << TOPE;
    gotoxy(110, 7);
    cout << EDA;
    gotoxy(9, 28);
    cout << EIB;
    gotoxy(110, 28);
    cout << EDB;
    for (int a = 8; a <= 26; a++)
    {
        gotoxy(35, a);
        VER
    }
    for (int a = 8; a <= 26; a++)
    {
        gotoxy(84, a);
        VER
    }
    gotoxy(35, 10);
    cout << V << "              -->   [1] MARCAS                  " << V;
    gotoxy(35, 12);
    cout << V << "              -->   [2] INVENTARIO              " << V;
    gotoxy(35, 14);
    cout << V << "              -->   [3] FACTURAS                " << V;
    gotoxy(35, 16);
    cout << V << "              -->   [4] MODO DE BANDA           " << V;
    gotoxy(35, 18);
    cout << V << "              -->   [5] AYUDA                   " << V;
    gotoxy(35, 22);
    ARENBJ;
    gotoxy(35, 26);
    ABJ;
    gotoxy(35, 24);
    cout << V << "                  ESC. SALIR                    " << V;
    gotoxy(35, 27);
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
        if(loginAdmins())
        {
            ModoBanda();
        }
        else
        {
            MenuPrincipal();
        }


        break;
    }
    case '5':
    {
        MenuAyuda();
        getch();
        MenuPrincipal();
        break;
    }
    case 27:
    {
         system("start Salida.vbs");
        ApagarBanda();
        gotoxy(7,31);
        exit(0);
        break;
    }
    default:
    {
        cout << " \aOPCION INCORRECTA, ELIJA NUEVAMENTE " << endl;
        getch();
        MenuPrincipal();
        break;
    }
    }
}
void MenuMarcas()
{
    char opc;
    SetConsoleTitle("MENU DE MARCAS");
    system("CLS");
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 5);
        HOR;
    }
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 6);
        PUN;
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 7);
        HOR;
    }
    gotoxy(50, 6);
    cout << " M  A  R  C  A  S ";
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 5);
    cout << TOPE;
    gotoxy(110, 5);
    cout << EDA;
    gotoxy(9, 7);
    cout << EIB;
    gotoxy(110, 7);
    cout << EDB;

    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 9);
        HOR;
    }
    for (int a = 9; a <= 24; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 24);
        HOR;
    }
    for (int a = 9; a <= 24; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 9);
    cout << TOPE;
    gotoxy(110, 9);
    cout << EDA;
    gotoxy(9, 24);
    cout << EIB;
    gotoxy(110, 24);
    cout << EDB;
    for (int a = 10; a <= 22; a++)
    {
        gotoxy(35, a);
        VER
    }
    for (int a = 10; a <= 22; a++)
    {
        gotoxy(84, a);
        VER
    }
    gotoxy(35, 11);
    cout << V << " -->   [1] INGRESO DE MARCAS                    " << V;
    gotoxy(35, 13);
    cout << V << " -->   [2] VISUALIZACION DEL LISTADO DE MARCAS  " << V;
    gotoxy(35, 15);
    cout << V << " -->   [3] MODIFICACION DE MARCAS               " << V;
    gotoxy(35, 17);
    cout << V << " -->   [4] ELIMINACION DE MARCAS                " << V;
    gotoxy(35, 19);
    ARENBJ;
    gotoxy(35, 23);
    ABJ;
    gotoxy(35, 21);
    cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
    gotoxy(35, 25);
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
        case 27:
        {  system("start Salida.vbs");
            ApagarBanda();
            exit(0);
            break;
        }
        default:
        {
            cout << "\aOPCION INCORRECTA, ELIJA NUEVAMENTE" << endl;
            getch();
            MenuMarcas();
            break;
        }
        }
    }
}
void IngresoDeMarcas()
{
    fflush(stdin);
    SetConsoleTitle("INGRESO DE MARCAS");
    Marcas Marca;
    char opc;
    FILE *ArchivoMarcas = fopen("Source/Marcas.dat", "a+b");
loop:
    rewind(ArchivoMarcas);
    string AUX;
    int AuxIdMarca;
    system("CLS");
    fflush(stdin);
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 3);
        PUN;
    }
    gotoxy(44, 3);
    cout << " I N G R E S O   D E   M A R C A S ";

    cout << "\n\n\n\t\t ID DE LA MARCA -> ";
    getline(cin, AUX);
    if (VerificadorDeNumeros(AUX))
    {
        AuxIdMarca = atoi(AUX.c_str());
    }
    else
    {
        for (int a = 11; a <= 99; a++)
        {
            gotoxy(a, 9);
            PUN;
        }
        cout << "\n\n\t   * EL INGRESO DE LETRAS O NUMEROS NEGATIVOS ES INCORRECTO, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
        getch();
        system("CLS");
        goto loop;
    }
    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
    while (!feof(ArchivoMarcas))
    {
        if (AuxIdMarca == Marca.idMarca)
        {
            cout << "\n\n\t\t\t\t\t   * EL ID QUE INGRESO YA EXISTE *" << endl;
            getch();
            goto loop;
        }
        fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
    }
    fflush(stdin);
    Marca.idMarca = AuxIdMarca;
    cout << "\n\n\n\t\t NOMBRE DE LA MARCA -> ";
    cin.getline(Marca.NombreMarca, 50, '\n');
    fflush(stdin);
    fwrite(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 13);
        PUN;
    }
    cout << "\n\n\t\t\t\t\tDESEA INGRESAR OTRO REGISTRO? (S | N) -> ";
    cin >> opc;
    if (opc == 'S' || opc == 's')
    {
        goto loop;
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 17);
        PUN;
    }
    cout << "\n\n\t\t\t\t\t\t* GUARDADO EXITOSAMENTE *" << endl;
    fclose(ArchivoMarcas);
}
void MostrarMarcas()
{
    system("CLS");
    int Filas = 7, FilasTotales = 7;
    SetConsoleTitle("LISTADO DE MARCAS");
    Marcas Marca;
    FILE *ArchivoMarcas = fopen("Source/Marcas.dat", "rb");
    if (ArchivoMarcas == NULL)
    {
        cout << " ERROR 001 " << endl;
        getch();
        MenuMarcas();
    }
    else
    {
        system("CLS");
        fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
        for (int a = 11; a <= 100; a++)
        {
            gotoxy(a, 2);
            PUN;
        }
        gotoxy(43, 2);
        cout << " L I S T A D O  D E  M A R C A S ";
        gotoxy(25, 4);
        cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
        gotoxy(25, 5);
        cout << V;
        gotoxy(27, 5);
        cout << "I D  M A R C A";
        gotoxy(42, 5);
        cout << V;
        gotoxy(63, 5);
        cout << "N O M B R E";
        gotoxy(94, 5);
        cout << V << endl;
        gotoxy(25, 6);
        separador;

        while (!feof(ArchivoMarcas))
        {
            gotoxy(25, Filas);
            cout << V;
            gotoxy(32, Filas);
            cout << Marca.idMarca;
            gotoxy(42, Filas);
            cout << V;
            gotoxy(66, Filas);
            cout << Marca.NombreMarca;
            gotoxy(94, Filas);
            cout << V << endl;
            ++Filas;
            ++FilasTotales;
            fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
        }
        gotoxy(25, FilasTotales);
        cout << EIB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDB << endl;
        fclose(ArchivoMarcas);
    }
}
void ModificarMarca()
{
    SetConsoleTitle("MODIFICACION DE MARCAS");
inicio:
    fflush(stdin);
    Marcas Marca;
    FILE *ArchivoMarcas = fopen("Source/Marcas.dat", "r+b");
    int AuxIdMarca, existe = 0, aux2;
    string AUX;
    system("CLS");
    fflush(stdin);
    MostrarMarcas();
    cout << "\n\n\n\t\t ID DE LA MARCA QUE DESEA MODIFICAR -> ";
    cin >> AUX;
    fflush(stdin);
    if (VerificadorDeNumeros(AUX))
    {
        fflush(stdin);
        AuxIdMarca = atoi(AUX.c_str());
    }
    else
    {
        cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
        getch();
        system("CLS");
        goto inicio;
    }
    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
    while (!feof(ArchivoMarcas))
    {
        if (AuxIdMarca == Marca.idMarca)
        {
            cout << "\n\t\t ID MARCA: " << Marca.idMarca << endl;
            cout << "\t\t NOMBRE DE LA MARCA: " << Marca.NombreMarca << endl
                 << endl;
            getch();
            int pos = ftell(ArchivoMarcas) - sizeof(Marcas);

            fflush(stdin);
loop:
            system("CLS");

            for (int a = 11; a <= 99; a++)
            {
                gotoxy(a, 3);
                PUN;
            }
            gotoxy(38, 3);
            cout << " M O D I F I C A C I O N   D E   M A R C A S ";
            cout << "\n\n\n\t\t ID NUEVO -> ";
            cin >> aux2;
            fflush(stdin);
            rewind(ArchivoMarcas);
            fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
            while (!feof(ArchivoMarcas))
            {
                if (aux2 == Marca.idMarca)
                {
                    for (int a = 11; a <= 99; a++)
                    {
                        gotoxy(a, 8);
                        PUN;
                    }
                    cout << "\n\n\t\t\t\t\t   * EL ID INGRESADO YA EXISTE *" << endl;
                    getch();
                    goto loop;
                }
                fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
            }
            fflush(stdin);

            Marca.idMarca = aux2;
            fflush(stdin);
            fseek(ArchivoMarcas, pos, SEEK_SET);
            cout << "\n\n\n\t\t NOMBRE NUEVO -> ";
            cin.getline(Marca.NombreMarca, 50, '\n');
            fflush(stdin);
            fwrite(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
            for (int a = 11; a <= 99; a++)
            {
                gotoxy(a, 12);
                PUN;
            }
            cout << "\n\n\t\t\t\t\t\t* MODIFICADO EXITOSAMENTE *" << endl;
            existe = 1;
            break;
        }

        fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
    }
    if (existe == 0)
    {
        for (int a = 11; a <= 99; a++)
        {
            gotoxy(a, 16);
            PUN;
        }
        cout << "\n\n\t\t\t\t\t* NO EXISTE UNA MARCA CON ESE ID *" << endl;
    }

    fclose(ArchivoMarcas);
    Actualizacion(aux2, AuxIdMarca);
}
void Actualizacion(int idnew, int idold)
{
    Productos Producto;
    FILE *Inventario = fopen("Source/Productos.dat", "r+b");
    FILE *Temporal = fopen("Source/temporal.dat", "a+b");
    fread(&Producto, sizeof(Productos), 1, Inventario);
    while (!feof(Inventario))
    {
        if (idold == Producto.idMarca)
        {
            Producto.CodigoProducto = Producto.CodigoProducto;
            strcpy(Producto.DescripcionProducto, Producto.DescripcionProducto);
            Producto.FechaDeIngreso.d = Producto.FechaDeIngreso.d;
            Producto.FechaDeIngreso.m = Producto.FechaDeIngreso.m;
            Producto.FechaDeIngreso.a = Producto.FechaDeIngreso.a;
            Producto.idMarca = idnew;
            Producto.PrecioCosto = Producto.PrecioCosto;
            Producto.PrecioVenta = Producto.PrecioVenta;
            fwrite(&Producto, sizeof(Productos), 1, Temporal);
        }
        else
        {
            fwrite(&Producto, sizeof(Productos), 1, Temporal);
        }
        fread(&Producto, sizeof(Productos), 1, Inventario);
    }

    fclose(Inventario);
    fclose(Temporal);
    remove("Source/Productos.dat");
    rename("Source/temporal.dat", "Source/Productos.dat");
}
void EliminarMarca()
{
    SetConsoleTitle("ELIMINACION DE MARCAS");
    fflush(stdin);
    Marcas Marca;
    FILE *ArchivoMarcas = fopen("Source/Marcas.dat", "rb");
    FILE *Temporal = fopen("Source/Temporal.dat", "wb");
loop:
    int AuxIdMarca, existe = 0;
    string AUX;
    system("CLS");
    fflush(stdin);
    MostrarMarcas();
    cout << "\n\n\n\t\t ID DE LA MARCA QUE DESEA ELIMINAR -> ";
    getline(cin,AUX);
    if (VerificadorDeNumeros(AUX))
    {
        AuxIdMarca = atoi(AUX.c_str());
    }
    else
    {

        cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
        getch();
        goto loop;
    }
    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
    while (!feof(ArchivoMarcas))
    {
        if (AuxIdMarca == Marca.idMarca)
        {
            cout << "\n\t\t ID MARCA: " << Marca.idMarca;
            cout << "\n\t\t NOMBRE DE LA MARCA: " << Marca.NombreMarca << endl
                 << endl;
            existe = 1;
            cout << endl;
            for (int a = 11; a <= 99; a++)
            {
                gotoxy(a, 18);
                PUN;
            }
            cout << "\n\n\t\t\t\t\t\t* SE HA ELIMINADO CORRECTAMENTE*" << endl;
        }
        else
        {
            fwrite(&Marca, sizeof(Marcas), 1, Temporal);
            fflush(stdin);
        }
        fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
    }
    if (existe == 0)
    {
        cout << "\n\n\t\t\t\t\t\t* NO EXISTE UNA MARCA CON ESE ID *" << endl;
    }

    fclose(Temporal);
    fclose(ArchivoMarcas);
    remove("Source/Marcas.dat");
    rename("Source/Temporal.dat", "Source/Marcas.dat");
}
void MenuInventario()
{
    char opc;
    SetConsoleTitle("MENU DE INVENTARIO");
    system("CLS");
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 5);
        HOR;
    }
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 6);
        PUN;
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 7);
        HOR;
    }
    gotoxy(50, 6);
    cout << " I N V E N T A R I O ";
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 5);
    cout << TOPE;
    gotoxy(110, 5);
    cout << EDA;
    gotoxy(9, 7);
    cout << EIB;
    gotoxy(110, 7);
    cout << EDB;

    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 9);
        HOR;
    }
    for (int a = 9; a <= 26; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 26);
        HOR;
    }
    for (int a = 9; a <= 26; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 9);
    cout << TOPE;
    gotoxy(110, 9);
    cout << EDA;
    gotoxy(9, 26);
    cout << EIB;
    gotoxy(110, 26);
    cout << EDB;
    for (int a = 10; a <= 24; a++)
    {
        gotoxy(35, a);
        VER
    }
    for (int a = 10; a <= 24; a++)
    {
        gotoxy(84, a);
        VER
    }
    gotoxy(35, 11);
    cout << V << " -->   [1] INGRESO DE PRODUCTOS                 " << V;
    gotoxy(35, 13);
    cout << V << " -->   [2] LISTADO DE PRODUCTOS                 " << V;
    gotoxy(35, 15);
    cout << V << " -->   [3] BUSQUEDA DE PRODUCTOS                " << V;
    gotoxy(35, 17);
    cout << V << " -->   [4] MODIFICACION DE PRODUCTOS            " << V;
    gotoxy(35, 19);
    cout << V << " -->   [5] ELIMINACION DE PRODUCTOS             " << V;
    gotoxy(35, 21);
    cout << V << " -->   [6] CODIGO DE BARRA                      " << V;
    gotoxy(35, 22);
    ARENBJ;
    gotoxy(35, 25);
    ABJ;
    gotoxy(35, 24);
    cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
    gotoxy(35, 27);
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
            MenuIngresoProductos();
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
            BuscarProductos();
            getch();
            MenuInventario();
            break;
        }
        case '4':
        {
            ModificarProductos();
            getch();
            MenuInventario();
            break;
        }
        case '5':
        {
            EliminarProducto();
            getch();
            MenuInventario();
            break;
        }
        case '6':
        {
            Codigo_barra();
            MenuInventario();
            break;
        }
        case 27:
        {  system("start Salida.vbs");
            ApagarBanda();
            gotoxy(7,31);
            exit(0);
            break;
        }
        default:
        {
            cout << "Opcion Incorreta elija de nuevo" << endl;
            getch();
            MenuInventario();
            break;
        }
        }
    }
}
void IngresoProductos()
{
    fflush(stdin);
    SetConsoleTitle("INGRESO DE PRODUCTOS");
    Productos Producto;
    Marcas Marca;
    FILE *ArchivoMarcas = fopen("Source/Marcas.dat", "rb");
    FILE *ArchivoProductos = fopen("Source/Productos.dat", "a+b");
InicioIngresoProductos:
codigoProducto:
    MostrarMarcas();
    int auxCodigoProducto, encontradoCodigoProducto = 0, auxIdMarca;
    string AUX,AUX2;
    cout << "\n\n\t\tCODIGO DEL PRODUCTO -> ";
    getline(cin,AUX);
    fflush(stdin);
    if (VerificadorDeNumeros(AUX))
    {
        auxCodigoProducto = atoi(AUX.c_str());
    }
    else
    {

        cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
        getch();
        goto InicioIngresoProductos;
    }
    fflush(stdin);
    rewind(ArchivoProductos);
    fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
    do
    {
        if (auxCodigoProducto == Producto.CodigoProducto)
        {
            encontradoCodigoProducto = 1;
        }
        fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
    }
    while (!feof(ArchivoProductos));
    if (encontradoCodigoProducto == 1)
    {
        cout << "\n\n\t\t\t\t\t * EL CODIGO QUE INGRESO YA EXISTE *" << endl;
        getch();
        goto codigoProducto;
    }
    fflush(stdin);
    Producto.CodigoProducto = auxCodigoProducto;
    fflush(stdin);
    cout << "\n\n\t\tNOMBRE DEL PRODUCTO -> ";
    cin.getline(Producto.DescripcionProducto, 100, '\n');
    fflush(stdin);
IdMarca:
    rewind(ArchivoMarcas);
    fflush(stdin);
    int encontradoIdMarca = 0;
    cout << "\n\n\t\tID DE LA MARCA DEL PRODUCTO -> ";
    getline(cin,AUX2);
    fflush(stdin);
    if (VerificadorDeNumeros(AUX2))
    {
        auxIdMarca = atoi(AUX2.c_str());
    }
    else
    {
        cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
        getch();
        goto IdMarca;
    }
    fflush(stdin);
    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
    do
    {
        if (auxIdMarca == Marca.idMarca)
        {
            encontradoIdMarca = 1;
        }
        fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
    }
    while (!feof(ArchivoMarcas));
    if (encontradoIdMarca == 0)
    {
        cout << "\n\n\t\t\t\t * NO EXISTE UNA MARCA CON EL ID QUE INGRESO *" << endl;
        getch();
        goto IdMarca;
    }
    fflush(stdin);
    Producto.idMarca = auxIdMarca;
    fflush(stdin);
    cout << "\n\n\t\tPRECIO DE VENTA DEL PRODUCTO " << Producto.DescripcionProducto << " -> ";
    cin >> Producto.PrecioVenta;
    fflush(stdin);
    cout << "\n\n\t\tPRECIO COSTO DEL PRODUCTO " << Producto.DescripcionProducto << " -> ";
    cin >> Producto.PrecioCosto;
    fflush(stdin);
    int formatofecha = 0;
    do
    {
        string dia,mes,anio;
FechaDia:
        cout << "\n\n\t\tDIA QUE EL PRODUCTO INGRESO -> ";
        getline(cin,dia);
        fflush(stdin);
        if (VerificadorDeNumeros(dia))
        {
            Producto.FechaDeIngreso.d = atoi(dia.c_str());
        }
        else
        {

            cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
            getch();
            goto FechaDia;
        }
        fflush(stdin);
FechaMes:
        cout << "\n\n\t\tMES QUE EL PRODUCTO INGRESO -> ";
        getline(cin,mes);
        fflush(stdin);
        if (VerificadorDeNumeros(mes))
        {
            Producto.FechaDeIngreso.m= atoi(mes.c_str());
        }
        else
        {
            cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
            getch();
            goto FechaMes;
        }
        fflush(stdin);
FechaAnio:
        cout << "\n\n\t\tANIO QUE EL PRODUCTO INGRESO -> ";
        getline(cin,anio);
        fflush(stdin);
        if (VerificadorDeNumeros(anio))
        {
            Producto.FechaDeIngreso.a= atoi(anio.c_str());
        }
        else
        {

            cout << "\n\n\t   * EL INGRESO DE LETRAS ES   O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
            getch();
            goto FechaAnio;
        }
        fflush(stdin);
        if ((Producto.FechaDeIngreso.d > 0 && Producto.FechaDeIngreso.d < 32) && (Producto.FechaDeIngreso.m > 0 && Producto.FechaDeIngreso.m < 13) && (Producto.FechaDeIngreso.a > 1999 && Producto.FechaDeIngreso.a < 2101))
        {
            formatofecha = 1;
        }
        else
        {
            cout << "\n\n\t\t* FORMATO INCORRECTO (DD/MM/AAAA)" << endl;
        }
    }
    while (formatofecha == 0);
    fwrite(&Producto, sizeof(Productos), 1, ArchivoProductos);
    cout << "\n\n\t\t\t\t\tDESEA INGRESAR OTRO PRODUCTO? (S | N) -> ";
    opc=getch();
    fflush(stdin);
    if (opc == 's' || opc == 'S')
    {
        goto InicioIngresoProductos;
    }
    cout<<"Guardado Exitosamente"<<endl;
    fclose(ArchivoMarcas);
    fclose(ArchivoProductos);
}
void MostrarProductos()
{
    system("CLS");
    int Filas = 6, FilasTotales = 6, encontradomarca = 0;
    SetConsoleTitle("LISTADO DE PRODUCTOS");
    Productos Producto;
    Marcas Marca;
    FILE *ArchivoMarcas = fopen("Source/Marcas.dat", "rb");
    FILE *ArchivoProductos = fopen("Source/Productos.dat", "rb");
    if (ArchivoProductos == NULL)
    {
        cout << " ERROR 001 " << endl;
        getch();
        MenuInventario();
    }
    else
    {
        system("CLS");
        fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
        for (int a = 10; a <= 100; a++)
        {
            gotoxy(a, 1);
            PUN;
        }
        gotoxy(43, 1);
        cout << " L I S T A D O  D E  P R O D U C T O S ";
        gotoxy(4, 3);
        cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
        gotoxy(4, 4);
        cout << V;
        gotoxy(111, 4);
        cout << V;
        gotoxy(6, 4);
        cout << "COD. PRODUCTO";
        gotoxy(20, 4);
        cout << V;
        gotoxy(24, 4);
        cout << "PRODUCTO";
        gotoxy(36, 4);
        cout << V;
        gotoxy(37, 4);
        cout << " ID MARCA";
        gotoxy(47, 4);
        cout << V;
        gotoxy(54, 4);
        cout << "MARCA";
        gotoxy(65, 4);
        cout << V;
        gotoxy(67, 4);
        cout << "PRECIO COSTO";
        gotoxy(81, 4);
        cout << V;
        gotoxy(84, 4);
        cout << "PRECIO VENTA";
        gotoxy(98, 4);
        cout << V;
        gotoxy(100, 4);
        cout << "FECHA. INGRESO";
        gotoxy(115, 4);
        cout << V;
        gotoxy(4, 5);
        separador2;
        while (!feof(ArchivoProductos))
        {
            gotoxy(4, Filas);
            cout << V;
            gotoxy(11, Filas);
            cout << Producto.CodigoProducto;
            gotoxy(20, Filas);
            cout << V;
            gotoxy(22, Filas);
            cout << Producto.DescripcionProducto;
            gotoxy(36, Filas);
            cout << V;
            rewind(ArchivoMarcas);
            fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
            while (!feof(ArchivoMarcas))
            {
                if (Producto.idMarca == Marca.idMarca)
                {
                    gotoxy(40, Filas);
                    cout << Marca.idMarca;
                    gotoxy(47, Filas);
                    cout << V;
                    gotoxy(50, Filas);
                    cout << Marca.NombreMarca;
                    encontradomarca = 1;
                }
                fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
            }
            if (encontradomarca == 0)
            {
                gotoxy(40, Filas);
                cout << "NULL";
                gotoxy(47, Filas);
                cout << V;
                gotoxy(50, Filas);
                cout << "ELIMINADA!";
            }

            gotoxy(65, Filas);
            cout << V;
            gotoxy(68, Filas);
            cout << "Q." << Producto.PrecioCosto;
            gotoxy(81, Filas);
            cout << V;
            gotoxy(85, Filas);
            cout << "Q." << Producto.PrecioVenta;
            gotoxy(98, Filas);
            cout << V;
            gotoxy(102, Filas);
            cout << Producto.FechaDeIngreso.d << "/" << Producto.FechaDeIngreso.m << "/" << Producto.FechaDeIngreso.a;
            gotoxy(115, Filas);
            cout << V << endl;
            ++Filas;
            ++FilasTotales;
            fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
        }
        gotoxy(4,FilasTotales);
        cout << EIB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDB << endl;
        fclose(ArchivoProductos);
        fclose(ArchivoMarcas);
    }
}
void BuscarProductos()
{
    char opc;
    SetConsoleTitle("MENU BUSQUEDA DE PRODUCTOS");
    system("CLS");
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 5);
        HOR;
    }
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 6);
        PUN;
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 7);
        HOR;
    }
    gotoxy(41, 6);
    cout << " B U S Q U E D A  D E  P R O D U C T O S ";
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 5);
    cout << TOPE;
    gotoxy(110, 5);
    cout << EDA;
    gotoxy(9, 7);
    cout << EIB;
    gotoxy(110, 7);
    cout << EDB;

    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 9);
        HOR;
    }
    for (int a = 9; a <= 20; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 20);
        HOR;
    }
    for (int a = 9; a <= 20; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 9);
    cout << TOPE;
    gotoxy(110, 9);
    cout << EDA;
    gotoxy(9, 20);
    cout << EIB;
    gotoxy(110, 20);
    cout << EDB;
    for (int a = 10; a <= 19; a++)
    {
        gotoxy(35, a);
        VER
    }
    for (int a = 10; a <= 19; a++)
    {
        gotoxy(84, a);
        VER
    }
    gotoxy(35, 11);
    cout << V << " -->   [1] POR MEDIO DE NOMBRE                  " << V;
    gotoxy(35, 13);
    cout << V << " -->   [2] POR MEDIO DE CODIGO                  " << V;
    gotoxy(35, 15);
    ARENBJ;
    gotoxy(35, 19);
    ABJ;
    gotoxy(35, 17);
    cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
    gotoxy(35, 22);
    opc = getch();
    if (opc == 8)
    {
        MenuInventario();
    }
    else
    {
        switch (opc)
        {
        case '1':
        {
            SearchProductsForName();
            getch();
            BuscarProductos();
            break;
        }
        case '2':
        {
            SearchProductsForCode();
            getch();
            BuscarProductos();
            break;
        }

        case 27:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "Opcion Incorreta elija de nuevo" << endl;
            getch();
            BuscarProductos();
            break;
        }
        }
    }
}
void SearchProductsForName()
{

    system("CLS");
    int Filas = 7, FilasTotales = 7, encontradomarca = 0;
    SetConsoleTitle("Listado De Productos");
    Productos Producto;
    Marcas Marca;
    FILE *ArchivoMarcas = fopen("Source/Marcas.dat", "rb");
    FILE *ArchivoProductos = fopen("Source/Productos.dat", "rb");
    if (ArchivoProductos == NULL)
    {
        cout << "Error 001" << endl;
        getch();
        MenuInventario();
    }
    else
    {
         system("CLS");
        fflush(stdin);
        string aux;
        string nombre;
        bool encontrado = false;

        fflush(stdin);
        cout << "\n\n\n\t\t Ingrese el nombre del producto que buscar-> ";
        fflush(stdin);
        Minusculas(aux);
system("CLS");
        SetConsoleTitle("Registros");

        for (int a = 10; a <= 100; a++)
        {
            gotoxy(a, 3);
            PUN;
        }
        gotoxy(35, 3);
        cout << " L I S T A D O  D E  C O I N C I D E N C I A S";
        gotoxy(4, 4);
        cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
        gotoxy(4, 5);
        cout << V;
        gotoxy(111, 5);
        cout << V;
        gotoxy(6, 5);
        cout << "COD. PRODUCTO";
        gotoxy(20, 5);
        cout << V;
        gotoxy(24, 5);
        cout << "PRODUCTO";
        gotoxy(36, 5);
        cout << V;
        gotoxy(37, 5);
        cout << " ID MARCA";
        gotoxy(47, 5);
        cout << V;
        gotoxy(54, 5);
        cout << "MARCA";
        gotoxy(65, 5);
        cout << V;
        gotoxy(67, 5);
        cout << "PRECIO COSTO";
        gotoxy(81, 5);
        cout << V;
        gotoxy(84, 5);
        cout << "PRECIO VENTA";
        gotoxy(98, 5);
        cout << V;
        gotoxy(100, 5);
        cout << "FECHA. INGRESO";
        gotoxy(115, 5);
        cout << V;
        gotoxy(4, 6);
        separador2;
        fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
        do
        {
            nombre = Producto.DescripcionProducto;
            Minusculas(nombre);
            fflush(stdin);
            if (nombre.find(aux) != string::npos)
            {
                encontrado = true;
                gotoxy(4, Filas);
                cout << V;
                gotoxy(11, Filas);
                cout << Producto.CodigoProducto;
                gotoxy(20, Filas);
                cout << V;
                gotoxy(22, Filas);
                cout << Producto.DescripcionProducto;
                gotoxy(36, Filas);
                cout << V;
                rewind(ArchivoMarcas);
                fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
                while (!feof(ArchivoMarcas))
                {
                    if (Producto.idMarca == Marca.idMarca)
                    {
                        gotoxy(40, Filas);
                        cout << Marca.idMarca;
                        gotoxy(47, Filas);
                        cout << V;
                        gotoxy(50, Filas);
                        cout << Marca.NombreMarca;
                        encontradomarca = 1;
                    }
                    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
                }

                gotoxy(65, Filas);
                cout << V;
                gotoxy(68, Filas);
                cout << "Q." << Producto.PrecioCosto;
                gotoxy(81, Filas);
                cout << V;
                gotoxy(85, Filas);
                cout << "Q." << Producto.PrecioVenta;
                gotoxy(98, Filas);
                cout << V;
                gotoxy(102, Filas);
                cout << Producto.FechaDeIngreso.d << "/" << Producto.FechaDeIngreso.m << "/" << Producto.FechaDeIngreso.a;
                gotoxy(115, Filas);
                cout << V << endl;
                ++Filas;
                ++FilasTotales;
            }
            fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
        }
        while (feof(ArchivoProductos) == 0);
        if (encontrado == false)
        {
            gotoxy(4,FilasTotales+2);
            cout << "No se encontro" << endl;
        }
        gotoxy(4,FilasTotales);
        cout << EIB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDB << endl;
        fclose(ArchivoProductos);
    }
}
void SearchProductsForCode()
{
    system("CLS");
    int Filas = 7, FilasTotales = 7, encontradomarca = 0;
    SetConsoleTitle("Listado De Productos");
    Productos Producto;
    Marcas Marca;
    FILE *ArchivoMarcas = fopen("Source/Marcas.dat", "rb");
    FILE *ArchivoProductos = fopen("Source/Productos.dat", "rb");
    if (ArchivoProductos == NULL)
    {
        cout << "Error 001" << endl;
        getch();
        MenuInventario();
    }
    else
    {
loop:
     system("CLS");
        fflush(stdin);
        int aux = 0;
        string AUX;
        bool encontrado = false;
        system("CLS");
        fflush(stdin);
        cout << "\n\n\n\t\t Ingrese el codigo del producto que buscar-> ";
        getline(cin,AUX);
        if (VerificadorDeNumeros(AUX))
        {
            aux= atoi(AUX.c_str());
        }
        else
        {
            cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
            getch();
            goto loop;
        }system("CLS");
        fflush(stdin);
        SetConsoleTitle("Registros");

        for (int a = 10; a <= 100; a++)
        {
            gotoxy(a, 3);
            PUN;
        }
        gotoxy(35, 3);
        cout << " L I S T A D O  D E  C O I N C I D E N C I A S";
        gotoxy(4, 4);
        cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
        gotoxy(4, 5);
        cout << V;
        gotoxy(111, 5);
        cout << V;
        gotoxy(6, 5);
        cout << "COD. PRODUCTO";
        gotoxy(20, 5);
        cout << V;
        gotoxy(24, 5);
        cout << "PRODUCTO";
        gotoxy(36, 5);
        cout << V;
        gotoxy(37, 5);
        cout << " ID MARCA";
        gotoxy(47, 5);
        cout << V;
        gotoxy(54, 5);
        cout << "MARCA";
        gotoxy(65, 5);
        cout << V;
        gotoxy(67, 5);
        cout << "PRECIO COSTO";
        gotoxy(81, 5);
        cout << V;
        gotoxy(84, 5);
        cout << "PRECIO VENTA";
        gotoxy(98, 5);
        cout << V;
        gotoxy(100, 5);
        cout << "FECHA. INGRESO";
        gotoxy(115, 5);
        cout << V;
        gotoxy(4, 6);
        separador2;
        fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
        do
        {
            if (aux == Producto.CodigoProducto)
            {
                encontrado = true;
                gotoxy(4, Filas);
                cout << V;
                gotoxy(11, Filas);
                cout << Producto.CodigoProducto;
                gotoxy(20, Filas);
                cout << V;
                gotoxy(22, Filas);
                cout << Producto.DescripcionProducto;
                gotoxy(36, Filas);
                cout << V;
                rewind(ArchivoMarcas);
                fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
                while (!feof(ArchivoMarcas))
                {
                    if (Producto.idMarca == Marca.idMarca)
                    {
                        gotoxy(40, Filas);
                        cout << Marca.idMarca;
                        gotoxy(47, Filas);
                        cout << V;
                        gotoxy(50, Filas);
                        cout << Marca.NombreMarca;
                        encontradomarca = 1;
                    }
                    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
                }

                gotoxy(65, Filas);
                cout << V;
                gotoxy(68, Filas);
                cout << "Q." << Producto.PrecioCosto;
                gotoxy(81, Filas);
                cout << V;
                gotoxy(85, Filas);
                cout << "Q." << Producto.PrecioVenta;
                gotoxy(98, Filas);
                cout << V;
                gotoxy(102, Filas);
                cout << Producto.FechaDeIngreso.d << "/" << Producto.FechaDeIngreso.m << "/" << Producto.FechaDeIngreso.a;
                gotoxy(115, Filas);
                cout << V << endl;
                ++Filas;
                ++FilasTotales;
            }
            fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
        }
        while (feof(ArchivoProductos) == 0);
        if (encontrado == false)
        {
            gotoxy(4,FilasTotales+2);
            cout << "No se encontro" << endl;
        }
        gotoxy(4,FilasTotales);
        cout << EIB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDB << endl;
        fclose(ArchivoProductos);
    }
}
void ModificarProductos()
{
    char Eleccion;
    fflush(stdin);
    SetConsoleTitle("MODIFICACION DE PRODUCTOS");
    Productos Producto;
    Marcas Marca;
    FILE *ArchivoMarcas = fopen("Source/Marcas.dat", "rb");
    FILE *ArchivoProductos = fopen("Source/Productos.dat", "r+b");
BusquedaParaModificar:
    system("CLS");
    MostrarProductos();
    rewind(ArchivoProductos);
    rewind(ArchivoMarcas);
    int AuxBusquedaCodigoProducto = 0, EncontradoCodigoaModificar = 0;
    string AUXP,AuxM;
    cout << "\n\n\n\t\t CODIGO DEL PRODUCTO QUE DESEA MODIFICAR -> ";
    getline(cin,AUXP);
    fflush(stdin);
    if (VerificadorDeNumeros(AUXP))
    {
        AuxBusquedaCodigoProducto = atoi(AUXP.c_str());
    }
    else
    {

        cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
        getch();
        goto BusquedaParaModificar;
    }
    fflush(stdin);
    fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
    while (!feof(ArchivoProductos))
    {
        if (AuxBusquedaCodigoProducto == Producto.CodigoProducto)
        {
            EncontradoCodigoaModificar = 1;
            cout << "\n\t\t - DESCRIPCION DEL PRODUCTO";
            cout << "\n\t\t\t CODIGO: " << Producto.CodigoProducto;
            cout << "\n\t\t\t PRODUCTO: " << Producto.DescripcionProducto;
            fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
            while (!feof(ArchivoMarcas))
            {
                if (Producto.idMarca == Marca.idMarca)
                {
                    cout << "\n\t\t\t ID MARCA: " << Marca.idMarca;
                    cout << "\n\t\t\t MARCA: " << Marca.NombreMarca;
                }
                fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
            }
            cout << "\n\t\t\t PRECIO COSTO: Q." << Producto.PrecioCosto;
            cout << "\n\t\t\t PRECIO VENTA: Q." << Producto.PrecioVenta;
            cout << "\n\t\t\t FECHA DE INGRESO: " << Producto.FechaDeIngreso.d << "/" << Producto.FechaDeIngreso.m << "/" << Producto.FechaDeIngreso.a << endl;
            cout << endl;
            cout << "\n\t\t\t\tESTE ES EL PRODUCTO QUE DESEA MODIFICAR S | N  = ";
            Eleccion=getch();
            fflush(stdin);
            if (Eleccion == 'N' || Eleccion == 'n')
            {
                goto BusquedaParaModificar;
            }
            int pos = ftell(ArchivoProductos) - sizeof(Productos);
            fflush(stdin);
codigoProducto:
            MostrarMarcas();
            int auxCodigoProducto, encontradoCodigoProducto = 0, auxIdMarca;
            string AUX;
            cout << "\n\t\t CODIGO NUEVO DEL PRODUCTO -> ";
            getline(cin,AUX);
            fflush(stdin);
            if (VerificadorDeNumeros(AUX))
            {
                auxCodigoProducto = atoi(AUX.c_str());
            }
            else
            {
                cout << "\n\n\t  * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
                getch();
                goto codigoProducto;
            }
            fflush(stdin);
            rewind(ArchivoProductos);
            fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
            do
            {
                if (auxCodigoProducto == Producto.CodigoProducto)
                {
                    encontradoCodigoProducto = 1;
                }
                fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
            }
            while (!feof(ArchivoProductos));
            if (encontradoCodigoProducto == 1)
            {
                cout << "\n\n\t\t\t\t\t* CODIGO YA EXISTENTE *" << endl;
                getch();
                goto codigoProducto;
            }
            fflush(stdin);
            Producto.CodigoProducto = auxCodigoProducto;
            fflush(stdin);
            fseek(ArchivoProductos, pos, SEEK_SET);
            fflush(stdin);
            cout << "\n\t\t NOMBRE NUEVO DEL PRODUCTO -> ";
            cin.getline(Producto.DescripcionProducto, 100, '\n');
            fflush(stdin);
IdMarca:
            rewind(ArchivoMarcas);
            fflush(stdin);
            int encontradoIdMarca = 0;
            cout << "\n\t\t ID DE LA MARCA DEL PRODUCTO -> ";
            getline(cin,AuxM);
            fflush(stdin);
            if (VerificadorDeNumeros(AuxM))
            {
                auxIdMarca= atoi(AuxM.c_str());
            }
            else
            {

                cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
                getch();
                goto IdMarca;
            }
            fflush(stdin);
            fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
            do
            {
                if (auxIdMarca == Marca.idMarca)
                {
                    encontradoIdMarca = 1;
                }
                fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
            }
            while (!feof(ArchivoMarcas));
            if (encontradoIdMarca == 0)
            {
                cout << "\n\n\t\t\t\t\t* NO EXISTE UNA MARCA CON ESE ID *" << endl;
                getch();
                goto IdMarca;
            }
            fflush(stdin);
            Producto.idMarca = auxIdMarca;
            fflush(stdin);
            cout << "\n\t\t PRECIO VENTA DE " << Producto.DescripcionProducto << " -> ";
            cin >> Producto.PrecioVenta;
            fflush(stdin);
            cout << "\n\t\t PRECIO COSTO DE " << Producto.DescripcionProducto << " -> ";
            cin >> Producto.PrecioCosto;
            fflush(stdin);
            int formatofecha = 0;
            do
            {
                string dia,mes,anio;
FechaDia:
                cout << "\n\n\t\tDIA QUE EL PRODUCTO INGRESO -> ";
                getline(cin,dia);
                fflush(stdin);
                if (VerificadorDeNumeros(dia))
                {
                    Producto.FechaDeIngreso.d = atoi(dia.c_str());
                }
                else
                {

                    cout << "\n\n\t  * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
                    getch();
                    goto FechaDia;
                }
                fflush(stdin);
FechaMes:
                cout << "\n\n\t\tMES QUE EL PRODUCTO INGRESO -> ";
                getline(cin,mes);
                fflush(stdin);
                if (VerificadorDeNumeros(mes))
                {
                    Producto.FechaDeIngreso.m= atoi(mes.c_str());
                }
                else
                {
                    cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
                    getch();
                    goto FechaMes;
                }
                fflush(stdin);
FechaAnio:
                cout << "\n\n\t\tANIO QUE EL PRODUCTO INGRESO -> ";
                getline(cin,anio);
                fflush(stdin);
                if (VerificadorDeNumeros(anio))
                {
                    Producto.FechaDeIngreso.a= atoi(anio.c_str());
                }
                else
                {

                    cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
                    getch();
                    goto FechaAnio;
                }
                fflush(stdin);
                if ((Producto.FechaDeIngreso.d > 0 && Producto.FechaDeIngreso.d < 32) && (Producto.FechaDeIngreso.m > 0 && Producto.FechaDeIngreso.m < 13) && (Producto.FechaDeIngreso.a > 1999 && Producto.FechaDeIngreso.a < 2101))
                {
                    formatofecha = 1;
                }
                else
                {
                    cout << "\n\n\t\t* FORMATO INCORRECTO (DD/MM/AAAA)" << endl;
                }
            }
            while (formatofecha == 0);
            fwrite(&Producto, sizeof(Productos), 1, ArchivoProductos);
            fflush(stdin);
            cout << "\n\n\t\t\t\t\t\t* MODIFICADO EXITOSAMENTE *" << endl;
            break;
        }
        fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
    }
    if (EncontradoCodigoaModificar == 0)
    {
        cout << "\n\n\t\t\t\t\t  * EL CODIGO QUE INGRESO NO EXISTE *" << endl;
        getch();
        goto BusquedaParaModificar;
    }

    fclose(ArchivoProductos);
    fclose(ArchivoMarcas);
}
void EliminarProducto()
{
    fflush(stdin);
    Productos Producto;
    SetConsoleTitle("ELIMINACION DE PRODUCTOS");
    FILE *ArchivoProductos = fopen("Source/Productos.dat", "rb");
    FILE *Temporal = fopen("Source/Temporal.dat", "w+b");
BusquedaDeCodigoParaEliminar:
    system("CLS");
    MostrarProductos();
    rewind(ArchivoProductos);
    int EncontradoCodigo = 0, AuxCodigoProducto = 0;
    string AUX;
    cout << "\n\n\n\t\t CODIGO DEL PRODUCTO QUE DESEA ELIMINAR -> ";
    getline(cin,AUX);
    fflush(stdin);
    if (VerificadorDeNumeros(AUX))
    {
        AuxCodigoProducto= atoi(AUX.c_str());
    }
    else
    {
        cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
        getch();
        goto BusquedaDeCodigoParaEliminar;
    }
    fflush(stdin);
    fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
    while (!feof(ArchivoProductos))
    {
        if (AuxCodigoProducto == Producto.CodigoProducto)
        {
            cout << "\n\n\t\t\t\t\t* SE HA ELIMINADO CORRECTAMENTE*" << endl;
            EncontradoCodigo = 1;
        }
        else
        {
            fwrite(&Producto, sizeof(Productos), 1, Temporal);
            fflush(stdin);
        }
        fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
    }
    if (EncontradoCodigo == 0)
    {
        cout << "\n\n\t\t\t\t\t* NO EXISTE UN PRODUCTO CON ESE CODIGO *" << endl;
        getch();
    }
    fclose(ArchivoProductos);
    fclose(Temporal);
    remove("Source/Productos.dat");
    rename("Source/Temporal.dat", "Source/Productos.dat");
}
//-------------------CODIGO DE BARRA-------------------
void Codigo_barra()
{
loop:
    fflush(stdin);
    system("CLS");
    SetConsoleTitle("CODIGO DE BARRA");
    MostrarProductos();
    int cp, enc = 0;
    string AUX="";
    cout << "\n\n\t\tINGRESE EL CODIGO -> ";
    getline(cin,AUX);
    if (VerificadorDeNumeros(AUX))
    {
        cp= atoi(AUX.c_str());
    }
    else
    {
        cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
        getch();
         fflush(stdin);
        goto loop;
    }

    FILE *ArchivoProductos = fopen("Source/Productos.dat", "rb");

    int indice = 0, pos = 0;
    Productos Producto;
    fread(&Producto, sizeof(Productos), 1, ArchivoProductos);

    while (!feof(ArchivoProductos))
    {
        if (Producto.CodigoProducto == cp)
        {
            enc=1;
            ofstream ArchivoProductos;
            ArchivoProductos.open("IMPRIMIR/Codigo_barra/Codigo_barra/bin/Debug/imprimir.txt", ios::out);
            if (ArchivoProductos.fail())
            {
                cout << "no es posible abrir el archivo";
                getch();
                exit(1);
            }
            else
            {
                fflush(stdin);
                ArchivoProductos << Producto.CodigoProducto << endl
                                 << Producto.DescripcionProducto << " marca ";
                FILE *ArchivoMarcas = fopen("Source/Marcas.dat", "a+b");
                Marcas Marca;
                fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
                do
                {
                    if (Producto.idMarca == Marca.idMarca)
                    {
                        ArchivoProductos << Marca.NombreMarca << endl;
                    }
                    fread(&Marca, sizeof(Marcas), 1, ArchivoMarcas);
                }
                while (feof(ArchivoMarcas) == 0);
                fclose(ArchivoMarcas);
                ArchivoProductos << fixed << setprecision(2) << Producto.PrecioVenta;

            }
            ArchivoProductos.close();
        }

        fread(&Producto, sizeof(Productos), 1, ArchivoProductos);
    }

    if(enc==0)
    {
          fflush(stdin);
        cout<<"No existe"<<endl;
        getch();
        fflush(stdin);
        goto loop;
    }
 fflush(stdin);
    fclose(ArchivoProductos);
    system("start IMPRIMIR/Codigo_barra/Codigo_barra/bin/Debug/Codigo_barra.exe");
    system("PAUSE");
    // remove("IMPRIMIR/Codigo_barra/Codigo_barra/bin/Debug/imprimir.txt");
}
void Clave(string x,string nom,long long int dpi)
{
    fflush(stdin);
    ofstream ArchivoProductos;
    ArchivoProductos.open("IMPRIMIR2/Codigo_barra/Codigo_barra/bin/Debug/imprimir.txt",ios::out);
    if(ArchivoProductos.fail())
    {
        cout<<"no es posible abrir el archivo";
        getch();
        exit(1);
    }
    else
    {
        fflush(stdin);
        ArchivoProductos<<x<<endl;
        ArchivoProductos<<nom<<endl<<dpi;

        ArchivoProductos.close();
        system("start IMPRIMIR2/Codigo_barra/Codigo_barra/bin/Debug/Codigo_barra.exe");
        system("PAUSE");
        remove("IMPRIMIR2/Codigo_barra/Codigo_barra/bin/Debug/imprimir.txt");

    }
}
void ModoBanda()
{
    char opc;
    ApagarBanda();
    SetConsoleTitle("MENU MODO DE BANDA");
    system("CLS");
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 5);
        HOR;
    }
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 6);
        PUN;
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 7);
        HOR;
    }
    gotoxy(41, 6);
    cout << " M O D O  D E  B A N D A";
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 5);
    cout << TOPE;
    gotoxy(110, 5);
    cout << EDA;
    gotoxy(9, 7);
    cout << EIB;
    gotoxy(110, 7);
    cout << EDB;

    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 9);
        HOR;
    }
    for (int a = 9; a <= 20; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 20);
        HOR;
    }
    for (int a = 9; a <= 20; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 9);
    cout << TOPE;
    gotoxy(110, 9);
    cout << EDA;
    gotoxy(9, 20);
    cout << EIB;
    gotoxy(110, 20);
    cout << EDB;
    for (int a = 10; a <= 19; a++)
    {
        gotoxy(35, a);
        VER
    }
    for (int a = 10; a <= 19; a++)
    {
        gotoxy(84, a);
        VER
    }
    gotoxy(35, 11);
    cout << V << " -->   [1] AUTOMATICO                  ";
     gotoxy(35, 13);
    cout << V << " -->   [2] MANUAL                  ";
    gotoxy(35, 15);
    ARENBJ;
    gotoxy(35, 19);
    ABJ;
    gotoxy(35, 17);
    cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
    gotoxy(35, 22);
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
            Puerto->WriteData("a",sizeof("a")-1);
            cout<<"Modo Activado"<<endl;
            getch();
            MenuPrincipal();
            break;
        }
                case '2':
        {
            Puerto->WriteData("c",sizeof("c")-1);
            cout<<"Modo Activado"<<endl;
            getch();
            MenuPrincipal();
            break;
        }

        case 27:
        {  system("start Salida.vbs");
             ApagarBanda();
            exit(0);
            break;
        }
        default:
        {
            cout << "OPCION INCORRECTA, INGRESE NUEVAMENTE LA OPCION" << endl;
            getch();
            ModoBanda();
            break;
        }
        }
    }
}
void MenuFacturas()
{
    char opc;
     system("color 0A");
    SetConsoleTitle("MENU DE FACTURA");
    system("CLS");
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 5);
        HOR;
    }
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 6);
        PUN;
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 7);
        HOR;
    }
    gotoxy(51, 6);
    cout << " F A C T U R A S ";
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 5);
    cout << TOPE;
    gotoxy(110, 5);
    cout << EDA;
    gotoxy(9, 7);
    cout << EIB;
    gotoxy(110, 7);
    cout << EDB;

    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 9);
        HOR;
    }
    for (int a = 9; a <= 22; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 22);
        HOR;
    }
    for (int a = 9; a <= 22; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 9);
    cout << TOPE;
    gotoxy(110, 9);
    cout << EDA;
    gotoxy(9, 22);
    cout << EIB;
    gotoxy(110, 22);
    cout << EDB;
    for (int a = 10; a <= 20; a++)
    {
        gotoxy(35, a);
        VER
    }
    for (int a = 10; a <= 20; a++)
    {
        gotoxy(84, a);
        VER
    }
    gotoxy(35, 11);
    cout << V << " -->   [1] COMPRA NUEVA                         " << V;
    gotoxy(35, 13);
    cout << V << " -->   [2] BUSQUEDA DE CLIENTES                 " << V;
    gotoxy(35, 15);
    cout << V << " -->   [3] BUSQUEDA DE FACTURAS                 " << V;
    gotoxy(35, 17);
    ARENBJ;
    gotoxy(35, 21);
    ABJ;
    gotoxy(35, 19);
    cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
    gotoxy(35, 23);
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
            getch();
            Puerto->WriteData("f",sizeof("f")-1);
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

        case 27:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "Opcion Incorreta elija de nuevo" << endl;
            getch();
            MenuFacturas();
            break;
        }
        }
    }
}
bool ValidacionNIT(string nit)
{
    int tam = nit.size();
    bool ver;
    char frase[tam];
    strcpy(frase, nit.c_str());
    for (int i = 0; i < tam; i++)
    {
        if (frase[i] == '-')
        {
            ver = true;
        }
    }
    if (ver == false)
    {
        gotoxy(1, 25);
        cout << "\n\t\t NIT INGRESADO NO CONTIENE GUION" << endl;
        real = false;
        Facture();
    }
    char *token, *aux, *numnit;
    token = strtok(frase, "-");
    int numval, tamnum;
    while (token != NULL && ver == true)
    {
        aux = token;
        token = strtok(NULL, "-");
        if (token == NULL)
        {
            char k = *aux;
            if (k == 'k')
            {
                numval = 10;
            }
            numval = atoi(aux);
        }
        else
        {
            numnit = aux;
            tamnum = strlen(aux);
        }
    }

    int digitos[tamnum], num1;
    num1 = atoi(numnit);
    for (int i = 0; i < tamnum; i++)
    {
        num1 = numnit[i] - '0';
        digitos[i] = num1;
    }
    int j = 1, acum = 0, mult, n1, n2, n3, n4, n5, codv, codigo;
    for (int i = tamnum - 1; i >= 0; i--)
    {
        j++;
        mult = digitos[i] * j;
        acum = acum + mult;
    }
    n1 = acum / 11;
    n2 = n1 * 11;
    n3 = acum - n2;
    n4 = n3 / 11;
    n5 = n4 * 11;
    codv = n3 - n5;
    codigo = 11 - codv;
    if (numval == codigo)
    {
        real = true;
    }
    if (numval != codigo)
    {
        real = false;
    }
    return real;
}
void Facture()
{
    fflush(stdin);
    SetConsoleTitle("FACTURA");
    Clientes Cliente;
    Facturas Factura;
    FILE *Clients = fopen("Source/Clientes.dat", "a+b");
    FILE *Temporal = fopen("Impresion.txt", "w+");
    int no=1,NO=1;
    char buffer[50];
    string Back="Source/Backup/Factura";
    no=Contador(NO);
    itoa(no,buffer,10);
    Back.append(buffer);
    Back.append(".txt");
    FILE *Temporal2 = fopen(Back.c_str(), "a+");
    int EncontradoNit = 0;
    string Auxnit;
    const char CF[]="CONSUMIDOR FINAL";
    const char Dir[]="CIUDAD";
    const char cfinal[]="c/f";
    const char cfinal3[]="cf";
    bool cf=false;
    do
    {
        system("CLS");
        for (int a = 11; a <= 99; a++)
        {
            gotoxy(a, 3);
            PUN;
        }
        gotoxy(43, 3);
        cout << " R E G I S T R O  D E   N I T ";
        cout << "\n\n\t\t NIT -> ";
        getline(cin, Auxnit);
        Minusculas(Auxnit);
        fflush(stdin);
        if((strcmp(Auxnit.c_str(),cfinal)==0)||(strcmp(Auxnit.c_str(),cfinal3)==0))
        {
            real=true;
            cf=true;
        }
        else
        {
            ValidacionNIT(Auxnit);
        }

    }
    while (real == false);
    fread(&Cliente, sizeof(Clientes), 1, Clients);
    while (!feof(Clients))
    {
        if (strcmp(Auxnit.c_str(), Cliente.NIT) == 0)
        {
            EncontradoNit = 1;
            IA = 1;
            fflush(stdin);
            Factura.NoFactura = Contador(IA);
            FILE *Factures = fopen("Source/Factura.dat", "a+b");
            strcpy(Factura.NITFactura, Auxnit.c_str());
            Factura.FechaFactura.d = tmP->tm_mday;
            Factura.FechaFactura.m = tmP->tm_mon + 1;
            Factura.FechaFactura.a = tmP->tm_year + 1900;
            fwrite(&Factura, sizeof(Facturas), 1, Factures);
            fclose(Factures);
            system("CLS");

            cout << "No.Factura " << Factura.NoFactura << "\t Fecha : " << Factura.FechaFactura.d << "/" << Factura.FechaFactura.m << "/" << Factura.FechaFactura.a << endl;
            cout << "NIT: " << Factura.NITFactura << endl;
            cout << "Cliente: " << Cliente.NombreCliente << endl;
            cout << "Direccion: " << Cliente.DireccionCliente << endl;
            cout << "--------------------------------------------------" << endl;
            fprintf(Temporal, "No.Factura %d                   Fecha: %d/%d/%d        \n", Factura.NoFactura, Factura.FechaFactura.d, Factura.FechaFactura.m, Factura.FechaFactura.a);
            fprintf(Temporal, "NIT: %s\n", Factura.NITFactura);
            fprintf(Temporal, "Cliente: %s\n", Cliente.NombreCliente);
            fprintf(Temporal, "Direccion: %s\n", Cliente.DireccionCliente);
            fprintf(Temporal, "-------------------------------------------------\n");
            ///////////////////////////////////////////////////////////////////////////
            fprintf(Temporal2, "No.Factura %d                  Fecha: %d/%d/%d\n", Factura.NoFactura, Factura.FechaFactura.d, Factura.FechaFactura.m, Factura.FechaFactura.a);
            fprintf(Temporal2, "NIT: %s\n", Factura.NITFactura);
            fprintf(Temporal2, "Cliente: %s\n", Cliente.NombreCliente);
            fprintf(Temporal2, "Direccion: %s\n", Cliente.DireccionCliente);
            fprintf(Temporal2, "-------------------------------------------------\n");//////////////////////////////////////////////////////////
        }
        fread(&Cliente, sizeof(Clientes), 1, Clients);
    }

    if ((EncontradoNit==0)&&(!cf))
    {
        fflush(stdin);
        IA = 1;
        cout << "\n\t\t NOMBRE COMPLETO DEL CLIENTE -> ";
        cin.getline(Cliente.NombreCliente, 50, '\n');
        fflush(stdin);
        cout << "\n\t\t DIRECCION DEL CLIENTE -> ";
        cin.getline(Cliente.DireccionCliente, 50, '\n');
        fflush(stdin);
        strcpy(Cliente.NIT, Auxnit.c_str());
        fflush(stdin);
        fwrite(&Cliente, sizeof(Clientes), 1, Clients);
        fflush(stdin);
        Factura.NoFactura = Contador(IA);
        FILE *Factures = fopen("Source/Factura.dat", "a+b");
        strcpy(Factura.NITFactura, Auxnit.c_str());
        Factura.FechaFactura.d = tmP->tm_mday;
        Factura.FechaFactura.m = tmP->tm_mon + 1;
        Factura.FechaFactura.a = tmP->tm_year + 1900;
        fwrite(&Factura, sizeof(Facturas), 1, Factures);
        fclose(Factures);
        system("CLS");
        cout << "No.Factura " << Factura.NoFactura << "\t Fecha : " << Factura.FechaFactura.d << "/" << Factura.FechaFactura.m << "/" << Factura.FechaFactura.a << endl;
        cout << "NIT: " << Factura.NITFactura << endl;
        cout << "Cliente: " << Cliente.NombreCliente << endl;
        cout << "Direccion: " << Cliente.DireccionCliente << endl;
        cout << "---------------------------------------------------" << endl;
        fprintf(Temporal, "No.Factura %d                   Fecha: %d/%d/%d\n", Factura.NoFactura, Factura.FechaFactura.d, Factura.FechaFactura.m, Factura.FechaFactura.a);
        fprintf(Temporal, "NIT: %s\n", Factura.NITFactura);
        fprintf(Temporal, "Cliente: %s\n", Cliente.NombreCliente);
        fprintf(Temporal, "Direccion: %s\n", Cliente.DireccionCliente);
        fprintf(Temporal, "--------------------------------------------------------\n");
        ////////////////////////////////////////////////////////////////////////////////////
        fprintf(Temporal2, "No.Factura %d                  Fecha: %d/%d/%d\n", Factura.NoFactura, Factura.FechaFactura.d, Factura.FechaFactura.m, Factura.FechaFactura.a);
        fprintf(Temporal2, "NIT: %s\n", Factura.NITFactura);
        fprintf(Temporal2, "Cliente: %s\n", Cliente.NombreCliente);
        fprintf(Temporal2, "Direccion: %s\n", Cliente.DireccionCliente);
        fprintf(Temporal2, "--------------------------------------------------------\n");
        ////////////////////////////////////////////////////////////////////////////////////
    }
    else if((EncontradoNit==0)&&(cf))
    {
        fflush(stdin);
        IA=1;
        fflush(stdin);
        strcpy(Cliente.NombreCliente,CF);
        fflush(stdin);
        strcpy(Cliente.DireccionCliente,Dir);
        fflush(stdin);
        strcpy(Cliente.NIT,cfinal);
        fflush(stdin);
        fflush(stdin);
        Factura.NoFactura=Contador(IA);
        FILE *Factures=fopen("Source/Factura.dat","a+b");
        strcpy(Factura.NITFactura,cfinal);
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
        /////////////////////////////////////////////////////////////////////////
        fprintf(Temporal2,"No.Factura %d \tFecha: %d/%d/%d\n",Factura.NoFactura,Factura.FechaFactura.d,Factura.FechaFactura.m,Factura.FechaFactura.a);
        fprintf(Temporal2,"NIT: %s\n",Factura.NITFactura);
        fprintf(Temporal2,"Cliente: %s\n",Cliente.NombreCliente);
        fprintf(Temporal2,"Direccion: %s\n",Cliente.DireccionCliente);
        fprintf(Temporal2,"-------------------------------------------------\n");
        ///////////////////////////////////////////////////////////////////////////

    }
    fclose(Clients);
    fclose(Temporal);
    fclose(Temporal2);
}
int Contador(int valor)
{
    Facturas Factura;
    FILE *Factures = fopen("Source/Factura.dat", "a+b");
    fread(&Factura, sizeof(Facturas), 1, Factures);
    while (!feof(Factures))
    {
        valor = valor + 1;
        fread(&Factura, sizeof(Facturas), 1, Factures);
    }
    fclose(Factures);
    return valor;
}
void ProductosAComprar()
{
    fflush(stdin);
    int no=1,NO=0;
    char buffer[50];
    string Back="Source/Backup/Factura";
    no=Contador(NO);
    itoa(no,buffer,10);
    Back.append(buffer);
    Back.append(".txt");
    FILE *Temporal2 = fopen(Back.c_str(), "a+");
    FILE *Details = fopen("Source/factura_detalle.dat", "a+b");
    FILE *Temporal = fopen("Impresion.txt", "a+");
    Facturas Factura;
    Marcas Marca;
    int FILAS=11,FILASTOTALES=11;
    Productos Producto;
    FacturasDetalle FacturaDetalle;
    double subtotal = 0;
    int AuxCodigo = 0, Contador2 = 0,AuxCodigo2=0;
    bool more=true;
    gotoxy(0, 9);
    cout << "No.\tCodigo         Descripcion\t     Subtotal" << endl;
    gotoxy(0, 10);
    cout <<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<< H<<H<<H<<H<<endl;
    fprintf(Temporal, "No.  Codigo \t   Descripcion  \t    Subtotal\n");
    fprintf(Temporal2, "No.  Codigo \t   Descripcion  \t    Subtotal\n");
    FacturaDetalle.idProductos = new int[100];
    FacturaDetalle.PrecioVenta = new double[100];
    do
    {
loop:
        fflush(stdin);
        string AUXC;
        int Cantidad = 0;
        gotoxy(0, 8);
        cout << "                         ";
        gotoxy(0, 8);
        getline(cin,AUXC);
        fflush(stdin);
        if(strcmp(AUXC.c_str(),"admin")==0)
        {
            gotoxy(0,8);
            cout<<"                 ";
            AuxCodigo=-1;
        }
        else if (VerificadorDeNumeros(AUXC))
        {
            AuxCodigo= atoi(AUXC.c_str());
        }
        else
        {

            goto loop;
        }
        if(AuxCodigo==0)
        {
            more=false;
        }
        if(AuxCodigo==-1)
        {
            login();
            fflush(stdin);
            gotoxy(0,8);
            cout<<"Ingrese el producto a anular:";
            gotoxy(37,8);
            cin>>AuxCodigo2;
            gotoxy(0,8);
            cout<<"                                                ";
            fflush(stdin);
            FILE *Products=fopen("Source/Productos.dat","rb");
            fread(&Producto,sizeof(Productos),1,Products);
            while(!feof(Products))
            {
                if(AuxCodigo2==Producto.CodigoProducto)
                {
                    Contador2++;
                    Cantidad++;
                    FacturaDetalle.idProductos[Cantidad]=AuxCodigo2;
                    gotoxy(0, 11 + Contador2);
                    cout << Contador2 ;
                    gotoxy(6,11+Contador2);
                    cout<<"(-)"<<endl;
                    gotoxy(10,11+Contador2);
                    cout << Producto.CodigoProducto;
                    gotoxy(15,11+Contador2);
                    cout << Producto.DescripcionProducto;
                    gotoxy(16+strlen(Producto.DescripcionProducto),11+Contador2);
                    cout << "Marca";
                    fprintf(Temporal,"%d\t%d\t%s\t",Contador2,Producto.CodigoProducto,Producto.DescripcionProducto);
                    fprintf(Temporal2,"%d\t%d\t%s\t",Contador2,Producto.CodigoProducto,Producto.DescripcionProducto);
                    FILE *Marcs=fopen("Source/Marcas.dat","rb");
                    fread(&Marca,sizeof(Marca),1,Marcs);
                    while(!feof(Marcs))
                    {
                        if(Producto.idMarca==Marca.idMarca)
                        {
                            gotoxy(strlen(Producto.DescripcionProducto)+22,11+Contador2);
                            cout<<Marca.NombreMarca;
                            fprintf(Temporal,"Marca %s \t",Marca.NombreMarca);
                            fprintf(Temporal2,"Marca %s \t",Marca.NombreMarca);
                        }
                        fread(&Marca,sizeof(Marca),1,Marcs);
                    }
                    fclose(Marcs);
                    gotoxy(45,11+Contador2);
                    cout<<" Q."<<Producto.PrecioVenta<<endl;
                    FacturaDetalle.PrecioVenta[Cantidad]=Producto.PrecioVenta;
                    fprintf(Temporal,"Q. %.2f \n",Producto.PrecioVenta);
                    fprintf(Temporal2,"Q. %.2f \n",Producto.PrecioVenta);
                    subtotal=subtotal-Producto.PrecioVenta;
                    FacturaDetalle.IdFacturaDetalle=Contador(0);
                    FacturaDetalle.NoFactura=Factura.NoFactura;
                    fwrite(&FacturaDetalle,sizeof(FacturasDetalle),1,Details);
                }
                fread(&Producto,sizeof(Productos),1,Products);
            }

            fclose(Products);

        }
        else
        {
            fflush(stdin);
            FILE *Products = fopen("Source/Productos.dat", "rb");
            fread(&Producto, sizeof(Productos), 1, Products);
            while (!feof(Products))
            {
                if (AuxCodigo == Producto.CodigoProducto)
                {
                    Contador2++;
                    Cantidad++;
                    FacturaDetalle.idProductos[Cantidad] = AuxCodigo;
                    gotoxy(0, 11 + Contador2);
                    cout << Contador2 ;
                    gotoxy(10,11+Contador2);
                    cout << Producto.CodigoProducto;
                    gotoxy(15,11+Contador2);
                    cout << Producto.DescripcionProducto;
                    gotoxy(16+strlen(Producto.DescripcionProducto),11+Contador2);
                    cout << "Marca";
                    fprintf(Temporal, "%d \t %d \t %s ", Contador2, Producto.CodigoProducto, Producto.DescripcionProducto);
                    fprintf(Temporal2, "%d \t %d \t %s ", Contador2, Producto.CodigoProducto, Producto.DescripcionProducto);
                    FILE *Marcs = fopen("Source/Marcas.dat", "rb");
                    fread(&Marca, sizeof(Marca), 1, Marcs);
                    while (!feof(Marcs))
                    {
                        if (Producto.idMarca == Marca.idMarca)
                        {
                            gotoxy(strlen(Producto.DescripcionProducto)+22,11+Contador2);
                            cout << Marca.NombreMarca;
                            fprintf(Temporal, "Marca %s \t ", Marca.NombreMarca);
                            fprintf(Temporal2, "Marca %s \t ", Marca.NombreMarca);
                        }
                        fread(&Marca, sizeof(Marca), 1, Marcs);
                    }
                    fclose(Marcs);
                    gotoxy(45,11+Contador2);
                    cout << " Q." << Producto.PrecioVenta << endl;
                    FacturaDetalle.PrecioVenta[Cantidad] = Producto.PrecioVenta;
                    fprintf(Temporal, "Q. %.2f \n", Producto.PrecioVenta);
                    fprintf(Temporal2, "Q. %.2f \n", Producto.PrecioVenta);
                    subtotal = subtotal + Producto.PrecioVenta;
                    FacturaDetalle.IdFacturaDetalle = Contador(0);
                    FacturaDetalle.NoFactura = Factura.NoFactura;
                    fwrite(&FacturaDetalle, sizeof(FacturasDetalle), 1, Details);
                }
                fread(&Producto, sizeof(Productos), 1, Products);
            }

            fclose(Products);
        }
    }
    while (more);
    delete[] FacturaDetalle.idProductos;
    delete[] FacturaDetalle.PrecioVenta;
    gotoxy(0, 8);
    cout << "                                                                                        ";
    gotoxy(0, 13 + Contador2);
    cout << "Total: Q." << subtotal << endl;
    gotoxy(0, 14 + Contador2);
    cout << "GRACIAS POR SU COMPRA \t BLACK MARCKET :D"<< endl;
    fprintf(Temporal,"---------------------------------------\n");
    fprintf(Temporal, "Total: Q. %.2f\n\n", subtotal);
    fprintf(Temporal,"GRACIAS POR SU COMPRA \t BLACK MARCKET :D");

    fprintf(Temporal2,"---------------------------------------\n");
    fprintf(Temporal2, "Total: Q. %.2f \n\n", subtotal);
    fprintf(Temporal2,"GRACIAS POR SU COMPRA \t BLACK MARCKET :D");
    fclose(Details);
    fclose(Temporal);
    fclose(Temporal2);
    system("start imprimir.exe");
    Puerto->WriteData("e",sizeof("e")-1);
}
void MenuBusquedaCliente()
{
    char opc;
    SetConsoleTitle("MENU BUSQUEDA DE CLIENTES");
    system("CLS");
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 5);
        HOR;
    }
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 6);
        PUN;
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 7);
        HOR;
    }
    gotoxy(41, 6);
    cout << " B U S Q U E D A  D E  C L I E N T E S ";
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 5);
    cout << TOPE;
    gotoxy(110, 5);
    cout << EDA;
    gotoxy(9, 7);
    cout << EIB;
    gotoxy(110, 7);
    cout << EDB;

    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 9);
        HOR;
    }
    for (int a = 9; a <= 20; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 20);
        HOR;
    }
    for (int a = 9; a <= 20; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 9);
    cout << TOPE;
    gotoxy(110, 9);
    cout << EDA;
    gotoxy(9, 20);
    cout << EIB;
    gotoxy(110, 20);
    cout << EDB;
    for (int a = 10; a <= 19; a++)
    {
        gotoxy(35, a);
        VER
    }
    for (int a = 10; a <= 19; a++)
    {
        gotoxy(84, a);
        VER
    }
    gotoxy(35, 11);
    cout << V << " -->   [1] POR MEDIO DE NOMBRE                  " << V;
    gotoxy(35, 13);
    cout << V << " -->   [2] POR MEDIO DE NIT                     " << V;
    gotoxy(35, 15);
    ARENBJ;
    gotoxy(35, 19);
    ABJ;
    gotoxy(35, 17);
    cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
    gotoxy(35, 22);
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

        case 27:
        {  system("start Salida.vbs");
            ApagarBanda();
            gotoxy(7,31);
            exit(0);
            break;
        }
        default:
        {
            cout << "OPCION INCORRECTA, INGRESE NUEVAMENTE LA OPCION" << endl;
            getch();
            MenuBusquedaCliente();
            break;
        }
        }
    }
}
void SearchWhitName()
{
    fflush(stdin);
    Clientes Cliente;
    FILE *Clients = fopen("Source/Clientes.dat", "rb");
    string aux;
    string nombre;
    int Filas = 9, FilasTotales = 9;
    bool encontrado = false;
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
        for (int a = 11; a <= 99; a++)
        {
            gotoxy(a, 3);
            PUN;
        }
        gotoxy(38, 3);
        cout << " B U S Q U E D A  D E  C L I E NT E S ";
        cout << "\n\n\t\t NOMBRE DEL CLIENTE QUE DESEA BUSCAR -> ";
        getline(cin, aux);
        fflush(stdin);
        Minusculas(aux);
        SetConsoleTitle("REGISTROS");
        gotoxy(4, 6);
        cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
        gotoxy(4,7);
        cout<<V;
        gotoxy(20,7);
        cout<<"NOMBRE";
        gotoxy(44,7);
        cout<<V;
        gotoxy(60,7);
        cout<<"DIRECCION";
        gotoxy(86,7);
        cout<<V;
        gotoxy(100,7);
        cout<<"NIT";
        gotoxy(115,7);
        cout<<V;
        gotoxy(4,8);
        cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
        fread(&Cliente, sizeof(Clientes), 1, Clients);
        do
        {

            nombre = Cliente.NombreCliente;
            Minusculas(nombre);
            fflush(stdin);
            if (nombre.find(aux) != string::npos)
            {
                gotoxy(4,Filas);
                cout<<V;
                gotoxy(7,Filas);
                cout << Cliente.NombreCliente;
                gotoxy(44,Filas);
                cout<<V;
                gotoxy(50,Filas);
                cout<<Cliente.DireccionCliente;
                gotoxy(86,Filas);
                cout<<V;
                gotoxy(95,Filas);
                cout<<Cliente.NIT;
                gotoxy(115,Filas);
                cout<<V;
                encontrado = true;
                Filas++;
                FilasTotales++;
            }
            fread(&Cliente, sizeof(Clientes), 1, Clients);
        }
        while (feof(Clients) == 0);
        if (encontrado == false)
        {
            gotoxy(4,FilasTotales+1);
            cout << "\n\t\t\t\t\t\t * NO SE ENCUENTRA *" << endl;
        }
        gotoxy(4,FilasTotales);
        cout << EIB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDB<< endl;
        fclose(Clients);
    }
}
void SearchClientWhitNIT()
{
    fflush(stdin);
    Clientes Cliente;
    FILE *Clients = fopen("Source/Clientes.dat", "rb");
    bool encontrado = false;
    string aux;
    int Filas=9,FilasTotales=9;
    if (Facture == NULL)
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
        for (int a = 11; a <= 99; a++)
        {
            gotoxy(a, 3);
            PUN;
        }
        gotoxy(38, 3);
        cout << " B U S Q U E D A  D E  C L I E N T E S ";
        cout << "\n\n\t\t NIT QUE DESEA BUSCAR -> ";
        getline(cin, aux);
        fflush(stdin);
        SetConsoleTitle("REGISTROS");
        gotoxy(4, 6);
        cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
        gotoxy(4,7);
        cout<<V;
        gotoxy(20,7);
        cout<<"NOMBRE";
        gotoxy(44,7);
        cout<<V;
        gotoxy(62,7);
        cout<<"DIRECCION";
        gotoxy(86,7);
        cout<<V;
        gotoxy(100,7);
        cout<<"NIT";
        gotoxy(115,7);
        cout<<V;
        gotoxy(4,8);
        cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
        fread(&Cliente, sizeof(Clientes), 1, Clients);
        do
        {
            fflush(stdin);
            if (strcmp(aux.c_str(), Cliente.NIT) == 0)
            {
                gotoxy(4,Filas);
                cout<<V;
                gotoxy(7,Filas);
                cout << Cliente.NombreCliente;
                gotoxy(44,Filas);
                cout<<V;
                gotoxy(50,Filas);
                cout<<Cliente.DireccionCliente;
                gotoxy(86,Filas);
                cout<<V;
                gotoxy(95,Filas);
                cout<<Cliente.NIT;
                gotoxy(115,Filas);
                cout<<V;
                encontrado = true;
                Filas++;
                FilasTotales++;
            }
            fread(&Cliente, sizeof(Clientes), 1,Clients );
        }
        while (feof(Clients) == 0);
        if (encontrado == false)
        {
            gotoxy(4,FilasTotales+1);
            cout << "\n\t\t\t\t\t\t * NO SE ENCUENTRA *" << endl;
        }
        gotoxy(4,FilasTotales);
        cout << EIB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDB<< endl;
        fclose(Clients);
    }
}
void MenuBusquedaFactura()
{
    char opc;
    SetConsoleTitle("MENU BUSQUEDA DE FACTURA");
    system("CLS");
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 5);
        HOR;
    }
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 6);
        PUN;
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 7);
        HOR;
    }
    gotoxy(41, 6);
    cout << " B U S Q U E D A  D E  F A C T U R A ";
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 5);
    cout << TOPE;
    gotoxy(110, 5);
    cout << EDA;
    gotoxy(9, 7);
    cout << EIB;
    gotoxy(110, 7);
    cout << EDB;

    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 9);
        HOR;
    }
    for (int a = 9; a <= 20; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 20);
        HOR;
    }
    for (int a = 9; a <= 20; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 9);
    cout << TOPE;
    gotoxy(110, 9);
    cout << EDA;
    gotoxy(9, 20);
    cout << EIB;
    gotoxy(110, 20);
    cout << EDB;
    for (int a = 10; a <= 19; a++)
    {
        gotoxy(35, a);
        VER
    }
    for (int a = 10; a <= 19; a++)
    {
        gotoxy(84, a);
        VER
    }
    gotoxy(35, 11);
    cout << V << " -->   [1] POR MEDIO DE CORRELATIVO             " << V;
    gotoxy(35, 13);
    cout << V << " -->   [2] POR MEDIO DE NIT                     " << V;
    gotoxy(35, 15);
    ARENBJ;
    gotoxy(35, 19);
    ABJ;
    gotoxy(35, 17);
    cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
    gotoxy(35, 22);
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

        case 27:
        {  system("start Salida.vbs");
            ApagarBanda();
            gotoxy(7,31);
            exit(0);
            break;
        }
        default:
        {
            cout << "Opcion Incorreta elija de nuevo" << endl;
            getch();
            MenuBusquedaCliente();
            break;
        }
        }
    }
}
void SearchWhitCorrelative()
{
    fflush(stdin);
    Facturas Factura;
    FILE *Factures = fopen("Source/Factura.dat", "rb");
    bool encontrado = false;
    int aux = 0,Filas=9,FilasTotales=9;
    string AUX;
    if (Factures == NULL)
    {
        SetConsoleTitle("Error 002");
        cout << "Error 002" << endl;
        getch();
        MenuBusquedaCliente();
    }
    else
    {
lop:
        system("CLS");
        fflush(stdin);
        for (int a = 11; a <= 99; a++)
        {
            gotoxy(a, 3);
            PUN;
        }
        gotoxy(38, 3);
        cout << " B U S Q U E D A  D E  F A C T U R A S ";
        cout << "\n\n\t\t CORRELATIVO DE LA FACTURA QUE QUE DESEA BUSCAR -> ";
        getline(cin,AUX);
        if (VerificadorDeNumeros(AUX))
        {
            aux= atoi(AUX.c_str());
        }
        else
        {
            cout << "\n\n\t   * EL INGRESO DE LETRAS ES INCORRECTO  O NUMEROS NEGATIVOS, VALIDO UNICAMENTE NUMEROS POSITIVOS *" << endl;
            getch();
            goto lop;
        }
        fflush(stdin);
        SetConsoleTitle("REGISTROS");
        gotoxy(4, 6);
        cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
        gotoxy(4,7);
        cout<<V;
        gotoxy(20,7);
        cout<<"No.Factura";
        gotoxy(44,7);
        cout<<V;
        gotoxy(62,7);
        cout<<"Fecha";
        gotoxy(86,7);
        cout<<V;
        gotoxy(100,7);
        cout<<"NIT";
        gotoxy(115,7);
        cout<<V;
        gotoxy(4,8);
        cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
        fread(&Factura, sizeof(Facturas), 1, Factures);
        do
        {
            fflush(stdin);
            if (aux == Factura.NoFactura)
            {
                gotoxy(4,Filas);
                cout<<V;
                gotoxy(24,Filas);
                cout << Factura.NoFactura;
                gotoxy(44,Filas);
                cout<<V;
                gotoxy(60,Filas);
                cout<<Factura.FechaFactura.d<<"/"<<Factura.FechaFactura.m<<"/"<<Factura.FechaFactura.a;
                gotoxy(86,Filas);
                cout<<V;
                gotoxy(95,Filas);
                cout<<Factura.NITFactura;
                gotoxy(115,Filas);
                cout<<V;
                encontrado = true;
                Filas++;
                FilasTotales++;
                encontrado = true;
            }
            fread(&Factura, sizeof(Facturas), 1, Factures);
        }
        while (feof(Factures) == 0);
        if (encontrado == false)
        {
            gotoxy(4,FilasTotales+1);
            cout << "\n\t\t\t\t\t\t * NO SE ENCUENTRA *" << endl;
        }
        gotoxy(4,FilasTotales);
        cout << EIB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDB<< endl;
        fclose(Factures);
    }
}
void SearchFactureWhitNIT()
{
    fflush(stdin);
    Facturas Factura;
    FILE *Facture = fopen("Source/Factura.dat", "rb");
    bool encontrado = false;
    string aux;
    const char cfinal[]="c/f";
    const char cfinal3[]="cf";
    bool cf=false;
    int Filas=9,FilasTotales=9;
    if (Facture == NULL)
    {
        SetConsoleTitle("Error 002");
        cout << "Error 002" << endl;
        getch();
        MenuBusquedaFactura();
    }
    else
    {
        do
        {
            system("CLS");
            fflush(stdin);
            for (int a = 11; a <= 99; a++)
            {
                gotoxy(a, 3);
                PUN;
            }
            gotoxy(38, 3);
            cout << " B U S Q U E D A  D E  F A C T U R A S ";
            cout << "\n\n\t\t NIT QUE DESEA BUSCAR -> ";
            getline(cin, aux);
            fflush(stdin);
            Minusculas(aux);
            fflush(stdin);
            if((strcmp(aux.c_str(),cfinal)==0)||(strcmp(aux.c_str(),cfinal3)==0))
            {
                real=true;
                cf=true;
            }
            else
            {
                ValidacionNIT(aux);
            }

        }
        while (real == false);
        SetConsoleTitle("REGISTROS");
        gotoxy(4, 6);
        cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
        gotoxy(4,7);
        cout<<V;
        gotoxy(20,7);
        cout<<"No.Factura";
        gotoxy(44,7);
        cout<<V;
        gotoxy(62,7);
        cout<<"Fecha";
        gotoxy(86,7);
        cout<<V;
        gotoxy(100,7);
        cout<<"NIT";
        gotoxy(115,7);
        cout<<V;
        gotoxy(4,8);
        cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
        fread(&Factura, sizeof(Facturas), 1, Facture);
        do
        {
            fflush(stdin);
            if (strcmp(aux.c_str(), Factura.NITFactura) == 0)
            {
                gotoxy(4,Filas);
                cout<<V;
                gotoxy(24,Filas);
                cout << Factura.NoFactura;
                gotoxy(44,Filas);
                cout<<V;
                gotoxy(60,Filas);
                cout<<Factura.FechaFactura.d<<"/"<<Factura.FechaFactura.m<<"/"<<Factura.FechaFactura.a;
                gotoxy(86,Filas);
                cout<<V;
                gotoxy(95,Filas);
                cout<<Factura.NITFactura;
                gotoxy(115,Filas);
                cout<<V;
                encontrado = true;
                Filas++;
                FilasTotales++;
                encontrado = true;
            }
            fread(&Factura, sizeof(Facturas), 1, Facture);
        }
        while (feof(Facture) == 0);
        if (encontrado == false)
        {
            gotoxy(4,FilasTotales+1);
            cout << "\n\t\t\t\t\t\t * NO SE ENCUENTRA *" << endl;
        }
        gotoxy(4,FilasTotales);
        cout << EIB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDB<< endl;
        fclose(Facture);
    }
}
void MenuAyuda()
{
    char opc;
    SetConsoleTitle("MENU DE AYUDA");
    system("CLS");
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 5);
        HOR;
    }
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 6);
        PUN;
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 7);
        HOR;
    }
    gotoxy(54, 6);
    cout << " A Y U D A ";
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 5);
    cout << TOPE;
    gotoxy(110, 5);
    cout << EDA;
    gotoxy(9, 7);
    cout << EIB;
    gotoxy(110, 7);
    cout << EDB;

    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 9);
        HOR;
    }
    for (int a = 9; a <= 25; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 25);
        HOR;
    }
    for (int a = 9; a <= 25; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 9);
    cout << TOPE;
    gotoxy(110, 9);
    cout << EDA;
    gotoxy(9, 25);
    cout << EIB;
    gotoxy(110, 25);
    cout << EDB;
    for (int a = 10; a <= 20; a++)
    {
        gotoxy(35, a);
        VER
    }
    for (int a = 10; a <= 20; a++)
    {
        gotoxy(84, a);
        VER
    }
    gotoxy(35, 11);
    cout << V << " -->   [1] ERRORES                              " << V;
    gotoxy(35, 13);
    cout << V << " -->   [2] MANUAL DE USUARIO                    " << V;
    gotoxy(35, 15);
    cout << V << " -->   [3] DIAGRAMA ENTIDAD RELACION            " << V;
    gotoxy(35, 17);
    cout << V << " -->   [4] ADMINISTRADOR                        " << V;
    gotoxy(35, 19);
    cout << V << " -->   [5] CREDITOS                             " << V;
    gotoxy(35, 21);
    ARENBJ;
    gotoxy(35, 23);
    ABJ;
    gotoxy(35, 22);
    cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
    gotoxy(35, 24);
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
            Errores();
            getch();
            MenuAyuda();
            break;
        }
        case '2':
        {
            system("start Source/Manual_De_Usuario.pdf");
            MenuAyuda();
            break;
        }

        case '3':
        {
            system("start Source/DiagramaEntidadRelacion.png");
            MenuAyuda();
            break;
        }
        case '4':
        {
            if(loginAdmins())
            {
                MenuAdmin();
            }
            else
            {
                MenuAyuda();
            }
            getch();
            MenuAyuda();
            break;
        }
        case '5':
        {
            creditos();
            MenuAyuda();
            break;
        }
        case 27:
        {  system("start Salida.vbs");
            ApagarBanda();
            gotoxy(7,31);
            exit(0);
            break;
        }
        default:
        {
            cout << "Opcion Incorreta elija de nuevo" << endl;
            getch();
            MenuAyuda();
            break;
        }
        }
    }
}
void Errores()
{
    FILE *Error = fopen("Source/Errores.txt", "r");
    char c;
    if (Error == NULL)
    {
        cout << "Error 001" << endl;
    }
    else
    {
        system("CLS");
        while (!feof(Error))
        {
            c = fgetc(Error);
            cout << c;
        }
        getch();
        fclose(Error);
    }
}
void Minusculas(string & s)
{
    int i;
    for (i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
}
void MenuAdmin()
{
    char opc;
    SetConsoleTitle("MENU DE ADMINISTRADOR");
    system("CLS");
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 5);
        HOR;
    }
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 6);
        PUN;
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 7);
        HOR;
    }
    gotoxy(50, 6);
    cout << " A D M I N I S T R A D O R ";
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 5);
    cout << TOPE;
    gotoxy(110, 5);
    cout << EDA;
    gotoxy(9, 7);
    cout << EIB;
    gotoxy(110, 7);
    cout << EDB;

    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 9);
        HOR;
    }
    for (int a = 9; a <= 24; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 24);
        HOR;
    }
    for (int a = 9; a <= 24; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 9);
    cout << TOPE;
    gotoxy(110, 9);
    cout << EDA;
    gotoxy(9, 24);
    cout << EIB;
    gotoxy(110, 24);
    cout << EDB;
    for (int a = 10; a <= 20; a++)
    {
        gotoxy(35, a);
        VER
    }
    for (int a = 10; a <= 20; a++)
    {
        gotoxy(84, a);
        VER
    }
    gotoxy(35, 11);
    cout << V << " -->   [1] INGRESO DE SUPERVISOR                " << V;
    gotoxy(35, 13);
    cout << V << " -->   [2] LISTADO DE SUPERVISORES              " << V;
    gotoxy(35, 15);
    cout << V << " -->   [3] ELIMINACION DE SUPERVISORES          " << V;
    gotoxy(35, 17);
    ARENBJ;
    gotoxy(35, 21);
    ABJ;
    gotoxy(35, 19);
    cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
    gotoxy(35, 23);
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
            fflush(stdin);
            Admin();
            getch();
            MenuAdmin();
            break;
        }
        case '2':
        {
            MostrarSupervisores();
            getch();
            MenuAdmin();
            break;
        }
        case '3':
        {
            EliminarSupervisores();
            getch();
            MenuAdmin();
            break;
        }

        case 27:
        {  system("start Salida.vbs");
            ApagarBanda();
            gotoxy(7,31);
            exit(0);
            break;
        }
        default:
        {
            cout << "\aOPCION INCORRECTA, ELIJA NUEVAMENTE" << endl;
            getch();
            MenuAdmin();
            break;
        }
        }
    }

}
void login()
{
    Supervisores Datos;
loop:
    SetConsoleTitle("Login");
    int enc=0;
    char b;
    char ch;
    string PAS="",US="";
    gotoxy(90, 11);
    cout << "LOGIN" << endl;
    gotoxy(85, 13);
    cout << "Ingrese el usuario" << endl;
    gotoxy(85, 14);
    getline(cin,US);
    fflush(stdin);
    gotoxy(85, 15);
    cout << "Ingrese La Contrasenia " << endl;
    gotoxy(85, 16);
    ch = getch();
    while (ch != 13)
    {
        if (ch != 8)
        {
            PAS.push_back(ch);
            cout << "*";
        }
        else
        {
            if (PAS.length() > 0)
            {
                cout << "\b \b";
                PAS = PAS.substr(0, PAS.length() - 1);
            }
        }
        ch = getch();
    }

    fflush(stdin);
    FILE *Manager=fopen("Source/Managers.dat","a+b");
    fread(&Datos,sizeof(Supervisores),1,Manager);
    while(!feof(Manager))
    {
        if ((strcmp(US.c_str(), Datos.usuario) == 0) && (strcmp(PAS.c_str(),Datos.Pass)==0))
        {
            enc=1;
            gotoxy(90, 17);
            cout << "Bienvenido ";
            b = 250;
            for (int i = 0; i <= 3; i++)
            {
                cout << b;
                Sleep(1000);
            }
            Sleep(200);
            gotoxy(90,17);
            cout<<"                    "<<endl;
            gotoxy(85,11);
            cout<<"                    "<<endl;
            gotoxy(85,13);
            cout<<"                    "<<endl;
            gotoxy(85,14);
            cout<<"                    "<<endl;
            gotoxy(85,15);
            cout<<"                      "<<endl;
            gotoxy(85,16);
            cout<<"                    "<<endl;


        }
        fread(&Datos,sizeof(Supervisores),1,Manager);
    }
    if(enc==0)
    {
        gotoxy(90,17);
        cout<<"                    "<<endl;
        gotoxy(85,11);
        cout<<"                    "<<endl;
        gotoxy(85,13);
        cout<<"                    "<<endl;
        gotoxy(85,14);
        cout<<"                    "<<endl;
        gotoxy(85,15);
        cout<<"                      "<<endl;
        gotoxy(85,16);
        cout<<"                    "<<endl;

        goto loop;
    }
    fclose(Manager);
}
void Admin()
{
    fflush(stdin);
    Supervisores Datos;
    FILE *Managers=fopen("Source/Managers.dat","a+b");
    fflush(stdin);
    system("CLS");

loop:
     fflush(stdin);
    system("CLS");
    int duplicado=0;
    string us,name,dire,Dpi;
    char opc2;
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 3);
        PUN;
    }
    gotoxy(38, 3);
    cout << " I N G R E S O  D E  S U P E R V I S O R ";
    cout<<"\n\n\t\t Ingrese el usuario que tendra-> ";
    getline(cin,us);
    fflush(stdin);
    rewind(Managers);
    fread(&Datos,sizeof(Supervisores),1,Managers);
    while(!feof(Managers))
    {
        if(strcmp(us.c_str(),Datos.usuario)==0)
        {
            duplicado=1;
            cout<<"\n\n\t\tUsuario ya existente"<<endl;
            getch();
            goto loop;
            fflush(stdin);
        }
        fread(&Datos,sizeof(Supervisores),1,Managers);
    }
    if(duplicado==0)
    {
        fflush(stdin);
        cout<<"\n\n\t\t Ingrese el nombre del empleado-> ";
        getline(cin,name);
        strcpy(Datos.nombre,name.c_str());
        fflush(stdin);

        cout<<"\n\n\t\t ingrese el DPI de "<<Datos.nombre<<" -> ";
        getline(cin,Dpi);
        Datos.DPI=atof(Dpi.c_str());
        fflush(stdin);
        cout<<"\n\n\t\t Ingrese la direccion de "<<Datos.nombre<<" -> ";
        getline(cin,dire);
        strcpy(Datos.Dir,dire.c_str());
        fflush(stdin);
        fflush(stdin);
        strcpy(Datos.usuario,us.c_str());
        fflush(stdin);
opc22:
        cout<<"\n\n\t\t  Desea password manual o automatico? M/A  -> ";
        cin>>opc2;
        fflush(stdin);
        if(opc2=='M'||opc2=='m')
        {
pass:
            fflush(stdin);
            string pas="";
            string pas1="";
            char ch1,ch;
            fflush(stdin);
            cout<<"\n\n\t\t Ingrese el password -> ";
            ch = getch();
            fflush(stdin);
            while (ch != 13)
            {
                if (ch != 8)
                {
                    pas.push_back(ch);
                    cout << "*";
                }
                else
                {
                    if (pas.length() > 0)
                    {
                        cout << "\b \b";
                        pas = pas.substr(0, pas.length() - 1);
                    }
                }
                ch = getch();
                fflush(stdin);
            }
            fflush(stdin);
            cout<<"\n\n\t\t Confirme el password -> ";
            ch1 = getch();
            fflush(stdin);
            while (ch1 != 13)
            {
                if (ch1 != 8)
                {
                    pas1.push_back(ch1);
                    cout << "*";
                }
                else
                {
                    if (pas1.length() > 0)
                    {
                        cout << "\b \b";
                        pas1 = pas1.substr(0, pas1.length() - 1);
                    }
                }
                ch1 = getch();
                fflush(stdin);
            }
            fflush(stdin);
            if(pas1!=pas)
            {
                cout<<endl;
                cout<<"Las contrasenias no coinciden"<<endl;
                getch();
                fflush(stdin);
                goto pass;
            }
            else
            {
                fflush(stdin);
                strcpy(Datos.Pass,pas.c_str());
                fflush(stdin);
                Clave(pas,name,Datos.DPI);
                fflush(stdin);
                fwrite(&Datos,sizeof(Supervisores),1,Managers);
                cout<<endl;
                cout<<"Agregado Exitosamente"<<endl;
                getch();
            }
        }
        else if(opc2=='A'||opc2=='a')
        {
            string pas="";
            generador(1);
            ifstream Archivo;

            string linea;
            Archivo.open("Source/CLAVES.dat",ios::in|ios::binary);
            getline(Archivo,linea);
            cout<<linea<<endl;

            strcpy(Datos.Pass,linea.c_str());
            fflush(stdin);
            Archivo.close();
            remove("Source/CLAVES.dat");
            Clave(linea,name,Datos.DPI);
            fflush(stdin);
            fwrite(&Datos,sizeof(Supervisores),1,Managers);
            cout<<endl<<"Agregado Exitosamente"<<endl;
        }
        else
        {
            cout<<"Elija A/M"<<endl;
            getch();
            goto opc22;
        }
    }
    fclose(Managers);
}
bool loginAdmins()
{
loop:
    fflush(stdin);
    system("CLS");
    SetConsoleTitle("Login Administrador");
    char b;
    char  ch;
    int aprove=0;
    string PAS = "";
    string US="";
    gotoxy(55, 5);
    cout << "Login Administrador" << endl;
    gotoxy(45, 7);
    cout << "Ingrese el usuario" << endl;
    gotoxy(45, 8);
    getline(cin,US);
    fflush(stdin);
    gotoxy(45, 9);
    cout << "Ingrese La Contrasenia " << endl;
    gotoxy(45, 10);
    ch = getch();
    while (ch != 13)
    {
        if (ch != 8)
        {
            PAS.push_back(ch);
            cout << "*";
        }
        else
        {
            if (PAS.length() > 0)
            {
                cout << "\b \b";
                PAS = PAS.substr(0, PAS.length() - 1);
            }
        }
        ch = getch();
    }
    if ((strcmp(US.c_str(), "admin") == 0) && (strcmp(PAS.c_str(), "123") == 0))
    {
        aprove=1;
        gotoxy(45, 12);
        cout << "Bienvenido ";
        b = 250;
        for (int i = 0; i <= 3; i++)
        {
            cout << b;
            Sleep(1000);
        }
        Sleep(200);
        gotoxy(45,17);
        cout<<"                                                                "<<endl;
        gotoxy(55,5);
        cout<<"                                                                "<<endl;
        gotoxy(45,7);
        cout<<"                                                                "<<endl;
        gotoxy(45,8);
        cout<<"                                                                "<<endl;
        gotoxy(45,9);
        cout<<"                                                                "<<endl;
        gotoxy(45,10);
        cout<<"                                                                "<<endl;
        gotoxy(20,12);
        cout<<"                                                                                     "<<endl;
        fflush(stdin);
        return true;
    }
    if(aprove==0)
    {
         system("start Error.vbs");
         Sleep(250);
        goto loop;
    }
}
void MostrarSupervisores()
{
    system("CLS");
    int Filas = 9, FilasTotales = 9, encontradomarca = 0;
    SetConsoleTitle("LISTADO DE SUPERVISORES");
    Supervisores Datos;
    bool encontrado=true;
    FILE *Manager=fopen("Source/Managers.dat","rb");
    if (Manager == NULL)
    {
        cout << " ERROR 001 " << endl;
        getch();
        MenuAdmin();
    }
    else
    {
        fflush(stdin);
        for (int a = 10; a <= 100; a++)
        {
            gotoxy(a, 1);
            PUN;
        }
        gotoxy(43, 1);
        cout << " L I S T A D O  D E  S U P E R V I S O R E S ";
        SetConsoleTitle("REGISTROS");
        gotoxy(4, 6);
        cout << EIA << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CT << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDA << endl;
        gotoxy(4,7);
        cout<<V;
        gotoxy(20,7);
        cout<<"NOMBRE";
        gotoxy(41,7);
        cout<<V;
        gotoxy(51,7);
        cout<<"DIRECCION";
        gotoxy(72,7);
        cout<<V;
        gotoxy(79,7);
        cout<<"DPI";
        gotoxy(90,7);
        cout<<V;
        gotoxy(100,7);
        cout<<"USUARIO";
        gotoxy(115,7);
        cout<<V;

        gotoxy(4,8);
        cout << LTI << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CRUZ << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << LTD << endl;
        fread(&Datos, sizeof(Supervisores), 1, Manager);
        do
        {
            gotoxy(4,Filas);
            cout<<V;
            gotoxy(5,Filas);
            cout<<Datos.nombre;
            gotoxy(41,Filas);
            cout<<V;
            gotoxy(42,Filas);
            cout<<Datos.Dir;
            gotoxy(72,Filas);
            cout<<V;
            gotoxy(75,Filas);
            cout<<Datos.DPI;
            gotoxy(90,Filas);
            cout<<V;
            gotoxy(91,Filas);
            cout<<Datos.usuario;
            gotoxy(115,Filas);
            cout<<V;
            encontrado = true;
            Filas++;
            FilasTotales++;
            encontrado = true;
            fread(&Datos, sizeof(Supervisores), 1, Manager);
        }
        while (feof(Manager) == 0);
        if (encontrado == false)
        {
            gotoxy(4,FilasTotales+1);
            cout << "\n\t\t\t\t\t\t * NO SE ENCUENTRA *" << endl;
        }
        gotoxy(4,FilasTotales);
        cout << EIB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << CB << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << H << EDB << endl;
    }
    fclose(Manager);
}
void generador(int ind)
{
    system("CLS");
    int contador=1;
    ofstream Archivo;
    fflush(stdin);
    Archivo.open("Source/CLAVES.dat",ios::out|ios::binary);
    srand(time(NULL));
    gotoxy(34,5);
    cout<<EIA<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<EDA<<endl;
    while(contador<=3)
    {
        char mi_letra3 = (char)(rand() % 26 + 'A');
        char mi_letra4 = (char)(rand() % 26 + 'a');
        char mi_letra5 = (char)(rand() % 9 + '0');
        gotoxy(35+(contador*3),6);
        cout << mi_letra3<<mi_letra4 << mi_letra5;
        Archivo<<mi_letra3<<mi_letra4<<mi_letra5<<" ";
        contador++;
    }
    Archivo<<endl;
    gotoxy(34,6);
    cout<<V;
    gotoxy(83,6);
    cout<<V;
    gotoxy(34,7);
    cout<<EIB<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<H<<EDB<<endl;
    cout<<"Clave Guardada"<<endl;

    Archivo.close();
}
void EliminarSupervisores()
{
    fflush(stdin);
    int encontrado=0;
    Supervisores Datos;
    FILE *Managers=fopen("Source/Managers.dat","a+b");
    FILE *Temporal=fopen("Source/Temporal.dat","a+b");
    fflush(stdin);
    system("CLS");
    for (int a = 10; a <= 100; a++)
    {
        gotoxy(a, 1);
        PUN;
    }
    gotoxy(43, 1);
    cout << " E L I M I N A R  S U P E R V I S O R ";
    string aux;
    cout<<"\n\n\t\t Ingrese el usuario a Eliminar -> ";
    getline(cin,aux);
    fflush(stdin);
    fread(&Datos,sizeof(Supervisores),1,Managers);
    while(!feof(Managers))
    {
        if(strcmp(aux.c_str(),Datos.usuario)==0)
        {
            encontrado=1;
            cout<<"\n\n\t\t Eliminado Correctamente "<<endl;
            getch();
        }
        else
        {
            fwrite(&Datos,sizeof(Supervisores),1,Temporal);
        }
        fread(&Datos,sizeof(Supervisores),1,Managers);
    }
    if(encontrado==0)
    {
        cout<<"No existe"<<endl;
        getch();
    }
    fclose(Managers);
    fclose(Temporal);
    remove("Source/Managers.dat");
    rename("Source/Temporal.dat","Source/Managers.dat");
}
void MenuIngresoProductos()
{
    char opc;
    SetConsoleTitle("MENU INGRESO DE PRODUCTOS");
    system("CLS");
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 5);
        HOR;
    }
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 6);
        PUN;
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 7);
        HOR;
    }
    gotoxy(41, 6);
    cout << " M E N U  I N G R E S O  D E  P R O D U C T O S ";
    for (int a = 5; a <= 6; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 5);
    cout << TOPE;
    gotoxy(110, 5);
    cout << EDA;
    gotoxy(9, 7);
    cout << EIB;
    gotoxy(110, 7);
    cout << EDB;

    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 9);
        HOR;
    }
    for (int a = 9; a <= 20; a++)
    {
        gotoxy(9, a);
        VER
    }
    for (int a = 10; a <= 101; a++)
    {
        gotoxy(a, 20);
        HOR;
    }
    for (int a = 9; a <= 20; a++)
    {
        gotoxy(110, a);
        VER
    }
    gotoxy(9, 9);
    cout << TOPE;
    gotoxy(110, 9);
    cout << EDA;
    gotoxy(9, 20);
    cout << EIB;
    gotoxy(110, 20);
    cout << EDB;
    for (int a = 10; a <= 19; a++)
    {
        gotoxy(35, a);
        VER
    }
    for (int a = 10; a <= 19; a++)
    {
        gotoxy(84, a);
        VER
    }
    gotoxy(35, 11);
    cout << V << " -->   [1] INGRESO MANUAL                       " << V;
    gotoxy(35, 13);
    cout << V << " -->   [2] IMPORTACION DE CSV                   " << V;
    gotoxy(35, 15);
    ARENBJ;
    gotoxy(35, 19);
    ABJ;
    gotoxy(35, 17);
    cout << V << "         <-- REGRESAR / ESC. SALIR              " << V;
    gotoxy(35, 22);
    opc = getch();
    if (opc == 8)
    {
        MenuInventario();
    }
    else
    {
        switch (opc)
        {
        case '1':
        {
            IngresoProductos();
            getch();
            MenuIngresoProductos();
            break;
        }
        case '2':
        {
            if(loginAdmins())
            {
                ImportacionCSV();
            }
            else
            {
                MenuIngresoProductos();
            }
            getch();
            MenuIngresoProductos();
            break;
        }

        case 27:
        {  system("start Salida.vbs");
            ApagarBanda();
            gotoxy(7,31);
            exit(0);
            break;
        }
        default:
        {
            cout << "OPCION INCORRECTA, INGRESE NUEVAMENTE LA OPCION" << endl;
            getch();
            MenuIngresoProductos();
            break;
        }
        }
    }
}
void ImportacionCSV()
{
    Productos Producto;
    fstream Archivo;
    system("CLS");
    fflush(stdin);
    string nombrearchivo;
    string csv=".csv";
    ofstream Archivo2;
    Archivo2.open("Source/Productos.dat",ios::out|ios::binary);
    system("CLS");
    fflush(stdin);
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 3);
        PUN;
    }
    gotoxy(38, 3);
    cout << " I M P O R T A C I O N  D E  I N V E N T A R I O ";
    cout << "\n\n Digite el nombre del archivo csv debe de estar en la carpeta -> ";
    getline(cin,nombrearchivo);
    nombrearchivo.append(".csv");
    cout<<"En un momento se mostrara la informacion :D"<<endl;
    Sleep(2000);
    string Codigo,nombre,idMarca,PrecioVenta,PrecioCosto,d,m,a;
    string texto;
    Archivo.open(nombrearchivo.c_str(),ios::in);
    getline(Archivo,texto);
    while(getline(Archivo,texto))
    {
        stringstream ss(texto);
        getline(ss,Codigo,';');
        Producto.CodigoProducto=atoi(Codigo.c_str());
        fflush(stdin);
        getline(ss,nombre,';');
        strcpy(Producto.DescripcionProducto,nombre.c_str());
        fflush(stdin);
        getline(ss,idMarca,';');
        Producto.idMarca=atoi(idMarca.c_str());
        fflush(stdin);
        getline(ss,PrecioVenta,';');
        Producto.PrecioVenta=atof(PrecioVenta.c_str());
        fflush(stdin);
        getline(ss,PrecioCosto,';');
        Producto.PrecioCosto=atof(PrecioCosto.c_str());
        fflush(stdin);
        getline(ss,d,'/');
        Producto.FechaDeIngreso.d=atoi(d.c_str());
        fflush(stdin);
        getline(ss,m,'/');
        Producto.FechaDeIngreso.m=atoi(m.c_str());
        fflush(stdin);
        getline(ss,a,'\0');
        Producto.FechaDeIngreso.a=atoi(a.c_str());
        fflush(stdin);

        cout<<"Codigo :"<<Codigo<<endl;
        cout<<"Nombre :"<<nombre<<endl;
        cout<<"IdMarca :"<<idMarca<<endl;
        cout<<"Precio Venta :Q."<<PrecioVenta<<endl;
        cout<<"Precio Costo :Q."<<PrecioCosto<<endl;
        cout<<"Fecha De Ingreso :"<<Producto.FechaDeIngreso.d<<"/"<<Producto.FechaDeIngreso.m<<"/"<<Producto.FechaDeIngreso.a<<endl;
        cout<<"-------------------------------"<<endl;
        Archivo2.write( (char *)&Producto,sizeof(Productos));

    }
    getch();
    Archivo.close();
    Archivo2.close();
}
void creditos()
{
    system("cls");
    system("start Creditos.vbs");
    for (int a = 11; a <= 99; a++)
    {
        gotoxy(a, 3);
        PUN;
    }
    gotoxy(50, 3);
    cout << " C R E D I T O S \n";
    fstream archivo;
    string linea;

    if(!archivo.is_open())
        archivo.open("Source/creditos.txt",ios::in);
    while(getline(archivo, linea))
        cout << "\n            \t\t\t" << linea << "\n";

    archivo.close();
    system("pause");
}
void ApagarBanda()
{
    Puerto->WriteData("d",sizeof("d")-1);
    Puerto->WriteData("b",sizeof("b")-1);
}
