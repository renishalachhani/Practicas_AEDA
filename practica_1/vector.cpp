#include <iostream>
#include <cstdlib>
#include "vector.hpp"
using namespace std;



int main()
{
	cout<<"INT: \n";
    	vector<int>vec(15);
    	vector<int>copy(15);
   	cout<<vec.add(5)<<"\n";
   	cout<<vec.add(10)<<"\n";
   	cout<<vec.add(43)<<"\n";
   	cout<<vec.add(0)<<"\n";
  	cout<<vec.add(20)<<"\n";
  	cout<<vec.add(90)<<"\n";
  	cout<<vec.add(1000)<<"\n";
  	cout<<vec.add(945)<<"\n";
  	cout<<vec.add(4)<<"\n";
  	cout<<vec.add(9)<<"\n";

	cout<<"printing copy : \n";
  	cout<<"\n";
    	cout<<"\n";
  
  	copy=vec;
  	for(int j =0;j<copy.howmanyelements();j++)
    		cout<<copy[j]<<"\n";
  	cout<<"\n";
    	cout<<"\n";

    	cout<<"size= "<<vec.vectorsize()<<"\n";
       	cout<<"element in index 2: "<<vec.locate(2)<<"\n";
        vec.substitute(1,100);
    
    	for(int j =0;j<vec.howmanyelements();j++)
    		cout<<vec[j]<<"\n";
    	
	cout<<"\n";
    	cout<<"\n";
    	cout<<"DOUBLE: \n";
    
     	vector<double>v(10);
   	cout<<v.add(5.99)<<"\n";
   	cout<<v.add(10.025)<<"\n";
   	cout<<v.add(43.32)<<"\n";
   	cout<<v.add(0.5)<<"\n";
  	cout<<v.add(20.75)<<"\n";
  
  
    	cout<<"size= "<<v.vectorsize()<<"\n";
       	cout<<"element in index 2: "<<v.locate(2)<<"\n";
        v.substitute(1,100.254);
    
    	for(int j =0;j<v.howmanyelements();j++)
    		cout<<v[j]<<"\n";
    
	return 0;
    
    
}

