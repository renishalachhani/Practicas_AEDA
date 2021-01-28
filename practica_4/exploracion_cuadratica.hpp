#pragma once

#include <cmath>
#include "exploracion.hpp"

class exploracion_cuadratica : public func_exploracion {
	public:
		exploracion_cuadratica(){};
		virtual ~exploracion_cuadratica(){};
		int exploracion(int x, int att, int nCeldas)
		{
			return (int(x+pow(att,2))%int(nCeldas));
		}

};
