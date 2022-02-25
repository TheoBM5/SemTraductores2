#pragma once
#ifndef _PILA
#define _PILA

#include <list>
#include <iostream>
#include <string>

using namespace std;



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
        cout<<elemento;
    }
    string regresar()
    {
        return elemento;
    }
};

class Noterminal : public ElementoPila {
    
public:
    Noterminal(string elemento)
    {
        this->elemento = elemento;
    }
    void muestra() {
        cout <<elemento;
    }
    string regresar()
    {
        return elemento;
    }
};

class Estado : public ElementoPila {
public:
    Estado(string elemento)
    {
        this->elemento = elemento;
    }
    void muestra() {
        cout <<elemento;
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


#endif