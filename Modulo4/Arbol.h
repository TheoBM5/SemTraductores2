#ifndef ARBOL_H
#define ARBOL_H


#include <string>
#include <iostream>
#include "pila.h"

using namespace std;



string tabs = "";
int i = 0;
int labelCounter = 0;

void aumenta() 
{
	i++;
	tabs = tabs + "   ";
}

void reduce() 
{
	i--;
	tabs = "";
	for (int x = 0; x < i; x++) 
	{
		tabs = tabs + "   ";
	}
}

class Tipo : Nodo
{
public:
	Tipo(string simbolo) {
		this->simbolo = simbolo;
		this->pSig = NULL;
	}

	void muestra() {
		mostrar();
		cout << "<Tipo> " << simbolo << endl;
	}
};

class Expresion : public Nodo {
public:
	Expresion* izq, * der;
	string guardaArbol() {
		return "";
	}
};

class Identificador : public Expresion {
public:
	Identificador(string simbolo, Nodo* sig = NULL) {
		this->simbolo = simbolo;
		this->pSig = sig;
	}

	void muestra() {
		mostrar();
		cout << "<Identificador> " << simbolo << endl;
		if (pSig != NULL) pSig->muestra();
	}
};

class RR : public Nodo
{
public:
	
	void muestra()
	{
		cout <<"<"<<this->simbolo<<">"<<endl;
	}
	
};

class R1 : public Nodo
{
protected:
	Nodo* Definiciones;
public:
	R1(Pila& pila)
	{
		pila.pop();
		this->Definiciones = ((Noterminal*)pila.pop())->getNodo();
	}
	void muestra()
	{
		cout << "<programa>" << endl;
		if (Definiciones != NULL) Definiciones->muestra();
		cout << "</Programa>\n"<<endl;
	}
};

class R3 : public Nodo
{
protected:
	Nodo* Definicion;
	Nodo* Definiciones;
public:
	R3(Pila& pila)
	{
		pila.pop();
		this->Definicion = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->Definiciones = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra()
	{
		cout <<tabs<< "<Definiciones>" << endl;
		aumenta();
		if (Definicion != NULL)Definicion->muestra();
		if (Definiciones != NULL)Definiciones->muestra();
		reduce();
		cout <<tabs<< "</Definiciones>" << endl;
	}

};

class R4 : public Nodo
{
protected:
	Nodo* DefVar;
public:
	R4(Pila& pila)
	{
		pila.pop();
		DefVar = ((Noterminal*)pila.pop())->nodo;
		
	}

	void muestra()
	{
		cout << tabs << "<DefVar>" << endl;
		aumenta();
		if(DefVar!=NULL) DefVar->muestra();
		reduce();
		cout << tabs << "</Definicion>" << endl;
	}
};

class R5 : public Nodo
{
protected:
	Nodo* DefFunc;
public:
	R5(Pila& pila)
	{
		pila.pop();
		DefFunc = ((Noterminal*)pila.pop())->nodo;;
	}

	void muestra()
	{
		cout << tabs << "<Definicion>"<<endl;
		aumenta();
		if (DefFunc != NULL) DefFunc->muestra();
		reduce();
		cout << tabs << "</Definicion>" << endl;
	}
};

class R6 : public Nodo
{
protected:
	string tipo;
	string id;
	Nodo* ListaVar;
public:
	R6(Pila& pila)
	{
		pila.pop();
		pila.pop();
		pila.pop();
		this->ListaVar = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->id = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->tipo = ((Terminal*)pila.pop())->regresar();
	}

	void muestra()
	{
		cout << tabs <<"<DefVar>" << endl;
		aumenta();
		cout << "<" << tipo << ">"<<endl;
		cout << "<"<<id<<">"<<endl;
		if(ListaVar!=NULL)ListaVar->muestra();
		cout << tabs << endl;
		reduce();
		cout <<tabs<< "</DefVar>" << endl;
	}
};


class R8 : public Nodo
{
protected:
	string id;
	Nodo* ListaVar;
public:
	R8(Pila& pila)
	{
		pila.pop();
		this->ListaVar= ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->id= ((Terminal*)pila.pop())->regresar();
		pila.pop();
		pila.pop();
	}

	void muestra()
	{
		cout << tabs << "<ListaVar>" << endl;
		aumenta();
		cout << tabs << "<" << id << ">" << endl;
		if (ListaVar != NULL) ListaVar->muestra();
		reduce();
		cout << tabs << "</ListaVar>" << endl;
	}
};

class R9 : public Nodo
{
protected:
	string id, tipo, pa, pc;
	Nodo *Parametros;
	Nodo *BloqFunc;
public:
	R9(Pila& pila)
	{
		pila.pop();
		this->BloqFunc= ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->pc= ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->Parametros = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->pa = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->id = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->tipo = ((Terminal*)pila.pop())->regresar();
	}
	void muestra()
	{
		cout << tabs << "<DefFunc>"<<endl;
		aumenta();
		cout << tabs << "< " << tipo << " >";
		cout << " < " << id << " >";
		cout << " < " << pa << " >";
		if (Parametros != NULL) Parametros->muestra();
		cout << " < " << pc << " >"<<endl;
		if (BloqFunc != NULL) BloqFunc->muestra();
		reduce();
		cout << tabs << "</DefFunc>"<<endl;
	}
};

class R11 : public Nodo
{
protected:
	string tipo;
	string id;
	Nodo *ListaParam;
public:
	R11(Pila& pila)
	{
		pila.pop();
		this->ListaParam = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->id = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->tipo = ((Terminal*)pila.pop())->regresar();
	}

	void muestra() 
	{
		cout << tabs << "<Parametros>" << endl;
		aumenta();
		cout << tabs << "< " << tipo << " >";
		cout << " < " << id << " >";
		if (ListaParam != NULL) ListaParam->muestra();
		reduce();
		cout << tabs << "</Parametros>" << endl;
	}
};

class R13 : public Nodo
{
protected:
	string tipo;
	string id;
	Nodo *ListaParam;
public:
	R13(Pila& pila)
	{
		pila.pop();
		this->ListaParam = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->id = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->tipo = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		pila.pop();
	}
	void muestra() 
	{
		cout << tabs << "<ListaParam>"<<endl;
		aumenta();
		cout << tabs << "< " << tipo << " >";
		cout << " < " << id << " >";
		if (ListaParam != NULL) ListaParam->muestra();
		reduce();
		cout << tabs << "</ListaParam>\n";
	}
};

class R14 : public Nodo
{
protected:
	string la, lc;
	Nodo* DefLocales;
public:
	R14(Pila& pila)
	{
		pila.pop();
		this->lc= ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->DefLocales= ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->la= ((Terminal*)pila.pop())->regresar();
	}
	void muestra() {
		cout << tabs << "<BloqFunc>"<<endl;
		aumenta();
		cout << tabs << "< " << la << " >" << endl;
		if (DefLocales != NULL) DefLocales->muestra();
		cout << tabs << "< " << lc << " >" << endl;
		reduce();
		cout << tabs << "</BloqFunc>"<<endl;
	}
};

class R16 : public Nodo
{
protected:
	Nodo* DefLocal;
	Nodo* DefLocales;
public:
	R16(Pila& pila)
	{
		pila.pop();
		this->DefLocales= ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->DefLocal= ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() 
	{
		cout << tabs << "<DefLocales>"<<endl;
		aumenta();
		if (DefLocal != NULL) DefLocal->muestra();
		if (DefLocales != NULL) DefLocales->muestra();
		reduce();
		cout << tabs << "</DefLocales>"<<endl;
	}
};

class R17 : public Nodo
{
protected:
	Nodo* DefVar;
public:
	R17(Pila& pila)
	{
		pila.pop();
		this->DefVar= ((Noterminal*)pila.pop())->nodo;
	}
	void muestra() {
		cout << tabs << "<DefLocal>"<<endl;
		aumenta();
		if (DefVar != NULL) DefVar->muestra();
		reduce();
		cout << tabs << "</DefLocal>"<<endl;
	}
};

class R18 : public Nodo
{
protected:
	Nodo *Sentencia;
public:
	R18(Pila& pila)
	{
		pila.pop();
		this->Sentencia= ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() {
		cout << tabs << "<DefLocal>"<<endl;
		aumenta();
		if (Sentencia != NULL) Sentencia->muestra();
		reduce();
		cout << tabs << "</DefLocal>"<<endl;
	}
};

class R20 : public Nodo
{
protected:
	Nodo* Sentencia;
	Nodo* Sentencias;
public:
	R20(Pila& pila)
	{
		pila.pop();
		this->Sentencias = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->Sentencia = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() {
		cout << tabs << "<Sentencias>"<<endl;
		aumenta();
		if (Sentencias != NULL) Sentencias->muestra();
		if (Sentencia != NULL) Sentencia->muestra();
		reduce();
		cout << tabs << "</Sentencias>"<<endl;
	}

};

class R21 : public Nodo
{
protected:
	string id, asignacion;
	Nodo* Expresion;

public:
	R21(Pila& pila)
	{
		pila.pop();
		pila.pop();
		pila.pop();
		this->Expresion=((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->asignacion=((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->id= ((Terminal*)pila.pop())->regresar();
	}
	void muestra() 
	{
		cout << tabs << "<Sentencia>"<<endl;
		aumenta();
		cout << tabs << "< " << id << " >";
		cout << " < " << asignacion << " >"<<endl;
		if (Expresion != NULL) Expresion->muestra();
		reduce();
		cout << tabs << "</Sentencia>"<<endl;
	}
};

class R22 : public Nodo
{
protected:
	string If, pa, pc;
	Nodo* Expresion;
	Nodo* SentenciaBloque;
	Nodo* Otro;
public:
	R22(Pila& pila)
	{
		pila.pop();
		this->Otro= ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->SentenciaBloque= ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->pc= ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->Expresion= ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->pa= ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->If= ((Terminal*)pila.pop())->regresar();
	}
	void muestra() {
		cout << tabs << "<Sentencia>"<<endl;
		aumenta();
		cout << tabs << "< " << If << " >";
		cout << " < " << pa << " >";
		if (Expresion != NULL) Expresion->muestra();
		cout << " < " << pc << " >";
		if (SentenciaBloque != NULL) SentenciaBloque->muestra();
		if (Otro != NULL) Otro->muestra();
		reduce();
		cout << tabs << "</Sentencia>"<<endl;
	}
};

class R23 : public Nodo
{
protected:
	
	Nodo* Expresion;
	Nodo* Bloque;
	string pa, pc, While;
public:
	R23(Pila& pila)
	{
		pila.pop();
		this->Bloque = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->pc = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->Expresion = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->pa = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->While = ((Terminal*)pila.pop())->regresar();
	}

	void muestra() 
	{
		cout << tabs << "<Sentencia>"<<endl;
		aumenta();
		cout << tabs << "< " << While << " >";
		cout << " < " << pa << " >";
		if (Expresion != NULL) Expresion->muestra();
		cout << " < " << pc << " >";
		if (Bloque != NULL) Bloque->muestra();
		reduce();
		cout << tabs << "</Sentencia>"<<endl;
	}
};

class R24 : public Nodo
{
protected:
	Nodo *ValorRegresa;
	string retur;
public:
	R24(Pila& pila)
	{
		pila.pop();
		pila.pop();
		pila.pop();
		this->ValorRegresa= ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->retur= ((Terminal*)pila.pop())->regresar();
	}

	void muestra() 
	{
		cout << tabs << "<Sentencia>"<<endl;
		aumenta();
		cout << tabs << "< " << retur << " > ";
		if (ValorRegresa != NULL) ValorRegresa->muestra();
		reduce();
		cout << tabs << "</Sentencia>"<<endl;
	}
};

class R25 : public Nodo
{
protected:
	Nodo* LlamadaFunc;
public:
	R25(Pila& pila)
	{
		pila.pop();
		pila.pop();
		pila.pop();
		this->LlamadaFunc = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() 
	{
		cout << tabs << "<Sentencia>"<<endl;
		aumenta();
		if (LlamadaFunc != NULL) LlamadaFunc->muestra();
		reduce();
		cout << tabs << "</Sentencia>"<<endl;
	}
};

class R27 : public Nodo
{
protected:
	Nodo *SentenciaBloque;
	string Else;
public:
	R27(Pila& pila)
	{
		pila.pop();
		this->SentenciaBloque = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->Else = ((Terminal*)pila.pop())->regresar();
	}

	void muestra() 
	{
		cout << tabs << "<Otro>"<<endl;
		aumenta();
		cout << tabs << "< " << Else << " >";
		if (SentenciaBloque != NULL) SentenciaBloque->muestra();
		reduce();
		cout << tabs << "</Otro>"<<endl;
	}
};

class R28 : public Nodo
{
protected:
	Nodo *Sentencias;
	string pa, pc;
public:
	R28(Pila& pila)
	{
		pila.pop();
		this->pc = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->Sentencias = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->pa = ((Terminal*)pila.pop())->regresar();
	}

	void muestra() {
		cout << tabs << "<Bloque>"<<endl;
		aumenta();
		cout << tabs << "< " << pa << " >" << endl;
		if (Sentencias != NULL) Sentencias->muestra();
		cout << "< " << pc << " >" << endl;
		reduce();
		cout << tabs << "</Bloque>"<<endl;
	}
};

class R30 : public Nodo
{
protected:
	Nodo* Expresion;
public:
	R30(Pila& pila)
	{
		pila.pop();
		this->Expresion = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() 
	{
		cout << tabs << "<ValorRegresa>"<<endl;
		aumenta();
		if (Expresion != NULL) Expresion->muestra();
		reduce();
		cout << tabs << "</ValorRegresa>"<<endl;
	}
};

class R32 : public Nodo
{
protected:
	Nodo* Expresion;
	Nodo* ListaArgumentos;
public:
	R32(Pila& pila)
	{
		pila.pop();
		this->Expresion = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->ListaArgumentos = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() 
	{
		cout << tabs << "<Argumentos>"<<endl;
		aumenta();
		if (Expresion != NULL) Expresion->muestra();
		if (ListaArgumentos != NULL) ListaArgumentos->muestra();
		reduce();
		cout << tabs << "</Argumentos>"<<endl;
	}
};

class R34 : public Nodo // <ListaArgumentos>
{
protected:
	//,
	Nodo* Expresion;
	Nodo* ListaArgumentos;
public:
	R34(Pila& pila)
	{
		pila.pop();
		this->ListaArgumentos = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->Expresion = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		pila.pop();
	}

	void muestra() {
		cout << tabs << "<ListaArgumentos>"<<endl;
		aumenta();
		if (Expresion != NULL) Expresion->muestra();
		if (ListaArgumentos != NULL) ListaArgumentos->muestra();
		reduce();
		cout << tabs << "</ListaArgumentos>"<<endl;
	}
};

class R35 : public Nodo // <Termino>
{
protected:
	Nodo* LlamadaFunc;
public:
	R35(Pila& pila)
	{
		pila.pop();
		this->LlamadaFunc = ((Noterminal*)pila.pop())->nodo;
	}
	void muestra() {
		cout << tabs << "<Termino>"<<endl;
		aumenta();
		if (LlamadaFunc != NULL) LlamadaFunc->muestra();
		reduce();
		cout << tabs << "</Termino>"<<endl;
	}
};

class R36 : public Nodo //Identificador <Termino>
{
protected:
	string id;
public:
	R36(Pila& pila)
	{
		pila.pop();
		this->id = ((Terminal*)pila.pop())->regresar();
	}

	void muestra() {
		cout << tabs << "<Termino>"<<endl;
		aumenta();
		cout << tabs << "< " << this->id << " >" << endl;
		reduce();
		cout << tabs << "</Termino>"<<endl;
	}
};

class R37 : public Nodo //entero <Termino>
{
protected:
	string entero;
public:
	R37(Pila& pila)
	{
		pila.pop();
		this->entero = ((Terminal*)pila.pop())->regresar();
	}

	void muestra() 
	{
		cout << tabs << "<Termino>"<<endl;
		aumenta();
		cout << tabs << "< " << entero << " >"<<endl;
		reduce();
		cout << tabs << "</Termino>";
	}
};

class R38 : public Nodo //Real <Termino>
{
protected:
	string real;
public:
	R38(Pila& pila)
	{
		pila.pop();
		this->real= ((Terminal*)pila.pop())->regresar();
	}

	void muestra() 
	{
		cout << tabs << "<Termino>"<<endl;
		aumenta();
		cout << tabs << "< " << real << " >"<<endl;
		reduce();
		cout << tabs << "</Termino>"<<endl;
	}

};

class R39 : public Nodo //Cadena <Termino>
{
protected:
	string cadena;
public:
	R39(Pila& pila)
	{
		pila.pop();
		cadena = ((Terminal*)pila.pop())->regresar();
	}

	void muestra() 
	{
		cout << tabs << "<Termino>"<<endl;
		aumenta();
		cout << tabs << "< " << cadena << " >"<<endl;
		reduce();
		cout << tabs << "</Termino>"<<endl;
	}
};

class R40 : public Nodo //<LlamadaFunc>
{
protected:
	string id, pa, pc;
	Nodo *Argumentos;
public:
	R40(Pila& pila)
	{
		this->pc = ((Terminal*)pila.pop())->regresar();
		this->Argumentos = ((Noterminal*)pila.pop())->nodo;
		this->pa = ((Terminal*)pila.pop())->regresar();
		this->id = ((Terminal*)pila.pop())->regresar();
	}

	void muestra() {
		cout << tabs << "<LlamadaFunc>"<<endl;
		aumenta();
		cout << tabs << "< " << id << " >";
		cout << " < " << pa << " > ";
		if (Argumentos != NULL) Argumentos->muestra();
		cout << "< " << pc << " >"<<endl;
		reduce();
		cout << tabs << "</LlamadaFunc>"<<endl;
	}
};

class R41 : public Nodo //<SentenciaBloque>
{
protected:
	Nodo* Sentencia;
public:
	R41(Pila& pila)
	{
		pila.pop();
		this->Sentencia = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() {
		cout << tabs << "<SentenciaBloque>"<<endl;
		aumenta();
		if (Sentencia != NULL) Sentencia->muestra();
		reduce();
		cout << tabs << "</SentenciaBLoque>"<<endl;
	}
};

class R42 : public Nodo //<SentenciaBloque>
{
protected:
	Nodo* Bloque;
public:
	R42(Pila& pila)
	{
		pila.pop();
		this->Bloque = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() 
	{
		cout << tabs << "<SentenicaBloque>"<<endl;
		aumenta();
		if (Bloque != NULL) Bloque->muestra();
		reduce();
		cout << tabs << "/<SentenciaBloque>"<<endl;
	}
};

class R43 : public Nodo //<Expresion>
{
protected:
	Nodo* expresion;
	string pa, pc;
public:
	R43(Pila& pila)
	{
		pila.pop();
		this->pc = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->expresion = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->pa = ((Terminal*)pila.pop())->regresar();
	}

	void muestra() {
		cout << tabs << "<Expresion>"<<endl;
		aumenta();
		cout << tabs << "< " << pa << " >" << endl;
		if (expresion != NULL) expresion->muestra();
		cout << "< " << pc << " >" << endl;
		reduce();
		cout << tabs << "</Expresion>"<<endl;
	}
};

class R44 : public Nodo //<Expresion>
{
protected:
	string opSuma;
	Nodo *expresion;
public:
	R44(Pila& pila)
	{
		pila.pop();
		expresion = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		opSuma = ((Terminal*)pila.pop())->regresar();
	}

	void muestra() 
	{
		cout << tabs << "<Expresion>"<<endl;
		aumenta();
		cout << tabs << " < " << opSuma << " > \n";
		if (expresion != NULL) expresion->muestra();
		reduce();
		cout << tabs << "</Expresion>"<<endl;
	}
};

class R45 : public Nodo //<Expresion>
{
protected:
	string opNot;
	Nodo *expresion;
public:
	R45(Pila& pila)
	{
		pila.pop();
		this->expresion = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->opNot = ((Terminal*)pila.pop())->regresar();
	}

	void muestra() 
	{
		cout << tabs << "<Expresion>"<<endl;
		aumenta();
		cout << tabs << "< " << opNot << " > "<<endl;
		if (expresion != NULL) expresion->muestra();
		reduce();
		cout << tabs << "</Expresion>"<<endl;
	}
};

class R46 : public Nodo //<Expresion>
{
protected:
	Nodo* expresion1;
	Nodo* expresion2;
	string opMult;

public:
	R46(Pila& pila)
	{
		pila.pop();
		this->expresion2 = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->opMult = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->expresion1 = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() {
		cout << tabs << "<Expresion>"<<endl;
		aumenta();
		if (expresion1 != NULL) expresion1->muestra();
		cout << tabs << "< " << opMult << " > "<<endl;
		if (expresion2 != NULL) expresion2->muestra();
		reduce();
		cout << tabs << "</Expresion>"<<endl;
	}
};

class R47 :public Nodo //<Expresion>
{
protected:
	Nodo* expresion1;
	Nodo* expresion2;
	string opSuma;
public:
	R47(Pila& pila)
	{
		pila.pop();
		this->expresion2 = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->opSuma = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->expresion1 = ((Noterminal*)pila.pop())->nodo;
	}
	void muestra() {
		cout << tabs << "<Expresion>" << endl;
		aumenta();
		if (expresion1 != NULL) expresion1->muestra();
		cout << tabs << "< " << opSuma << " > "<<endl;
		if (expresion2 != NULL) expresion2->muestra();
		reduce();
		cout << tabs << "</Expresion>" << endl;
	}
};

class R48 : public Nodo //<Expresion>
{
protected:
	Nodo* expresion1;
	Nodo* expresion2;
	string opRelac;
public:
	R48(Pila& pila)
	{
		pila.pop();
		this->expresion2 = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->opRelac = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->expresion1 = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() {
		cout << tabs << "<Expresion>" << endl;
		aumenta();
		if (expresion1 != NULL) expresion1->muestra();
		cout << tabs << "< " << opRelac << " > " << endl;
		if (expresion2 != NULL) expresion2->muestra();
		reduce();
		cout << tabs << "</Expresion>" << endl;
	}
};

class R49 : public Nodo //<Expresion>
{
protected:
	Nodo* expresion1;
	Nodo* expresion2;
	string opIgual;
public:
	R49(Pila& pila)
	{
		pila.pop();
		this->expresion2 = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->opIgual = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->expresion1 = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() {
		cout << tabs << "<Expresion>" << endl;
		aumenta();
		if (expresion1 != NULL) expresion1->muestra();
		cout << tabs << "< " << opIgual << " > " << endl;
		if (expresion2 != NULL) expresion2->muestra();
		reduce();
		cout << tabs << "</Expresion>" << endl;
	}
};

class R50 : public Nodo //<Expresion>
{
protected:
	Nodo* expresion1;
	Nodo* expresion2;
	string opAnd;
public:
	R50(Pila& pila)
	{
		pila.pop();
		this->expresion2 = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->opAnd = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->expresion1 = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() {
		cout << tabs << "<Expresion>" << endl;
		aumenta();
		if (expresion1 != NULL) expresion1->muestra();
		cout << tabs << "< " << opAnd << " > " << endl;
		if (expresion2 != NULL) expresion2->muestra();
		reduce();
		cout << tabs << "</Expresion>" << endl;
	}
};

class R51 : public Nodo //<Expresion>
{
protected:
	Nodo* expresion1;
	Nodo* expresion2;
	string opOr;
public:
	R51(Pila& pila)
	{
		pila.pop();
		this->expresion2 = ((Noterminal*)pila.pop())->nodo;
		pila.pop();
		this->opOr = ((Terminal*)pila.pop())->regresar();
		pila.pop();
		this->expresion1 = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra() 
	{
		cout << tabs << "<Expresion>" << endl;
		aumenta();
		if (expresion1 != NULL) expresion1->muestra();
		cout << tabs << "< " << opOr << " > " << endl;
		if (expresion2 != NULL) expresion2->muestra();
		reduce();
		cout << tabs << "</Expresion>" << endl;
	}
};

class R52 : public Nodo //<Expresion>
{
protected:
	Nodo *Termino;
public:
	R52(Pila &pila)
	{
		pila.pop();
		Termino = ((Noterminal*)pila.pop())->nodo;
	}

	void muestra()
	{
		cout << tabs << "<Expresion>"<<endl;
		aumenta();
		if (Termino != NULL) Termino->muestra();
		reduce();
		cout << tabs << "</Expresion>"<<endl;
	}
};

#endif  // ARBOL_H_INCLUDED