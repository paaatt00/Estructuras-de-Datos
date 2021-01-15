#ifndef NODOPILA_H
#define NODOPILA_H
#include "Pedido.h"

class NodoPila
{
    friend class PilaPedidos;

    private:
        Pedido pedido_np;
        NodoPila* siguiente_np;

    public:
        NodoPila(Pedido p, NodoPila* sig);
        ~NodoPila();
};

#endif // NODOPILA_H
