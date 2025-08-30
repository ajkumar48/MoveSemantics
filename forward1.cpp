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

void UseObject(Object& x1)
{
  cout << "calling UseObject(Object &)" << endl;
}

void UseObject(const Object& x1)
{
  cout << "calling UseObject(const Object &)" << endl;
}

void UseObject(Object&& x1)
{
  cout << "calling UseObject(Object &&)" << endl;
}

template <typename T>
void NotForwardToUseObject(T x)
{
  UseObject(x);
}

template <typename T>
void ForwardToUseObject(T &&x) {
  UseObject(static_cast<T &&>(x));
}

template <typename T>
void PerfectForwardToUseObject(T &&x) {
  UseObject(forward<T>(x));
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
  ForwardToUseObject(object);
  ForwardToUseObject(const_object);
  ForwardToUseObject(move(object));
  cout << "----" << endl;

  PerfectForwardToUseObject(object);
  PerfectForwardToUseObject(const_object);
  PerfectForwardToUseObject(move(object));

}
