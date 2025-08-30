#include <iostream>

using namespace std ;

class Holder
{
  public:

    Holder(int size)         // Constructor
    {
	  cout << "Argument constructor." << size << endl ;
	  printf( "%p\n" , this) ;
      m_data = new int[size];
      m_size = size;
    }

	Holder(const Holder& other)
	{
      cout << "Copy constructor." << m_size <<  endl ;
	  m_data = new int[other.m_size];  // (1)
	  std::copy(other.m_data, other.m_data + other.m_size, m_data);  // (2)
	  m_size = other.m_size;
	}

	Holder(Holder&& other)     // <-- rvalue reference in input
	{
	  cout << "Move copy constructor." << other.m_size << endl ;
	  m_data = other.m_data;   // (1)
	  m_size = other.m_size;
	  other.m_data = nullptr;  // (2)
	  other.m_size = 0;
	}

	Holder& operator=(const Holder& other)
	{
	  cout << "assignment operator" << other.m_size << endl ;
	  if(this == &other) return *this;  // (1)
	  delete[] m_data;  // (2)
	  m_data = new int[other.m_size];
	  std::copy(other.m_data, other.m_data + other.m_size, m_data);
	  m_size = other.m_size;
	  return *this;  // (3)
	}

Holder& operator=(Holder&& other)     // <-- rvalue reference in input
{
  cout << "Move assignment operator." << other.m_size <<  endl ;

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
	  cout << "Destructor." << m_size << endl ;
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

Holder createHolder1(int size)
{
  return move(Holder(size)) ;
}


int main()
{
	//Copy constructor
    Holder h1 = createHolder(1000)  ;
    printf( "main %p\n" , &h1 ) ;
    cout << "Move Copy attempt.\n" << endl ;

    Holder h2 = createHolder1(1000)  ;


    //Move Assignment operator
    cout << "Move Assignment.\n" << endl ;
    h1 = createHolder(500);
    printf( "main %p\n" , &h1 ) ;
    cout << "End of main." << endl ;
	return 0 ;
}