#ifndef PEDIDOPEQUE_H
#define PEDIDOPEQUE_H
#include <string>
#include <iostream>

using namespace std;

class PedidoPeque
{
    private:
        string descripcionArt, direccionEntrega;
        int tiempoPrepEnvio;

    public:
        PedidoPeque();
        PedidoPeque(string descripcion, string direccion, int tiempo);
        ~PedidoPeque();
        // Métodos
        string imprimir();
        // Getters y Setters
        string getDescripcionArt();
        string getDireccionEntrega();
        int getTiempoPrepEnvio();

};

#endif // PEDIDOPEQUE_H
