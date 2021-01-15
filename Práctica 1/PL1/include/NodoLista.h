#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Pedido.h"

class NodoLista
{
    friend class ListaPedidos;

    private:
        Pedido pedido_nl;
        NodoLista* anterior_nl;
        NodoLista* siguiente_nl;
    public:
        NodoLista(Pedido p, NodoLista* ant, NodoLista* sig);
        ~NodoLista();
};

#endif // NODOLISTA_H
