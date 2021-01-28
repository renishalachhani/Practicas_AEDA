#pragma once

#include <cstdio>

#include "nodoBB.hpp"
#include "imprimir.hpp"

using namespace std;

extern int contador;  
extern mod MODO;  

template <class clave>
class ABB
{
private:
    nodoBB <clave> *raiz_;  

public:
    ABB (void):
    raiz_(NULL)
    {

    }

    ABB (nodoBB<clave>* raiz):
    raiz_(raiz)
    {

    }

    ~ABB (void)
    {
        podar(raiz_);
    }

    void podar (nodoBB<clave>* &nodo)
    {
        if (nodo != NULL){  
            podar(nodo->get_izq());  
            podar(nodo->get_dch()); 
            delete nodo;  
            nodo = NULL;
        }
    }

    nodoBB<clave>* buscar (clave dato)
    {
        return buscar_rama (raiz_, dato);
    }

    nodoBB<clave>* buscar_rama (nodoBB<clave>* nodo, clave dato)
    {
        if (MODO == estadistico){  
            contador ++; 
        }

        if (nodo == NULL){
            return NULL;
        }
        if (dato == nodo->get_dato()){
            return nodo;
        }
        if (dato < nodo->get_dato()){
            return buscar_rama (nodo->get_izq(), dato);
        }
        if (dato > nodo->get_dato()){
            return buscar_rama (nodo->get_dch(), dato);
        }
    }

    void insertar (clave dato)
    {
        insert(raiz_, dato);
    }

    void insert (nodoBB<clave>* &nodo, clave dato)
    {
        if (nodo == NULL){
            nodo = new nodoBB<clave>(dato);
        }
        else{
            if (dato == nodo->get_dato()){
                cerr << "Clave ya insertada!" << endl;
            }
            else{
                if (dato < nodo->get_dato()){
                    insert(nodo->get_izq(), dato);
                }
                else{
                    if (dato > nodo->get_dato()){
                        insert(nodo->get_dch(), dato);
                    }
                }
            }
        }
    }

    void eliminar (clave dato){
        eliminate(raiz_, dato);
    }

    void eliminate (nodoBB<clave>* &nodo, clave dato)
    {
        if (nodo == NULL){
            cerr << "El nodo a eliminar no esta en el arbol!" << endl;
        }
        else{
            if (dato == nodo->get_dato()){
                if (nodo->get_dch() == NULL){
                    nodo = nodo->get_izq();
                }
                else{
                    if (nodo->get_izq() == NULL){
                        nodo = nodo->get_dch();
                    }
                    else{
			nodoBB<clave>* eliminar = nodo;  
                        sustituir(eliminar, nodo->get_izq());
                    }
                }
            }
            else{
                if (dato < nodo->get_dato()){
                    eliminate(nodo->get_izq(), dato);
                }
                else{
                    if (dato > nodo->get_dato()){
                        eliminate(nodo->get_dch(), dato);
                    }
                }
            }
        }
    }

    void sustituir (nodoBB<clave>* &eliminar, nodoBB<clave>* &sust)
    {
        if (sust->get_dch() != NULL){
            sustituir(eliminar, sust->get_dch());
        }
        else{  
            eliminar->set_dato(sust->get_dato());
            eliminar = sust;
            sust = sust->get_izq();
        }
    }

    ostream& write (ostream& os) const
    {
        imprimir<clave> cola;  
        nodoBB<clave>* nodo;  
        int nivel = 0;  
        int nivel_actual = 0;  
        cola.insertar(raiz_, nivel);  
        os << "Nivel 0: ";
        while (!cola.vacia()){
            cola.extraer(nodo, nivel); 
            if (nivel > nivel_actual){
                nivel_actual = nivel;
                os << "\nNivel " << nivel_actual << ": ";
            }
	    

            nodo->write(os);
            if (nodo != NULL){
                cola.insertar(nodo->get_izq(), nivel+1);
                cola.insertar(nodo->get_dch(), nivel+1);
		

            }
	    
        }
    }
};
