#include <iostream>


using namespace std ;

template <typename T>
constexpr bool is_lvalue(T&&) {
  return std::is_lvalue_reference<T>{};
}

//LVALUE REFERENCE
void function1LValueRef( int& a1 )
{
   cout << "function1: " << a1 << endl ;
}

//RVALUE REFERENCE
void function2RValueRef( int&& a1 )
{
  //It will always be a lvalue because a1 is a name. However
  //when the function is called it must pass in a rvalue.
  cout << "Is a1 a lvalue: " << is_lvalue( a1 ) << endl ;
  //a1 = 25 ;
}

int main()
{
   int x1 = 10 ;    int y1 = 30 ;
   cout << boolalpha;

   //Need to initialize rvalue references
   int&& x1R = 20 ;
   int&& x2R = 30 ;
   int& x1L = x1  ;

   //compiler error
   //A rvalue reference must be initialized
   // int&& x3R  ;
   //Can only initialize it with a temporary object
   //  int&& x3R = x1  ;

   //can reassign values to r reference
   //Am only changing the value. The x1R is not pointing to
   //something else.
   x1R = x2R ;

   //Can initialize l-value reference with r-value
   //reference. Anything that has a name is l-value.
   int& x3R = x1R ;

   //cannot do
   //At the point of definition. It needs a lvalue
   //int& x2L = 25 ;
   //can do
   const int& x2L = 20 ;

   //int&& x4R = x1L ;
   //Cannot assign lvalue to rvalue reference.

   function1LValueRef( x1 ) ;
   function2RValueRef(  20 ) ;

   // The value of x1 is being assigned to x1R. x1R is not
   // pointing to a different location.
   x1R = x1 ;
   x1R = 40 ;   //can assign another rvalue. Changing the original value of x1R

   //Not a reassignment of the lvalue reference as y1 is a r-value
   //changes the value of x1 because x1L "points" to x1 .
   x1L = y1 ;

   cout << "x1R:" << x1R << endl ;

   //x1R's value is being assigned to x1.
   x1 = x1R ;
   cout << "x1:" << x1 << endl ;

   //function 2 is r reference
   //Compiler error r-value reference expects a constant
   //ref1.cpp:88:27: error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
   //88 |      function2RValueRef(  x1  ) ;
   //  function2RValueRef(  x1  ) ;

    //ok move converts a l value to a r value
   function2RValueRef( move(x1)  ) ;

    //x1R is a name so it's a l value at this point
   function1LValueRef( x1R ) ;

    cout << "Is x1R a lvalue: " << is_lvalue( x1R ) << endl ;
    cout << "Is 12 a lvalue: " << is_lvalue( 12 ) << endl ;

    function2RValueRef(  move(x1R)   ) ;
    cout << "x1R value: " << x1R << endl ;
    //compiler error even though x1R is rvalue !!!
    //But it has a name so now is lvalue !!
    // function2RValueRef(  x1R   ) ;
     function2RValueRef( 21 ) ;

     int x2 = 5 ;
     cout << x2 << " " << move(x2) << endl ;





   return 0 ;
}

