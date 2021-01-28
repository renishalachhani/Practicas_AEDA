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
class ShellSort{
	private:
		int vec;
		int comp;
		Clave* datos;

	public:
		
		ShellSort(int);

		
		~ShellSort();

		
		void setDato(Clave, int );
		
		void ordenar (double , int);
		void deltasort(int , int );
		
		int getComparaciones ();
};

template <class Clave>
ShellSort<Clave>::ShellSort(int tam)
{
	vec =tam;
	comp = 0;
	datos = new Clave[vec];
}

template <class Clave>
ShellSort<Clave>::~ShellSort(){}

template <class Clave>
void ShellSort<Clave>::setDato(Clave dato, int pos)
{
	datos[pos] = dato;
}

template <class Clave>
void ShellSort<Clave>::ordenar(double alfa, int show)
{
	int delta = alfa * vec;

	while (delta >= 1)
	{
		
		comp++;

		
		if (show == 1)
			cout << endl << "Delta: " << delta << endl;
		

		deltasort(delta, show);
		delta = delta / 2;
	}
}

template <class Clave>
void ShellSort<Clave>::deltasort(int delta, int show)
{
	for (int i = delta; i < vec; i++)
	{
		Clave x = datos[i];
		int j = i;

		
		if (show == 1)
		{
			cout << "Subsecuencia " << i << ": " << endl;
			cout << "posición " << i <<" : "<<  datos[i] << endl;
			cout << " posición " << j - delta << " : " << datos[j - delta] << endl;
			
				for (int i = 0; i < vec; i++)
				{
					cout << datos[i] << ", ";
				}
				cout << endl;
			
			string t;
			getline(cin,t);
		}
		

		while ((j >= delta) && (x < datos[j - delta]))
		{
			datos[j] = datos[j - delta];
			j = j - delta;

			
			comp++;
		}

		datos[j] = x;
	}
}



template <class Clave>
int ShellSort<Clave>::getComparaciones()
{
	return comp;
}
