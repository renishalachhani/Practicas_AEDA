#ifndef CELULA2_HPP_
#define CELULA2_HPP_

#include <iostream>

#include "celula.hpp"

using namespace std;


class Celula2: public celula
{
	public:
    		Celula2();  
    		~Celula2(); 

    		int actualizarEstado();  
		ostream& mostrar(ostream& os) const;
};

#endif
