#include "celula.hpp"
#include "tablero.hpp"


celula::celula ()
{

	estado = 0;
	next_estado = 0;
    
}



celula::celula (int Estado)
{
    	estado = Estado;
	next_estado = Estado;
}



celula::~celula ()
{
    
}



int celula::getEstado() const
{
    	return estado;
}



int celula::setEstado (int s)
{
   	estado = s;
	return estado;
}



int celula::getNextEstado() const
{
    	return next_estado;
}



void celula::setNextEstado (int s)
{
    	next_estado = s;
}




