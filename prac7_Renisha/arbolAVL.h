#pragma once

#include <iostream>
#include "nodoAVL.h"
#include "dni.h"
#include <queue>

using namespace std;

template <class Clave>
class arbolAVL{
	private:
		nodoAVL<Clave> *root_;
		
	public:

		inline arbolAVL(nodoAVL<Clave>  *raiz=NULL): root_(raiz) {}
		inline~arbolAVL() {podar(root_);}
		
		void podar(nodoAVL<Clave>* nodo);
		inline nodoAVL<Clave>* get_raiz() {return root_;}
		inline nodoAVL<Clave>* get_root() {return root_;};

		inline bool es_vacio() {return root_==NULL;}
		inline bool es_hoja(nodoAVL<Clave> *nodo) {return !nodo->get_dcho() && !nodo->get_izq();}
		
		void pre_orden(nodoAVL<Clave> *nodo);
		void post_orden(nodoAVL<Clave> *nodo);
		void in_orden(nodoAVL<Clave> *nodo);


		inline void imprimir_dato(nodoAVL<Clave>* nodo) {cout<<nodo->get_clave();}
		void imprimir(nodoAVL<Clave> *nodo, int nivel);
		
		void recorreN(nodoAVL<Clave> *raiz);

		void insertar(Clave clave_dada);
		void insertar_bal(nodoAVL<Clave>* &nodo,nodoAVL<Clave>* nuevo, bool& crece);


		nodoAVL<Clave>* buscar(Clave clave_dada);
		nodoAVL<Clave>* buscarRama(nodoAVL<Clave>* nodo,Clave clave_dada);

		void eliminar(Clave clave_dada);
		void eliminarRama(nodoAVL<Clave>* &nodo, Clave clave_dada, bool& decrece);

		void sustituye(nodoAVL<Clave>* &eliminado,nodoAVL<Clave>* &sust,bool &decrece);
		
		void insert_re_balancea_izda(nodoAVL<Clave>* &nodo,bool& crece);
		void insert_re_balancea_dcha(nodoAVL<Clave>* &nodo,bool& crece);
		void eliminar_re_balancea_izda(nodoAVL<Clave>* &nodo,bool& decrece);
		void eliminar_re_balancea_dcha(nodoAVL<Clave>* &nodo,bool& decrece);

		void rotacion_II(nodoAVL<Clave>* &nodo);
		void rotacion_ID(nodoAVL<Clave>* &nodo);
		void rotacion_DI(nodoAVL<Clave>* &nodo);
		void rotacion_DD(nodoAVL<Clave>* &nodo);


};

template<class Clave>
struct NIV
{
		nodoAVL<Clave>* node=NULL;
		int niv;
};

int aux=-1;

template<class Clave>
void arbolAVL<Clave>:: podar(nodoAVL<Clave>* nodo)
{
	if(nodo==NULL) return;
	podar(nodo->get_izq());
	podar(nodo->get_dcho());
	delete nodo;
	nodo=NULL;
}

template <class Clave>
void arbolAVL<Clave>::pre_orden(nodoAVL<Clave> *nodo)
{
	if (nodo == NULL) return;
	imprimir_dato(nodo);
	cout<<"\t";
	pre_orden(nodo->get_izq());
	pre_orden(nodo->get_dcho());
}

template <class Clave>
void arbolAVL<Clave>::in_orden(nodoAVL<Clave> *nodo)
{
	if (nodo == NULL) return;
	in_orden(nodo->get_izq());
	imprimir_dato(nodo);
	cout<<"\t";
	in_orden(nodo->get_dcho());
}

template <class Clave>
void arbolAVL<Clave>:: post_orden(nodoAVL<Clave> *nodo)
{ 
	if (nodo == NULL) return;
	post_orden(nodo->get_izq());
	post_orden(nodo->get_dcho());
	imprimir_dato(nodo);
	cout<<"\t";
}

template <class Clave>
void arbolAVL<Clave>:: insertar(Clave clave_dada)
{    

	nodoAVL<Clave>* nuevo= new nodoAVL<Clave>(clave_dada,NULL,NULL);
	    

	bool crece=false;
	   

	insertar_bal(root_,nuevo,crece);
	

}

template<class Clave>
nodoAVL<Clave>* arbolAVL<Clave>::buscar(Clave clave_dada)
{
	
	return buscarRama(root_,clave_dada);
	
	
}

template<class Clave>
nodoAVL<Clave>* arbolAVL<Clave>::buscarRama(nodoAVL<Clave>* nodo, Clave clave_dada)
{

	if(nodo==NULL){
		
	
		return NULL;}
	if(clave_dada==nodo->get_clave()){
		
		return nodo;}
	if(clave_dada <nodo->get_clave()){
		
		return buscarRama(nodo->get_izq(),clave_dada);}
		
	return buscarRama(nodo->get_dcho(),clave_dada);
}

template <class Clave>
void arbolAVL<Clave>::recorreN(nodoAVL<Clave> *raiz)
{

	NIV<Clave> raizS;
	NIV<Clave> nodoS;
	NIV<Clave> naux;

	raizS.node=raiz;
	raizS.niv=0;	
	queue<NIV <Clave> > Q;
	int nivel_actual=0;
	Q.push(raizS); 

	while(!Q.empty())
	{
		nodoS=Q.front();
		Q.pop();
		if(nodoS.niv > nivel_actual)
			nivel_actual=nodoS.niv;
		if(nodoS.node!= NULL)
		{

			imprimir(nodoS.node,nivel_actual);

			naux.niv=nodoS.niv;
			naux.node=nodoS.node->get_izq();
			naux.niv=naux.niv+1;			
			Q.push(naux);

			naux.node=nodoS.node->get_dcho();
			Q.push(naux);
		}
		else 
		{
			imprimir(nodoS.node,nivel_actual);
		}
	}
	aux=-1;
	cout<<endl;
}

template<class Clave>
void arbolAVL<Clave>:: imprimir(nodoAVL<Clave> *nodo, int nivel)
{
	
	if(root_==NULL)
	{
		cout<<"Arbol vacio"<<endl;
		cout<<"Nivel 0: [.]"<<endl;
	}
	else
	{
		if(nivel>aux)
		{ 
			cout<<endl;
			cout<<"Nivel "<<nivel<<": ";
			if(nodo==NULL)
				cout<<"[.]";
			else
			{
				cout<<"[";
				cout<<nodo->get_clave();
				cout<<"]";
			}			
		}
		else 
		{
			if(nodo==NULL)
				cout<<"[.]";
			else
			{
				cout<<"[";
				cout<<nodo->get_clave();
				cout<<"]";
			}
		}

	}	
	aux=nivel;
}

template <class Clave>
void arbolAVL<Clave>::eliminar(Clave clave_dada)
{
	bool decrece=false;
	eliminarRama(root_,clave_dada,decrece);
}

template<class Clave>
void arbolAVL<Clave>::rotacion_II(nodoAVL<Clave>* &nodo)
{
	nodoAVL<Clave>* nodo1=nodo->get_izq();
	nodo->set_izq(nodo1->get_dcho());
	nodo1->set_dcho(nodo);
	if(nodo1->get_bal()==1)
	{
		nodo->set_bal(0);
		nodo1->set_bal(0);
	}
	else
	{
		nodo->set_bal(1);
		nodo1->set_bal(-1);
	}
	nodo=nodo1;
}

template<class Clave>
void arbolAVL<Clave>::rotacion_DD(nodoAVL<Clave>* &nodo)
{
	nodoAVL<Clave>* nodo1=nodo->get_dcho();
	nodo->set_dcho(nodo1->get_izq());
	nodo1->set_izq(nodo);
	if(nodo1->get_bal()==1)
	{
		nodo->set_bal(0);
		nodo1->set_bal(0);
	}
	else
	{
		nodo->set_bal(-1);
		nodo1->set_bal(1);
	}
	nodo=nodo1;
}

template<class Clave>
void arbolAVL<Clave>:: rotacion_ID(nodoAVL<Clave>* &nodo)
{
	nodoAVL<Clave>* nodo1 =nodo->get_izq();
	nodoAVL<Clave>* nodo2=nodo1->get_dcho();
	nodo->set_izq(nodo2->get_dcho());
	nodo2->set_dcho(nodo);
	nodo1->set_dcho(nodo2->get_izq());
	nodo2->set_izq(nodo1);

	if(nodo2->get_bal()== -1)
		nodo1->set_bal(1);
	else
		nodo1->set_bal(0);
	if(nodo2->get_bal()==1)
		nodo->set_bal(-1);
	else
		nodo->set_bal(0);

	nodo2->set_bal(0);
	nodo=nodo2;
}

template<class Clave>
void arbolAVL<Clave>:: rotacion_DI(nodoAVL<Clave>* &nodo)
{
	nodoAVL<Clave>* nodo1 =nodo->get_dcho();
	nodoAVL<Clave>* nodo2=nodo1->get_izq();
	nodo->set_dcho(nodo2->get_izq());
	nodo2->set_izq(nodo);
	nodo1->set_izq(nodo2->get_dcho());
	nodo2->set_dcho(nodo1);

	if(nodo2->get_bal()==1)
		nodo1->set_bal(-1);
	else
		nodo1->set_bal(0);
	if(nodo2->get_bal()==-1)
		nodo->set_bal(1);
	else
		nodo->set_bal(0);

	nodo2->set_bal(0);
	nodo=nodo2;
}

template<class Clave>
void arbolAVL<Clave>:: insertar_bal(nodoAVL<Clave>* &nodo,nodoAVL<Clave>* nuevo, bool& crece)
{
	if(nodo==NULL)
	{
		nodo=nuevo;
		crece=true;
	}

	else if (nuevo->get_clave() < nodo->get_clave())
	{
		insertar_bal(nodo->get_izq(),nuevo,crece);
		if (crece)
			insert_re_balancea_izda(nodo,crece);
	}
	else
	{
		insertar_bal(nodo->get_dcho(),nuevo,crece);
		if (crece)
			insert_re_balancea_dcha(nodo,crece);
	}
}

template<class Clave>
void arbolAVL<Clave>:: insert_re_balancea_izda(nodoAVL<Clave>* &nodo, bool& crece)
{
	switch(nodo->get_bal())
	{
		case -1: nodo->set_bal(0);
				 crece=false;
				 break;
		case 0: nodo->set_bal(1);
				break;
		case 1: nodoAVL<Clave>* nodo1=nodo->get_izq();
				if(nodo1->get_bal()==1)
					rotacion_II(nodo);
				else
					rotacion_ID(nodo);
				crece=false;
	}
}

template<class Clave>
void arbolAVL<Clave>:: insert_re_balancea_dcha(nodoAVL<Clave>* &nodo,bool& crece)
{
	switch (nodo->get_bal())
	{
		case 1: nodo->set_bal(0);
				crece=false;
				break;
		case 0: nodo->set_bal(-1);
				break;
		case -1: nodoAVL<Clave>* nodo1=nodo->get_dcho();
				 if(nodo1->get_bal()==-1)
				 	rotacion_DD(nodo);
				 else
				 	rotacion_DI(nodo);
				 crece=false;
	}
}

template<class Clave>
void arbolAVL<Clave>::eliminarRama(nodoAVL<Clave>* &nodo,Clave clave_dada,bool& decrece)
{
	if(nodo==NULL) return;
	if(clave_dada < nodo->get_clave())
	{
		eliminarRama(nodo->get_izq(),clave_dada,decrece);
		if(decrece)
			eliminar_re_balancea_izda(nodo,decrece);
	}
	else if (clave_dada > nodo->get_clave())
	{
		eliminarRama(nodo->get_dcho(),clave_dada,decrece);
		if(decrece)
			eliminar_re_balancea_dcha(nodo,decrece);
	}
	else
	{
		nodoAVL<Clave>* eliminado=nodo;
		if (nodo->get_izq()==NULL)
		{
			nodo=nodo->get_izq();
			decrece=true;
		}
		else if(nodo->get_dcho()==NULL)
		{
			nodo=nodo->get_izq();
			decrece=true;
		}
		else
		{
			sustituye(eliminado,nodo->get_izq(),decrece);
			if(decrece)
				eliminar_re_balancea_izda(nodo,decrece);
		}
		delete eliminado;
	}
}

template <class Clave>
void arbolAVL<Clave>::sustituye(nodoAVL<Clave>* &eliminado,nodoAVL<Clave>* &sust, bool &decrece)
{
	if(sust->get_dcho()!=NULL)
	{
		sustituye(eliminado,sust->get_dcho(),decrece);
		if(decrece)
			eliminar_re_balancea_dcha(sust,decrece);
	}
	else
	{
		eliminado->set_clave(sust->get_clave());
		eliminado=sust;
		sust=sust->get_izq();
		decrece=true;
	}
}

template<class Clave>
void arbolAVL<Clave>::eliminar_re_balancea_izda(nodoAVL<Clave>* &nodo,bool& decrece)
{
	switch(nodo->get_bal())
	{
		case -1: 
		{
			nodoAVL<Clave>* nodo1=nodo->get_dcho();
				 if(nodo1->get_bal() > 0)
				 	rotacion_DI(nodo);
				 else
				 {
				 	if(nodo1->get_bal()==0)
				 		decrece=false;
				 	rotacion_DD(nodo);
				 }
				 break;
		}
		case 0: nodo->set_bal(-1);
				decrece=false;
				break;
		case 1: nodo->set_bal(0);
				break;
	}
}

template<class Clave>
void arbolAVL<Clave>::eliminar_re_balancea_dcha(nodoAVL<Clave>* &nodo,bool& decrece)
{
	switch(nodo->get_bal())
	{
		case 1: 
		{
				nodoAVL<Clave>* nodo1=nodo->get_izq();
				if(nodo1->get_bal() < 0)
					rotacion_ID(nodo);
				else
				{
					if(nodo1->get_bal()== 0)
						decrece=false;
					rotacion_II(nodo);
				}
				break;
			}
		case 0: nodo->set_bal(1);
				decrece=false;
				break;
		case -1: nodo->set_bal(0);
				 break;
	}
}