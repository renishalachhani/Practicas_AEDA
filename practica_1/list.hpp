#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <algorithm>

using namespace std;
template<class TDATO>
class list
{
    	class node
    	{
    		public:
        		TDATO data;
        		node* next;
        		node* prev;

        
        		node(){next=NULL; prev=NULL;}
        		node(TDATO d){data=d; next=NULL; prev=NULL;}
       
    	};
    	node* first = NULL;
    	node* last = NULL;
	public:

    
    		friend ostream& operator<<(ostream& os, list<TDATO>& q)
{     
			os<<"List: ";
    			for(node* n = q.first; n != NULL; n = n->next)
    			{
       				os << n->data<<" ";
    			}
    			os<<endl;
    			return os;
}

    	//basic functions
    	void insertback(TDATO);
    	void insertfront(TDATO);
    	bool isEmpty();
    	void reverse();
    	void clear();
    	void remove(TDATO);
   
  
};



template <class TDATO>
void list<TDATO>:: insertback(TDATO dat)
{
    	node* current = new node(dat);
    	if (first == NULL)
    	{
        	first = current;
    	}
    	else
    	{
        	last -> next = current;
        	current -> prev = last;
    	}
    	last = current;
}




template <class TDATO>
void list<TDATO>:: insertfront(TDATO dat)
{
    	node* current = new node(dat);
    	if (first == NULL)
    	{
        	first = current;
        	last = current;
    	}
    	else
    	{
        	first -> prev = current;
        	current -> next = first;
        	first = current;
    	}
}




template <class TDATO>
bool list<TDATO>:: isEmpty()
{
    	if (first == NULL && last == NULL)
    	{
       		cout << "true: list is empty"<<endl;
        	return true;
    	}
    	else
    		cout << "false: list is not empty"<<endl;
        return false;
}




template <class TDATO>
void list<TDATO>:: reverse()
{
    	node* current = last;
    	node* future_next = NULL;
    	while (current)
    	{
        	future_next = current -> prev;
        	if (current == last)
        	{
            		first = last;
            		current -> prev =NULL;
            		current -> next = future_next;
        	}
        	else
        	{
            		current -> next = future_next;
            		current -> prev = last;
        	}
        	last = current;
        	current = future_next;
    	}
}




template <class TDATO>
void list<TDATO>::remove(TDATO dat)
{
    	node* current = first;
    	node* previous = first;
    	while (current)
    	{
        	if (current -> data == dat)
        	{
            		if(first == last)
            		{
                		first = NULL;
                		last = NULL;
                		delete current;
                		cout << "Removed: " << dat << endl;
                		return ;
            		}
            		else if (current == first)
            		{
                		first = current->next;
                		first -> prev = NULL;
                		delete current;
                		cout << "Removed: " << dat << endl;
                		return ;
            		}
            		else if (current == last)
            		{
               			previous -> next = NULL;
                		last = previous;
                		delete current;
                		cout << "Removed: " << dat <<endl;
                		return ;
            		}
            		else
            		{
                		(previous -> next) = (current -> next);
                		(current -> next) -> prev = previous;
                		delete current;
                		cout << "Removed: " << dat <<endl;
                		return ;
            		}
        	}
        	previous = current;
        	current = current -> next;
    	}
    	cerr << "Element not in list" << endl;
    	return ;
}




template <class TDATO>
void list<TDATO>::clear()
{
    	node* current = first;
    	node* temp = first;
    	while (current)
    	{
        	current = current -> next;
        	delete temp;
        	temp = current;
    	}
    	delete temp;
    	first = NULL;
    	last = NULL;
    	cout<<"List has been emptied"<<endl;
}



#endif
