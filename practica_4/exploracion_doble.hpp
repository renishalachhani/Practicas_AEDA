#pragma once

#include "exploracion.hpp"
#include <iostream>

class exploracion_doble : public func_exploracion {
	private:
		int primo(int n)
		{
			int max;
			bool primo;
			for(int i=n-1;i>2;i--)
			{
				primo=true;
				for(int j=2;j<i;j++)
				{
					if(!(i%j))
						primo=false;
					max=i;
				}
				if(primo)
				return max;
			}
		}

	public:
		exploracion_doble(){};
		virtual ~exploracion_doble(){};
		int exploracion(int x, int att, int nCeldas)
		{
			int p=primo(nCeldas);
			int h=p-x%p;
			return ((x+att*(h))%nCeldas);
		}
};
