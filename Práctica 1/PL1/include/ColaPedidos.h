#ifndef COLAPEDIDOS_H
#define COLAPEDIDOS_H
#include "NodoCola.h"
#include "Pedido.h"

class ColaPedidos
{
    private:
        NodoCola* primero;
        NodoCola* ultimo;

    public:
        // Constructores y Destructores
        ColaPedidos();
        ~ColaPedidos();
        // Métodos
        void encolar(Pedido p);
        void desencolar();
        void mostrarCola();
        // Getters y Setters
        Pedido getPrimerPedido();
        NodoCola* getPrimero();
        NodoCola* getUltimo();
        bool esVacia();

};

#endif // COLAPEDIDOS_H
