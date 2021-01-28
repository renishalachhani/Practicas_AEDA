#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


class dni
{
private:
    char valor_ [8]; 

public:
    dni (void);  
    dni (string valor); 
    ~dni (void);  

    operator int (void);  
    bool operator == (const dni &dni_) const;  
    bool operator < (const dni &dni_) const;  
    bool operator > (const dni &dni_) const;  
    bool operator <= (const dni &dni_) const;  
    bool operator >= (const dni &dni_) const;  

    ostream& write (ostream& os) const;  
};
