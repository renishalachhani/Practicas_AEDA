#include "celula.hpp"
#include "tablero.hpp"

#include <cstdlib>
#include <fstream>

using namespace std;




int main ()
{
	
	

	int row = 0;
	int col = 0;
	int cel = 0;

	
	cout << "Tablero:" << endl;
	while ((row*col)<1){
		cout << "N° de filas: ";
		cin >> row;
		
		cout << "N° de columnas: ";
		cin >> col;
		
		if ((row*col)<1){
			cout << "Tablero con dimensiones no válidas. Vuelva introducir datos:" << endl;
			
		}
	}

	

	tablero* t = new tablero(row, col);
	

	
	cout << "\nIntroduzca el número de células vivas: ";
	cin >> cel;
	

   
	while ((cel<0) || (cel>(row*col))){
		if (cel<0)
			cout << "Vuelva introducir número de células vivas: " << endl;
		else
			if (cel>(row*col))
				cout << "Demasiadas células. " << endl;
		cout << "Vuelva introducir número de células vivas:  ";
		cin >> cel;
		
	}
	
	if(cel>0){  
		int m,n;
		
		cout << "\nIntroduzca coordenadas de celulas vivas:" << endl;
		for (int i=1; i<=cel; i++){
			bool check = true;
			while(check){

				cout << "\nCelula " << i << ":" << endl;
				cout << "fila: ";
				cin >> m;
				
				while ((m<0) || (m>=row)){
					cout << "Fila no válida. Vuelva a introducirlo: ";
					cin >> m;
					
				}
				cout << "columna: ";
				cin >> n;
				
				while ((n<0) || (n>=col)){
					cout << "Columna no válida. Vuelva a introducirlo: ";
					cin >> n;
					
				}
				if (t->viva(m, n)){
					cout << "Celula viva. Introducir de nuevo:" << endl;
					
				}
				else{
					t->setViva(m, n);
					check=false;
				}
			}
		}
	}




	t->ejecutar();  

	return 0;
}
