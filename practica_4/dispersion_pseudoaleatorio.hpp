#pragma once

#include <cstdlib>
#include "dispersion.hpp"

template <class clave>
class dispersion_pseudoaleatorio : public func_dispersion<clave> {
	public:
		dispersion_pseudoaleatorio(){};
		virtual ~dispersion_pseudoaleatorio(){};
		int dispersion(clave&, int);
};

template <class clave>
int dispersion_pseudoaleatorio<clave>::dispersion(clave& x, int sz)
{
	srand(int(x.get_value()));
	return rand()%sz;
}