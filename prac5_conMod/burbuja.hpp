#pragma once
#include <iostream>
#include <cstdio>
#include <stdlib.h>     
#include <time.h>       
#include <iomanip>
#include <stdint.h>
#include <vector>
#include <cstdlib>
#include <string>



using namespace std;

template <class Clave>
class Burbuja{
	private:
		int vec;
		int comp;
		Clave 	*datos;

	public:
		
		Burbuja(int );

		
		~Burbuja();

		
		void setDato(Clave , int );
		void ordenar (int);
		
		int getComparaciones ();
};

template <class Clave>
Burbuja<Clave>::Burbuja(int tam)
{
	vec = tam;
	comp = 0;
	datos = new Clave[vec];
}

template <class Clave>
Burbuja<Clave>::~Burbuja(){}

template <class Clave>
void Burbuja<Clave>::setDato(Clave dato, int pos)
{
	datos[pos] = dato;
}

template <class Clave>
void Burbuja<Clave>::ordenar(int show)
{
	

	int bur, aux;

	for (int i = 1; i < vec; i++){
		for (int j = vec -1; j >= i; j--){
			bur = datos[j-1];
			if (datos[j] < datos[j-1]) {
				bur = datos[j];
				aux = datos[j-1];
				datos[j-1] = datos[j];
				datos[j] = aux;

				
				comp++;

				if (show == 1)
				{
					cout << endl << "Iter: " << i << endl;
					cout << bur << " se cambia por " << aux << endl;
					for (int i = 0; i < vec; i++)
					{
						cout << datos[i] << ", ";
					}
					cout << endl;
					
					string t;
					getline(cin,t);
				}
				
			}
		}
	}
}


template <class Clave>
int Burbuja<Clave>::getComparaciones()
{
	return comp;
}
