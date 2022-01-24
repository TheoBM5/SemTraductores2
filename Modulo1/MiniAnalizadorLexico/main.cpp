#include <cstdlib>
#include <iostream>
#include <string>


#include "lexico.h"

using namespace std;

int main(int argc, char *argv[]){
    
    Lexico lexico;
    lexico.entrada("hola+*3243");
    
    cout << "Resultado del Analisis Lexico" << endl << endl;
    cout << "Simbolo\t\tTipo" << endl;
    
    while ( lexico.simbolo.compare("$") != 0 ){ //compare compara el simbolo actual con el $ 
                                                //si compare da 0 es porque ambas cadenas son iguales
          lexico.sigSimbolo();                  //mientras no sea el final "$" seguira analizando simbolos
          cout <<  lexico.simbolo << "\t\t" << lexico.tipoAcad(lexico.tipo) << endl;          
    }
        
    cin.get();
  
    return 0;
}