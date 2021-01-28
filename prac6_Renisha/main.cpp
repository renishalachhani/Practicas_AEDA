#include <climits>
#include <vector>
#include <ctime>
#include <map>

using namespace std;

#include "mod.hpp"
mod MODO;  
int contador;  
#include "dni.hpp"
#include "ABB.hpp"


struct estadisticas_t {
    int min = INT_MAX;
    int med = 0;
    int max = INT_MIN;
};

int main (void)
{
    int opcion = 0; 

   
    while (opcion != 3){ 
        cout << endl;
     
        cout << "\t1. Modo demostracion" << endl;
        cout << "\t2. Modo estadistico" << endl;
      
        cin >> opcion;
        cout << endl;

       
        switch (opcion){
            case 1:{  
                MODO = demostracion; 
                ABB<dni> abb; 
               
                cout << endl;

                int opcion_demo = 0;
               
                while (opcion_demo != 3){  
                    cout << endl;
                   
                    cout << "\t1. Insertar clave" << endl;
                    cout << "\t2. Eliminar clave" << endl;
                    cout << "\t3. Salir" << endl;
                   
                    cin >> opcion_demo;
                    cout << endl;

                   
                    switch (opcion_demo){
                        case 1:{  
                            char DNI[8];  
                            cout << "Introduzca la clave: ";
                            cin >> DNI;
                            dni aux(DNI); 
                            abb.insertar(aux);  
                            cout << endl;
                            abb.write(cout); 
                            cout << endl;
                            break;
                        }
                        case 2:{  
                            char DNI[8];  
                            cout << "Introduzca la clave a eliminar: ";
                            cin >> DNI;
                            dni aux(DNI);  
                            abb.eliminar(aux);  
                            cout << endl;
                            abb.write(cout);  
                            cout << endl;
                            break;
                        }
                        case 3:{  exit(1);
                            break;
                        }
                        default:{  
                            cerr << "OPCION INCORRECTA!" << endl;
                        }
                    }
                }
                break;
            }
            case 2:{  
                MODO = estadistico;  
                srand(time(NULL));  
                int N;  
                int nPruebas;  
                int med_aux = 0; 
                char DNI[8];  
                bool iguales; 
                vector<int> pos; 
                vector<dni> banco_pruebas; 
                ABB<dni> abb; 
                estadisticas_t estadist_busq; 
                estadisticas_t estadist_inse; 
                
                cout << "\nTamaño del arbol: ";
                cin >> N;
                cout << "Numero de pruebas: ";
                cin >> nPruebas;
              

                banco_pruebas.clear();
                banco_pruebas.resize(2*N);  
                for (int i=0; i<banco_pruebas.size(); i++){
                    iguales = true;
                    while (iguales){
                        for (int j=0; j<4; j++){
                            DNI[j] = rand() % 10 + 48;
                        }

                        for (int j=4; j<7; j++){
                            DNI[j] = rand() % 26 + 65;
                        }
                        dni aux(DNI);  

                        iguales = false;
                        int j = 0;
                        while ((j<i) && (!iguales)){ 
                            if (aux == banco_pruebas[j]){
                                iguales = true;
                            }
                            j ++;
                        }

                        if (!iguales){
                            banco_pruebas[i] = aux;
                        }
                    }
                }

                for (int i=0; i<N; i++){
                    abb.insertar(banco_pruebas[i]);
                }

                med_aux = 0;  
                pos.clear();  
                pos.resize(nPruebas);  
                for (int i=0; i<nPruebas; i++){
                    contador = 0;  
                    iguales = true;
                    while (iguales){
                        pos[i] = rand() % N; 

                        iguales = false;
                        int j = 0;
                        while ((j<i) && (!iguales)){  
                            if (pos[i] == pos[j]){
                                iguales = true;
                            }
                            j ++;
                        }
                    }

                    abb.buscar(banco_pruebas[pos[i]]); 
                    if (contador < estadist_busq.min){
                        estadist_busq.min = contador;
                    }
                    if (contador > estadist_busq.max){
                        estadist_busq.max = contador;
                    }
                    med_aux += contador;
                }
                estadist_busq.med = med_aux / nPruebas;  
                
                med_aux = 0;  
                pos.clear();  
                pos.resize(nPruebas);  
                for (int i=0; i<nPruebas; i++){
                    contador = 0;  
                    iguales = true;
                    while (iguales){
                        pos[i] = rand() % N + N;  

                        iguales = false;
                        int j = 0;
                        while ((j<i) && (!iguales)){  
                            if (pos[i] == pos[j]){
                                iguales = true;
                            }
                            j ++;
                        }
                    }

                    abb.buscar(banco_pruebas[pos[i]]); 
                    if (contador < estadist_inse.min){
                        estadist_inse.min = contador;
                    }
                    if (contador > estadist_inse.max){
                        estadist_inse.max = contador;
                    }
                    med_aux += contador; 
                }
                estadist_inse.med = med_aux / nPruebas; 


		cout << "        " << "              " <<" Número de Comparaciones"<<endl;

                cout << "        " << "           " << "N" << "       " << "Pruebas" << "      " << "MINIMO" << "      " << "MEDIO" << "      " << "MAXIMO" << endl;

                cout <<"Busqueda" << "           " << N << "         " << nPruebas << "          " << estadist_busq.min << "          " << estadist_busq.med << "          " << estadist_busq.max << endl;

                cout <<"Insercion" << "          " << N << "         " << nPruebas << "          " << estadist_inse.min << "          " << estadist_inse.med << "          " << estadist_inse.max << endl;
                cout << endl;
                exit(1);
                break;
            }
            default:{ 
                cerr << "OPCION INCORRECTA!" << endl;
            }
        }
    }

    return 0;
}
