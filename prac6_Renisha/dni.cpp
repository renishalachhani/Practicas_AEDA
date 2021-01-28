#include <cmath>

#include "dni.hpp"
#include "mod.hpp"

extern int contador; 
extern mod MODO;  

dni::dni (void)
{
    for (int i=0; i<7; i++){
        valor_[i] = 0;
    }
}
dni::dni (string valor)
{
    contador ++;
    for (int i=0; i<7; i++){
        valor_[i] = valor[i];
    }
}

dni::~dni (void)
{

}

bool dni::operator == (const dni &dni_) const
{
     if (MODO == estadistico){  
         contador ++;  
     }

    bool iguales = true;
    int i = 0;
    while ((i < 7) && (iguales == true)){
        if (valor_[i] != dni_.valor_[i]){
            iguales = false;
        }
        i ++;
    }

    return iguales;
}

bool dni::operator < (const dni &dni_) const
{
     if (MODO == estadistico){  // Si se está ejecutando el programa en modo estadístico...
         contador ++;  // Se aumenta el contador
    }

    int i = 0;
    bool menor = true;

    while ((i < 7) && (menor)){
        if (valor_[i] < dni_.valor_[i]){
            i = 7;
        }
        else{
            if (valor_[i] > dni_.valor_[i]){
                menor = false;
            }
        }
        i ++;
    }

    if (i == 7){
        return false;
    }
    else{
        return menor;
    }
}

bool dni::operator > (const dni &dni_) const
{
     if (MODO == estadistico){  // Si se está ejecutando el programa en modo estadístico...
         contador ++;  // Se aumenta el contador
     }

    int i = 0;
    bool mayor = true;

    while ((i < 7) && (mayor)){
        if (valor_[i] > dni_.valor_[i]){
            i = 7;
        }
        else{
            if (valor_[i] < dni_.valor_[i]){
                mayor = false;
            }
        }
        i ++;
    }

    if (i == 7){
        return false;
    }
    else{
        return mayor;
    }
}

bool dni::operator <= (const dni &dni_) const
{
     if (MODO == estadistico){  
         contador ++;  
     }

    int i = 0;
    bool menor_igual = true;

    while ((i < 7) && (menor_igual)){
        if (valor_[i] < dni_.valor_[i]){
            i = 6;
        }
        else{
            if (valor_[i] > dni_.valor_[i]){
                menor_igual = false;
            }
        }
        i ++;
    }

    return menor_igual;
}

bool dni::operator >= (const dni &dni_) const
{
     if (MODO == estadistico){ 
         contador ++;  
     }

    int i = 0;
    bool mayor_igual = true;

    while ((i < 7) && (mayor_igual)){
        if (valor_[i] > dni_.valor_[i]){
            i = 6;
        }
        else{
            if (valor_[i] < dni_.valor_[i]){
                mayor_igual = false;
            }
        }
        i ++;
    }

    return mayor_igual;
}

ostream& dni::write (ostream& os) const
{
    if (valor_[0] == '\0'){  
        os << "N/A";
    }
    else{
        os << valor_;
    }
    return os;
}
