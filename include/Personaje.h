#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
using namespace std;



class Personaje
{
    public:
        Personaje();
        Personaje(string,int,int);
        ~Personaje();

        string getNombre(void){
        return nombre;
        };
        void setNombre(string nom){
            nombre=nom;
        };

        int getNivel(void){
            return nivel;
        };
        void setNivel(int nivel){
            this->nivel=nivel;
        };

        int getId(void){
            return id;
        };

        void setId(int id){
            this->id=id;
        }

    protected:

    private:
        string nombre;
        int id;
        int nivel;
};

#endif // PERSONAJE_Hs
