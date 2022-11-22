#include "Arbol.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include "Personaje.h"
#include "Nodo.h"
using namespace std;
void Arbol::cargar(){
   int i,j;
  string d;
  ifstream is("file01.txt", ifstream::binary);
  if (is) {
    // get length of file:
    is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);

    char * buffer = new char [length];
    char * registro=new char;
    char * campo=new char;

    char *tokenPtr;
    char *tokenCampo;



    cout << "Reading " << length << " characters... ";
    // read data as a block:
    is.read (buffer,length);

    stringstream ss(buffer);

    vector<string> tokens;
    vector<string> tokensC;

    string tmpStr;
    string tmpStrC;

    if (is)
    {
      cout<< "all characters read successfully."<<endl;
      //cout<<buffer<<endl;
      i=0;
      d=(string)buffer;
      int p=0;


      while(getline(ss,tmpStr,'*'))
      {
          tokens.push_back(tmpStr);
      }


         for(int i = 0; i < tokens.size()-1; i++)
         {
            stringstream cm(tokens[i]);
            Personaje p1("a",1,1);
                   while(getline(cm,tmpStrC,'|'))
                  {
                      tokensC.push_back(tmpStrC);
                      p++;

                  }
                     //for(int i = 0; i < tokensC.size(); i++) {
                          //cout << tokensC[i] << "";
                    //}
                    //cout<<"limite del for"<<endl;
           // cout << tokens[i]<<endl;
           p1.setId(atoi(tokensC[p-3].c_str()));
           p1.setNombre(tokensC[p-2]);
           p1.setNivel(atoi(tokensC[p-1].c_str()));
           Nodo *padre = new Nodo();
           insertar(raiz,padre,p1);
         }
    }
    else{
      cout << "error: only " << is.gcount() << " could be read";

    is.close();

    // ...buffer contains the entire file...

    delete[] buffer;
  }
}
}

bool Arbol::vacio(Nodo *root){
    if(root == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void Arbol::buscar(Nodo *root, int e){
    if(vacio(raiz)){
        cout<<"Arbol vacio"<<endl;
    }
    if(vacio(raiz)==false and root==nullptr){
        cout<<"dato no encontrado"<<endl;
    }
    else{
        Nodo *tmp = root;
        if(tmp->dato.getId()==e){
            cout<<"dato encontrado"<<endl;
        }
        else if(tmp->dato.getId()>e){
            buscar(tmp->der,e);
        }
        else if(tmp->dato.getId()<e){
            buscar(tmp->izq,e);
        }
    }
 }

void Arbol::insertar(Nodo *&actual,Nodo *padre,Personaje p){
    int e;
    e=p.getId();
    if(raiz==nullptr){
        Nodo *tmp = new Nodo();
        tmp->dato=p;
        raiz=tmp;
        raiz->padre = padre;
    }
    else{
    if(actual==nullptr){
        Nodo *tmp = new Nodo();
        tmp->dato=p;
        actual=tmp;
        actual->padre = padre;
    }
    else{
        int vraiz=actual->dato.getId();
        if(e<vraiz){
            insertar(actual->izq,actual,p);
        }
        else{
            insertar(actual->der,actual,p);
        }
    }

    }
 }

void Arbol::mostrar(Nodo *actual,int cont){
    if(vacio(raiz)){
        cout<<"Arbol vacio!"<<endl;
    }
    else{
                if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        mostrar(actual->der,cont+1);{
            for(int i=0;i<cont;i++){
                cout<<"   ";
            }
            cout<<actual->dato.getId()<<endl;
            mostrar(actual->izq,cont+1);
        }
    }
    }
 }

void Arbol::inorden(Nodo *actual){
    if(vacio(raiz)){
        cout<<"Arbol vacio!"<<endl;
    }
    else{
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        inorden(actual->izq);
        cout<<"[Nombre: "<<actual->dato.getNombre()<<" Nivel: "<<actual->dato.getNivel()<<" Id: "<<actual->dato.getId()<<"]";
        inorden(actual->der);
    }

    }
 }

void Arbol::preorden(Nodo *actual){
    if(vacio(raiz)){
        cout<<"Arbol vacio!"<<endl;
    }
    else{
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        cout<<"[Nombre: "<<actual->dato.getNombre()<<" Nivel: "<<actual->dato.getNivel()<<" Id: "<<actual->dato.getId()<<"]";
        preorden(actual->izq);
        preorden(actual->der);
    }
    }
 }

 void Arbol::postorden(Nodo *actual){
    if(vacio(raiz)){
        cout<<"Arbol vacio!"<<endl;
    }
    else{
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        postorden(actual->izq);
        postorden(actual->der);
        cout<<"[Nombre: "<<actual->dato.getNombre()<<" Nivel: "<<actual->dato.getNivel()<<" Id: "<<actual->dato.getId()<<"]";
    }
    }
 }

void Arbol::eliminar(Nodo *actual,Nodo *&Padre, int e){
    if(vacio(raiz)){
        cout<<"Arbol vacio!"<<endl;
    }
    else{
    int vraiz=actual->dato.getId();
    if(vraiz==e){
            //caso raiz
            if(raiz->dato.getId()==actual->dato.getId()){
                    //caso raiz hoja
                    if(raiz->izq==nullptr &&  raiz->der==nullptr){
                        raiz=nullptr;
                    }
                    //caso hijo derecho
                    else if((raiz->izq==nullptr) && raiz->der!=nullptr){
                            raiz=raiz->der;
                            raiz->padre=nullptr;
                    }
                    //caso hijo izquierdo
                    else if ((raiz->der==nullptr) && raiz->izq){
                            raiz=raiz->izq;
                            raiz->padre=nullptr;
                    }
                    //caso ambos hijos
                    else if(raiz->der && raiz->der){
                            Nodo *auxiliar = new Nodo();
                            auxiliar=raiz->izq;
                            while (auxiliar->der){
                                auxiliar = auxiliar->der;
                            }
                            eliminar(actual->izq,actual,auxiliar->dato.getId());
                            auxiliar->padre=nullptr;
                            auxiliar->der = raiz->der;
                            auxiliar->izq = raiz->izq;
                            raiz->der->padre = auxiliar;
                            //como elimine su nodo izquierdo para reemplazarlo, necesito comprobar que no haya quedado nulo.
                            if (raiz->izq){
                                raiz->izq->padre = auxiliar;
                                auxiliar->izq = raiz->izq;
                            }
                            raiz=auxiliar;
                    }
            }
            //caso nodo ambos hijos.
            else if(actual->der and actual->izq){
                    if(Padre->der==actual){
                            //nodo a eliminar es hijo derecho.
                        Nodo *auxiliar = new Nodo();
                        auxiliar=actual->izq;
                        while (auxiliar->der){
                            auxiliar = auxiliar->der;
                        }
                        eliminar(actual->izq,actual,auxiliar->dato.getId());
                        auxiliar->padre=actual->padre;
                        auxiliar->der = actual->der;
                        auxiliar->izq = actual->izq;
                        actual->der->padre = auxiliar;

                        //validamos
                        if (actual->izq){
                            actual->izq->padre = auxiliar;
                        }
                        Padre->der = auxiliar;
                    }
                    else{
                        //nodo a eliminar es hijo izquierdo.
                            //nodo a eliminar es hijo derecho.
                        Nodo *auxiliar = new Nodo();
                        auxiliar=actual->izq;
                        while (auxiliar->der){
                            auxiliar = auxiliar->der;
                        }
                        eliminar(actual->izq,actual,auxiliar->dato.getId());
                        auxiliar->padre=actual->padre;
                        auxiliar->der = actual->der;
                        auxiliar->izq = actual->izq;
                        actual->der->padre = auxiliar;

                        //validamos
                        if (actual->izq){
                            actual->izq->padre = auxiliar;
                        }
                        Padre->izq = auxiliar;
                    }
                        }
            //caso nodo hijo izquierdo
            else if(actual->izq and actual->der==nullptr){
                    //padre por derecha
                if(Padre->der==actual){
                    actual->izq->padre=actual->padre;
                    Padre->der = actual->izq;
                }
            //padre por izq.
                else{
                    actual->izq->padre = actual->padre;
                    Padre->izq = actual->izq;

                }
            }
            //caso nodo hijo derecho
           else  if(actual->der and actual->izq==nullptr){
                //padre por derecha.
                if(Padre->der==actual){
                    actual->der->padre=actual->padre;
                    Padre->der = actual->der;
                }
            //padre por izq.
                else{
                    actual->der->padre = actual->padre;
                    Padre->izq = actual->der;

                }
            }

            //caso nodo hoja
            if(actual->der==nullptr and actual->izq==nullptr){
                    //padre por derecha
                    if(Padre->der==actual){
                        Padre->der=nullptr;
                    }
                    //padre por izquierda.
                    else{
                        Padre->izq=nullptr;

                    }
            }
    }
    else{
        if(e<vraiz){
                if(actual->izq){
                    eliminar(actual->izq,actual,e);
                }
                else{
                    cout<<"No encontrado."<<endl;
                }
        }
        else{
                if (actual->der){
                    eliminar(actual->der,actual,e);
                }
                else{
                    cout<<"No encontrado."<<endl;
                }
        }
    }

    }
}

void Arbol::guardarinor(Nodo *aux){
        if(vacio(raiz)){
            cout<<"Arbol vacio!"<<endl;
        }
        else{
        //el constructor de ofstream abre el archivo
        ofstream archivoClientesSalida( "file01.txt", ios::app );
        // sale del programa si no puede crear el archivo
        if ( !archivoClientesSalida ) // operador ! sobrecargado
        {
        cerr << "No se pudo abrir el archivo" << endl;
        exit( EXIT_FAILURE );
        } // fin de if
        if (aux == nullptr){
            archivoClientesSalida.close();
            return;

        }
        else{
            guardarinor(aux->izq);
            cout<<"[Nombre: "<<aux->dato.getNombre()<<" Nivel: "<<aux->dato.getNivel()<<" Id: "<<aux->dato.getId()<<"]";
            archivoClientesSalida << aux->dato.getId() << "|" << aux->dato.getNombre() << "|" << aux->dato.getNivel() << "*";
            archivoClientesSalida.close();
            guardarinor(aux->der);
        }

    }
}

Arbol::Arbol()
{
    raiz=nullptr;
}
