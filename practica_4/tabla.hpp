#pragma once

#include <iostream>
#include <cstring>
#include <cmath>
#include "celda.hpp"
#include "dni.hpp"
#include "exploracion_lineal.hpp"
#include "exploracion_cuadratica.hpp"
#include "exploracion_doble.hpp"
#include "exploracion_redispersion.hpp"
#include "dispersion_modulo.hpp"
#include "dispersion_suma.hpp"
#include "dispersion_pseudoaleatorio.hpp"

using namespace std;

template <class clave>
class tabla {
	private:
		int nCeldas;
		celda<clave>** vCelda;
		func_exploracion* g_;
		func_dispersion<clave>* h_;
		
	public:
		tabla(int, int, char, char);
		~tabla();
		
		bool Insertar(clave&) const;
		bool Buscar(clave&) const;
		
		bool Insertar(clave&, int&) const;
		bool Buscar(clave&, int&) const;
		
		void imprimir() const;
};

template <class clave>
tabla<clave>::tabla(int nCeldas, int nclave, char g, char h)
{
	 
	nCeldas=nCeldas;
	vCelda=new celda<clave>* [nCeldas];
	for (int i=0;i<nCeldas;i++)
	{
		vCelda[i]=new celda<clave>(nclave);
	}
	switch(g)
	{
		case 'l':
		g_=new exploracion_lineal();
		break;
		  
		case 'c':
		g_=new exploracion_cuadratica();
		break;
		  
		case 'd':
		g_=new exploracion_doble();
		break;
		  
		case 'r':
		g_=new exploracion_redispersion();
		break;
	}
	switch(h)
	{
		case 'm':
		h_=new dispersion_modulo<clave>();
		break;
		  
		case 's':
		h_=new dispersion_suma<clave>();
		break;
		  
		case 'p':
		h_=new dispersion_pseudoaleatorio<clave>();
		break;
		  
		  
	}
  
}

template <class clave>
tabla<clave>::~tabla()
{
	
	if (vCelda!=NULL)
	{
		for (int i=0;i<nCeldas;i++)
		{
			if (vCelda[i]!=NULL)
			{
				delete vCelda[i];
				vCelda[i]=NULL;
			}
		}
		delete [] vCelda;
	}
}



template <class clave>
bool tabla<clave>::Insertar(clave& x) const
{
	bool inserted=false;
  	int i=0;
  	while((!inserted)&&(i<nCeldas))
  	{
    		inserted=vCelda[g_->exploracion(h_->dispersion(x,nCeldas),i,nCeldas)]->Insertar(x);
    		if (inserted==false)
    		{
      
	  		g_->exploracion(h_->dispersion(x,nCeldas),i,nCeldas);
      			i++;
      
      			g_->exploracion(h_->dispersion(x,nCeldas),i,nCeldas);

    		}
  	}
  	if(inserted)
	  	return true;
  	else
	  	return false;
}



template <class clave>
bool tabla<clave>::Buscar(clave& x) const
{
	
	bool find=false;
	bool llena=false;
	int i=0;
	while((!find)&&(i<nCeldas)&&(!llena))
	{
		find=vCelda[g_->exploracion(h_->dispersion(x,nCeldas),i,nCeldas)]->Buscar(x);
		llena = (vCelda[g_->exploracion(h_->dispersion(x,nCeldas),i,nCeldas)]->estaLlena());
		if (!find)
			i++;
	}
	return find;
}



template <class clave>
bool tabla<clave>::Insertar(clave& x, int& comp) const
{
  	bool inserted=false;
  	int i=0;
  	while((!inserted)&&(i<nCeldas))
  	{
    		inserted=vCelda[g_->exploracion(h_->dispersion(x,nCeldas),i,nCeldas)]->Insertar(x);
    		if (inserted==false)
    		{
     
	  		g_->exploracion(h_->dispersion(x,nCeldas),i,nCeldas);
      i++;
      
      			g_->exploracion(h_->dispersion(x,nCeldas),i,nCeldas);
	  
    		}
  	}
  	comp=i;
  	if(inserted)
	  	return true;
  	else
	  	return false;
}




template <class clave>
bool tabla<clave>::Buscar(clave& x, int& comp) const
{
	bool find=false;
	bool llena=true;
	int i=0;
	while((!find)&&(i<nCeldas)&&(llena))
	{
		find=vCelda[g_->exploracion(h_->dispersion(x,nCeldas),i,nCeldas)]->Buscar(x);
		llena = (vCelda[g_->exploracion(h_->dispersion(x,nCeldas),i,nCeldas)]->estaLlena());
		if (!find)
			i++;
	}
	comp=i;
	return find;
}

