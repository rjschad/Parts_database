/*
 * =====================================================================================
 *
 *   Program name:  main.cpp
 *         Author:  Raymond Schad (Rio)
 *      Course No:  CSCI 311
 *
 *   Project Desc:  Doubly Linked List that allows the user
 *                  to view, insert, and remove integers.

 * Change/Fix Log: Version 1.0  9-11-2014: Made Skeleton Program
 *                 Version 1.1  9-15-2014: Create List class
 *                 Version 1.2  9-16-2014: Insert function & Sorting
 *                 Version 1.3  9-20-2014: Removal Functions
 *                 Version 1.4  9-21-2014: User Display functions
 *                 Version 1.5  9-24-2014: Count and Empty Function
 *                 Version 1.6  9-25-2014: Finish remaining functions`
 *                 Version 1.7  9-26-2014: Special case, bounds & range testing
 *
 *        Version:  1.7
 *        Created:  09/11/2014 13:33:04
 *       Compiler:  gcc 4.8.2
 *
 * =====================================================================================
 */


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

#define TRUE 1
#define FALSE 0

using namespace std;

/* GLOBALS */
 List list;
 Resistor* rptr;


////////////////////////////////////////////////////////////
/*

Desc: main function
In: No command line args other than basic console info
Out: int 1 = success

*/

int main( int argc, char* argv[])
{

   list.track = 0; 
   int number=0;
   int num_add =0;
   int s_choice = 0;
   int c_choice = 0;

   double in_num = 0.00; 
   int in_num_r = 0;
   string in_string;
   string case_search;
   string partnumber;
   string case1 =  "0402";
   string case2 =  "0603";
   string case3 =  "axial";
   string case4 =  "0805";
   string case5 =  "2010";

//-----------------------------------------------------------------
load_file(); 

fstream ofile1_init("output4.txt", ios::out); 

do
 {
  clr_scrn(); //clear screen initally

   switch(Display()) // act on user input
   {
     /*
     case 1: // ADD FRONT
       clr_scrn();
       cout<< "Add number to front: " << endl;
       cin>> num_add;
       list.addfront(rptr,num_add);
       list.track++; // increment track
       clr_scrn();
       list.print();
       user_choice();
       clr_scrn();
       break;

     case 2: // ADD BACK
       clr_scrn();
       cout<< "Add number to back: " << endl;
       cin>> num_add;
       list.addback(rptr,num_add);
       list.track++;
       clr_scrn();
       list.print();
       user_choice();
       clr_scrn();
       break;

     case 3: // COUNT
       clr_scrn();
       cout<< "list cnt: " << list.track << endl;
       list.print();
       user_choice();
       clr_scrn();
       break;

     case 4: // EMPTY
       clr_scrn();
       empty();
       user_choice();
       clr_scrn();
       break;

     case 5: // REMOVE FRONT
       clr_scrn();
       list.remove_front(); 
       if(list.track == 0)
        {clr_scrn();cout<< "Empty List" << endl; user_choice(); clr_scrn(); break;}
       list.track--; // decrement track
       assert(list.track !=  -1); // error check
       list.print();
       user_choice();
       clr_scrn();
       break;

     case 6: // REMOVE BACK
       clr_scrn();
       list.remove_back(); 
       if(list.track == 0)
        {clr_scrn();cout<< "Empty List" << endl; user_choice(); clr_scrn(); break;}
       list.track--;
       assert(list.track !=  -1); // error check
       list.print();
       user_choice();
       clr_scrn();
       break;
     */
     case 1: // INSERT
       insert_case();
       break;

     case 2: // SEARCH
       clr_scrn();
       cout<<"Search by: (1) Value  (2) Case  (3) Part No.  -->  ";
       cin>> s_choice;
       if(s_choice == 1)
         search_case();
       if(s_choice == 2)
         {
          cout<< "Enter Case Type: ";
          cout<< "(1) 0402  (2) 0603  (3) axial  (4) 0805  (5) 2010  -->  ";
          cin >> c_choice;

        while(c_choice >= 0)
         {
          if(c_choice == 1)
            { case_search = case1;break;}
          if(c_choice == 2)
             {case_search = case2;break;}
          if(c_choice == 3)
             {case_search = case3;break;}
          if(c_choice == 4)
             {case_search = case4;break;}
          if(c_choice == 5)
             {case_search = case5;break;}
          if(c_choice < 1 || c_choice > 5)
            { 
             cout<<"Invalid chocie!" <<endl;
             cout<< "Enter Case Type: ";
             cout<< "(1) 0402  (2) 0603  (3) axial  (4) 0805  (5) 2010  -->  ";
             cin >> c_choice;
            }
          }          
           clr_scrn();
           list.lookup_bycase(case_search);
           user_choice();
           clr_scrn();
         }
       if(s_choice == 3)
       {
         clr_scrn();
         cout<< "Enter Part No: " << endl;
         cin >> partnumber;
         list.lookup_bypartnum(rptr, partnumber);
         cout<<endl;
         user_choice();
         clr_scrn();
        }
       break;

     case 3: // PRINT
       clr_scrn();
       list.print();
       cout<< endl;
       user_choice();
       clr_scrn();
       break;
     
      case 4: // Update
       clr_scrn();
       cout<< "Update in progress, see insert" << endl;
       cout<< endl;
       user_choice();
       clr_scrn();
       break;

     case 5: // QUIT
       list.pushto_out(ofile1_init);
       clr_scrn();
       cout<< "Writing to output file.\nQuitting program...\n"<< endl;
       return 0; // return sucessfull


     default:
       clr_scrn();
       cout<< "You have entered an invalid choice.\nPlease choose again from the following choices.\n";
       user_choice();
       break;

   }


} while(1);

   cout<<endl;
   cout << "end of program !!! \n";
   cout.flush(); // flush output
   
   return 0;

}

