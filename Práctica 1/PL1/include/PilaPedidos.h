#ifndef PILAPEDIDOS_H
#define PILAPEDIDOS_H
#include "NodoPila.h"
#include "Pedido.h"

class PilaPedidos
{
    private:
        NodoPila* cima;

    public:
        // Constructores y destructores
        PilaPedidos();
        ~PilaPedidos();
        // Métodos
        void apilar(Pedido p);
        void desapilar();
        void mostrarCima();
        void apilarPrioridad(Pedido p);
        int comprobarCimaRegistrado();
        // Getters y Setters
        bool esVacia();
        Pedido getCimaPedido();
};

#endif // PILAPEDIDOS_H
