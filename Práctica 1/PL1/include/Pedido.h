#ifndef PEDIDO_H
#define PEDIDO_H
#include <string>
#include <iostream>

using namespace std;


class Pedido
{
    private:
        string descripcionArt, nombreCliente, direccionEntrega, tipoCliente;
        long long numTarjeta;
        int tiempoPrepEnvio;
    public:
        // Constructores y Destructores
        Pedido();
        Pedido(string descripcion, string nombre, string direccion, string tipo, long long tarjeta, int tiempo);
        ~Pedido();
        // Métodos
        bool comprobarPedidoErroneo();
        string imprimir();
        void completarPedido();
        void reducirTiempoPrepEnvio();
        // Getters y Setters
        string getDescripcionArt();
        string getNombreCliente();
        string getDireccionEntrega();
        string getTipoCliente();
        long long getNumTarjeta();
        int getTiempoPrepEnvio();
};

#endif // PEDIDO_H
