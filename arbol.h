#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
using namespace std;
class Arbol
{
    public:
        Arbol();
        void insertar(Nodo *&,Nodo* padre,Personaje);
        void mostrar(Nodo *,int);
        void inorden(Nodo *);
        void preorden(Nodo *);
        void postorden(Nodo *);
        bool vacio(Nodo *);
        void buscar(Nodo *,int e);
        void eliminar(Nodo *actual,Nodo *&Padre, int e);
        void cargar();
        void guardarinor(Nodo*);
        Nodo *raiz;
    private:
};

#endif // ARBOL_H
