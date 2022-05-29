#include "pila.h"
#include "lexico.h"
#include <sstream>


void Pila::push(ElementoPila* x) {
    lista.push_front(x);
}

ElementoPila* Pila::pop() {

    ElementoPila* x = *lista.begin();
    lista.erase(lista.begin());

    return x;
}

ElementoPila* Pila::top() {
    return *lista.begin();
}

void Pila::muestra() {

    list <ElementoPila*>::reverse_iterator  it;
    ElementoPila* x;
    cout << "Pila: ";

    for (it = lista.rbegin(); it != lista.rend(); it++) 
    {
        x = *it;
        x->muestra();
        //cout << (*it) << " ";
    }

    cout << endl;
}