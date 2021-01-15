#include "NodoPila.h"

// CONTRUCTORES Y DESTRUCTORES //

NodoPila::NodoPila(Pedido p, NodoPila* sig)
{
    pedido_np = p;
    siguiente_np = sig;
}

NodoPila::~NodoPila()
{

}


