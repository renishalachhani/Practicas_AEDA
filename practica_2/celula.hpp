#ifndef CELULA_HPP_
#define CELULA_HPP_


#include <iostream>

using namespace std;


class celula
{
	private:
		int estado;  
		int next_estado; 

	public:
		celula ();  
		celula (int);  
		~celula ();  

		int getEstado () const;  
		int setEstado (int );  

		int getNextEstado () const;  
		void setNextEstado (int);  

	
};

#endif
