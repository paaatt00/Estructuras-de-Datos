#include "NodoArbol.h"


//CONSTRUCTORES Y DESTRUCTORES //

NodoArbol::NodoArbol(Cliente c, NodoArbol* dcha, NodoArbol* izqq)
{
    cliente_na = c;
    izquierda_na = izqq;
    derecha_na = dcha;
    lista_na = ListaPedidos();
}

NodoArbol::NodoArbol()
{

}

NodoArbol::~NodoArbol()
{
    //dtor
}
