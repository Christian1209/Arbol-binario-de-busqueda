#include <iostream>
#include "Nodo.h"
#include "Arbol.h"
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{
    int op,e;
    Personaje p1("a",1,1);
    Arbol *uno = new Arbol();
    Nodo *padre = new Nodo();
    string nom;
    int niv;
    int ide;
    do {
    cout<<"Bienvenido a Arbol binario de Busqueda" <<endl<<"Elige una opcion!"<<endl;
    cout<<"1.-)Insertar elementos\n2.-)Mostrar arbol\n3.-)Mostrar Inorden\n4.-)Mostrar preorden.\n5.-)Mostrar postorden\n6.-)Eliminar un numero\n7.-)es vacia"<<endl;
    cout<<"8.-)buscar\n9.-)Guardar(inorden).\n10.-)Cargar\n12.-) Salir."<<endl;
    cin>>op;
    switch(op){
        case 1:{
                cout<<"Escogiste insertar, introduce el nombre personaje a insertar"<<endl;
                cin.ignore();
                getline(cin,nom);
                cout<<"Introduce el Nivel que tendra el personaje"<<endl;
                cin>>niv;
                cout<<"Introduce el ID de tu personaje."<<endl;
                cin>>ide;
                p1.setNombre(nom);
                p1.setNivel(niv);
                p1.setId(ide);
                uno->insertar(uno->raiz,padre,p1);
        }
            break;
        case 2:{
            cout<<"Escogiste Mostrar!, Mostrando arbol..."<<endl;
            int c=0;
            uno->mostrar(uno->raiz,c);
            break;
                }
        case 3:
            cout<<"Escogiste Inorden!, Mostrando..."<<endl;
            uno->inorden(uno->raiz);
            break;
        case 4:
            cout<<"Escogiste Preorden!, Mostrando..."<<endl;
            uno->preorden(uno->raiz);
            break;
        case 5:
            cout<<"Escogiste Post!, Mostrando..."<<endl;
            uno->postorden(uno->raiz);
            break;
        case 6:{
            int el;
            cout<<"Escogiste eliminar, introduce nodo a eliminar..."<<endl;
            cin>>e;
            uno->eliminar(uno->raiz,padre,e);
        }
            break;
        case 7:
            if(uno->vacio(uno->raiz)){
                cout<<"Arbol vacio"<<endl;
            }
            else{
                cout<<"Arbol con elementos"<<endl;
            }
            break;
        case 8:{
            int b;
            cout<<"introduce dato a buscar"<<endl;
            cin>>b;
            uno->buscar(uno->raiz,b);
        }
        break;
        case 9:{
            ofstream archivoClientesSalida( "file01.txt", ios::out);
            uno->guardarinor(uno->raiz);
        }
            break;
        case 10:
            uno->cargar();
            break;
               }
    }while(op!=11);

}
