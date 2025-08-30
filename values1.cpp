#include <iostream>


using namespace std ;



//Returns a rvalue
int setValue()
{
    return 6;
}

int global = 100;

int& setGlobal()
{
    return global;
}




int main()
{
    int x1 = 100 ;
    //x1 is lvalue because it has an address
    //100 is a rvalue because it is temporary and does
    //not have a permanent address in memory. It may be stored
    //in a register but after the statement,
    //it's value is lost.

    // 100 = x1 ;
    //This produces a compiler error.
    //values1.cpp: In function ‘int main()’:
    //values1.cpp:20:6: error: lvalue required as left operand of assignment
    //   20 |      100 = x1 ;
    //The "100" does not have an address and is a rvalue and we cannot
    //put it to the left as it makes no sense.
    //The left of an assignment must be a lvalue .

    //setValue() = 100 ;
    //Compiler error as the function does not return a lvalue


    setGlobal() = 100 ;
    //The above is all right because the function
    // "setGlobal" returns a lvalue .

     int x2 = x1 ;
     //Here x2 is a lvalue and x1 is also a lvalue.
     // Because x1 is a name and anything that has a name has an address.

    int& x3 = x1 ;
    //x3 is a lvalue. There is a name.
    // Right hand side x1 is also a lvale

    string str1 = "Te" ;
    string str2 = "st" ;

    //Left hand side is not a lvalue
    str1 + str2 = "Test" ;



}