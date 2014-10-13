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
/*
   double r_val = 1000;
   int    r_quant = 2;
   rptr = new Resistor(r_val,r_quant); 
*/

   list.track = 0; // track number of items in list
   int number=0;
   int num_add =0;

   double in_num = 0.00; 
   int in_num_r = 0;
   string in_string;

//-----------------------------------------------------------------
        int track = 1;
        int flag = 0;
        double value = 0.00;
        int quant = 0;
        string casetype;
        string getinfo;
        char buffer[10];
        string str;
        char* cstr = new char[str.length()];

	/* Load data into array */
	fstream ifile_1("output4.txt",ios::in);
	fstream ifile_2("output4.txt",ios::in); // used for to track # of entries

      while(ifile_2)
      {
        ifile_2>> getinfo;
        flag++;
      }
 
       int stop = flag -1; // break value
       flag = 0; // reset flag

       while(ifile_1)
        {
          ifile_1>> str;
          strcpy(cstr, str.c_str()); // cstr contains a cstyle string copr of str

          if(track == 1)
            {
             value = atof(cstr);
            }
          if(track == 2)
            {
             quant = atoi(cstr);
            }
          if(track == 3)
            {
             casetype = cstr;
		      rptr = new Resistor(value,quant,casetype);
		      list.insert(rptr,value);
             track = 0; // reset
            }

          track++;
          flag++;

          if(flag == stop)
           break;
       }


   
       delete[] cstr;

//-----------------------------------------------------------------
	/* CREATE I/O OBJECTS USED FOR COPYING */
	fstream ifile("output1.txt", ios::in);
	fstream ifile2("output2.txt", ios::in);
	fstream ifile3("output3.txt", ios::in);


	fstream ofile("input1.txt", ios::out); 
	fstream ofile2("input2.txt", ios::out); 
	fstream ofile3("input3.txt", ios::out); 

	/* COPY OUTPUT FILE TO INPUT FILE */
	ofile << ifile.rdbuf();
	ofile2 << ifile2.rdbuf();
	ofile3 << ifile3.rdbuf();

	/* CLOSE THE OUTPUT & INPUT FILES */
	ofile.close();
	ofile2.close();
	ofile3.close();

	ifile.close();
	ifile2.close();
	ifile3.close();

	/* CREATE NEW I/O OBJECTS */
	fstream ifile1("input1.txt", ios::in);
        fstream ifile1_r("input2.txt", ios::in);
        fstream ifile1_rr("input3.txt", ios::in);


	fstream ofile1("output1.txt", ios::out); 
	fstream ofile1_r("output2.txt", ios::out); 
	fstream ofile1_rr("output3.txt", ios::out); 

	fstream ofile1_init("output4.txt", ios::out); 

/* LOAD INPUT FILES INTO LIST */
//------------------------------------------
/*
   ifile1 >> in_num;
   ifile1_r >> in_num_r;
   ifile1_rr >> in_string;

   while(ifile1 && ifile1_r && ifile1_rr)
    {
      rptr = new Resistor(in_num,in_num_r,in_string);
      list.insert(rptr,in_num);
      ifile1 >> in_num;
      ifile1_r >> in_num_r;
      ifile1_rr >> in_string;
    }
*/

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
       cout<< endl;
       user_choice();
       clr_scrn();
       break;

     case 9: // QUIT
       list.pushto_out(ofile1, ofile1_r,ofile1_rr, ofile1_init);
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

