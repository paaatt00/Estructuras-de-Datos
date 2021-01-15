#ifndef LISTAPEDIDOS_H
#define LISTAPEDIDOS_H
#include "NodoLista.h"
#include "ListaPedidos.h"
#include "Cliente.h"
#include "Pedido.h"

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
        void enlistarCliente(Cliente c);
        void insertarDerechaCliente(Cliente c);
        void insertarIzquierdaCliente(Cliente c);
        void desenlistar();
        void enlistarPrioridad(Pedido p);
        void mostrarLista();
        void mostrarListaPeques();
        void mostrarListaCliente();
        void ordenarLista(Cliente c);
        int contar(string descripcion);
        // Getters y Setters
        bool esVacia();
        NodoLista* getPrimero();
        void setPrimero(Pedido p);
        Pedido getPrimerPedido();
        Pedido getUltimoPedido();
};

#endif // LISTAPEDIDOS_H
