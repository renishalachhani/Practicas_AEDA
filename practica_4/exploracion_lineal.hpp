#pragma once

#include "exploracion.hpp"

class exploracion_lineal : public func_exploracion {
	public:
		exploracion_lineal(){};
		virtual ~exploracion_lineal(){};
		int exploracion(int x, int att, int nCeldas)
		{
			return ((x+att)%nCeldas);
		}
};
