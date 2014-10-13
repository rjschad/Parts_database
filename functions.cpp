#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <sstream>
#include "var.h"
#include "Part.h"
#include "list.h"
#include "functions.h"

using namespace std;


////////////////////////////////////////////////////////////
/*

Desc: contains all the functions for the loading the input file
In: None
Out: None

*/

void load_file()
{

        string casetype;
        string parttype;
        string getinfo;
        string str;
        int track = 1;
        int flag = 0;
        double value = 0.00;
        int quant = 0;
        char* cstr = new char[str.length()];

	/* Load data into array */
	fstream ifile_1("output4.txt",ios::in);
	fstream ifile_2("output4.txt",ios::in); // used for to track # of entries

      while(ifile_2)
      {
        ifile_2>> getinfo;
        flag++;
      }
 
       int stop = (flag -1); // break value
       flag = 0; // reset flag

       while(ifile_1)
        {
          ifile_1>> str;
          strcpy(cstr, str.c_str()); // cstr contains a cstyle string copr of str

          if(track == 1)
             value = atof(cstr);
          if(track == 2)
             quant = atoi(cstr);
          if(track == 3)
             casetype = cstr;
          if(track == 4)
            {
             parttype = cstr;
             rptr = new Resistor(value,quant,casetype,parttype);
             list.insert(rptr,value);
             track = 0; // reset
            }

          track++;
          flag++;

          if(flag == stop)
           break;
       }
       delete[] cstr;
}
////////////////////////////////////////////////////////////
/*

Desc: contains all the functions for the insert case
In: None
Out: None

*/

void insert_case(void)
{

   clr_scrn();
   string r_case;
   string r_part;
   double r_val = parser();
   int    r_quant = 0;
   

   cout<< "Enter Quantity: ";
   cin>> r_quant;
   cout<< "Enter Case Type: ";
   cin >> r_case;
   cout<< "Enter Part No: ";
   cin>> r_part;

   rptr = new Resistor(r_val,r_quant, r_case, r_part);


       clr_scrn();
       list.track++;
       list.insert(rptr, r_val);
       clr_scrn();
       list.print();
       cout<<endl;
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

  cout<< "Enter Resistor Value: ";
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
  
  cout<<"\t\t\t\tTEKPEA PARTS DATABASE" << endl;
  cout<<"\t\t\t\t----------------------" << endl;
  cout<<"\t\t\t\t    MENU OPTIONS" << endl;
  cout<<"\t\t\t\t----------------------" << endl;
  cout<<"\t\t\t\t1) Add Front" << endl; 
  cout<<"\t\t\t\t2) Add Back" << endl; 
  cout<<"\t\t\t\t3) Count" << endl;
  cout<<"\t\t\t\t4) Empty" << endl; 
  cout<<"\t\t\t\t5) Remove Front" << endl;
  cout<<"\t\t\t\t6) Remove Back" << endl;
  cout<<"\t\t\t\t7) Insert" << endl;
  cout<<"\t\t\t\t8) Print" << endl;
  cout<<"\t\t\t\t9) Quit" << endl;
  cout<<"\t\t\t\t10) Search" << endl << endl;

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
