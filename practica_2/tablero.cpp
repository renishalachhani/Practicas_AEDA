#include "celula.hpp"
#include "tablero.hpp"


tablero::tablero ()
{

	filas = 2;
	columnas = 2;
	turno = 0;
	
	game_fin = false;
    	board.resize(2, vector<celula>(2)); 

}

tablero::tablero (int rows, int columns)
{

	filas = rows;
	columnas = columns;
	turno = 0;
	
	game_fin = false;
    	board.resize(rows+2, vector<celula>(columns+2)); 

}

tablero::~tablero ()
{

}


void tablero::setViva(int i, int j)
{
	 
	if ((i>=0) && (i<filas) && (j>=0) && (j<columnas))
		board[i][j].setEstado(1)==1;
}



void tablero::setMuerta (int i, int j)
{
	
	if ((i>=0) && (i<filas) && (j>=0) && (j<columnas))
		board[i][j].setEstado(0)==0;
}





bool tablero::viva (int i, int j)
{
     
	if ((i>=0) && (i<filas) && (j>=0) && (j<columnas))

	        if (board[i][j].getEstado() == 1)  
            		return true;

	return false;
}



void tablero::ejecutar ()
{
    while (!game_fin){  
		getchar();
	  
        	write(cout);  
		actualizarEstado();
		 
    }

	
}


void tablero::actualizarEstado ()
{
	int c;  
	game_fin = true;
	cambiado = 0;
	 

    	for (int i=0; i<filas; i++){  
        	for (int j=0; j<columnas; j++){
            		c = contarVecinas(i,j);
		  
           


            		if (board[i][j].getEstado() == 0){ 
				if (c == 3)
				{  
					board[i][j].setNextEstado(1); 
					cambiado++;
					game_fin = false; 
				}
				else
				{
					board[i][j].setNextEstado(0);  
				}
            		}
            		else
			{
                		if (board[i][j].getEstado() == 1){  
					if (c == 2)
					{  
						board[i][j].setNextEstado(1); 
					}
					else
					{
						if (c == 3)
						{  
							board[i][j].setNextEstado(1);  
						}
						else
						{  
							board[i][j].setNextEstado(0); 
							cambiado++; 
							game_fin = false;  
						}
					}
                		}
            		}
        	}
    	}

    

	for (int i=0; i<filas; i++){  
        	for (int j=0; j<columnas; j++){
            		board[i][j].setEstado(board[i][j].getNextEstado())==board[i][j].getNextEstado();  
        	}
    	}

    	turno++;
}




int tablero::contarVecinas(int i, int j)
{

	v =0;
	


	if(i==0 && j>0)
	{

		if(board[i][j-1].getEstado()==1)
			v ++;
		if(board[i][j+1].getEstado()==1)
			v ++;
		if(board[i+1][j-1].getEstado()==1)
			v ++;
		if(board[i+1][j].getEstado()==1)
			v ++;
		if(board[i+1][j+1].getEstado()==1)
			v ++;
	}
	else if(j == 0 && i>0)
	{

		if(board[i-1][j].getEstado()==1)
			v ++;
		if(board[i-1][j+1].getEstado()==1)
			v ++;

		if(board[i][j+1].getEstado()==1)
			v ++;

		if(board[i+1][j].getEstado()==1)
			v ++;
		if(board[i+1][j+1].getEstado()==1)
			v ++;

	}

	else if( i==0 && j==0)
	{
		if(board[i][j+1].getEstado()==1)
			v ++;
		if(board[i+1][j].getEstado()==1)
			v ++;
		if(board[i+1][j+1].getEstado()==1)
			v ++;
	}
	else
	{

		if(board[i-1][j-1].getEstado()==1)
			v ++;
		if(board[i-1][j].getEstado()==1)
			v ++;
		if(board[i-1][j+1].getEstado()==1)
			v ++;
		if(board[i][j-1].getEstado()==1)
			v ++;
		if(board[i][j+1].getEstado()==1)
			v ++;
		if(board[i+1][j-1].getEstado()==1)
			v ++;
		if(board[i+1][j].getEstado()==1)
			v ++;
		if(board[i+1][j+1].getEstado()==1)
			v ++;
	}


	return v;
}





ostream& tablero::write (ostream& os)
{
    
	os << "Turno: " << turno << endl;
	
	os << "Celulas cambiadas: " << cambiado << endl;


    	for (int i=0; i<filas; i++){
        	os << " ";
        	for (int j=0; j<columnas; j++){
            		if (board[i][j].getEstado() == 1)
                		os << "X";
            		else
                		os << " ";
        	}
        	os << " " << endl;
    	}

	
    	os << endl;

	

    	return os;
}
