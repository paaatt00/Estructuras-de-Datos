#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <iostream>

using namespace std;

class Cliente
{
    private:
        string nombreCliente, tipoCliente;
        long long numTarjeta;
    public:
        Cliente();
        Cliente(string nombre, string tipo, long long tarjeta);
        ~Cliente();
        // Métodos
        string imprimir();
        // Getters y Setters
        string getNombreCliente();
        string getTipoCliente();
        long long getNumTarjeta();
};

#endif // CLIENTE_H
