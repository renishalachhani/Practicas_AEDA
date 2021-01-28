#include <iostream>
#include <cstdlib>
#include <cstring>
#include "stack.hpp"
using namespace std;
//#define SIZE 50


int main()
{
    	cout<<"INT :"<<"\n";
    	stack<int> t(SIZE);
    	stack<int> copy(SIZE);
    	t.push(4);
    	t.push(5);
    	t.push(6);
    	t.push(99);
    	t.push(10045);
     	copy =t;
   
    	for(int i =0; i<5;i++)
    		cout<<copy.pop()<<"\n";

    	cout<<"peek: "<<t.peek()<<"...";
    	cout<<"size : "<<t.sizeofstack()<<"\n";

    	for(int i =0; i<5;i++)
    		cout<<t.pop()<<"\n";

    	cout<<"size: "<<t.sizeofstack()<<"\n";
   
    
    
    	cout<<"DOUBLE :"<<"\n";
    	stack<double> tt(SIZE);
    	tt.push(4.35);
    	tt.push(5.8);
    	tt.push(6.248);
    	tt.push(99.01);
    	tt.push(10045.00);
    	cout<<"peek: "<<tt.peek()<<"...";
    	cout<<"size : "<<tt.sizeofstack()<<"\n";
    	for(int i =0; i<5;i++)
    		cout<<tt.pop()<<"\n";

    	cout<<"size: "<<tt.sizeofstack()<<"\n";
    	return 0;
    
}
