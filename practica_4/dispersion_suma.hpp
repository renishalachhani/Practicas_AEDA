#pragma once

#include "dispersion.hpp"

template <class clave>
class dispersion_suma : public func_dispersion<clave> {
	
	public:
		dispersion_suma(){};
		virtual ~dispersion_suma(){};
		int dispersion(clave&, int);
};

template <class clave>
int dispersion_suma<clave>::dispersion(clave& x, int sz)
{
	
    	int d=0,y;
    	int k=x.get_value();
    	while(k>0)
	{
		y=(k%10);
		d=d+y;
		k=k/10;
	}
    	return (d%sz);
}
