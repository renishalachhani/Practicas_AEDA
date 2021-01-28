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

class Seguridad{

  private:
    int number;
    char let1;
    char let2;
    char let3;
    char let4;
   
    
  public:
    
    Seguridad();
    Seguridad(int );
    

    
    ~Seguridad();

    
    void setSeg(char, char, int, char, char );
    char getLetra1();
    char getLetra2();
    char getLetra3();
    char getLetra4();
    int getSegNum();
    
    
    bool operator == (Seguridad& seg);
    bool operator < (Seguridad& seg);
    bool operator > (Seguridad& seg);
    operator int();

    friend ostream& operator<<(ostream& os, Seguridad& seg);

};

Seguridad::Seguridad():
number(0000000000 + rand() % (9999999999 + 1)),
let1('A' + rand() % (('A' - 'Z') + 1)),
let2('A' + rand() % (('A' - 'Z') + 1)),
let3('A' + rand() % (('A' - 'Z') + 1)),
let4('A' + rand() % (('A' - 'Z') + 1))
{}



Seguridad::Seguridad(int num){
	number = num;
	
	
}


Seguridad::~Seguridad(){}



void Seguridad::setSeg(char letra1, char letra2, int n, char letra3, char letra4){
	number = n;
	let1 = letra1;
	let2 = letra2;
	let3 = letra3;
	let4 = letra4;
	
}

int Seguridad::getSegNum(){
	return number;
}

char Seguridad::getLetra1(){
	return let1;
}

char Seguridad::getLetra2(){
	return let2;
}

char Seguridad::getLetra3(){
	return let3;
}


char Seguridad::getLetra4(){
	return let4;
}



bool Seguridad::operator == (Seguridad& seg){
	if(getSegNum() == seg.getSegNum()){
		return true;
	}
	else{
		return false;
  }
}

bool Seguridad::operator < (Seguridad& seg){
	if(getSegNum() < seg.getSegNum()){
		return true;
	}
	else{
		return false;
  }
}

bool Seguridad::operator > (Seguridad& seg){
	if(getSegNum() > seg.getSegNum()){
		return true;
	}
	else{
		return false;
  }
}

Seguridad::operator int(){
	return number;
}

ostream& operator<<(ostream& os, Seguridad& seg){

	os <<seg.getLetra1()<<seg.getLetra2()<<"-"<< seg.getSegNum()<<"-"<<seg.getLetra3()<<seg.getLetra4() ;
	return os;
}
