#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "ListaPedidos.h"
#include "Cliente.h"

class NodoArbol
{
    friend class ArbolPedidos;

    private:
        Cliente cliente_na;
        NodoArbol* izquierda_na;
        NodoArbol* derecha_na;
        ListaPedidos lista_na;

    public:
        NodoArbol(Cliente c, NodoArbol* dcha, NodoArbol* izq);
        NodoArbol();
        ~NodoArbol();
};

#endif // NODOARBOL_H
