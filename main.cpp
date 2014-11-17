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
 int trck1 = 0;
 int gtrck  = 0;
 


////////////////////////////////////////////////////////////
/*

Desc: main function
In: No command line args other than basic console info
Out: int 1 = success

*/

int main( int argc, char* argv[])
{

   list.track = 0; 
   int s_choice = 0;
   int c_choice = 0;

   string partspec;
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

fstream ofile1_init("output5.txt", ios::out); 

do
 {
  clr_scrn(); 

   switch(Display()) // act on user input
   {
     case 1: // Insert
       insert_case();
       break;

     case 2: // Search
       clr_scrn();
       cout<<"\t\t\t\t\t\t\t\tSearch by: (1) Value  (2) Case  (3) Part No. (4) Advanced Part Search -->  ";
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
           list.lookup_bypartnum(partnumber);
           cout<<endl;
           user_choice();
           clr_scrn();
          }

         if(s_choice == 4)
         {
         /* advanced search algorithm */
           clr_scrn();
           list.adv_search_partno();
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
       /*  
       double numEntered;
       cout<< "Enter value you wish to search for: " << endl;
       cin>> numEntered;
       */
       list.edit(parser());


       cout<< endl;
       user_choice();
       clr_scrn();
       break;

      case 5: // Remove
       clr_scrn();
       clr_scrn();
       cout<< "Enter Part number you wish to remove: " << endl;
       cin>> partspec;
       list.remove(partspec);
       break;

     case 6: // Quit
       list.pushto_out(ofile1_init);
       clr_scrn();
       cout<< "Writing to output file.\nQuitting program...\n"<< endl;
       return 0; // return sucessfull

     default:
       list.pushto_out(ofile1_init);
       clr_scrn();
       cout<< "You have entered an invalid choice.\n";
       cerr<< "Program has been aborted." <<endl;
       return 1;//return error

   }


} while(1);

/* 
   cout<<endl;
   cout << "end of program !!! \n";
   cout.flush(); // flush output
   return 0;

*/

}

