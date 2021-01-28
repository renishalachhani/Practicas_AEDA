#include "Celula3.hpp"


Celula3::Celula3():
celula(3)
{

}


Celula3::~Celula3()
{

}



int Celula3::actualizarEstado()
{
    	if ((getVecinos() == 5) || (getVecinos() == 1))
	{
        	return 3;
    	}
    	else
	{
        	return 0;
    	}
}



ostream& Celula3::mostrar(ostream& os) const
{
    	os << "3";
    	return os;
}
