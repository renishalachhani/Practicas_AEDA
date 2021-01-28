#include "experimento.hpp"
#include <iomanip>


experimento::experimento()
{
		
	nCeldas=0;
	nclave=0;
	nPruebas=0;
	g_=0;
	h_=0;
	factor=0.0;
	comp_[0]=0;
	comp_[1]=0;
	tabla_=NULL;
}

experimento::~experimento()
{
	nCeldas=0;
	nclave=0;
	nPruebas=0;
	g_=0;
	h_=0;
	factor=0.0;
	if (tabla_)
	{
		delete tabla_;
		tabla_=NULL;
	}
}

void experimento::inicializar()
{
	cout<<" Celdas: ";
	cin>>nCeldas;
	cout<<" Clave: ";
	cin>>nclave;
	do
	{
		cout<<"Funcion Exploracion"<<endl;
		cout<<"lineal(l)  cuadratica(c)   doble(d)   redispersion(r)"<<endl;
		cin>>g_;
		if (g_=='c')
		{
			if (!primo(nCeldas))
			{
				nCeldas=primo_cercano(nCeldas);
			}
		}
		cout<<"Funcion Dispersion"<<endl;
		cout<<"modulo(m)    suma(s)    pseudoaleatoria(p)"<<endl;
		cin>>h_;
		cout<<"Factor de carga: ";
		cin>>factor;
		cout<<"Número de pruebas: ";
		cin>>nPruebas;
	
		tabla_ = new tabla<dni>(nCeldas, nclave, g_ , h_);
			
	}while(!tabla_);
		

	N=2*(factor*nCeldas*nclave);
	banco_=new dni*[N];
	for (int i=0;i<N;i++)
		banco_[i]=new dni((rand()%50000000)+30000000);

}


void experimento::reiniciar()
{
	this->~experimento();
	inicializar();
}


void experimento::prueba_inserciones()
{
	
	int comp;
	int i=0;
	int N=(factor*nCeldas*nclave);
	int j=N;
	comp_[0]=N;
	comp_[1]=N;
	while((i<nPruebas)&&(j<2*N))
	{
		tabla_->Buscar(*banco_[j],comp);
		i++;
		j++;
		if (comp<comp_[0])
			comp_[0]=comp;
		if(comp>comp_[1])
			comp_[1]=comp;
	}
}

void experimento::prueba_busqueda()
{
	
	int comp;
	int i=0;
	int j=0;
	int N=(factor*nCeldas*nclave);
	comp_[0]=N;
	comp_[1]=N;
	while((i<nPruebas)&&(j<N))
	{
		tabla_->Buscar(*banco_[j],comp);
		i++;
		j++;
		if (comp<comp_[0])
			comp_[0]=comp;
		if(comp>comp_[1])
			comp_[1]=comp;
	}
}

void experimento::presentar_resultados()
{
		
	
	cout << "\n\n\tCELDAS\tnclave\tDISPERSION\tEXPLORACION\tCARGA\tPRUEBAS\n";

	cout << "\t------"  << "\t------"<< "\t-----------" << "\t-----------"  << "\t-----"  << "\t------"  << endl;

	cout << "\t" << nCeldas << "\t  " << nclave << "\t   " << h_ << "\t         " << g_<< "\t        " << factor << "\t    " << nPruebas<< endl << endl;  

	cout << "\t\t\tMINIMO" << "\tMEDIO" << "\tMAXIMO" << endl;
	prueba_busqueda();
  	cout << "\t\t\t------" << "\t------" << "\t------" << endl;

  	cout << "\tBUSQUEDAS" << "\t" << comp_[0] << "\t" << (comp_[0]+comp_[1])/2 << "\t" << comp_[1] << endl;

  	cout << "\tINSERCION" << "\t" << comp_[0] << "\t" << (comp_[0]+comp_[1])/2 << "\t" << comp_[1] << endl;

                  
}



bool experimento::primo(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if((n%i)==0)
			return false;
	}
	return true;
}

int experimento::primo_cercano(int n)
{
	int max;
	bool primo;
	for(int i=n-1;i>2;i--)
	{
		primo=true;
		for(int j=2;j<i;j++)
		{
			if(!(i%j))
				primo=false;
			max=i;
		}
		if(primo)
			return max;
	}
}
