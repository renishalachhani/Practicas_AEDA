#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define SIZE 50


template<class TDATO>
class stack
{
    	public:
    		int top;
    		int capacity;
    		TDATO *me;
    
    		stack ( int);
    		void push(TDATO x);
    		TDATO pop();
    		bool isEmpty();
    		bool isFull();
    		TDATO peek();
    		int sizeofstack();
    		stack (const stack<TDATO>& src);
};


template<class TDATO>
stack<TDATO>::stack(int size)
{
    	top=-1;
    	capacity=size;
    	me=new TDATO[capacity];
}



template<class TDATO>
stack<TDATO>::stack(const stack<TDATO>& src):
     	capacity(src.capacity),
    	top(src.top)
{
	me=new int[capacity];
      	for(int i=0;i<top;i++)
      		me[i]=src.me[i];
}



//push method 
template<class TDATO>
void stack<TDATO>::push(TDATO x)
{
    	if(isFull())
	{
		cout<<"overflow";
    		exit(0);
    	}
    	top++;
    	me[top]=x;

}
    


//pop method 
template<class TDATO>
TDATO stack<TDATO>::pop()
{
  	if(isEmpty())
	{
		cout<<"underflow";
    		exit(0);
    	} 
    	TDATO result= me[top];
    	top--;
    	return result;
}



// to check if it is empty
template<class TDATO>
bool stack<TDATO>::isEmpty()
{
    	return top==-1;
}



//to check if its is full
template<class TDATO>
bool stack<TDATO>:: isFull()
{
    	return top==capacity-1;
}



//to see the top element
template<class TDATO>
TDATO stack<TDATO>::peek()
{
	if(top!=-1)
		return me[top]; 
	else 
		exit(0);
}



template<class TDATO>
int stack<TDATO>::sizeofstack()
{
	return top+1;
}

#endif
