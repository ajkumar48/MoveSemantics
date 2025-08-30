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

};

class B
{
	public:
       B(  )
        {
          cout << "B Empty constructor." << endl ;
		}


       B& operator=(B&& other) noexcept
       {
           cout << "B Move assignment operator for class B." << endl ;
           return *this ;
	   }
};



class C
{
	public:
	B BObject1 ;

       C(  )
        {
          cout << "C Empty constructor." << endl ;
		}

      C&  operator=(C&& obj1) = default ;
};




int main()
{
   A  AObject1 ;
   AObject1.x1 = 10 ;
   AObject1.x2 = 20 ;
   A  AObject2 ;
   AObject2  = AObject1 ;
   cout <<  AObject2.x1 << " " << AObject2.x2 << endl ;

   C CObject1 ;
   C CObject2 ;
   CObject2 =  move(CObject1) ;
   return 0 ;
}

