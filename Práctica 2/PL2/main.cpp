#include <iostream>
#include <fstream>
#include "Pedido.h"
#include "ColaPedidos.h"
#include "ListaPedidos.h"
#include "PilaPedidos.h"
#include "Correos.h"
#include "ArbolPedidos.h"
#include "Cliente.h"

using namespace std;

int main()
{
    Correos correos;
    correos.lecturaTxt();
    correos.gestionCorreos();
}
