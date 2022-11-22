#include "Nodo.h"
#include <stdlib.h>
#include<stdio.h>
#include "Nodo.h"
Nodo::Nodo()
{
    dato.setNombre("");
    dato.setId(0);
    dato.setNivel(0);
    padre = nullptr;
    izq = nullptr;
    der = nullptr;
}
