#pragma once

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include "tabla.hpp"



class experimento {
	
	private:
		char h_;
		char g_;
		int nCeldas;
		int nclave;
		double factor;
		int nPruebas;
		int N;
		int comp_[2];
	
		dni** banco_;
		tabla<dni>* tabla_;
	public:
		experimento();
		~experimento();
		
		void inicializar();
		void reiniciar();
		void cargar_datos();
		void prueba_inserciones();
		void prueba_busqueda();
		
		void presentar_resultados();
		
	private:
		bool primo(int);
		int primo_cercano(int);
};
