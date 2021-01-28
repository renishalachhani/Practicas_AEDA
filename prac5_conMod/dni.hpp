#pragma once
#include <iostream>
#include <cstdio>
#include <stdlib.h>     
#include <time.h>       
#include <iomanip>
#include <stdint.h>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

class DNI{

  private:
    int number;
    char let;
   
    
  public:
    
    DNI();
    DNI(int );
    

    
    ~DNI();

    
    void setDni(int, char );
    char getLetra();
    int getDni();
    
    
    bool operator == (DNI& dni);
    bool operator < (DNI& dni);
    bool operator > (DNI& dni);
    operator int();

    friend ostream& operator<<(ostream& os, DNI& dni);

};

DNI::DNI():
number(00000000 + rand() % (99999999 + 1)),
let('A' + rand() % (('A' - 'Z') + 1))


{}



DNI::DNI(int num){
	number = num;
	
	
}


DNI::~DNI(){}



void DNI::setDni(int n, char letra){
	number = n;
	let = letra;
	
}

int DNI::getDni(){
	return number;
}

char DNI::getLetra(){
	return let;
}


bool DNI::operator == (DNI& dni){
	if(getDni() == dni.getDni()){
		return true;
	}
	else{
		return false;
  }
}

bool DNI::operator < (DNI& dni){
	if(getDni() < dni.getDni()){
		return true;
	}
	else{
		return false;
  }
}

bool DNI::operator > (DNI& dni){
	if(getDni() > dni.getDni()){
		return true;
	}
	else{
		return false;
  }
}

DNI::operator int(){
	return number;
}

ostream& operator<<(ostream& os, DNI& dni){

	os << dni.getDni()<<"-"<<dni.getLetra() ;
	return os;
}
