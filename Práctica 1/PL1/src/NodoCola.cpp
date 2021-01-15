#include "NodoCola.h"

//CONSTRUCTORES Y DESTRUCTORES //

NodoCola::NodoCola(Pedido p, NodoCola* sig)
{
    pedido_nc = p;
    siguiente_nc = sig;
}

NodoCola::~NodoCola()
{

}


