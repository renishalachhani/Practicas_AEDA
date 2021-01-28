#ifndef CELULA3_HPP_
#define CELULA3_HPP_

#include <iostream>

#include "celula.hpp"

using namespace std;


class Celula3: public celula
{
	public:
    	Celula3();  
    	~Celula3();  

    	int actualizarEstado(); 
	ostream& mostrar(ostream& os) const;
};

#endif
