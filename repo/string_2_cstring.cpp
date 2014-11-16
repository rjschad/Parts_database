/*
 * =====================================================================================
 *
 *       Filename:  string_2_cstring.cpp
 *
 *    Description: Converts std::string into C-style string
 *
 *        Version:  1.0
 *        Created:  11/11/2014 11:32:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rio Schad (Rio), rj.schad2006@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std; // ::std

//globals
 int sflag = 0;
 int trck = 0;

void reset(void)
{
   trck = 0;
   sptr = part;
}

void flagReset(void)
{sflag = 0;}

int main()
{

 /* ficticious part no.s for test purposes only */

  string partno ("ERJ-3GEYJ100V");
  string partno2 ("ERJ-1G4YJ100V");
  string partno3 ("ERJ-3G5YJ100V");
  string partno4 ("ERJ-2G7YJ100V");
  string partno5 ("ERJ-3G8YJ100V");
  string partno6 ("ERJ-2G8YJ100V");

  string partno7 ("RCW040221R0FKED");
  string partno8 ("RCW121022R0JNEA");
  string partno9 ("CRCW201047R0JNEF");

  /* convert each partno string into c-style string */

  char* cstr = new char[partno.length()+1]; // set pointer to new mem location
  strcpy(cstr, partno.c_str()); // copy contents

  char* cstr1 = new char[partno2.length()+1]; // set pointer to new mem location
  strcpy(cstr1, partno2.c_str()); // copy contents

  char* cstr2 = new char[partno3.length()+1]; // set pointer to new mem location
  strcpy(cstr2, partno3.c_str()); // copy contents

  char* cstr3 = new char[partno4.length()+1]; // set pointer to new mem location
  strcpy(cstr3, partno4.c_str()); // copy contents

  char* cstr4= new char[partno5.length()+1]; // set pointer to new mem location
  strcpy(cstr4, partno5.c_str()); // copy contents

  char* cstr5= new char[partno6.length()+1]; // set pointer to new mem location
  strcpy(cstr5, partno6.c_str()); // copy contents



  /* user entered part */
  char part [40];
  cout<<"enter part" <<endl;
  cin >> part;

  /* ptr to part */
  char* sptr = part;

  /* print out user part */

  cout<<"you entered: " <<endl;
  cout<<part << endl;

   while(*sptr != '\0')
    {
     cout<< *sptr;
     sptr++;
    }
    
   cout<<endl;

   //compare parts
   int trck = 0;
   
   sptr = part; //reset ptr

   //compare with part 1
   while(*sptr == *cstr)
   {
     sptr++;
     cstr++;
     sflag = 1; // set flag
   }
    
   if(sflag==1)
   {
     cout<<"match found for part 1" <<endl;
     flagReset();
   }

   reset();

   //compare with part 2
   while(*sptr == *cstr1)
   {
     sptr++;
     cstr1++;
     sflag = 1;
   }


   if(sflag==1)
   {
     cout<<"match found for part 2" <<endl;
     sflag = 0; //reset flag
   }

    reset();

   return 0;

}

