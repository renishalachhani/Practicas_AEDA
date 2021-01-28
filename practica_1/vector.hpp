#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstdlib>
using namespace std;

template<class TDATO>
class vector{
	
    	public:
    		TDATO *me;
    		int size;
    		int numelements;
    
    		vector(int);
    		TDATO add(TDATO x);
    		TDATO del();
    		int vectorsize();
    		int howmanyelements();
    		void substitute(int pos, TDATO data);
    		bool isEmpty();
    		bool isFull();
    		TDATO locate(int index);
    		TDATO operator [] (int ind);
    		vector(const vector<TDATO>& src);
};


template<class TDATO>
vector<TDATO>::vector(int maxsize)
{
    
    	size=maxsize;
    	me=new TDATO[size];
    
    	numelements=0;
}


template<class TDATO>
vector<TDATO>::vector(const vector<TDATO>& src):
     	numelements(src.numelements),
     	size(src.size)
{
        me=new int[size];
      	for(int i=0;i<numelements;i++)
      	me[i]=src.me[i];
}



template<class TDATO>
TDATO vector<TDATO>::add(TDATO x)
{
    	int plus=100;
    	if(isFull())
	{
        	size=size+plus;
        	TDATO *me2=new TDATO(size);
      		for(int i=0; i<numelements;i++)
          		me2[i]=me[i];
          	delete [] me;
          	me=me2;
          
          
        
    	}
    	me[numelements]=x;
    	numelements++;
    	return x;
}



template<class TDATO>
TDATO vector<TDATO>::del()
{
    	if(isEmpty())
		cout<<"vector is empty";
   	delete me[numelements];
   
    	numelements--;
}


template<class TDATO>
int vector<TDATO>::vectorsize()
{
	return size;
}



template<class TDATO>
void vector<TDATO>::substitute(int pos, TDATO data)
{
    	if(isEmpty())
	{
		cout<<"vector is empty"; 
		exit(0);
	}
    	for(int i=0;i<numelements;i++)
	{
        	if(i==pos)
			me[i]=data;
    	}
}



template<class TDATO>
TDATO vector<TDATO>::locate(int index)
{
    	if(isEmpty())
	{
		cout<<"vector is empty";
		exit(0);	
	}
    	return me[index];
}



template<class TDATO>
bool vector<TDATO>::isEmpty()
{
	return numelements==0;
}




template<class TDATO>
bool vector<TDATO>::isFull()
{
	return numelements==size;
}



template<class TDATO>
int vector<TDATO>::howmanyelements()
{
	return numelements;
}



template<class TDATO>
TDATO vector<TDATO>::operator [] (int ind)
{
    	return me[ind];
    
}

#endif
