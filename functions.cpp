#include "functions.h"
#include "var.h"
#include <stdlib.h>
#include <iostream>

using namespace std;


////////////////////////////////////////////////////////////
/*

Desc: contains all the functions for the insert case
In: None
Out: None

*/

void insert_case(void)
{
       clr_scrn();
       list.track++;
       list.insert(rptr, parser());
       clr_scrn();
       list.print();
       user_choice();
       clr_scrn();
}

////////////////////////////////////////////////////////////
/*

Desc: contains all the functions for the search case
In: None
Out: None

*/

void search_case(void)
{
       clr_scrn();
       list.lookup(rptr, parser());
       user_choice();
       clr_scrn();
}
////////////////////////////////////////////////////////////
/*

Desc: Parse the user input to distinguish the true value of input: 125k --> 125000
In: None
Out: double to indicate the true number representation

*/

double parser(void)
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
  //cout<< "final value: " << value << endl;
}
else if(*c == 'm' || *c == 'M')
{
  value = value*1000000;
  //cout<< "final value: " << value << endl;
}
else 
{ 
value = value;
//cout<< "final value: " << value << endl;
}

 return value;
}


////////////////////////////////////////////////////////////
/*

Desc: User display and input
In: None
Out: integer to indicate user choice value

*/

int Display(void)
{
  int choice = 0;
  
  cout<<"TEKPEA PARTS DATABASE" << endl;
  cout<<"----------------------" << endl;
  cout<<"1) Add Front" << endl; 
  cout<<"2) Add Back" << endl; 
  cout<<"3) Count" << endl;
  cout<<"4) Empty" << endl; 
  cout<<"5) Remove Front" << endl;
  cout<<"6) Remove Back" << endl;
  cout<<"7) Insert" << endl;
  cout<<"8) Print" << endl;
  cout<<"9) Quit" << endl;
  cout<<"10) Search" << endl << endl;

  cin>> choice;
  return choice;
}

////////////////////////////////////////////////////////////
/*

Desc: Pause system
In: None
Out: none

*/

void user_choice()
{
  cout<<"Press Enter to continue" << endl;
  cin.ignore();
  cin.get();
}


////////////////////////////////////////////////////////////
/*

Desc: Clear console screen
In: None
Out: none

*/

void clr_scrn(void)
{
 cout<< string(100, '\n');
}



////////////////////////////////////////////////////////////
/*

Desc: Check if List is empty
In: None
Out: none

*/

void empty()
{

   cout<< "Empty List ?" <<endl;

   if(list.empty() == true)
     cout<<"T"<<endl;
   else
     cout<<"F"<<endl;
}
