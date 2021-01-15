#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Pedido.h"
#include "PedidoPeque.h"
#include "Cliente.h"

class NodoLista
{
    friend class ListaPedidos;

    private:
        Pedido pedido_nl;
        Cliente cliente_nl;
        NodoLista* anterior_nl;
        NodoLista* siguiente_nl;

    public:
        NodoLista(Pedido p, NodoLista* ant, NodoLista* sig);
        NodoLista(Cliente c, NodoLista* ant, NodoLista* sig);
        ~NodoLista();
};

#endif // NODOLISTA_H
