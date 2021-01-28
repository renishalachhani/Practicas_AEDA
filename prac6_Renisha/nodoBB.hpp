#pragma once

#include <cstdio>

using namespace std;

template <class clave>
class nodoBB
{
private:
    clave dato_; 
    nodoBB<clave> *izq_;  
    nodoBB<clave> *dch_;  

public:
    nodoBB (void):
    izq_(NULL),
    dch_(NULL)
    {

    }

    nodoBB (const clave dato, nodoBB<clave> *izq=NULL, nodoBB<clave> *dch=NULL):
    dato_(dato),
    izq_(izq),
    dch_(dch)
    {

    }

    ~nodoBB (void)
    {
        if (izq_ != NULL){
            delete izq_;
            izq_ = NULL;
        }
        if (dch_ != NULL){
            delete dch_;
            dch_ = NULL;
        }
    }

    clave get_dato (void)
    {
        return dato_;
    }

    void set_dato (clave dato){
        dato_ = dato;
    }

    nodoBB<clave>*& get_izq (void)
    {
        return izq_;
    }

    nodoBB<clave>*& get_dch (void)
    {
        return dch_;
    }

    ostream& write (ostream& os) const
    {
        if (this == NULL){
            os << "[.]";
        }
        else{
            os << "[";
            dato_.write(os);
            cout << "]";
        }
        return os;
    }
};
