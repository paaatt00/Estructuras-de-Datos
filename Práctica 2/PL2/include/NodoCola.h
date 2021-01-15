#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "Pedido.h"

class NodoCola
{
    friend class ColaPedidos;

    private:
        NodoCola* siguiente_nc;
        Pedido pedido_nc;

    public:
        NodoCola(Pedido p, NodoCola *sig);
        ~NodoCola();
};

#endif // NODOCOLA_H
