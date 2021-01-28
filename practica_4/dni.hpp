#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class dni {
	private:
		int value_;
		
	public:
		inline dni(): value_(0) {}
		inline dni(int value): value_(value) {}
		inline dni(dni& n): value_(n.value_) {}
		inline ~dni() { value_= 0; }
		
		inline int get_value() { return value_; }
		
		inline int operator %(int n) { return value_%n; }
		inline bool operator==(dni& n) const 
		{ 
			return value_==n.value_; 
		}
		inline bool operator==(int n) const 
		{ 
			return value_==n; 
		}

		dni& operator= (dni& n)
		{
			value_= n.value_;
			return *this;
		}
		
		
		ostream& imprimir(ostream& os) const
		{
  			os << value_;
  			return os;
		}

};


