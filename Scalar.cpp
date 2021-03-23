using namespace std;
#include <iostream>

class Scalar
{
    public:
	
     explicit Scalar( int initialValue = 0 )
     { 
	 storedValue = new int{ initialValue };  
     
     }
	
    ~Scalar( )  
    { 
        delete storedValue; 
    }
   
    Scalar ( const Scalar & rhs ) // Copy constructor
    { 
    	storedValue = new int{ *rhs.storedValue }; 
    }

    Scalar ( Scalar && rhs ) : storedValue{ rhs.storedValue } // Move constructor
    { 
    	rhs.storedValue = nullptr; 
    }
  
    Scalar & operator= ( const Scalar & rhs ) // Copy assignment
    { 
    	if( this != &rhs )
			*storedValue = *rhs.storedValue;
		return *this;
    }
  
    Scalar & operator= ( Scalar && rhs ) // Move assignment
    {
    	swap( storedValue, rhs.storedValue );
    	return *this;
    }
    
    int read( ) const
    { 
   	  return *storedValue; 
    }
   
    void write( int x )
    { 
	    *storedValue = x; 
    }
   
   private:
    int *storedValue;
 };

int main()
{
	Scalar a{ 2 };
	Scalar b = a;
	Scalar c;
	c = b;
	a.write( 4 );
	cout << a.read( ) << endl << b.read( ) << endl << c.read( ) << endl;
}
