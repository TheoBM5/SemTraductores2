#include <cstdlib>
#include <iostream>
#include <string>

#include "lexico.h"
#include "pila.h"

using namespace std;
void ejercicio1(string& cadena);
void ejercicio2(string& cadena);

int main(int argc, char* argv[]) {

    string cadena;
    getline(cin, cadena);
    ejercicio1(cadena);
    return 0;
}


void ejercicio1(string& cadena)
{
    Pila pila;
    int fila, columna, accion;
    bool aceptacion = false;
    Lexico lexico;
    lexico.entrada(cadena);
    pila.push(TipoSimbolo::PESOS);
    pila.push(0);
    lexico.sigSimbolo();

    fila = pila.top();
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
        pila.push(lexico.tipo);
        pila.push(accion);
        lexico.sigSimbolo();

        fila = pila.top();
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


        fila = pila.top();
        columna = 3; //el no terminal que representa a E
        accion = tablaLR[fila][columna];

        pila.push(3); //el 3 es el entero que representa el no terminal E
        pila.push(accion);
        pila.muestra();
        cout << "entrada: " << lexico.simbolo << endl;
        cout << "accion: " << accion << endl << endl;

        fila = pila.top();
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


    Pila pila;
    int fila, columna, accion, cont = 0;
    bool aceptacion = false;
    Lexico lexico;
    lexico.entrada(cadena);
    pila.push(TipoSimbolo::PESOS);
    pila.push(0);
    lexico.sigSimbolo();
    fila = pila.top();
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
            pila.push(lexico.tipo);
            pila.push(accion);
            lexico.sigSimbolo();

            fila = pila.top();
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
                    fila = pila.top();
                    columna = 3; //el no terminal que representa a E
                    accion = tablaLR2[fila][columna];

                    pila.push(3); //el 3 es el entero que representa el no terminal E
                    pila.push(accion);
                    pila.muestra();
                    cout << "entrada: " << lexico.simbolo << endl;
                    cout << "accion: " << accion << endl << endl;

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
                        fila = pila.top();
                        columna = 3; //el no terminal que representa a E
                        accion = tablaLR2[fila][columna];

                        pila.push(3); //el 3 es el entero que representa el no terminal E
                        pila.push(accion);
                        pila.muestra();
                        cout << "entrada: " << lexico.simbolo << endl;
                        cout << "accion: " << accion << endl << endl;
                    }
                    break;
                }

            }
            else
                break;
    }


    pila.muestra();
    fila = pila.top();
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