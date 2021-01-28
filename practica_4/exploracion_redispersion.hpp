#pragma once

#include <cstdlib>
#include "exploracion.hpp"

class exploracion_redispersion : public func_exploracion {
	public:
		exploracion_redispersion(){};
		virtual ~exploracion_redispersion(){};
		int exploracion(int x, int att, int nCeldas)
		{
			return ((rand()+att)%nCeldas);
		}
};
