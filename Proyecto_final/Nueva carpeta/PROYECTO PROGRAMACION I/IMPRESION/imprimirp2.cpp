 #include <iostream>
#include <fstream>
using namespace  std ;

int main()
{
   // Identifica el puerto de la impresora
   char const * const  pszPrinterName = "PRN" ;

   // Abre el flujo de la impresora
   ofstream  prn( pszPrinterName );

   // Asegura que la impresora se abrio exitosamente
   if ( !prn) {
      cerr << "ERROR: No se puede abrir " << pszPrinterName << '\n' ;
      return  1 ;
   }

   // Imprime un mensaje
   prn << "Hola mundo!" ;

   prn << '\r'     // Retorno de carro (ENTER)
       << '\f' ;   // Expulsa la ultima hoja de la impresora

   // Cierra la impresora
   prn.close();
   
   return 0;
} 
