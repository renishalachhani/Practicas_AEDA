
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>

#include "tablero.hpp"

using namespace std;


int main ()
{
	
	int row = 0;
	int col = 0;
	int cel = -1;

	
	cout << "Tablero:" << endl;
	while ((row*col)<1)
	{
		cout << "N° de filas: ";
		cin >> row;
		
		cout << "N° de columnas: ";
		cin >> col;
		
		if ((row*col)<1)
		{
			cout << "Tablero con dimensiones no válidas. Vuelva introducir datos:" << endl;
		}
	}

	
	tablero* t = new tablero(row, col);

	
	cout << "\nIntroduzca el número de células vivas: ";
	cin >> cel;
	
	while ((cel<0) || (cel>(t->getFilas()*t->getColumnas())))
	{
		if (cel<0){
			cout << "Vuelva introducir número de células vivas: " << endl;
		}
		else
		{
			if (cel>(t->getFilas()*t->getColumnas()))
			{
				cout << "Demasiadas células. " << endl;
			}
		}
		cout << "Vuelva introducir número de células vivas:  ";
		cin >> cel;
		
	}

	if (cel>0)
	{ 
		int tipo1, tipo2, tipo3;
		int m;
		int n;
		bool check;
		
		cout << "\nN° de celulas de tipo 1: ";
		cin >> tipo1;
		
		while ((tipo1<0) || (tipo1>cel))
		{
			cout << "Introduzca un n° valido: ";
			cin >> tipo1;
			
		}
		
		for (int i=1; i<=tipo1; i++)
		{
			check = true;
			while (check)
			{
				cout << "\ncelula 1_" << i << ":" << endl;
				cout << "fila: ";
				cin >> m;
				
				while ((m<1) || (m>t->getFilas()))
				{
					cout << "Fila no válida. Vuelva a introducirlo:  ";
					cin >> m;
					
				}
				cout << "columna: ";
				cin >> n;
				
				while ((n<1) || (n>t->getColumnas()))
				{
					cout << "columna no válida. Vuelva a introducirlo: ";
					cin >> n;
					
				}

				if (!(t->Estado(m, n)==0))
				{
					cout << "celula ocupada. Introducir de nuevo: " << endl;
					
				}
				else
				{
					t->createCelula(1, m, n);
					check = false;
				}
			}
		}

		if ((cel-tipo1)>0)
		{
			cout << "\nN° de celulas de tipo 2: ";
			cin >> tipo2;
			
			while ((tipo2<0) || ((tipo1+tipo2)>cel))
			{
				cout << "Introduzca un n° valido: ";
				cin >> tipo2;
				
			}
			
			for (int i=1; i<=tipo2; i++)
			{
				check = true;
				while (check)
				{
					cout << "\ncelula 2_" << i << ":" << endl;
					cout << "fila: ";
					cin >> m;
					
					while ((m<1) || (m>t->getFilas()))
					{
						cout << "Fila no válida. Vuelva a introducirlo:   ";
						cin >> m;
						
					}
					cout << "columna: ";
					cin >> n;
					
					while ((n<1) || (n>t->getColumnas()))
					{
						cout << "Columna no válida. Vuelva a introducirlo:  ";
						cin >> n;
						
					}

					if (!(t->Estado(m, n)==0))
					{
						cout << "celula ocupada. Introducir de nuevo: " << endl;
					}
					else
					{
						t->createCelula(2,m, n);
						check = false;
					}
				}
			}

			tipo3 = cel - (tipo1 + tipo2);
			if (tipo3>0){
				cout << "\nN° de celulas de tipo 3: " << tipo3 << endl;
				
				for (int i=1; i<=tipo3; i++)
				{
					check = true;
					while (check)
					{
						cout << "\ncelula 3_" << i << ":" << endl;
						cout << "fila: ";
						cin >> m;
						
						while ((m<1) || (m>t->getFilas()))
						{
							cout << "Fila no válida. Vuelva a introducirlo:  ";
							cin >> m;
							
						}
						cout << "columna: ";
						cin >> n;
						
						while ((n<1) || (n>t->getColumnas()))
						{
							cout << "Columna no válida. Vuelva a introducirlo:  ";
							cin >> n;
							
						}

						if (!(t->Estado(m, n)==0))
						{
							cout << "celula ocupada. Introducir de nuevo: " << endl;
						}
						else
						{
							t->createCelula(3,m, n);
							check = false;
						}
					}
				}
			}
			else
			{
				cout << "\nNo hay celulas de tipo C." << endl;
			}
		}
	}

	
	t->mostrar();  

	return 0;
}
