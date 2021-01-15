#ifndef CORREOS_H
#define CORREOS_H
#include "Pedido.h"
#include "ColaPedidos.h"
#include "PilaPedidos.h"
#include "ListaPedidos.h"
#include "ArbolPedidos.h"

class Correos
{
    private:
        ColaPedidos colaRegistrados;
        ColaPedidos colaNoRegistrados;
        PilaPedidos pilaPedidosErroneos;
        ListaPedidos listaPrepEnviar1;
        ListaPedidos listaPrepEnviar2;
        ArbolPedidos arbolPedidosEnviados;
    public:
        Correos();
        ~Correos();
        void lecturaTxt();
        void gestionCorreos();
};

#endif // CORREOS_H
