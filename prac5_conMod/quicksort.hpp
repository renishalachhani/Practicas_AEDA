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
class QuickSort{
	private:
		int vec;
		int comp;
		Clave* datos;

	public:
		
		QuickSort(int);

		
		~QuickSort();

		
		void setDato(Clave , int );
		
		void ordenar (int , int , int);
		
		int getComparaciones();
};

template <class Clave>
QuickSort<Clave>::QuickSort(int tam)
{
	vec =tam;
	comp = 0;
	datos = new Clave[vec];
}

template <class Clave>
QuickSort<Clave>::~QuickSort(){}

template <class Clave>
void QuickSort<Clave>::setDato(Clave dato, int pos)
{
	datos[pos] = dato;
}

template <class Clave>
void QuickSort<Clave>::ordenar(int i, int f, int show)
{
	int ini = i, fin = f;
	Clave piv = datos[(ini + fin) / 2];
	while (ini <= fin)
	{
		while (datos[ini] < piv)
		{
			ini++;

			
			comp++;
		}

		while (datos[fin] > piv)
		{
			fin--;

			
			comp++;
		}

		if (ini <= fin)
		{
			Clave x = datos[ini];
			datos[ini] = datos[fin];
			datos[fin] = x;
			ini++;
			fin--;

			
			comp++;

			
			if (show == 1)
			{
				cout << endl << "pivote: " << piv << endl;
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

	if (i < fin)
	{
		ordenar(i, fin, show);

		
		comp++;
	}

	if (ini < f)
	{
		ordenar(ini, f, show);

		
		comp++;
	}
}


template <class Clave>
int QuickSort<Clave>::getComparaciones()
{
	return comp;
}
