#include "Pedido.h"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

// CONSTRUCTORES Y DESTRUCTORES //

Pedido::Pedido()
{

}

Pedido::Pedido(string descripcion, string nombre, string direccion, string tipo, long long tarjeta, int tiempo)
{
    descripcionArt = descripcion;
    nombreCliente = nombre;
    direccionEntrega = direccion;
    tipoCliente = tipo;
    numTarjeta = tarjeta;
    tiempoPrepEnvio = tiempo;
}

Pedido::~Pedido()
{

}

// MÉTODOS //

bool Pedido::comprobarPedidoErroneo()
{
    string i = to_string(numTarjeta);
    int longTarjeta = i.length();
    if (descripcionArt == "" || nombreCliente == "" || direccionEntrega == "" || longTarjeta != 12 || (10 < tiempoPrepEnvio || tiempoPrepEnvio < 1)) {
        return true;
    } else {
        return false;
    }
}

string Pedido::imprimir()
{
    string i = to_string(numTarjeta);
    string j = to_string(tiempoPrepEnvio);
    string pedido = descripcionArt + "//" + nombreCliente + "//" + direccionEntrega + "//" + tipoCliente + "//" + i + "//" + j;
    return pedido;
}

void Pedido::completarPedido()
{
    string i = to_string(numTarjeta);
    int longTarjeta = i.length();
    while (comprobarPedidoErroneo()) {
        srand (time(NULL));
        int random = 1 + rand() % 6;
        if (descripcionArt == "") {
            if (random == 1) {
                descripcionArt = "Xiaomi Mi Smart Band 5";
            } else if (random == 2) {
                    descripcionArt = "PlayStation 5";
            } else if (random == 3) {
                descripcionArt = "GeForce RTX 3090";
            } else if (random = 4) {
                descripcionArt = "i7-9700K 3.6GHz";
            } else {
                descripcionArt = "Iphone 12";
            }
        } else if (nombreCliente == "") {
            if (random == 1) {
                nombreCliente = "Jorge Arroyo Megia";
            } else if (random == 2) {
                nombreCliente = "Isabel Blanco Martinez";
            } else if (random == 3) {
                nombreCliente = "Maria Sanz Espeja";
            } else if (random = 4) {
                nombreCliente = "Patricia Cuesta Ruiz";
            } else {
                nombreCliente = "Lucia Campos Díaz";
            }
        } else if (direccionEntrega == "") {
            if (random == 1) {
                direccionEntrega = "Calle Pesogordo, 2";
            } else if (random == 2) {
                direccionEntrega = "Calle Mayor, 1";
            } else if (random == 3) {
                direccionEntrega = "Plaza Santo Domingo, 4";
            } else if (random = 4) {
                direccionEntrega = "Avenida del Ejercito, 23";
            } else {
                direccionEntrega = "Calle Bardales, 7";
            }
        } else if (longTarjeta != 12) {
            if (random == 1) {
                numTarjeta = 654236874523;
            } else if (random == 2) {
                numTarjeta = 514300453469;
            } else if (random == 3) {
                numTarjeta = 937933494195;
            } else if (random = 4) {
                numTarjeta = 548744023638;
            } else {
                numTarjeta = 615271819368;
            }
        } else if (10 < tiempoPrepEnvio || tiempoPrepEnvio < 1) {
            int tiempoRandom = 1 + rand() % 11;
            tiempoPrepEnvio = tiempoRandom;
        }
    }
}

void Pedido::reducirTiempoPrepEnvio()
{
    tiempoPrepEnvio--;
}

// GETTERS Y SETTERS
string Pedido::getDescripcionArt()
{
    return descripcionArt;
}

string Pedido::getNombreCliente()
{
    return nombreCliente;
}

string Pedido::getDireccionEntrega()
{
    return direccionEntrega;
}

string Pedido::getTipoCliente()
{
    return tipoCliente;
}

long long Pedido::getNumTarjeta()
{
    return numTarjeta;
}

int Pedido::getTiempoPrepEnvio()
{
    return tiempoPrepEnvio;
}


