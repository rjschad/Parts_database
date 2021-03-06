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
#include <assert.h>
#include "list.h"

#define TRUE 1
#define FALSE 0


using namespace std;

/* instantiate object */

List list;

////////////////////////////////////////////////////////////
/*

Desc: User display and input
In: None
Out: integer to indicate user choice value

*/

int Display(void)
{
  int choice = 0;
  
  cout<<"DOUBLY LINKED LIST" << endl;
  cout<<"1) Add Front" << endl; 
  cout<<"2) Add Back" << endl; 
  cout<<"3) Count" << endl;
  cout<<"4) Empty" << endl; 
  cout<<"5) Remove Front" << endl;
  cout<<"6) Remove Back" << endl;
  cout<<"7) Insert" << endl;
  cout<<"8) Print" << endl<<endl;;

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

////////////////////////////////////////////////////////////
/*

Desc: main function
In: No command line args other than basic console info
Out: int 1 = success

*/

int main( int argc, char* argv[])
{

   list.track = 0; // track number of items in list
   int number=0;
   int num_add =0;


 do
 {
  clr_scrn(); //clear screen initally
   switch(Display()) // act on user input
   {
     case 1: // ADD FRONT
       clr_scrn();
       cout<< "Add number to front: " << endl;
       cin>> num_add;
       list.addfront(num_add);
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
       list.addback(num_add);
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
       clr_scrn();
       cout<< "Insert number: " << endl;
       cin >> number;
       list.track++;
       list.insert(number);
       clr_scrn();
       list.print();
       user_choice();
       clr_scrn();
       break;

     case 8: // PRINT
       clr_scrn();
       list.print();
       user_choice();
       clr_scrn();
       break;

     default:
       cout<<" Invalid entry: Exiting program." << endl;
       return 1; // return error

   }


} while(1); // infinite loop force

   cout<<endl;
   cout << "end of program !!! \n";
   cout.flush(); // flush output
   
   return 0;

}

