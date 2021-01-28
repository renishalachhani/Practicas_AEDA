#include "Celula1.hpp"


Celula1::Celula1():
celula(1)
{

}



Celula1::~Celula1()
{

}


int Celula1::actualizarEstado()
{
    	if ((getVecinos() == 2) || (getVecinos() == 3))
	{
        	return 1;
    	}
    	else
	{
        	return 0;
    	}
}



ostream& Celula1::mostrar(ostream& os) const
{
    	os << "1";
    	return os;
}
