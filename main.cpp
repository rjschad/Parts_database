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
#include <fstream>
#include <stdlib.h>
#include <assert.h>
#include "var.h"
#include "Part.h"
#include "list.h"
#include "functions.h"

#define TRUE 1
#define FALSE 0

using namespace std;

/* GLOBAL DECLARTION */
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
   double r_val = 1000;
   int    r_quant = 2;
   rptr = new Resistor(r_val,r_quant); // defined in var.h as Extern pointer to resistor object
 
   list.track = 0; // track number of items in list
   int number=0;
   int num_add =0;
   double in_num = 0.00; 

	/* CREATE I/O OBJECTS USED FOR COPYING */
	fstream ifile("output1.txt", ios::in);
	fstream ofile("input1.txt", ios::out); 

	/* COPY OUTPUT FILE TO INPUT FILE */
	ofile << ifile.rdbuf();
	ofile.close();
	ifile.close();

	/* CREATE NEW I/O OBJECTS */
	fstream ifile1("input1.txt", ios::in);
	fstream ofile1("output1.txt", ios::out); 

/* LOAD INPUT FILES INTO LIST */
//------------------------------------------
   ifile1 >> in_num;

   while(ifile1)
    {
      list.insert(rptr,in_num);
      ifile1 >> in_num;
    }
//------------------------------------------

 do
 {
  clr_scrn(); //clear screen initally
   switch(Display()) // act on user input
   {
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

     case 7: // INSERT
       insert_case();
       break;

     case 8: // PRINT
       clr_scrn();
       list.print();
       user_choice();
       clr_scrn();
       break;

     case 9: // QUIT
       list.pushto_out(ofile1); // write list contents to output file
       clr_scrn();
       cout<< "Writing to output file.\nQuitting program...\n"<< endl;
       return 0; // return sucessfull

     case 10: // SEARCH
       search_case();
       break;

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

