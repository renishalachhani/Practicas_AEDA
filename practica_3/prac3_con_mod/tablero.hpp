#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "celula.hpp"

using namespace std;


class tablero
{
private:
	int filas;  
	int columnas;  
	vector<vector<celula*> > board;  
	int turno; 
	int v;
	  
	bool game_fin;  
	
	void actualizarEstado();
	


public:
	tablero();  
	tablero(int, int);  
	~tablero();  

	int getFilas () const;  
	int getColumnas () const;  
	int Estado(int i, int j) const; 
	
	virtual int contarVecinas(int, int);
	void createCelula(int, int, int);

	void mostrar();

	ostream& write (ostream& os) const; 

	 

};
