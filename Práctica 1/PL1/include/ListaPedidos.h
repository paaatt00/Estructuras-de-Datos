#ifndef LISTAPEDIDOS_H
#define LISTAPEDIDOS_H
#include "NodoLista.h"

class ListaPedidos
{
    private:
        NodoLista* primero;
        NodoLista* ultimo;
    public:
        // Constructores y Destructores
        ListaPedidos();
        ~ListaPedidos();
        // Métodos
        void enlistar(Pedido p);
        void insertarDerecha(Pedido p);
        void insertarIzquierda(Pedido p);
        void desenlistar();
        void mostrarLista();
        // Getters y Setters
        bool esVacia();
        Pedido getPrimerPedido();
        Pedido getUltimoPedido();
};

#endif // LISTAPEDIDOS_H
