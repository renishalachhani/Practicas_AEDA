#include "celula.hpp"


celula::celula()
{
	
	estado = 0;
	vecinos=0;


}



celula::celula(int Estado)
{
	estado = Estado;
	vecinos = 0;
}



celula::~celula ()
{

}



int celula::getEstado() const
{
    	return estado;
}



int celula::getVecinos() const
{
    	return vecinos;
}



void celula::setVivoVecino(int n)
{
    	vecinos = n;
}



int celula::actualizarEstado()
{
    	if (vecinos == 3)
	{
        	return 1;
    	}
    	else
	{
        	if ((vecinos == 3) || (vecinos == 6) || (vecinos == 8))
		{
            		return 2;
        	}
        	else
		{
            		if ((vecinos == 3) || (vecinos == 4) || (vecinos == 6))
			{
                		return 3;
            		}
           		else
			{
                		return 0;
            		}
        	}
    	}
}



ostream& celula::mostrar(ostream& os) const
{
    	os << " ";
    	return os;
}
