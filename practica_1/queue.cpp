#include <iostream>
#include <cstdlib>
#include "queue.hpp"
using namespace std;
//#define SIZE 50


int main()
{
	cout<<"INT: \n";
    	queue<int> t(SIZE);
    	queue<int> copy(SIZE);
   
    	t.enqueue(4);
    	t.enqueue(5);
    	t.enqueue(6);
    	t.enqueue(99);
    	t.enqueue(10045);
     	copy=t;
    	for(int i =0; i<5;i++)
    		cout<<copy.dequeue()<<"\n";

    	cout<<"\n";
    	cout<<"\n";
    	cout<<"first: "<<t.First()<<"...";
    	cout<<"last: "<<t.Last()<<"...";
    	cout<<"size : "<<t.sizeofqueue()<<"\n";
    	for(int i =0; i<5;i++)
    		cout<<t.dequeue()<<"\n";

    	cout<<"size: "<<t.sizeofqueue()<<"\n";

	cout<<"\n";
    	cout<<"\n";
    
    	cout<<"DOUBLE: \n";
    	queue<double> tt(SIZE);
    	tt.enqueue(4.8);
    	tt.enqueue(5.92);
    	tt.enqueue(6.01);
    	tt.enqueue(99.3);
    	tt.enqueue(10045.9);
    	cout<<"first: "<<tt.First()<<"...";
    	cout<<"last: "<<tt.Last()<<"...";
    	cout<<"size : "<<tt.sizeofqueue()<<"\n";
    	for(int i =0; i<5;i++)
    		cout<<tt.dequeue()<<"\n";

    	cout<<"size: "<<tt.sizeofqueue()<<"\n";
     
     	return 0;
    
}
