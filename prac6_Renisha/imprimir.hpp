#pragma once

#include <cstdio>
#include <vector>

#include "nodoBB.hpp"

using namespace std;

template <class clave>
class imprimir
{
private:
    int size_;  
    vector<nodoBB<clave>* > nodo_; 
    vector<int> nivel_;  

public:
    imprimir (void):
    size_(0) 
    {
        nodo_.clear(); 
        nivel_.clear(); 
    }

    ~imprimir (void)
    {

    }

    void insertar (nodoBB<clave>* nodo, int nivel)
    {
        nodo_.push_back(nodo);  
        nivel_.push_back(nivel); 
        size_ ++;  
    }

    void extraer (nodoBB<clave>* &nodo, int &nivel)
    {
        nodo = nodo_[0];  
        nivel = nivel_[0]; 
        nodo_.erase(nodo_.begin()); 
        nivel_.erase(nivel_.begin());  
        size_ --;  
    }

    bool vacia (void)
    {
        if (size_ < 1){
            return true;
        }
        else{
            return false;
        }
    }
};
