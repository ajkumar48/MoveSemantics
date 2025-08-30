#include <iostream>

using namespace std ;

class Holder
{
  public:

    Holder(int size)         // Constructor
    {
	  cout << "Argument constructor." << endl ;
      m_data = new int[size];
      m_size = size;
    }

	Holder(const Holder& other)
	{
      cout << "Copy constructor." << endl ;
	  m_data = new int[other.m_size];  // (1)
	  std::copy(other.m_data, other.m_data + other.m_size, m_data);  // (2)
	  m_size = other.m_size;
	}

	Holder(Holder&& other)     // <-- rvalue reference in input
	{
	  cout << "Move copy constructor." << endl ;
	  m_data = other.m_data;   // (1)
	  m_size = other.m_size;
	  other.m_data = nullptr;  // (2)
	  other.m_size = 0;
	}

	Holder& operator=(const Holder& other)
	{
	  cout << "assignment operator" << endl ;
	  if(this == &other) return *this;  // (1)
	  delete[] m_data;  // (2)
	  m_data = new int[other.m_size];
	  std::copy(other.m_data, other.m_data + other.m_size, m_data);
	  m_size = other.m_size;
	  return *this;  // (3)
	}

Holder& operator=(Holder&& other)     // <-- rvalue reference in input
{
  cout << "Move assignment operator." << endl ;

  if (this == &other)
   return *this;

  delete[] m_data;         // (1)

  m_data = other.m_data;   // (2)
  m_size = other.m_size;

  other.m_data = nullptr;  // (3)
  other.m_size = 0;

  return *this;
}


    ~Holder()                // Destructor
    {
	  cout << "Destructor." << endl ;
	  if ( m_data != NULL )
        delete[] m_data;
    }

  private:
    int*   m_data;
    size_t m_size;
};

Holder createHolder(int size)
{
  return Holder(size);
}


int main()
{
	//
    Holder h1(1000)  ;
    {
		Holder h2(1000)  ;
		cout << "Before Assignment.\n" << endl ;
		//Assignment operator
		h1 = move( h2 )  ;
    }
	return 0 ;
}