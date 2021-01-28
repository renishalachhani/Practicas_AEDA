#pragma once

template <class clave>
class func_dispersion {
	public:
		func_dispersion(){};
		virtual ~func_dispersion(){};
		virtual int dispersion(clave&, int)=0;
		
};