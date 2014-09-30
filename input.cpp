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
  char* c; //ptr
  int num_trck = 0;
  int let_trck = 0;
  int k = 0;

  cout<< "Enter number" << endl;
  cin >> buffer;
  c = buffer; // set c ptr to buffer[0]


/*  PARSING STRING  */

do
{
	 if(*c >= '0' && *c <= '9')
	{
	  cout << "valid number" << endl;
          cout << "number: " << *c << endl;
          num_buf[num_trck] = *c;
          num_trck++;
	  c++;
	}
	 else // assuming there is only 1 letter appending entry
	{ 
	   cout<< "letter:" << *c << endl;
           let_buf[let_trck] = *c;
           let_trck++;
	   break;   
	}


}while(c);

// append delimiters manually

num_buf[num_trck] = '\n';
let_buf[let_trck] = '\n';

/*  PRINT OUT BUFERS */

cout<< "---------------------------" << endl;

//set c to point to num_buf[]
 c = num_buf;

 while(*c != '\n')
   { 
     cout<< *c << endl;
     c++; 
   }

//set c to point to let_buf[]
 c = let_buf;

 while(*c != '\n')
   { 
     cout<< *c << endl;
     c++; 
   }

cout<< "---------------------------" << endl;
// CONVERT BUFFERS TO DOUBLES 

double value = 0.0;
value = atof(num_buf);

cout<< "Double value = " << value << endl;
// still need to convert letter: K and M to 1000 and 100000 respectively

cout<< "EOF" << endl << endl;
   




  




 return 0;
}
