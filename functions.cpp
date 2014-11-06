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

Desc: Parse the load file
In: None
Out: double to indicate the true number representation

*/


double load_parser(char buffer[5])
{

  //char buffer[5];
  char num_buf[20];
  char let_buf[20];
  char* c; 
  int num_trck = 0;
  int let_trck = 0;
  //int k = 0;

  //cout<< "Enter Resistor Value: ";
  //cin >> buffer;
  c = buffer; 
   

/*  BEGIN PARSING STRING  */

do
{
	 if( *c == '.' || (*c >= '0' && *c <= '9'))
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

Desc: contains all the functions for the loading the input file
In: None
Out: None

*/

void load_file()
{
        string casetype;
        string parttype;
        string getinfo;
        string pwr;
        string str;
        string smd;
        int track = 1;
        int flag = 0;
        double value = 0.00;
        double lim_volt = 0.00;
        int quant = 0;
        string parse_value;
        char* cstr = new char[str.length()];

	/* Load data into array */
	fstream ifile_1("output5.txt",ios::in);
	fstream ifile_2("output5.txt",ios::in); // used for to track # of entries

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
            {
             //parse_value = cstr; //get string value of number
             value =  load_parser(cstr);
             //value = atof(cstr);     //value, old code
            }
          if(track == 2)
             quant = atoi(cstr);     //quantity
          if(track == 3)
             casetype = cstr;        //case
          if(track == 4)
             parttype = cstr;        //part type 
          if(track == 5)
             smd = cstr;             //smd
          if(track == 6)
             lim_volt = atof(cstr);  //limit volt
          if(track == 7)
            {
             pwr = cstr;
             rptr = new Resistor(value,quant,casetype,parttype,smd,lim_volt,pwr);
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
   string r_smd;
   string r_power;
   double r_val = parser();
   double r_limvolt = 0.00;
   int    r_quant = 0;

   string case1 = "0402";
   string case2 = "0603";
   string case3 = "axial";
   string case4 = "surface_mount";
   string case5 = "through_hole";
   int case_choice = 0;
   int desc_choice = 0;
   

   cout<< "Enter Quantity: ";
   cin>> r_quant;

   cout<< "Enter Case Type: ";
   cout<< "(1)0402  (2)0603  (3)axial  -->  ";
   cin >> case_choice;

  while(case_choice >= 0)
 {
    if(case_choice == 1 )
    {
      r_case = case1;
      break;
    }
    if(case_choice == 2 )
    {
      r_case = case2;
      break;
    }
    if(case_choice == 3 )
    {
      r_case = case3;
      break;
     }
    if((case_choice < 1) || (case_choice > 3))
    {
     cout<<"Inavalid choice!" << endl;
     cout<< "Enter Case Type: ";
     cout<< "(1) 0402  (2) 0603  (3) axial  -->  ";
     cin >> case_choice;
    }
}
 
   cout<< "Enter Part No: ";
   cin>> r_part;

   cout<< "Enter Description: ";
   cout<< "(1) Surface_Mount  (2) Through_Hole  -->  ";
   cin >> desc_choice;
   
  while(desc_choice >= 0)
   {
      if(desc_choice == 1)
       {
        r_smd = case4;
        break;
       }
      if(desc_choice == 2)
       {
        r_smd = case5;
        break;
       }
      if(desc_choice < 1 || desc_choice > 2)
       {
        cout<<"Inavalid choice!" << endl;
        cout<< "Enter Description: ";
        cout<< "(1) Surface_Mount  (2) Through_Hole  -->  ";
        cin >> desc_choice;
       }
    }


   cout<< "Enter Limiting Voltage: ";
   cin >> r_limvolt;
   cout<< "Enter Power Rating: ";
   cin >> r_power;

   rptr = new Resistor(r_val,r_quant, r_case, r_part, r_smd, r_limvolt, r_power);

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
       cout<< endl;
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
  //int k = 0;

  cout<< "Enter Resistor Value: ";
  cin >> buffer;
  c = buffer; 

/*  BEGIN PARSING STRING  */

do
{
	 if( *c == '.' || (*c >= '0' && *c <= '9'))
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
  
  cout<<"\t\t\t\t\t\t\t\t\t\tTEKPEA PARTS DATABASE" << endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t----------------------" << endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t    MENU OPTIONS" << endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t----------------------" << endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t(1) Insert" << endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t(2) Search" << endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t(3) Print" << endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t(4) Update" << endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t(5) Quit" << endl;
  cout<<"\n\n\n\n\n\n\n";

  cout<<"\t\t\t\t\t";
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
