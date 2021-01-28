
#include "tablero.hpp"
#include "Celula1.hpp"
#include "Celula2.hpp"
#include "Celula3.hpp"
#include "celula.hpp"

using namespace std;


tablero::tablero ()
{
	filas = 2;
	columnas = 2;
	turno = 0;
	game_fin = false;

   
    	board.resize(filas, vector<celula*>(columnas));  

    	for (int i=0; i<filas; i++)
	{
        	for (int j=0; j<columnas; j++)
		{
            		if (board[i][j]!=NULL)
			{
                		delete board[i][j];
                		board[i][j] = NULL;
            		}
            		board[i][j] = new celula();
        	}
    	}
}



tablero::tablero (int rows, int columns)
{
	filas = rows;
	columnas = columns;
	turno = 0;
	game_fin = false;
	

	    
    	board.resize(filas+2, vector<celula*>(columnas+2)); 
    	for (int i=0; i<filas+2; i++)
	{
        	if (board[i][0]!=NULL)
		{
            		delete board[i][0];
            		board[i][0] = NULL;
        	}
        	board[i][0] =  new celula();

        	if (board[i][columnas+1]!=NULL)
		{
            		delete board[i][columnas+1];
            		board[i][columnas+1] = NULL;
        	}
        	board[i][columnas+1] = new celula();
    	}

    	for (int i=1; i<=columnas; i++)
	{
        	if (board[0][i]!=NULL)
		{
            		delete board[0][i];
            		board[0][i] = NULL;
        	}
        	board[0][i] = new celula();

        	if (board[filas+1][i]!=NULL)
		{
            		delete board[filas+1][i];
            		board[filas+1][i] = NULL;
        	}
        	board[filas+1][i] = new celula();
    	}

    	for (int i=1; i<=filas; i++)
	{
        	for (int j=1; j<=columnas; j++)
		{
            		if (board[i][j]!=NULL)
			{
                		delete board[i][j];
                		board[i][j] = NULL;
            		}
            		board[i][j] = new celula();
        	}
    	}
}



tablero::~tablero ()
{
    
   
}



int tablero::getFilas() const
{
    return filas;
}



int tablero::getColumnas() const
{
    return columnas;
}



int tablero::Estado(int i, int j) const
{
    if ((i>=1) && (i<=filas) && (j>=1) && (j<=columnas)){
        return board[i][j]->getEstado();
    }
}


void tablero::createCelula(int x, int i, int j) 
{
	if (board[i][j]!=NULL){
        	delete board[i][j];
        	board[i][j] = NULL;
    	}
    	if(x == 1)
	{
	
		board[i][j] = new Celula1();
	}
	else if(x == 2)
	{
		board[i][j] = new Celula2();
	}
	else
	{
		board[i][j] = new Celula3();
	}
}	
	



void tablero::mostrar()
{
    
    	while (!game_fin)
	{
		getchar();  
        	write(cout);
       
        	actualizarEstado();  
       
    	}

	
}



int tablero::contarVecinas(int i, int j)
{

	v =0;
	


	if(i==0 && j>0)
	{

		if((board[i][j-1]->getEstado()==1) || (board[i][j-1]->getEstado()==2) || (board[i][j-1]->getEstado()==3))
			v ++;
		if((board[i][j+1]->getEstado()==1) || (board[i][j+1]->getEstado()==2) || (board[i][j+1]->getEstado()==3))
			v ++;
		
		if((board[i+1][j]->getEstado()==1) || (board[i+1][j]->getEstado()==2) || (board[i+1][j]->getEstado()==3))
			v ++;
		
	}

	else if(j == 0 && i>0)
	{

		if((board[i-1][j]->getEstado()==1) || (board[i-1][j]->getEstado()==2) || (board[i-1][j]->getEstado()==3))
			v ++;
		

		if((board[i][j+1]->getEstado()==1) || (board[i][j+1]->getEstado()==2) || (board[i][j+1]->getEstado()==3))
			v ++;

		if((board[i+1][j]->getEstado()==1) || (board[i+1][j]->getEstado()==2) || (board[i+1][j]->getEstado()==3))
			v ++;
		

	}

	else if( i==0 && j==0)
	{
		if((board[i][j+1]->getEstado()==1) || (board[i][j+1]->getEstado()==2) || (board[i][j+1]->getEstado()==3))
			v ++;
		if((board[i+1][j]->getEstado()==1) || (board[i+1][j]->getEstado()==2) || (board[i+1][j]->getEstado()==3))
			v ++;
		
	}
	else
	{

		
		if((board[i-1][j]->getEstado()==1) || (board[i-1][j]->getEstado()==2) || (board[i-1][j]->getEstado()==3))
			v ++;
		
		if((board[i][j-1]->getEstado()==1) || (board[i][j-1]->getEstado()==2) || (board[i][j-1]->getEstado()==3))
			v ++;
		if((board[i][j+1]->getEstado()==1) || (board[i][j+1]->getEstado()==2) || (board[i][j+1]->getEstado()==3))
			v ++;
		
		if((board[i+1][j]->getEstado()==1) || (board[i+1][j]->getEstado()==2) || (board[i+1][j]->getEstado()==3))
			v ++;
		
	}


	return v;
}



void tablero::actualizarEstado()
{
    	game_fin=true;
    	for (int i=1; i<=filas; i++)
	{
        	for (int j=1; j<=columnas; j++)
		{
            		board[i][j]->setVivoVecino(contarVecinas(i,j));
        	}
    	}

    	int s ;
    	for (int i=1; i<=filas; i++)
	{
        	for (int j=1; j<=columnas; j++)
		{
            		s  = board[i][j]->actualizarEstado();
            		if (s !=0)
			{
               			 game_fin=false;
            		}
            		if (board[i][j]->getEstado()!=s )
			{
                		switch (s )
				{
                    			case 1:
                        			delete board[i][j];
                        			board[i][j] = new Celula1();
                        			game_fin=false;
                        			break;
                    			case 2:
                        			delete board[i][j];
                        			board[i][j] = new Celula2();
                        			game_fin=false;
                        			break;
                    			case 3:
                        			delete board[i][j];
                        			board[i][j] = new Celula3();
                        			game_fin=false;
                        			break;
                    			case 0:
                        			delete board[i][j];
                        			board[i][j] = new celula();
                        			game_fin=false;
                        			break;
                   	 		default:
                       
                        			exit(1);
                		}
            		}
        	}
    	}
    	turno++;
}



ostream& tablero::write (ostream& os) const
{
	os << "Turno: " << turno << endl;
	
	os << " ";
    	for (int i=0; i<columnas+2; i++)
	{
        	os << " ";
    	}
    	os << endl;

    	for (int i=0; i<filas+2; i++)
	{
        	os << " ";
        	for (int j=0; j<columnas+2; j++)
		{
            		board[i][j]->mostrar(os);
        	}
        	os << " " << endl;
    	}

	os << " ";
    	for (int i=0; i<columnas+2; i++)
	{
        	os << " ";
    	}
    	os << endl;

	return os;
}
