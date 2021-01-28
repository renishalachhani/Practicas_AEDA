#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstdlib>
#define SIZE 50

using namespace std;

template<class TDATO>
class queue
{
    	private:
    		int last,first,counter;
    		int capacity;
    		TDATO *me;
    	public:
    		queue (int);
    		void enqueue(TDATO x);
    		TDATO dequeue();
    		bool isEmpty();
    		bool isFull();
    		TDATO First();
    		TDATO Last();
    		int sizeofqueue();
    		queue(const queue<TDATO>& src);
};



template<class TDATO>
queue<TDATO>::queue(int size)
{
    	first=0;
    	last=-1;
    	counter=0;
    	capacity=size;
    	me=new TDATO[capacity];
}



template<class TDATO>
queue<TDATO>::queue(const queue<TDATO>& src):
     	capacity(src.capacity),
     	first(src.first),
     	last(src.last),
     	counter(src.counter)
{
	me=new int[capacity];
      	for(int i=0;i<counter;i++)
      		me[i]=src.me[i];
}



//enqueue method 
template<class TDATO>
void queue<TDATO>::enqueue(TDATO x)
{
    	if(isFull())
	{
		cout<<"queue is full";
    		exit(0);
    	}
   	last=(last+1)%capacity;
   	me[last]=x;
   	counter++;

}



    
//dequeue method 
template<class TDATO>
TDATO queue<TDATO>::dequeue()
{
  	if(isEmpty())
	{
		cout<<"queue is empty";
    		exit(0);
   	} 
    	TDATO result= me[first];
    	first=(first+1)%capacity;
    	counter--;
    	return result;
}



//to check the size;
template<class TDATO>
int queue<TDATO>::sizeofqueue()
{
	return counter;
}



// to check if it is empty
template<class TDATO>
bool queue<TDATO>::isEmpty()
{
    	return counter==0;
}



//to check if its is full
template<class TDATO>
bool queue<TDATO>:: isFull()
{
    	return counter==capacity;
}



//to see the first element
template<class TDATO>
TDATO queue<TDATO>::First()
{
	if(isEmpty())
	{
		cout<<"queue is empty"; 
		exit(0);
	} 
	else 	
		return me[first];
}




//to see the last element
template<class TDATO>
TDATO queue<TDATO>::Last()
{
	if(isEmpty())
	{
		cout<<"queue is empty"; 
		exit(0);
	} 
	else 
		return me[last];
}


#endif
