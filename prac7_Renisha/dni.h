#ifndef DNI_H
#define DNI_H
#include <cstdlib>
#include <random>
#include <iostream>

class DNI
{


public:

    int num;
    static int cont;

     DNI(){


        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(10000000, 99999999);

        num=dis(gen);




    }


    void cero(){

        cont=0;


    }

    int rand(){


        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(10000000, 99999999);

        return dis(gen);

    }

     bool operator==(DNI X){

        cont++;

        if (this->num==X.num)
            return 1;
        else return 0;


    }

     bool operator<(DNI X){

        cont++;

        if (this->num<X.num)
            return 1;
        else return 0;


    }

     bool operator>(DNI X){

        cont++;

        if (this->num>X.num)
            return 1;
        else return 0;


    }

     bool operator>=(DNI X){

        cont++;

        if (this->num>=X.num)
            return 1;
        else return 0;


    }


     bool operator<=(DNI X){

        cont++;

        if (this->num<=X.num)
            return 1;
        else return 0;


    }

     int operator=(int n){



        this->num=n;

        return *this;


    }

     operator int(){

        return this->num;

    }


};

int DNI::cont;

#endif // DNI_H
