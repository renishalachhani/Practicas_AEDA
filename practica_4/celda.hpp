#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

template <class clave>
class celda {
	private:
		int nclave_;
		clave* clave_;
		
	public:
		celda(int);
		~celda();
		
		bool Buscar(clave);
		bool Insertar(clave);
		
		bool estaLlena() const;
		
		void imprimir() const;
};



template <class clave>
celda<clave>::celda(int nclave)
{
  
	nclave_=nclave;
	clave_=new clave[nclave_];
 
}



template <class clave>
celda<clave>::~celda()
{
	if (clave_ != NULL)
	    delete [] clave_;
	nclave_=0;
}



template <class clave>
bool celda<clave>::Buscar(clave x)
{
	for(int i=0;i<nclave_;i++)
	{
		if(clave_[i]==x)
			return true;
	}
	return false;
}



template <class clave>
bool celda<clave>::Insertar(clave x)
{
	bool inserted=false;
	int i=0;
	while ((!inserted)&&(i<nclave_))
	{
		if (clave_[i]==0)
		{
			clave_[i]=x;
			inserted=true;
		}
		i++;
	}
	return inserted;
}



template <class clave>
bool celda<clave>::estaLlena() const
{
  	for (int i=0;i<nclave_;i++)
  	{
    		if (clave_[i]==0)
      			return false;
  	}
  	return true;
}




template <class clave>
void celda<clave>::imprimir() const
{
	for (int i=0;i<nclave_;i++)
	{
		cout<<setw(10);
		clave_[i].imprimir(cout);
	}
}
