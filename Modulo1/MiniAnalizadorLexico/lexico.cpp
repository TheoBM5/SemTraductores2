#include "lexico.h"

  Lexico::Lexico(string fuente){
    ind= 0;       // Posicion del caracter que esta analizando           
    this->fuente= fuente;
  }      

  Lexico::Lexico(){
    ind= 0;       // Posicion del caracter que esta analizando           
  }      
  
  string Lexico::tipoAcad(int tipo){ // lexico.tipoAcad(lexico.tipo)
         string cad= "";
         
         switch (tipo){
           case TipoSimbolo::IDENTIFICADOR:  //0
                cad= "Identificador";
                break;
                
           case TipoSimbolo::OPADIC:  //1
                cad= "Op. Adicion";
                break;

           case TipoSimbolo::OPMULT:
                cad= "Op. Multiplicacion";
                break;            

           case TipoSimbolo::PESOS:
                cad= "Fin de la Entrada";
                break;            

           case TipoSimbolo::ENTERO:
                cad= "Entero";
                break;
           case TipoSimbolo::REAL:
                cad= "Real";
                break;
                
         }
         
         return cad;
  }
  
  void Lexico::entrada(string fuente){ //lexico.entrada("+-+");
     ind= 0;                   // Posicion del caracter que esta analizando
     this->fuente= fuente;
  }

int Lexico::sigSimbolo(){
    
    estado=0;  //reinicia el automata al estado inicial
    continua= true;  //mientras no sea el final sera verdadero
    simbolo= ""; //almacena el simbolo que se imprimira 
    
    //Inicio del Automata
    while (continua){
      c= sigCaracter();
      
      switch (estado){
        case 0:
             if ( c == '+' || c=='-') aceptacion(1); 
             else
              if ( c == '$' ) aceptacion(3);
              else
               if( c == '*' ) aceptacion(2);
               else
                if(esDigito(c)) sigEstado(1);
                else
                 if(esLetra(c)) sigEstado(3);
                break;
          case 1:
               if (esDigito(c)) sigEstado(1);
                else
                 if ( c == '.') sigEstado(2);
                 else
                  if( c != '.')
                  { 
                    retroceso();
                    this->estado=4;
                    //aceptacion(4);
                  } 
               break;
          case 2:
               if(esDigito(c)) sigEstado(2);
               else
                if (!esDigito(c))
                { 
                    retroceso(); 
                    this->estado=5;
                    //aceptacion(5);
                } 
               break;    
          case 3:
               if(esDigito(c)) sigEstado(3);
               else
                if(esLetra(c)) sigEstado(3);
               else{
                    retroceso(); 
                    this->estado=0;
               }  
      }  
     
   }    
    //Fin del Automata
    
      switch (estado){
         
          case 0:
               tipo= TipoSimbolo::IDENTIFICADOR;
               break;
          case 1:
               tipo= TipoSimbolo::OPADIC;
               break;
          case 2:
              tipo= TipoSimbolo::OPMULT;
              break; 
          case 3:
               tipo= TipoSimbolo::PESOS;
               break;
          case 4:
               tipo= TipoSimbolo::ENTERO;
               break;
          case 5:
               tipo= TipoSimbolo::REAL;
               break;
        dafault:                 
              tipo= TipoSimbolo::ERROR;
      }
    		
	return tipo;
}

 char Lexico::sigCaracter(){
      if (terminado()) return '$'; //si ya no hay caracteres regresa $ 
      
      return fuente[ind++];   //avanza al siguiente caracter de la cadena aumentando el indice
 }

  void Lexico::sigEstado(int estado){
       this->estado= estado;
       simbolo+= c;
  }
  
  void Lexico::aceptacion(int estado){
       sigEstado(estado);
       continua= false;
  }

  bool Lexico::terminado(){//fin de cadena
         return ind >= fuente.length(); //tamaño de la entrada es igual la posicion en la 
                                        //que va.
  }

   bool Lexico::esLetra(char c){   //Si el caracter es una letra es verdadero?
        return isalpha(c) || c=='_';
   }
   
   
   bool Lexico::esDigito(char c){ //si el caracter es un digito es verdadero?
        return isdigit(c);
   }
   
   bool Lexico::esEspacio(char c){ //Si el caracter es una espacio o salto de linea es verdadero?
        return c== ' ' || c== '\t';        
   }

            
   void Lexico::retroceso(){ //retroce el indice del caracter que se esta analizando
      if ( c != '$') ind--;
        continua= false;
    }

