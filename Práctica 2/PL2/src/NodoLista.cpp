#include "NodoLista.h"

// CONTRUCTORES Y DESTRUCTORES //

NodoLista::NodoLista(Pedido p, NodoLista* ant, NodoLista* sig)
{
    pedido_nl = p;
    anterior_nl = ant;
    siguiente_nl = sig;
}

NodoLista::NodoLista(Cliente c, NodoLista* ant, NodoLista* sig)
{
    cliente_nl = c;
    anterior_nl = ant;
    siguiente_nl = sig;
}

NodoLista::~NodoLista()
{
    //dtor
}


