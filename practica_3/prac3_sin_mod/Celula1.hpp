#ifndef CELULA1_HPP_
#define CELULA1_HPP_

#include <iostream>

#include "celula.hpp"

using namespace std;


class Celula1: public celula
{
	public:
    		Celula1(); 
    		~Celula1(); 

    		int actualizarEstado();
		ostream& mostrar(ostream& os) const;
};

#endif
