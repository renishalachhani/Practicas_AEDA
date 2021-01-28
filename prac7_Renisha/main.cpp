#include <iostream>
#include <cstring>
#include "nodoAVL.h"
#include "arbolAVL.h"
#include "dni.h"
#include <cstdlib>
#include <vector>
using namespace std;


int main ()
{
	int opt,op;
	int N,pruebas;
	int k;
	arbolAVL<int> Tree;

	cout<<"1. Modo Demostración"<<endl;
	cout<<" 2. Modo Estadística"<<endl;
	cin>>op;
	switch(op){
		
	case 1:
	do
	{
		cout<<"Traza de AVL, Renisha Lachhani Punjbai"<<endl;
		cout<<"1.Insertar clave"<<endl;
		cout<<"2. Eliminar clave"<<endl;
		cout<<"3. Salir"<<endl;
		cin>> opt;
		
		switch(opt)
		{
			case 1:
				cout<<"Introducir clave: ";
				cin>> k;
				Tree.insertar(k);
				Tree.recorreN(Tree.get_root());
			break;
			
			case 2:
				cout<<"Introducir clave: ";
				cin>> k;
				Tree.eliminar(k);
				Tree.recorreN(Tree.get_root());
			break;
			
			case 3:
			exit(1);
			break;
		}
		
	}while(opt!='s');
	break;
	case 2:
	arbolAVL<DNI> ArbolInt;
       cout<<"Tamaño del arbol\n";
    cin>>N;

    cout<<" Numero de pruebas \n";
    cin>>pruebas;

    int medio,maximo,minimo;
    
    vector<DNI> banco;

    banco.resize(2*N);

    //cout<<"hey"<<endl;






    for(int i=0; i<N;i++){
	//cout<<banco.at(i)<<endl;
        ArbolInt.insertar(banco.at(i));
	}

//cout<<"hey"<<endl;
 



    medio=maximo=minimo=0;
    banco.at(0).cero();
       

    for(int i=0;i<N;i++){


        ArbolInt.buscar(banco.at(i));

        if(i==0){

            minimo=maximo=banco.at(0).cont;

        }

        medio+=banco.at(i).cont;

        if (minimo>banco.at(i).cont)
            minimo=banco.at(i).cont;

        if (maximo<banco.at(i).cont)
            maximo=banco.at(i).cont;

        banco.at(0).cero();
    }
    
    
    medio=medio/N;

    cout<<"                       Numero de comparaciones     "<<endl;
    cout<<"                 Minimo          Medio            Maximo"<<endl;
    cout<<" Busqueda        "<<minimo<<"                 "<<medio<<"               "<<maximo<<endl;


    medio=maximo=minimo=0;
    banco.at(0).cero();
    for(int i=N;i<banco.size();i++){


        ArbolInt.buscar(banco.at(i));


        if(i==N){

            minimo=maximo=banco.at(0).cont;

        }

        medio+=banco.at(0).cont;

        if (minimo>banco.at(0).cont)
            minimo=banco.at(0).cont;

        if (maximo<banco.at(0).cont)
            maximo=banco.at(0).cont;

        banco.at(0).cero();
    }


    medio=medio/N;



    cout<<" Insercion       "<<minimo<<"                "<<medio<<"               "<<maximo<<endl;






                
                break;
}
	
}
