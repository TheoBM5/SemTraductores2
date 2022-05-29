#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "lexico.h"
#include "pila.h"
#include "Arbol.h"
using namespace std;

void Analizador(int arreglo2[95][46], string& cadena, string nombreRegla[], string idRegla[], string longRegla[]);
void reglas(int num, Pila& pila, string nombre, Nodo** head);

int main(int argc, char* argv[]) {
    int arreglo2[95][46];
    string nombreRegla[52]{}, idRegla[52]{}, longRegla[52]{};
    int x, y;
    string cadena = "int hola; int main(){ c=a+b; }";
    ifstream file("compilador.lr");
    string hola;
    if (!file.is_open())
    {
        cout << "Cannot open file.\n";
    }
    else {
        getline(file, hola); //cantidad de reglas
        cout << hola << endl;
        for (int i = 0; i < 52; i++) 
        {
            file >> idRegla[i];
            file >> longRegla[i];
            file >> nombreRegla[i];
        }
        file >> hola; //tamano de la matriz
        file >> hola; //tamano de la matriz

        cout << "Se abrio" << endl;
        for (x = 0; x < 95; x++) 
        {
            for (y = 0; y < 46; y++) 
            {
                file >> arreglo2[x][y];
            }
        }
        file.close();
    }
    Analizador(arreglo2, cadena, nombreRegla, idRegla, longRegla);
    return 0;
}

void Analizador(int arreglo2[95][46], string& cadena, string nombreRegla[], string idRegla[], string longRegla[])
{
    list<Nodo> lista;
    Pila pila;
    int fila, columna, accion = 1;
    int bandera = 0;
    ElementoPila* element;
    int contadorNoterminales = 0;
    Lexico lexico;
    lexico.entrada(cadena);
    pila.push(new Terminal("$"));
    pila.push(new Estado("0"));
    string nombre;
    Nodo* actual = NULL;
    while (accion != -1) //cambiar cuando tiene que parar
    {
        if (bandera == 0)
        {
            bandera = 0;
            lexico.sigSimbolo();
            
        }
        element = pila.top();
        fila = stoi(element->regresar());
        columna = lexico.tipo;
        accion = arreglo2[fila][columna];

        if (accion > 0)
        {
            bandera = 0;
            pila.push(new Terminal(lexico.simbolo));
            pila.push(new Estado(to_string(accion)));
        }
        else
            if (accion < 0 && accion != -1)
            {
                contadorNoterminales++;
                bandera = 1;
                int tamano = 0;
                
                accion = abs(accion);
                tamano = stoi(longRegla[accion - 2]);
                nombre = nombreRegla[accion - 2];
                reglas(accion, pila, nombre, &actual);
                element = pila.top();
                fila = stoi(element->regresar());
                columna = stoi(idRegla[accion - 2]);
                pila.push(new Noterminal(actual));
                accion = arreglo2[fila][columna];
                pila.push(new Estado(to_string(accion)));
            }
            else
                if (accion == 0)
                {
                    cout << "Error" << endl;
                    break;
                }
    }

    actual->muestra();

   
}

void reglas(int num, Pila& pila, string nombre, Nodo** head)
{
    
    Nodo* nodo_ = new Nodo();
    switch (num - 1)
    {
        case 1:
        {
            R1 *r1 = new R1(pila);
            r1->simbolo = nombre;
            r1->pSig = (*head);
            (*head) = r1;
            break;
        }

        case 3:
        {
            R3* r3 = new R3(pila);
            r3->simbolo = nombre;
            r3->pSig = (*head);
            (*head) = r3;
            break;
        }
        
        case 4: {
            R4* r4 = new R4(pila);
            r4->simbolo = nombre;
            r4->pSig = (*head);
            (*head) = r4;
            break;
           
        }
        
        case 5: {
            R5* r5 = new R5(pila);
            r5->simbolo = nombre;
            r5->pSig = (*head);
            (*head) = r5;
            break;
        }
        case 6:
        {
            R6* r6 = new R6(pila);
            r6->simbolo = nombre;
            r6->pSig = (*head);
            (*head) = r6;
            break;
        }

        case 8:
        {
            R8* r8 = new R8(pila);
            r8->simbolo = nombre;
            r8->pSig = (*head);
            (*head) = r8;
            break;
        }

        case 9:
        {
            R9* r9 = new R9(pila);
            r9->simbolo = nombre;
            r9->pSig = (*head);
            (*head) = r9;
            break;
        }

        case 11:
        {
            R11* r11 = new R11(pila);
            r11->simbolo = nombre;
            r11->pSig = (*head);
            (*head) = r11;
            break;
        }

        case 13:
        {
            R13* r13 = new R13(pila);
            r13->simbolo = nombre;
            r13->pSig = (*head);
            (*head) = r13;
            break;
        }

        case 14:
        {
            R14* r14 = new R14(pila);
            r14->simbolo = nombre;
            r14->pSig = (*head);
            (*head) = r14;
            break;
        }

        case 16: {
            R16* r16 = new R16(pila);
            r16->simbolo = nombre;
            r16->pSig = (*head);
            (*head) = r16;
            break;

        }

        case 17: {
            R17* r17 = new R17(pila);
            r17->simbolo = nombre;
            r17->pSig = (*head);
            (*head) = r17;
            break;
        }
        case 18:
        {
            R18* r18 = new R18(pila);
            r18->simbolo = nombre;
            r18->pSig = (*head);
            (*head) = r18;
            break;
        }

        case 20:
        {
            R20* r20 = new R20(pila);
            r20->simbolo = nombre;
            r20->pSig = (*head);
            (*head) = r20;
            break;
        }

        case 21:
        {
            R21* r21 = new R21(pila);
            r21->simbolo = nombre;
            r21->pSig = (*head);
            (*head) = r21;
            break;
        }

        case 22:
        {
            R22* r22 = new R22(pila);
            r22->simbolo = nombre;
            r22->pSig = (*head);
            (*head) = r22;
            break;
        }
        
        case 23: {
            R23* r23 = new R23(pila);
            r23->simbolo = nombre;
            r23->pSig = (*head);
            (*head) = r23;
            break;
        }
        case 24:
        {
            R24* r24 = new R24(pila);
            r24->simbolo = nombre;
            r24->pSig = (*head);
            (*head) = r24;
            break;
        }

        case 25:
        {
            R25* r25 = new R25(pila);
            r25->simbolo = nombre;
            r25->pSig = (*head);
            (*head) = r25;
            break;
        }

        case 27:
        {
            R27* r27 = new R27(pila);
            r27->simbolo = nombre;
            r27->pSig = (*head);
            (*head) = r27;
            break;
        }

        case 28:
        {
            R28* r28 = new R28(pila);
            r28->simbolo = nombre;
            r28->pSig = (*head);
            (*head) = r28;
            break;
        }
        
        case 30:
        {
            R30* r30 = new R30(pila);
            r30->simbolo = nombre;
            r30->pSig = (*head);
            (*head) = r30;
            break;
        }

        case 32:
        {
            R32* r32 = new R32(pila);
            r32->simbolo = nombre;
            r32->pSig = (*head);
            (*head) = r32;
            break;
        }

        case 34:
        {
            R34* r34 = new R34(pila);
            r34->simbolo = nombre;
            r34->pSig = (*head);
            (*head) = r34;
            break;
        }

        case 35:
        {
            R35* r35 = new R35(pila);
            r35->simbolo = nombre;
            r35->pSig = (*head);
            (*head) = r35;
            break;
        }

        case 36:
        {
            R36* r36 = new R36(pila);
            r36->simbolo = nombre;
            r36->pSig = (*head);
            (*head) = r36;
            break;
        }

        case 37:
        {
            R37* r37 = new R37(pila);
            r37->simbolo = nombre;
            r37->pSig = (*head);
            (*head) = r37;
            break;
        }

        case 38:
        {
            R38* r38 = new R38(pila);
            r38->simbolo = nombre;
            r38->pSig = (*head);
            (*head) = r38;
            break;
        }

        case 39:
        {
            R39* r39 = new R39(pila);
            r39->simbolo = nombre;
            r39->pSig = (*head);
            (*head) = r39;
            break;
        }
        
        case 40:
        {
            R40* r40 = new R40(pila);
            r40->simbolo = nombre;
            r40->pSig = (*head);
            (*head) = r40;
            break;
        }

        case 41:
        {
            R41* r41 = new R41(pila);
            r41->simbolo = nombre;
            r41->pSig = (*head);
            (*head) = r41;
            break;
        }

        case 42:
        {
            R42* r42 = new R42(pila);
            r42->simbolo = nombre;
            r42->pSig = (*head);
            (*head) = r42;
            break;
        }

        case 43:
        {
            R43* r43 = new R43(pila);
            r43->simbolo = nombre;
            r43->pSig = (*head);
            (*head) = r43;
            break;
        }

        case 44:
        {
            R44* r44 = new R44(pila);
            r44->simbolo = nombre;
            r44->pSig = (*head);
            (*head) = r44;
            break;
        }

        case 45:
        {
            R45* r45 = new R45(pila);
            r45->simbolo = nombre;
            r45->pSig = (*head);
            (*head) = r45;
            break;
        }

        case 46:
        {
            R46* r46 = new R46(pila);
            r46->simbolo = nombre;
            r46->pSig = (*head);
            (*head) = r46;
            break;
        }

        case 47:
        {
            R47* r47 = new R47(pila);
            r47->simbolo = nombre;
            r47->pSig = (*head);
            (*head) = r47;
            break;
        }

        case 48:
        {
            R48* r48 = new R48(pila);
            r48->simbolo = nombre;
            r48->pSig = (*head);
            (*head) = r48;
            break;
        }

        case 49:
        {
            R49* r49 = new R49(pila);
            r49->simbolo = nombre;
            r49->pSig = (*head);
            (*head) = r49;
            break;
        }

        case 50:
        {
            R50* r50 = new R50(pila);
            r50->simbolo = nombre;
            r50->pSig = (*head);
            (*head) = r50;
            break;
        }

        case 51:
        {
            R51* r51 = new R51(pila);
            r51->simbolo = nombre;
            r51->pSig = (*head);
            (*head) = r51;
            break;
        }

        case 52:
        {
            R52* r52 = new R52(pila);
            r52->simbolo = nombre;
            r52->pSig = (*head);
            (*head) = r52;
            break;
        }



        default:
        {
            RR* rr = new RR();
            rr->simbolo = nombre;
            rr->pSig = (*head);
            (*head) = rr;
            break;
        }
    }
    return;

}