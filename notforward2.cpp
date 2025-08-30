#include <iostream>

using namespace std ;

class Object
{
 public:
  Object() = default;

  void SetName(const string &name) { name_ = move(name); }
  string GetName() const { return name_; }

 private:
  string name_;
};

void UseObject( Object& x1 )
{
  cout << "calling UseObject(Object &)" << endl;
}

void UseObject( const Object& x1 )
{
  cout << "calling UseObject(const Object &)" << endl;
}

void UseObject( Object&& x1 )
{
  cout << "calling UseObject(Object &&)" << endl;
}

void UseObject1( Object&& x1 )
{
  cout << "calling UseObject1(Object &&)" << endl;
}


template <typename T>
void NotForwardToUseObject( T& x1 )
{
  UseObject(x1);
}

template <typename T>
void NotForwardToUseObject( const T& x1 )
{
  UseObject(x1);
}


template <typename T>
void NotForwardToUseObject( T&& x1 )
{
  cout <<  "NotForwardToUseObject:" << "Move reference." << endl ;
  UseObject1( move(x1) );
}


int main()
{
  Object object;
  const Object const_object;
  UseObject(object);
  UseObject(const_object);
  UseObject(move(object));
  cout << "----" << endl;

   NotForwardToUseObject(object);
   NotForwardToUseObject(const_object);
   NotForwardToUseObject(move(object));

  cout << "----" << endl;


}
