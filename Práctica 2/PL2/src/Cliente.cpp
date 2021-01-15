#include "Cliente.h"

// CONSTRUCTORES Y DESTRUCTORES //

Cliente::Cliente()
{
    //ctor
}

Cliente::Cliente(string nombre, string tipo, long long tarjeta)
{
    nombreCliente = nombre;
    tipoCliente = tipo;
    numTarjeta = tarjeta;
}

Cliente::~Cliente()
{
    //dtor
}

// MÉTODOS //

string Cliente::imprimir()
{
    string i = to_string(numTarjeta);
    string pedido = nombreCliente + "//" + tipoCliente + "//" + i;
    return pedido;
}

// GETTERS Y SETTERS //

string Cliente::getNombreCliente()
{
    return nombreCliente;
}

string Cliente::getTipoCliente()
{
    return tipoCliente;
}

long long Cliente::getNumTarjeta()
{
    return numTarjeta;
}
