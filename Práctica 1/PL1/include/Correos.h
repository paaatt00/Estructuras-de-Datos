#ifndef CORREOS_H
#define CORREOS_H
#include "Pedido.h"
#include "ColaPedidos.h"
#include "PilaPedidos.h"
#include "ListaPedidos.h"

class Correos
{
    public:
        Correos();
        ~Correos();
        void gestionCorreos(ColaPedidos colaRegistrados, ColaPedidos colaNoRegistrados);
};

#endif // CORREOS_H
