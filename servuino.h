
void interruptNow();
void writeStatus();
void stopEncoding();
void updateFromRegister();
void digitalWrite(int pin,int value);
int  digitalRead(int pin);

char  interruptType[50][80];
void  (*interrupt[9])();

#define S_UNIMPLEMENTED            0
#define S_SETUP                    1
#define S_LOOP                     2
#define S_DIGITAL_WRITE_LOW        3
#define S_DIGITAL_WRITE_HIGH       4
#define S_DIGITAL_READ             5
#define S_ANALOG_REFERENCE         6
#define S_ANALOG_WRITE             7
#define S_ANALOG_READ              8
#define S_PIN_MODE_INPUT           9
#define S_PIN_MODE_OUTPUT         10
#define S_DELAY                   11
#define S_DELAY_MS                12
#define S_ATTACH_INTERRUPT_LOW     13
#define S_ATTACH_INTERRUPT_RISING  14
#define S_ATTACH_INTERRUPT_FALLING 15
#define S_ATTACH_INTERRUPT_CHANGE  16
#define S_DETACH_INTERRUPT        17
#define S_SERIAL_BEGIN            18
#define S_SERIAL_END              19
#define S_SERIAL_PRINT_INT        20
#define S_SERIAL_PRINT_INT_BASE   21
#define S_SERIAL_PRINT_CHAR       22
#define S_SERIAL_PRINT_STRING     23
#define S_SERIAL_PRINT_SSTRING    24

#define S_SERIAL_PRINTLN_INT      25
#define S_SERIAL_PRINTLN_INT_BASE 26
#define S_SERIAL_PRINTLN_CHAR     27
#define S_SERIAL_PRINTLN_STRING   28
#define S_SERIAL_PRINTLN_SSTRING  29
#define S_SERIAL_PRINTLN_VOID     30
#define S_SERIAL_WRITE            31



int A0;
int A1;
int A2;
int A3;
int A4;
int A5;
int A6;
int A7;
int A8;
int A9;
int A10;
int A11;
int A12;
int A13;
int A14;

unsigned int PORTA=0,PORTB=0,PORTC=0,PORTD=0,PORTE=0,PORTF=0,PORTG=0,PORTH=0,PORTJ=0,PORTK=0,PORTL=0;
unsigned int DDRA=0,DDRB=0,DDRC=0,DDRD=0;
unsigned int PINA=0,PINB=0,PINC=0,PIND=0;

#define R_PORT 1
#define R_DDR  2
#define R_PIN  3

void  bitWrite(unsigned int *x, int n,int b);
int   bitRead(int x, int n);
int   readRegister(int reg, int port);
void  writeRegister(int digital, int reg, int port, int value);
void  registerLog();
void  setPINRegister(int step); 


//=====================================
// String
//=====================================

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

#include <iomanip>
using std::setw;

#include <cstring> 
using std::strcmp;
using std::strcpy;
using std::strcat;

#include <string> 
using std::string;

#include <cstdlib>
using std::exit;

#include <sstream>
using std::stringstream;

class String
{
   friend ostream &operator<<( ostream &, const String & );
   friend istream &operator>>( istream &, String & );

public:
   String( const char * = "" ); // conversion/default constructor
   String( const String & ); // copy constructor
   ~String(); // destructor

   const String &operator=( const String & ); // assignment operator
   const String &operator+=( const String & ); // concatenation operator

   bool operator!() const; // is String empty?
   bool operator==( const String & ) const; // test s1 == s2
   bool operator<( const String & ) const; // test s1 < s2

   bool operator!=( const String &right ) const
   { 
      return !( *this == right ); 
   } 

   bool operator>( const String &right ) const
   { 
      return right < *this; 
   } 
 
   bool operator<=( const String &right ) const
   { 
      return !( right < *this ); 
   }

   bool operator>=( const String &right ) const
   { 
      return !( *this < right ); 
   } 

   char &operator[]( int ); // subscript operator (modifiable lvalue)
   char operator[]( int ) const; // subscript operator (rvalue)
   String operator()( int, int = 0 ) const; // return a substring
   int getLength() const; // return string length

   // ============ Benny adding =============
   String( const int x ); 
   String( const int x, const int base );
 
   const String &operator=( string right );
   const String &operator=( const char *right );

   String operator+( const int number );
   String operator+( const char one );
   String operator+( unsigned long number );
   String operator+( String right );

   char charAt(const int n);
   int compareTo(const String s);
   String concat(const String s); 	
   bool endsWith(const String s);
   bool equals(const String s);
   bool equalsIgnoreCase(const String s);	
   void getBytes(int buf[], int *len);	
   int indexOf(char val); 
   int indexOf(String val); 
   int indexOf(char val, int from); 
   int indexOf(String val, int from); 
   int lastIndexOf(char val); 
   int lastIndexOf(String val); 
   int lastIndexOf(char val, int from); 
   int lastIndexOf(String val, int from); 
   int length(); 
   String replace(String sub1, String sub2); 
   void setCharAt(int index,char c); 
   bool startsWith(String s); 
   String substring(int from);
   String substring(int from, int to);
   void toCharArray(char buf[], int *len);
   void toLowerCase(); 
   void toUpperCase(); 
   void trim(); 
   char *getPointer(); 

private:
   int lngth; // string length (not counting null terminator)
   char *sPtr; // pointer to start of pointer-based string

   void setString( const char * ); // utility function



}; // end class String

