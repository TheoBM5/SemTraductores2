#ifndef PILA_H
#define PILA_H


#include <list>
#include <iostream>
#include <string>


using namespace std;


class Nodo {
public:
    string simbolo;
    Nodo* pSig;

public:
    //static int sangria;
    void mostrar() {
        //for (int i = 0; i < sangria; i++)
        cout << " ";
    }
    virtual void muestra() {};
};

class ElementoPila {
protected:
    string elemento;
public:
    virtual void muestra() {}
    virtual string regresar() {
        return "0";

    }
};

class Terminal : public ElementoPila {
protected:

public:
    Terminal(string elemento) {
        this->elemento = elemento;
    }
    void muestra() {
        cout << elemento;
    }
    string regresar()
    {
        return elemento;
    }
};

class Noterminal : public ElementoPila {
public:
    Nodo* nodo;
public:
    Noterminal(Nodo* elemento)//Nodo *nodo)
    {
        this->nodo = elemento;
    }
    void muestra()
    {
        nodo->mostrar();
    }

    Nodo* getNodo()
    {
        return nodo;
    }

    string regresar()
    {
        return nodo->simbolo;
    }
};

class Estado : public ElementoPila {
public:
    Estado(string elemento)
    {
        this->elemento = elemento;
    }
    void muestra()
    {
        cout << elemento;
    }
    string regresar()
    {
        return elemento;
    }
};

class Pila {

private:
    list <ElementoPila*> lista;

public:
    void push(ElementoPila* x);
    ElementoPila* top();
    ElementoPila* pop();
    void muestra();
};

#endif // PILA_H_INCLUDED
