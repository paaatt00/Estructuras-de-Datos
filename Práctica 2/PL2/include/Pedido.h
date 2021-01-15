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
        Pedido(string descripcion, string direccion, int tiempo);
        ~Pedido();
        // Métodos
        bool comprobarPedidoErroneo();
        string imprimir();
        string imprimirPeque();
        void completarPedido();
        void reducirTiempoPrepEnvio();
        // Getters y Setters
        string getDescripcionArt();
        string getNombreCliente();
        string getDireccionEntrega();
        string getTipoCliente();
        long long getNumTarjeta();
        int getTiempoPrepEnvio();
        int setTiempoPrepEnvio(int tiempo);
        void socorroYaNoSeQueHacer(Pedido p);
};

#endif // PEDIDO_H
