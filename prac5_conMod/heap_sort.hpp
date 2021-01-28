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
class Heap_Sort{
	private:
		int vec;
		int comp;
		Clave* datos;

	public:
		
		Heap_Sort(int);

		
		~Heap_Sort();

		
		void setDato(Clave , int );
		void baja (int , int );
		void ordenar (int);
		
		int getComparaciones();
};

template <class Clave>
Heap_Sort<Clave>::Heap_Sort(int tam)
{
	vec =tam;
	comp = 0;
	datos = new Clave[vec];
}

template <class Clave>
Heap_Sort<Clave>::~Heap_Sort(){}

template <class Clave>
void Heap_Sort<Clave>::setDato(Clave dato, int pos)
{
	datos[pos] = dato;
}

template <class Clave>
void Heap_Sort<Clave>::baja (int pos, int n)
{
	int x = 0, h = 0;
	x = datos[pos];
	while (2 * pos <= n)
	{
		int h1 = 2 * pos;
		int h2 = h1 +1;

		if (h1 == n)
		{
			h = h1;

			
			comp++;
		}
		else if (datos[h1] > datos[h2])
		{

			h = h1;

			
			comp++;
		}
		else
		{
			h = h2;

			
			comp++;
		}

		if (datos[h] <= x)
		{
			
			comp++;

			break;
		}
		else
		{
			datos[pos] = datos[h];
			datos[h] = x;
			pos = h;

			
			comp++;

		}
	}
}

template <class Clave>
void Heap_Sort<Clave>::ordenar(int show)
{
	for (int i = (vec / 2) - 1; i >= 0; i--)
	{

		baja(i, vec);

		
		if (show == 1)
		{
			cout << endl << " insercion: ";
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

	for (int i = vec - 1; i > 0; i--)
	{

		int x = datos[0];
		datos[0] = datos[i];
		datos[i] = x;
		baja(0, i-1);

		if (show == 1)
		{
			cout << endl << " extraccion: ";
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
int Heap_Sort<Clave>::getComparaciones()
{
	return comp;
}
