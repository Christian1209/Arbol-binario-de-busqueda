#ifndef NODO_H
#define NODO_H
#include "Personaje.h"
#include <stdlib.h>
#include<iostream>

class Nodo
{
    public:
        Nodo();
        ~Nodo();
        Personaje dato;
        Nodo *padre;
        Nodo *izq;
        Nodo *der;
    private:
};

#endif // NODO_H
