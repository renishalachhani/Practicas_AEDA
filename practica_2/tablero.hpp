#ifndef TABLERO_HPP_
#define TABLERO_HPP_

using namespace std;

#include "celula.hpp"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>


class tablero
{
	private:
	
	 	int filas;  
	 	int columnas;  
	 	int v;
		vector<vector<celula > > board;  
		int turno;  
	
		bool game_fin; 
		int cambiado;

		void  actualizarEstado();  

		ostream& write (ostream& os); 
	

	public:

	
		tablero();
		tablero (int , int );  
		~tablero ();  

	

		void setViva (int, int);  
		void setMuerta (int, int);  

	
		int contarVecinas(int,int);
		bool viva (int, int);  

		void ejecutar ();  
	
 
};

#endif
