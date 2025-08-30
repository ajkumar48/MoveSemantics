#include <iostream>


using namespace std ;

class A
{
	public:
	int x1 ;
	int x2 ;
       A(  )
        {
          cout << "A Empty constructor." << endl ;
		}
	   //Move constructor
       A( A&& obj1  )
        {
          cout << "A Empty constructor." << endl ;
		}
      A& operator=(A&& other) = default ;
};


int main()
{
   A  AObject1 ;
   AObject1.x1 = 10 ;
   AObject1.x2 = 20 ;
   A  AObject2 ;
   AObject2  = move(AObject1) ;
   cout <<  AObject2.x1 << " " << AObject2.x2 << endl ;



   return 0 ;
}

