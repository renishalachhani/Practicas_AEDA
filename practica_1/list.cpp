#include <iostream>
#include <algorithm>
#include "list.hpp"





int main()
{
	std::cout<<"INT: \n";
    
    	list<int> list1;
    	int temp=10;
   
    	for(int i=0;i<temp;i++)
    		list1.insertback(i);

    	std::cout << list1;
    	list1.remove(1);
    	std::cout << list1;
    	list1.reverse();
    	std::cout << list1;
     	list1.insertfront(20);
      	list1.insertfront(47);
      	list1.insertback(100);
    	std::cout << list1;
    	list1.clear();
    	std::cout << list1;
    	list1.isEmpty();
   
   
   	std::cout<<"DOUBLE: \n";
   
    	list<double> list2;
    	int t=15;
   
    	for(double i=0.33;i<t;i++)
    		list2.insertback(i);

    	std::cout << list2;
    	list2.remove(5.1);
    	std::cout << list2;
    	list2.reverse();
    	std::cout << list2;
     	list2.insertfront(20.95);
      	list2.insertfront(47.99);
      	list2.insertback(100.05);
    	std::cout << list2;
    
    	list2.isEmpty();

	return 0;
   
   
}
