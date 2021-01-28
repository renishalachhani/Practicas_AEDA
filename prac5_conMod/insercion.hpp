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
class Insercion{
	private:
		int vec;
		int comp;
		Clave 	*datos;

	public:
		
		Insercion(int );

		
		~Insercion();

		
		void setDato(Clave , int );
		void ordenar (int );
		
		int getComparaciones ();
};

template <class Clave>
Insercion<Clave>::Insercion(int tam)
{
	vec = tam;
	comp = 0;
	datos = new Clave[vec];

}

template <class Clave>
Insercion<Clave>::~Insercion(){}

template <class Clave>
void Insercion<Clave>::setDato(Clave dato, int pos)
{
	datos[pos] = dato;
}

template <class Clave>
void Insercion<Clave>::ordenar(int show)
{
	int pos;

	for (int i = 0; i < vec; i++){
		pos = i;
		Clave aux = datos[i];
		while ((pos > 0) && (aux < datos[pos-1]))
		{
			datos[pos] = datos[pos-1];
			pos--;

			
			comp++;
		}
		datos[pos] = aux;

		
		if (show == 1 )
		{
			cout << endl << " Iter: " << i << endl;
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



template <class Clave>
int Insercion<Clave>::getComparaciones()
{
	return comp;
}
