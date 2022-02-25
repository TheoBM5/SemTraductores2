#include <cstdlib>
#include <iostream>
#include <string>

#include "lexico.h"
#include "pila.h"

using namespace std;
void ejercicio1(string& cadena);
void ejercicio2(string& cadena);
void ejemplo();

int main(int argc, char* argv[]) {

    string cadena;
    getline(cin, cadena);
    ejercicio2(cadena);
    //ejercicio1(cadena);
    
    return 0;
}



void ejercicio1(string& cadena)
{
    Pila pila;
    ElementoPila* element;
    int fila, columna, accion;
    bool aceptacion = false;
    Lexico lexico;
    lexico.entrada(cadena);
    pila.push(new Terminal("$"));
    //pila.push(TipoSimbolo::PESOS);
    pila.push(new Estado("0"));
    lexico.sigSimbolo();
    element = pila.top();

    fila = stoi(element->regresar());
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;
    if (accion == 0)
    {
        cout << "Error";
        return;
    }
    
    for (int i = 0; i <= 2; i++) {
        pila.push(new Terminal(lexico.simbolo));
        pila.push(new Estado(to_string(accion)));
        lexico.sigSimbolo();

        element = pila.top();
        fila = stoi(element->regresar());
        columna = lexico.tipo;
        accion = tablaLR[fila][columna];
        if (accion == 0)
        {
            break;
        }

        pila.muestra();
        cout << "entrada: " << lexico.simbolo << endl;
        cout << "accion: " << accion << endl;
    }

    
    if (accion != 0)
    {
        for (int a = 0; a <= 5; a++) {
            pila.pop();
        }
        pila.muestra();

        element = pila.top();
        fila = stoi(element->regresar());
        columna = 3; //el no terminal que representa a E
        accion = tablaLR[fila][columna];

        pila.push(new Noterminal("E")); //el 3 es el entero que representa el no terminal E
        pila.push(new Estado(to_string(accion)));
        pila.muestra();
        cout << "entrada: " << lexico.simbolo << endl;
        cout << "accion: " << accion << endl << endl;

        element = pila.top();
        fila = stoi(element->regresar());
        columna = lexico.tipo;
        accion = tablaLR[fila][columna];


    }
    pila.muestra();
    
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;
    aceptacion = accion == -1;
    if (aceptacion)
    {
        cout << "aceptacion" << endl;
    }
    else {
        cout << "Error" << endl;
    }
}


void ejercicio2(string& cadena) {

    ElementoPila* element;
    Pila pila;
    int fila, columna, accion, cont = 0;
    bool aceptacion = false;
    Lexico lexico;
    lexico.entrada(cadena);
    pila.push(new Terminal("$"));
    pila.push(new Estado("0"));
    lexico.sigSimbolo();
    element = pila.top();
    fila = stoi(element->regresar());
    columna = lexico.tipo;
    accion = tablaLR2[fila][columna]; //cambie numero de tabla
    cout << cont;
    pila.muestra();

    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;
    cont++;
    while (accion != -1) {
        if (accion > 0)
        {
            pila.push(new Terminal(lexico.simbolo));
            pila.push(new Estado(to_string(accion)));
            lexico.sigSimbolo();

            element = pila.top();
            fila = stoi(element->regresar());
            columna = lexico.tipo;
            accion = tablaLR2[fila][columna]; //cambie numero de tabla

            cout << cont;
            pila.muestra();
            cout << "entrada: " << lexico.simbolo << endl;
            cout << "accion: " << accion << endl;
            cont++;
        }
        else
            if (accion < 0)
            {
                if (accion == -3)
                {
                    pila.pop();
                    pila.pop();
                    element = pila.top();
                    fila = stoi(element->regresar());
                    columna = 3; //el no terminal que representa a E
                    accion = tablaLR2[fila][columna];

                    pila.push(new Noterminal("E")); //el 3 es el entero que representa el no terminal E
                    pila.push(new Estado(to_string(accion)));
                    pila.muestra();
                    cout << "entrada: " << lexico.simbolo << endl;
                    cout << "accion: " << accion << endl;

                }

                if (accion == 4)
                {
                    while (accion == 4) {
                        pila.pop();
                        pila.pop();
                        pila.pop();
                        pila.pop();
                        pila.pop();
                        pila.pop();
                        element = pila.top();
                        fila = stoi(element->regresar());
                        columna = 3; //el no terminal que representa a E
                        accion = tablaLR2[fila][columna];

                        pila.push(new Noterminal("E")); //el 3 es el entero que representa el no terminal E
                        pila.push(new Estado(to_string(accion)));
                        pila.muestra();
                        cout << "entrada: " << lexico.simbolo << endl;
                        cout << "accion: " << accion << endl;
                    }
                    break;
                }

            }
            else
                break;
    }


    pila.muestra();
    element = pila.top();
    fila = stoi(element->regresar());
    columna = lexico.tipo;
    accion = tablaLR2[fila][columna];
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;
    aceptacion = accion == -1;
    if (aceptacion)
    {
        cout << "aceptacion" << endl;
    }
    else {
        cout << "Error" << endl;
    }
}