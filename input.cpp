#include <iostream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(void)
{

  char buffer[5];
  char num_buf[20];
  char let_buf[20];
  char* c; 
  int num_trck = 0;
  int let_trck = 0;
  int k = 0;

  cout<< "Enter Resistor Value: " << endl;
  cin >> buffer;
  c = buffer; 

/*  BEGIN PARSING STRING  */

do
{
	 if( *c == '.' || *c >= '0' && *c <= '9')
	{
          num_buf[num_trck] = *c;
          num_trck++;
	  c++;
	}
	 else // assuming there is only 1 letter appending entry
	{ 
           let_buf[let_trck] = *c;
           let_trck++;
	   break;   
	}

}while(c);


num_buf[num_trck] = '\n';
let_buf[let_trck] = '\n';

 c = num_buf;

// CONVERT NUM_BUFFER TO TYPE DOUBLE

double value = 0.0;
value = atof(num_buf);


c=let_buf; //reset ptr

// ENSURE CASE SENSITIVE INPUTS

if(*c ==  'k' || *c == 'K')
{
  value =  value*1000;
 cout<< "final value: " << value << endl;
}
else if(*c == 'm' || *c == 'M')
{
  value = value*1000000;
  cout<< "final value: " << value << endl;
}
else 
cout<< "final value: " << value << endl;

 return 0;
}
