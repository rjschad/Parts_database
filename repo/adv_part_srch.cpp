/*
 * =====================================================================================
 *
 *       Filename:  adv_part_srch.cpp
 *
 *    Description: advanced part search 
 *
 *        Version:  1.0
 *        Created:  11/12/2014 16:21:41
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

using namespace std; // :std

/* globals */
 int gtrck = 0;
 int trck1 = 0;

char* adv_search(string thepartNo)
{
  string user_part = thepartNo;

  /* parse through input to make case insensitive  */
    char* c_ptr= new char[user_part.length()+1];
    strcpy(c_ptr, user_part.c_str());

    char* d_ptr =  c_ptr; // set d_ptr to point to same place as c_ptr

    while(*c_ptr != '\0')  // change in lowercase letters in array to uppercase
    {
      *c_ptr = toupper(*c_ptr);
       c_ptr++; 
       trck1++;
    }
    return d_ptr;
}

bool userPart_srch(char* ptr1, string datapart)
{
  string partno = datapart;
  char* sptr = ptr1;
  int trck2 = 0;

  /* convert part number string into c-style string  */
  char* cstr = new char[partno.length()+1];
  char* copy = cstr; // make copy of ptr to delete later
  strcpy(cstr, partno.c_str()); 

  /* compare part numbers */
  while(*sptr == *cstr)
  {
    sptr++;
    cstr++;
    trck2++;
  }

  if(trck1 == trck2)
  {
    cout<< "Match found." <<endl;
    gtrck++;
    return true;
    delete[] copy; // free mem
    delete sptr;
  }
  else 
  {
    cout<< "No match." <<endl;
    return false;
    delete[] copy;  //free mem
    delete sptr;
  }

}

int main()
{
  string partno ("ERJ-3GEYJ100V");
  string user_part;

  /* user information */
  cout << "Enter part" << endl;
  cin>> user_part;

  //adv_search(user_part);


  if(userPart_srch(adv_search(user_part), partno))
    cout<< "function returned true" << endl;
  else
    cout<< "function returned false" << endl;

   return 0;
}

