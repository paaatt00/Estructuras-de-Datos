#include "PedidoPeque.h"

PedidoPeque::PedidoPeque()
{
    //ctor
}

PedidoPeque::PedidoPeque(string descripcion, string direccion, int tiempo)
{
    descripcionArt = descripcion;
    direccionEntrega = direccion;
    tiempoPrepEnvio = tiempo;
}

PedidoPeque::~PedidoPeque()
{
    //dtor
}

string PedidoPeque::imprimir()
{
    string j = to_string(tiempoPrepEnvio);
    string pedido = descripcionArt + "//" + direccionEntrega +  "//" + j;
    return pedido;
}

string PedidoPeque::getDescripcionArt()
{
    return descripcionArt;
}

string PedidoPeque::getDireccionEntrega()
{
    return direccionEntrega;
}

int PedidoPeque::getTiempoPrepEnvio()
{
    return tiempoPrepEnvio;
}

