#include <iostream>
#include <fstream>
#include "Pedido.h"
#include "ColaPedidos.h"
#include "ListaPedidos.h"
#include "PilaPedidos.h"
#include "Correos.h"

using namespace std;

int main()
{
    // VARIABLES //

    Correos correos;
    ColaPedidos colaR;
    ColaPedidos colaNR;

    // CÓDIGO PARA LEER TXT //

    string desc;
    string nombre;
    string dir;
    string type;
    long long creditCard;
    int time;
    ifstream fe;
    string str;
    fe.open("D:/Universidad/2º/1º cuatrimestre/Estructura de Datos 2.0/Laboratorio/Práctica 1/datos.txt", ios::in); //ruta de la ubicacion del txt
    if (fe.fail()) {
        cout << "No se pudo abrir el archivo." << endl;
        exit(1);
    } else {
        cout << "PEDIDOS" << endl;
        do {
            getline(fe,str);
            str.empty();
            long posicion;
            posicion = str.find("//");
            desc = str.substr(0, posicion);
            str.erase(0, posicion + 2);
            long posicion1;
            posicion1 = str.find("//");
            nombre = str.substr(0, posicion1);
            str.erase(0, posicion1 + 2);
            long posicion2;
            posicion2 = str.find("//");
            dir = str.substr(0, posicion2);
            str.erase(0, posicion2 + 2);
            long posicion3;
            posicion3 = str.find("//");
            type = str.substr(0,posicion3);
            str.erase(0,posicion3 + 2);
            long posicion4;
            posicion4 = str.find("//");
            creditCard = std::stoll(str.substr(0,posicion4));
            str.erase(0,posicion4 + 2);
            long posicion5;
            posicion5 = str.find("//");
            time = stoi(str.substr(0, posicion5));
            str.erase(0,posicion5 + 2);
            Pedido pedido(desc, nombre, dir, type, creditCard, time);
            if (pedido.getTipoCliente() == "VIP" || pedido.getTipoCliente() == "NVIP"){
                cout << pedido.imprimir() << endl;
                colaR.encolar(pedido);
            }
            else if(pedido.getTipoCliente() == "NR"){
                cout << pedido.imprimir() << endl;
                colaNR.encolar(pedido);
            }
        } while (!fe.eof());
        fe.close();

        // FIN LECTURA TXT //

        cout << "" << endl;
        correos.gestionCorreos(colaR, colaNR);
    }
}


