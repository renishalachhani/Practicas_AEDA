#pragma once

#include <iostream>
#include "dni.h"

using namespace std;

template <class Clave>
class nodoAVL {
	private:
		Clave clave_;
		int bal_;
		nodoAVL *izdo_;
		nodoAVL *dcho_;

	public:
		inline nodoAVL(Clave clave, nodoAVL<Clave> *izq=NULL, nodoAVL<Clave> *der=NULL): bal_(0), clave_(clave), izdo_(izq), dcho_(der){}
		inline ~nodoAVL(){}
		
		inline nodoAVL<Clave>*& get_izq() {return izdo_;}
		inline nodoAVL<Clave>*& get_dcho() {return dcho_;}
		inline Clave get_clave() {return clave_;}
		inline int get_bal() {return bal_;}
		
		inline void set_izq(nodoAVL<Clave>* nodo) {izdo_=nodo;}
		inline void set_dcho(nodoAVL<Clave>* nodo) {dcho_=nodo;}
		inline void set_bal(int bal) {bal_=bal;}
		inline void set_clave(Clave clave) {clave_=clave;}
	};