
#include <iostream>
#include "dni.hpp"
#include "seguridad.hpp"
#include "insercion.hpp"
#include "burbuja.hpp"
#include "heap_sort.hpp"
#include "quicksort.hpp"
#include "shellsort.hpp"

using namespace std;

int main() {




	int op = 0, vec = 0, mod = 0, which = 0;
	double alfa = 0.0;

	

  		cout << "Tamaño de vector: ";
    		cin >> vec;
    		
    		cout << " 1. Demostración" << endl;
    		cout << " 2. Estadística" << endl;
    		
    		cin >> mod;
		
		cout << " 1. DNI" <<endl;
		cout << " 2. Número Seguridad Social" <<endl;
		cin>>which;


		switch(which){

		    case 1: {

			//MAIN PARA DNIIIII
    			switch(mod){

    				case 1:
    				{
    				

    					

    					Insercion<DNI> insercion(vec);
    					Burbuja<DNI> burbuja(vec);
    					Heap_Sort<DNI> heap_sort(vec);
    					QuickSort<DNI> quicksort(vec);
    					ShellSort<DNI> shellsort(vec);


    						
    						cout << "  Seleccione una opción: " << endl;
    						cout << "  1. Inserción" << endl;
    						cout << "  2. Burbuja" << endl;
    						cout << "  3. Heap Sort" << endl;
    						cout << "  4. QuickSort" << endl;
    						cout << "  5. ShellSort" << endl;
    						
    						cin >> op;
						
						
							

    						switch(op){
    							case 1:
    								{
    									
    									
    										for(int i = 0 ; i < vec ; i++)
    										{
    											DNI d;
    										    insercion.setDato(d, i);
    										}
    									

    									cout << " INSERCIÓN " << endl;
    									insercion.ordenar(1);
    									
    									break;
    								}

    							case 2:
    								{
    									
    									
    										for(int i = 0 ; i < vec ; i++)
    										{
    											DNI d;
    											burbuja.setDato(d, i);
    										}
    									

    									cout <<  " BURBUJA "  << endl;
    									
    									burbuja.ordenar(1);
    									
    									break;
    								}

    							case 3:
    								{
    									
    									
    										for(int i = 0 ; i < vec ; i++)
    										{
    											DNI d;
    											heap_sort.setDato(d, i);
    										}
    									

    									cout << " HEAPSORT " << endl;
    									
    									heap_sort.ordenar(1);
    									
    									break;
    								}

    							case 4:
    								{
    									
    										for(int i = 0 ; i < vec ; i++)
    										{
    											DNI d;
    											quicksort.setDato(d, i);
    										}
    									

    									cout << " QUICKSORT " << endl;
    									
    									quicksort.ordenar(0, vec - 1, 1);
    									
    									break;
    								}

    							case 5:
    								{
    										cout << "Valor de alfa (Entre 0 y 1): ";
    										cin >> alfa;
    									
    										for(int i = 0 ; i < vec ; i++)
    										{
    											DNI d;
    											shellsort.setDato(d, i);
    										}
    									

    									cout << " SHELLSORT " << endl;
    									
    									shellsort.ordenar(alfa, 1);
    									
    									break;
    								}
    						}
    					
    					break;
    				}

    				case 2:
    				{
    					int nPruebas;

    					cout << "Número de pruebas : ";
    					cin >> nPruebas;

    					cout << "Valor de alfa (Entre 0 y 1): ";
    					cin >> alfa;

    					
    					int max_inser = 0, min_inser = 2000000000, suma_inser = 0;
    					int max_bur = 0, min_bur = 2000000000, suma_bur = 0;
    					int max_heap = 0, min_heap = 2000000000, suma_heap= 0;
    					int max_quick = 0, min_quick = 2000000000, suma_quick = 0;
    					int max_shell = 0, min_shell = 2000000000, suma_shell = 0;

    					

    					Insercion<DNI> insercion_est(vec);
    					Burbuja<DNI> burbuja_est(vec);
    					Heap_Sort<DNI> heap_sort_est(vec);
    					QuickSort<DNI> quicksort_est(vec);
    					ShellSort<DNI> shellsort_est(vec);

    					
    					for(int p = 0 ; p < nPruebas ; p++)
    					{
    						
    						for(int i = 0 ; i < vec ; i++)
    						{
        						DNI d;
        						insercion_est.setDato(d.getDni(), i);
        						burbuja_est.setDato(d.getDni(), i);
        						heap_sort_est.setDato(d.getDni(), i);
        						quicksort_est.setDato(d.getDni(), i);
        						shellsort_est.setDato(d.getDni(), i);
    						}

    						
    						insercion_est.ordenar(0);

    						
    						
    							max_inser = insercion_est.getComparaciones();

    						
    						if (insercion_est.getComparaciones() < min_inser)
    							min_inser = insercion_est.getComparaciones();

    						suma_inser += insercion_est.getComparaciones();

    						
    						burbuja_est.ordenar(0);

    						
    						
    							max_bur = burbuja_est.getComparaciones();

    						
    						if (burbuja_est.getComparaciones() < min_bur)
    							min_bur = burbuja_est.getComparaciones();

    						suma_bur += burbuja_est.getComparaciones();

    						
    						heap_sort_est.ordenar(0);

    					
    						
    							max_heap = heap_sort_est.getComparaciones();

    						
    						if (heap_sort_est.getComparaciones() < min_heap)
    							min_heap = heap_sort_est.getComparaciones();

    						suma_heap += heap_sort_est.getComparaciones();

    						
    						quicksort_est.ordenar(0, vec - 1, 0);

    						
    						
    							max_quick = quicksort_est.getComparaciones();

    						
    						if (quicksort_est.getComparaciones() < min_quick)
    							min_quick = quicksort_est.getComparaciones();

    						suma_quick += quicksort_est.getComparaciones();

    						
    						shellsort_est.ordenar(alfa, 0);

    						
    						
    							max_shell = shellsort_est.getComparaciones();

    						
    						if (shellsort_est.getComparaciones() < min_shell)
    							min_shell = shellsort_est.getComparaciones();

    						suma_shell += shellsort_est.getComparaciones();

    						

    					} 


    					cout << endl << setw(40) << " NÚMERO DE COMPARACIONES " << endl;
    					cout << setw(20) << "Mínimo" << setw(9) << "Medio"  << setw(10) << "Máximo" << endl;
    					cout << "INSERCIÓN: " << setw(5) << min_inser  << setw(10) << suma_inser / nPruebas  << setw(10) << max_inser << endl;
    					cout << "BURBUJA  : "  << setw(5) << min_bur    << setw(10) << suma_bur / nPruebas << setw(10) << max_bur << endl;
    					cout << "HEAP SORT: "  << setw(5) << min_heap  << setw(10) << suma_heap / nPruebas  << setw(10) << max_heap << endl;
    					cout << "QUICKSORT: "  << setw(5) << min_quick << setw(10) << suma_quick / nPruebas  << setw(10) << max_quick << endl;
    					cout << "SHELLSORT: "  << setw(5) << min_shell  << setw(10) << suma_shell / nPruebas << setw(10) << max_shell << endl;

    					break;
    				}
    			}
			break; 
		     }

		     case 2: 
		           {

			//MAIN PARA Seguridad social
    			switch(mod){

    				case 1:
    				{
    				

    					

    					Insercion<Seguridad> insercion(vec);
    					Burbuja<Seguridad> burbuja(vec);
    					Heap_Sort<Seguridad> heap_sort(vec);
    					QuickSort<Seguridad> quicksort(vec);
    					ShellSort<Seguridad> shellsort(vec);


    						
    						cout << "  Seleccione una opción: " << endl;
    						cout << "  1. Inserción" << endl;
    						cout << "  2. Burbuja" << endl;
    						cout << "  3. Heap Sort" << endl;
    						cout << "  4. QuickSort" << endl;
    						cout << "  5. ShellSort" << endl;
    						
    						cin >> op;
						
						
							

    						switch(op){
    							case 1:
    								{
    									
    									
    										for(int i = 0 ; i < vec ; i++)
    										{
    											Seguridad d;
    										    insercion.setDato(d, i);
    										}
    									

    									cout << " INSERCIÓN " << endl;
    									insercion.ordenar(1);
    									
    									break;
    								}

    							case 2:
    								{
    									
    									
    										for(int i = 0 ; i < vec ; i++)
    										{
    											Seguridad d;
    											burbuja.setDato(d, i);
    										}
    									

    									cout <<  " BURBUJA "  << endl;
    									
    									burbuja.ordenar(1);
    									
    									break;
    								}

    							case 3:
    								{
    									
    									
    										for(int i = 0 ; i < vec ; i++)
    										{
    											Seguridad d;
    											heap_sort.setDato(d, i);
    										}
    									

    									cout << " HEAPSORT " << endl;
    									
    									heap_sort.ordenar(1);
    									
    									break;
    								}

    							case 4:
    								{
    									
    										for(int i = 0 ; i < vec ; i++)
    										{
    											Seguridad d;
    											quicksort.setDato(d, i);
    										}
    									

    									cout << " QUICKSORT " << endl;
    									
    									quicksort.ordenar(0, vec - 1, 1);
    									
    									break;
    								}

    							case 5:
    								{
    										cout << "Valor de alfa (Entre 0 y 1): ";
    										cin >> alfa;
    									
    										for(int i = 0 ; i < vec ; i++)
    										{
    											Seguridad d;
    											shellsort.setDato(d, i);
    										}
    									

    									cout << " SHELLSORT " << endl;
    									
    									shellsort.ordenar(alfa, 1);
    									
    									break;
    								}
    						}
    					
    					break;
    				}

    				case 2:
    				{
    					int nPruebas;

    					cout << "Número de pruebas : ";
    					cin >> nPruebas;

    					cout << "Valor de alfa (Entre 0 y 1): ";
    					cin >> alfa;

    					
    					int max_inser = 0, min_inser = 2000000000, suma_inser = 0;
    					int max_bur = 0, min_bur = 2000000000, suma_bur = 0;
    					int max_heap = 0, min_heap = 2000000000, suma_heap= 0;
    					int max_quick = 0, min_quick = 2000000000, suma_quick = 0;
    					int max_shell = 0, min_shell = 2000000000, suma_shell = 0;

    					

    					Insercion<Seguridad> insercion_est(vec);
    					Burbuja<Seguridad> burbuja_est(vec);
    					Heap_Sort<Seguridad> heap_sort_est(vec);
    					QuickSort<Seguridad> quicksort_est(vec);
    					ShellSort<Seguridad> shellsort_est(vec);

    					
    					for(int p = 0 ; p < nPruebas ; p++)
    					{
    						
    						for(int i = 0 ; i < vec ; i++)
    						{
        						Seguridad d;
        						insercion_est.setDato(d.getSegNum(), i);
        						burbuja_est.setDato(d.getSegNum(), i);
        						heap_sort_est.setDato(d.getSegNum(), i);
        						quicksort_est.setDato(d.getSegNum(), i);
        						shellsort_est.setDato(d.getSegNum(), i);
    						}

    						
    						insercion_est.ordenar(0);

    						
    						
    							max_inser = insercion_est.getComparaciones();

    						
    						if (insercion_est.getComparaciones() < min_inser)
    							min_inser = insercion_est.getComparaciones();

    						suma_inser += insercion_est.getComparaciones();

    						
    						burbuja_est.ordenar(0);

    						
    						
    							max_bur = burbuja_est.getComparaciones();

    						
    						if (burbuja_est.getComparaciones() < min_bur)
    							min_bur = burbuja_est.getComparaciones();

    						suma_bur += burbuja_est.getComparaciones();

    						
    						heap_sort_est.ordenar(0);

    					
    						
    							max_heap = heap_sort_est.getComparaciones();

    						
    						if (heap_sort_est.getComparaciones() < min_heap)
    							min_heap = heap_sort_est.getComparaciones();

    						suma_heap += heap_sort_est.getComparaciones();

    						
    						quicksort_est.ordenar(0, vec - 1, 0);

    						
    						
    							max_quick = quicksort_est.getComparaciones();

    						
    						if (quicksort_est.getComparaciones() < min_quick)
    							min_quick = quicksort_est.getComparaciones();

    						suma_quick += quicksort_est.getComparaciones();

    						
    						shellsort_est.ordenar(alfa, 0);

    						
    						
    							max_shell = shellsort_est.getComparaciones();

    						
    						if (shellsort_est.getComparaciones() < min_shell)
    							min_shell = shellsort_est.getComparaciones();

    						suma_shell += shellsort_est.getComparaciones();

    						

    					} 


    					cout << endl << setw(40) << " NÚMERO DE COMPARACIONES " << endl;
    					cout << setw(20) << "Mínimo" << setw(9) << "Medio"  << setw(10) << "Máximo" << endl;
    					cout << "INSERCIÓN: " << setw(5) << min_inser  << setw(10) << suma_inser / nPruebas  << setw(10) << max_inser << endl;
    					cout << "BURBUJA  : "  << setw(5) << min_bur    << setw(10) << suma_bur / nPruebas << setw(10) << max_bur << endl;
    					cout << "HEAP SORT: "  << setw(5) << min_heap  << setw(10) << suma_heap / nPruebas  << setw(10) << max_heap << endl;
    					cout << "QUICKSORT: "  << setw(5) << min_quick << setw(10) << suma_quick / nPruebas  << setw(10) << max_quick << endl;
    					cout << "SHELLSORT: "  << setw(5) << min_shell  << setw(10) << suma_shell / nPruebas << setw(10) << max_shell << endl;

    					break;
    				}
    			}
			break;
		    }
	}


	return 0;
}
