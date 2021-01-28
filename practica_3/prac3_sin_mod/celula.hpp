#ifndef CELULA_HPP_
#define CELULA_HPP_

#include <iostream>



using namespace std;



class celula
{
	private:
		int estado;  
		int vecinos;  

	public:
		celula();  
		celula(int);  
		  
		int getVecinos() const;  
		void setVivoVecino(int); 
		virtual ~celula();  

		virtual int getEstado() const; 
	
		virtual int actualizarEstado();  
		virtual ostream& mostrar(ostream& os) const; 
};

#endif
