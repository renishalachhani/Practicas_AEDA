#pragma once

#include "dispersion.hpp"

template <class clave>
class dispersion_modulo : public func_dispersion<clave> {
	public:
		dispersion_modulo(){};
		virtual ~dispersion_modulo(){};
		int dispersion(clave&, int);
};

template <class clave>
int dispersion_modulo<clave>::dispersion(clave& x, int sz)
{
	return x%sz;
}