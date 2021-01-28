#include <iostream>
#include <cstdlib>
#include "celda.hpp"
#include "tabla.hpp"
#include "dni.hpp"
#include "experimento.hpp"

using namespace std;

int main()
{
	//char op;
	experimento* E = new experimento();
	
	E->inicializar();
    	E->presentar_resultados();

}
