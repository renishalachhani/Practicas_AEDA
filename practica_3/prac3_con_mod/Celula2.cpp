#include "Celula2.hpp"


Celula2::Celula2():
celula(2)
{

}



Celula2::~Celula2()
{

}



int Celula2::actualizarEstado()
{
    	if ((getVecinos() == 2) || (getVecinos() == 4) || (getVecinos() == 5))
	{
        	return 2;
    	}
    	else
	{
        	return 0;
    	}
}

ostream& Celula2::mostrar(ostream& os) const
{
    os << "2";
    return os;
}
