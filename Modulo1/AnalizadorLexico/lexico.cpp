#include "lexico.h"

Lexico::Lexico(string fuente) {
    ind = 0;       // Posicion del caracter que esta analizando           
    this->fuente = fuente;
}

Lexico::Lexico() {
    ind = 0;       // Posicion del caracter que esta analizando           
}

string Lexico::tipoAcad(int tipo) { // lexico.tipoAcad(lexico.tipo)
    string cad = "";

    switch (tipo) {
    case TipoSimbolo::IDENTIFICADOR:  //0
        cad = "Identificador";
        break;
    case TipoSimbolo::ENTERO:  //1
        cad = "Entero";
        break;
    case TipoSimbolo::REAL:  //2
        cad = "Real";
        break;
    case TipoSimbolo::CADENA:  //3
        cad = "Cadena";
        break;
    case TipoSimbolo::TIPO:  //4
        cad = "Tipo";
        break;
    case TipoSimbolo::OPADIC:  //5
        cad = "Op. Adicion";
        break;
    case TipoSimbolo::OPMULT: //6
        cad = "Op. Multiplicacion";
        break;
    case TipoSimbolo::OPREL: //7
        cad = "Op. Relacion";
        break;
    case TipoSimbolo::OPOR: //8
        cad = "Op. OR";
        break;
    case TipoSimbolo::OPAND: //9
        cad = "Op. AND";
        break;
    case TipoSimbolo::OPNOT: //10
        cad = "Op. Negacion";
        break;
    case TipoSimbolo::OPIGUALD:  //11
        cad = "opIgualdad";
        break;
    case TipoSimbolo::OPPTCM:  //12
        cad = "Punto y coma";
        break;
    case TipoSimbolo::OPCOMA:  //13
        cad = "Coma";
        break;
    case TipoSimbolo::OPPARANTI:  //14
        cad = "Parentesis";
        break;
    case TipoSimbolo::OPPARANTF:  //15
        cad = "Parentesis";
        break;
    case TipoSimbolo::OPLLAVEI: //16
        cad = "Llave";
        break;
    case TipoSimbolo::OPLLAVEF: //17
        cad = "Llave";
        break;
    case TipoSimbolo::OPASIG: //18
        cad = "Operador de asignacion";
        break;
    case TipoSimbolo::OPCONDI: //19
        cad = "Condicional";
        break;
    case TipoSimbolo::OPITERA: //20
        cad = "Iteracion";
        break;
    case TipoSimbolo::OPRETURN: //21
        cad = "Return";
        break;
    case TipoSimbolo::OPSINO: //22
        cad = "Else";
        break;
    case TipoSimbolo::PESOS: //23
        cad = "Fin de la Entrada";
        break;
    case TipoSimbolo::ERROR:
        cad = "Error";
        break;
    }

    return cad;
}

void Lexico::entrada(string fuente) { //lexico.entrada("+-+");
    ind = 0;                   // Posicion del caracter que esta analizando
    this->fuente = fuente;
}

int Lexico::sigSimbolo() {

    estado = 0;  //reinicia el automata al estado inicial
    continua = true;  //mientras no sea el final sera verdadero
    simbolo = ""; //almacena el simbolo que se imprimira 

    //Inicio del Automata
    while (continua) {
        c = sigCaracter();

        switch (estado) {
        case 0:
            if (c == '+' || c == '-') aceptacion(5);
            else
                if (c == '$') aceptacion(23);
                else
                    if (c == '*' || c == '/') aceptacion(6);
                    else
                        if (c == '<' || c == '>') sigEstado(5);
                        else
                            if (c == '|') sigEstado(6);
                            else
                                if (c == '&') sigEstado(7);
                                else
                                    if (c == '{' || c == '}') sigEstado(8), ind--;
                                    else
                                        if (c == '(' || c == ')') sigEstado(8), ind--;
                                        else
                                            if (c == '=') sigEstado(4);
                                            else
                                                if (c == ',') aceptacion(13);
                                                else
                                                    if (c == ';') aceptacion(12);
                                                    else
                                                        if (c == '!') sigEstado(9);
                                                        else
                                                            if (esDigito(c)) sigEstado(1);
                                                            else
                                                                if (esLetra(c)) sigEstado(3);
                                                                else
                                                                 if(esEspacio(c)) this->estado=0;

                                                                
            break;
        case 1:
            if (esDigito(c)) sigEstado(1);
            else
                if (c == '.') sigEstado(2);
                else
                    if (c != '.')
                    {
                        retroceso();
                        this->estado = 1;
                        //aceptacion(4);
                    }
            break;
        case 2:
            if (esDigito(c)) sigEstado(2);
            else
                if (!esDigito(c))
                {
                    retroceso();
                    this->estado = 2;
                    //aceptacion(5);
                }
            break;
        case 3:
            if (esDigito(c)) sigEstado(3);
            else
                if (esLetra(c)) sigEstado(3);
                else
                    if (simbolo == "int" || simbolo == "float" || simbolo == "void" || simbolo == "if" ||
                        simbolo == "while" || simbolo == "return" || simbolo == "else") this->estado = 10,ind--;
                    else
                    if(c=='[') sigEstado(3);
                    else
                         if(esDigito(c)||esEspacio(c)) sigEstado(3);
                         else
                              if (c==']'){
                                   this->estado = 3;
                                   continua = false;
                                   simbolo+=c;
                              }          
                          
                    else {
                        retroceso();
                        this->estado = 0;
                    }
            break;
        case 4:

            if (c == '=') aceptacion(11);
            else
                if (c != '=') {
                    retroceso();
                    this->estado = 18;
                }
            break;
        case 5:
            if (c == '=')  aceptacion(7);
            else {
                retroceso();
                this->estado = 7;
            }
            break;
        case 6:
            if (c == '|')  aceptacion(8);
            else {
                retroceso();
                this->estado = -1;
            }
            break;
        case 7:
            if (c == '&')  aceptacion(9);
            else {
                retroceso();
                this->estado = -1;
            }
            break;
        case 8:
            if (c == '(') {
                this->estado = 14;
                continua = false;
            }
            else
                if (c == ')') {
                    this->estado = 15;
                    continua = false;
                }
                else
                    if (c == '{')
                        this->estado = 16,
                        continua = false;
                    else
                        if (c == '}')
                            this->estado = 17;
            continua = false;
            break;
        case 9:
            if (c == '=') aceptacion(11);
            else
                if (c != '=') {
                    retroceso();
                    this->estado = 10;
                }
            break;

        case 10:
            if (simbolo == "int") {
                this->estado = 4;
                continua = false;
            }
            else
                if (simbolo == "float") {
                    this->estado = 4;
                    continua = false;
                }
                else
                    if (simbolo == "void") {
                        this->estado = 4;
                        continua = false;
                    }
                    else
                        if (simbolo == "if") {
                            this->estado = 19;
                            continua = false;
                        }
                        else
                            if (simbolo == "while") {
                                this->estado = 20;
                                continua = false;
                            }
                            else
                                if (simbolo == "return") {
                                    this->estado = 21;
                                    continua = false;
                                }
                                else
                                    if (simbolo == "else") {
                                        this->estado = 22;
                                        continua = false;
                                    }
            break;

            }
        }
        //Fin del Automata

        switch (estado) {
        case -1:
            tipo = TipoSimbolo::ERROR;
            break;
        case 0:
            tipo = TipoSimbolo::IDENTIFICADOR;
            break;
        case 1:
            tipo = TipoSimbolo::ENTERO;
            break;
        case 2:
            tipo = TipoSimbolo::REAL;
            break;
        case 3:
            tipo = TipoSimbolo::CADENA;
            break;
        case 4:
            tipo = TipoSimbolo::TIPO;
            break;
        case 5:
            tipo = TipoSimbolo::OPADIC;
            break;
        case 6:
            tipo = TipoSimbolo::OPMULT;
            break;
        case 7:
            tipo = TipoSimbolo::OPREL;
            break;
        case 8:
            tipo = TipoSimbolo::OPOR;
            break;
        case 9:
            tipo = TipoSimbolo::OPAND;
            break;
        case 10:
            tipo = TipoSimbolo::OPNOT;
            break;
        case 11:
            tipo = TipoSimbolo::OPIGUALD;
            break;
        case 12:
            tipo = TipoSimbolo::OPPTCM;
            break;
        case 13:
            tipo = TipoSimbolo::OPCOMA;
            break;
        case 14:
            tipo = TipoSimbolo::OPPARANTI;
            break;
        case 15:
            tipo = TipoSimbolo::OPPARANTF;
            break;
        case 16:
            tipo = TipoSimbolo::OPLLAVEI;
            break;
        case 17:
            tipo = TipoSimbolo::OPLLAVEF;
            break;
        case 18:
            tipo = TipoSimbolo::OPASIG;
            break;
        case 19:
            tipo = TipoSimbolo::OPCONDI;
            break;
        case 20:
            tipo = TipoSimbolo::OPITERA;
            break;
        case 21:
            tipo = TipoSimbolo::OPRETURN;
            break;
        case 22:
            tipo = TipoSimbolo::OPSINO;
            break;
        case 23:
            tipo = TipoSimbolo::PESOS;
            break;
        dafault:
            tipo = TipoSimbolo::ERROR;
        }

        return tipo;
    }


char Lexico::sigCaracter() {
    if (terminado()) return '$'; //si ya no hay caracteres regresa $ 

    return fuente[ind++];   //avanza al siguiente caracter de la cadena aumentando el indice
}

void Lexico::sigEstado(int estado) {
    this->estado = estado;
    simbolo += c;
}

void Lexico::aceptacion(int estado) {
    sigEstado(estado);
    continua = false;
}

bool Lexico::terminado() {//fin de cadena
    return ind >= fuente.length(); //tamaño de la entrada es igual la posicion en la 
                                   //que va.
}

bool Lexico::esLetra(char c) {   //Si el caracter es una letra es verdadero?
    return isalpha(c) || c == '_';
}


bool Lexico::esDigito(char c) { //si el caracter es un digito es verdadero?
    return isdigit(c);
}

bool Lexico::esEspacio(char c) { //Si el caracter es una espacio o salto de linea es verdadero?
    return c == ' ' || c == '\t';
}


void Lexico::retroceso() { //retroce el indice del caracter que se esta analizando
    if (c != '$') ind--;
    continua = false;
}