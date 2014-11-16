/*
 * =====================================================================================
 *
 *   Program name:  list.cpp
 *         Author:  Raymond Schad (Rio)
 *      Course No:  CSCI 311
 *
 *   Project Desc:  Define List Class functions
 *
 *        Created:  09/12/2014 9:47:04
 *       Compiler:  gcc 4.8.2
 *
 * =====================================================================================
 */

#include <string>
#include <stdio.h>
#include "list.h"
#include "Part.h"
#include "functions.h"
#include "var.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

////////////////////////////////////////////////////////////
/*

Desc: constructor
In: None
Out: None

*/

List::List()
{
  ptr_head = NULL;
  ptr_tmp = ptr_head;
  ptr_lookup = ptr_head;
}

////////////////////////////////////////////////////////////
/*

Desc: destructor: deallocate memory
In: none
Out: none

*/

List::~List()
 {
   Node* ptr = ptr_head;

   while(ptr != NULL)
   {
     Node* ptr_tmp;

     ptr_tmp = ptr;
     ptr = ptr->m_ptr_next;
     delete ptr_tmp;
   }
 }

////////////////////////////////////////////////////////////
/*

Desc: lookup specific part by value
In: number (double)
Out: none

*/


void List::lookup(Resistor* r_ptr, double num)
{


   int tracker = 0;
   ptr_lookup = ptr_head;
    
   if(ptr_head == NULL)
     {
      cout<< "No match found beacuse list is empty." << endl;
      return; 
     }

   if(ptr_lookup->r_ptr->get_value() == num)
      tracker++;
     

   while(ptr_lookup->m_ptr_next != NULL)
   {
     ptr_lookup = ptr_lookup->m_ptr_next;
 
     if(ptr_lookup->r_ptr->get_value() == num)
         tracker++;
    }

        if(tracker == 1)
         cout<< tracker << " match found: " << num << endl;
        if(tracker > 1)
         cout<< tracker << " matches found: " << num << endl;

   ptr_lookup = ptr_head; // reset ptr
   
  if(ptr_lookup->r_ptr->get_value() == num)
        {  
         cout<< "Resistor value (ohms): " << ptr_lookup -> r_ptr-> get_value();
         cout<<"\t";
         cout<< "Quantity: " << ptr_lookup->r_ptr-> get_quant();
         cout<<"\t";
         cout<< "Case: " << ptr_lookup->r_ptr->get_case();
         cout<<"\t";
         cout<< "Pwr(watts): " << ptr_lookup->r_ptr->get_power();
         cout<<"\t\t";
         cout<< "Descr: " << ptr_lookup->r_ptr->get_smd();
         cout<<"\t\t";
         cout<< "Lim Volt: " << ptr_lookup->r_ptr->get_lev();
         cout<<"\t\t";
         cout<< "Part No: " << ptr_lookup->r_ptr->get_partno()<< endl;
        }
     

   while(ptr_lookup->m_ptr_next != NULL)
   {
     ptr_lookup = ptr_lookup->m_ptr_next;
 
     if(ptr_lookup->r_ptr->get_value() == num)
        {  
         cout<< "Resistor value (ohms): " << ptr_lookup -> r_ptr-> get_value();
         cout<<"\t";
         cout<< "Quantity: " << ptr_lookup->r_ptr-> get_quant();
         cout<<"\t";
         cout<< "Case: " << ptr_lookup->r_ptr->get_case();
         cout<<"\t";
         cout<< "Pwr(watts): " << ptr_lookup->r_ptr->get_power();
         cout<<"\t\t";
         cout<< "Descr: " << ptr_lookup->r_ptr->get_smd();
         cout<<"\t\t";
         cout<< "Lim Volt: " << ptr_lookup->r_ptr->get_lev();
         cout<<"\t\t";
         cout<< "Part No: " << ptr_lookup->r_ptr->get_partno()<<endl;
        }
     }

 if(tracker == 0)
    cout<< "None found" << endl;
}

////////////////////////////////////////////////////////////
/*

Desc: lookup specific part by part no.
In: part no (string)
Out: none

*/


void List::lookup_bypartnum(string partnum)
{
   int tracker = 0;
   ptr_lookup = ptr_head;
   cout<< "Part no. entered: " << partnum << endl;
   
   if(ptr_head == NULL)
     {
      cout<< "No match found beacuse list is empty." << endl;
      return; 
     }

    //cout<< "here1" << endl;
    //cout<<"ptr: " <<ptr_lookup << endl;
    //cout<<"ptr->m_next: " << ptr_lookup->m_ptr_next << endl;
    
 // cout<<"here0" <<endl;   
   
  while(partnum !=  ptr_lookup->r_ptr->get_partno() && ptr_lookup->m_ptr_next != NULL) //traverse list fwd
   {
   //  cout<<"here1" << endl;
     ptr_lookup = ptr_lookup->m_ptr_next;
   }

   //found partnumber

     cout<<"printing part no: " << ptr_lookup->r_ptr->get_partno() << endl;
     cout<<"printing part value: " << ptr_lookup->r_ptr->get_value() << endl;
  //   cout<<"here2" << endl;


    if(ptr_lookup->r_ptr->get_partno() == partnum)
      {  
         cout<< "here3" << endl;
         tracker++;
         cout<< endl;
         cout<< tracker << " match found:" << partnum << endl;
         cout<< "Resistor value (ohms): " << ptr_lookup -> r_ptr-> get_value();
         cout<<"\t";
         cout<< "Quantity: " << ptr_lookup->r_ptr-> get_quant();
         cout<<"\t";
         cout<< "Case: " << ptr_lookup->r_ptr->get_case();
         cout<<"\t";
         cout<< "Pwr(watts): " << ptr_lookup->r_ptr->get_power();
         cout<<"\t\t";
         cout<< "Descr: " << ptr_lookup->r_ptr->get_smd();
         cout<<"\t\t";
         cout<< "Lim Volt: " << ptr_lookup->r_ptr->get_lev();
         cout<<"\t\t";
         cout<< "Part No: " << ptr_lookup->r_ptr->get_partno()<<endl;
         return;
      }
     else
      cout<< "Not found" << endl;

}


////////////////////////////////////////////////////////////
/*

Desc: lookup specific part by part no.
In: part no (string)
Out: none

*/


void List::adv_search_partno(void)
{
    
   trck1 = 0;
   int tracker = 0;
   string partnum;

   cout<<"Enter any part number: " << endl;
   cout<<"...searching...." << endl << endl;
   cin>> partnum;
   cout<< endl << endl;

//break string into c style string....cin --> char* adv_search(string thepartNo)
   
 char* cstyPtr =  adv_search(partnum); // return pointer to array that holds c-style string


/*_________________________________________________________________________________________*/

   ptr_lookup = ptr_head; // set ptr to head

   if(ptr_head == NULL)
     {
      cout<< "No match found because list is empty." << endl;
      return; 
     }
    
  while(ptr_lookup->m_ptr_next != NULL) 
   {
     string getpart = ptr_lookup->r_ptr->get_partno();
     /* pass 'getpart' & cstyPtr to userPart_srch() to compare, return true if match else false*/

     if(userPart_srch(cstyPtr, getpart))
     {
       cout<< ptr_lookup->r_ptr->get_partno()<<endl;
       tracker++;
     }

     ptr_lookup = ptr_lookup->m_ptr_next; // go to next
   }

  cout<< endl;
  cout<< tracker << " matches that fit your description." << endl;


/*  
    if(ptr_lookup->r_ptr->get_partno() == partnum)
      {  
         cout<< "here3" << endl;
         tracker++;
         cout<< endl;
         cout<< tracker << " match found:" << partnum << endl;
         cout<< "Resistor value (ohms): " << ptr_lookup -> r_ptr-> get_value();
         cout<<"\t";
         cout<< "Quantity: " << ptr_lookup->r_ptr-> get_quant();
         cout<<"\t";
         cout<< "Case: " << ptr_lookup->r_ptr->get_case();
         cout<<"\t";
         cout<< "Pwr(watts): " << ptr_lookup->r_ptr->get_power();
         cout<<"\t\t";
         cout<< "Descr: " << ptr_lookup->r_ptr->get_smd();
         cout<<"\t\t";
         cout<< "Lim Volt: " << ptr_lookup->r_ptr->get_lev();
         cout<<"\t\t";
         cout<< "Part No: " << ptr_lookup->r_ptr->get_partno()<<endl;
         return;
      }
     else
      cout<< "Not found" << endl;
*/

}

////////////////////////////////////////////////////////////
/*

Desc: lookup specific part by case
In: number (double)
Out: none

*/


void List::lookup_bycase(string casetype)
{
   int tracker = 0;
   ptr_lookup = ptr_head;
    
   if(ptr_head == NULL)
     {
      cout<< "No match found beacuse list is empty." << endl;
      return; 
     }

   if(ptr_lookup->r_ptr->get_case() == casetype)
      tracker++;
     

   while(ptr_lookup->m_ptr_next != NULL)
   {
     ptr_lookup = ptr_lookup->m_ptr_next;
 
     if(ptr_lookup->r_ptr->get_case() == casetype)
         tracker++;
    }

        if(tracker == 1)
         cout<< tracker << " match found: " << casetype << endl;
        if(tracker > 1)
         cout<< tracker << " matches found: " << casetype << endl;

   ptr_lookup = ptr_head; // reset ptr
   
  if(ptr_lookup->r_ptr->get_case() == casetype)
        {  
         cout<< "Resistor value (ohms): " << ptr_lookup -> r_ptr-> get_value();
         cout<<"\t";
         cout<< "Quantity: " << ptr_lookup->r_ptr-> get_quant();
         cout<<"\t";
         cout<< "Case: " << ptr_lookup->r_ptr->get_case();
         cout<<"\t";
         cout<< "Pwr(watts): " << ptr_lookup->r_ptr->get_power();
         cout<<"\t\t";
         cout<< "Descr: " << ptr_lookup->r_ptr->get_smd();
         cout<<"\t\t";
         cout<< "Lim Volt: " << ptr_lookup->r_ptr->get_lev();
         cout<<"\t\t";
         cout<< "Part No: " << ptr_lookup->r_ptr->get_partno()<< endl;
        }
     

   while(ptr_lookup->m_ptr_next != NULL)
   {
     ptr_lookup = ptr_lookup->m_ptr_next;
 
     if(ptr_lookup->r_ptr->get_case() == casetype)
        {  
         cout<< "Resistor value (ohms): " << ptr_lookup -> r_ptr-> get_value();
         cout<<"\t";
         cout<< "Quantity: " << ptr_lookup->r_ptr-> get_quant();
         cout<<"\t";
         cout<< "Case: " << ptr_lookup->r_ptr->get_case();
         cout<<"\t";
         cout<< "Pwr(watts): " << ptr_lookup->r_ptr->get_power();
         cout<<"\t\t";
         cout<< "Descr: " << ptr_lookup->r_ptr->get_smd();
         cout<<"\t\t";
         cout<< "Lim Volt: " << ptr_lookup->r_ptr->get_lev();
         cout<<"\t\t";
         cout<< "Part No: " << ptr_lookup->r_ptr->get_partno()<<endl;
        }
     }

 if(tracker == 0)
    cout<< "None found" << endl;
}


////////////////////////////////////////////////////////////
/*

Desc: lookup specific part by case
In: number (double)
Out: none

*/

void List::remove(string partnumber)
{
   int tracker = 0;
   ptr_lookup = ptr_head;
    
   if(ptr_head == NULL)
     {
      cout<< "No match found beacuse list is empty." << endl;
      return; 
     }

   if(ptr_lookup->r_ptr->get_partno() == partnumber)
      tracker++;
   

   while(ptr_lookup->m_ptr_next != NULL)
   {
     ptr_lookup = ptr_lookup->m_ptr_next;
 
     if(ptr_lookup->r_ptr->get_partno() == partnumber)
         tracker++;
   }
        if(tracker == 1)
         cout<< tracker << " match found: " << partnumber << endl;
        if(tracker > 1)
         cout<< tracker << " matches found: " << partnumber << endl;

   ptr_lookup = ptr_head; // reset ptr

   cout<< "Is this the part you wish to remove: " << endl;
   
  if(ptr_lookup->r_ptr->get_partno() == partnumber)
        {  
         cout<< "Resistor value (ohms): " << ptr_lookup -> r_ptr-> get_value();
         cout<<"\t";
         cout<< "Quantity: " << ptr_lookup->r_ptr-> get_quant();
         cout<<"\t";
         cout<< "Case: " << ptr_lookup->r_ptr->get_case();
         cout<<"\t";
         cout<< "Pwr(watts): " << ptr_lookup->r_ptr->get_power();
         cout<<"\t\t";
         cout<< "Descr: " << ptr_lookup->r_ptr->get_smd();
         cout<<"\t\t";
         cout<< "Lim Volt: " << ptr_lookup->r_ptr->get_lev();
         cout<<"\t\t";
         cout<< "Part No: " << ptr_lookup->r_ptr->get_partno()<< endl;
        }

}


////////////////////////////////////////////////////////////
/*

Desc: add number to back of list
In: number (num)
Out: none

*/
void List::addback(Resistor* r_ptr , int num)
{
  ptr_addback = ptr_head;

/* check if list is empty  */

  if(ptr_head == NULL)
    ptr_head = new Node(NULL,ptr_head,num, r_ptr);

  else
 {
    while(ptr_addback->m_ptr_next != NULL)
      ptr_addback =  ptr_addback->m_ptr_next;

/*  traverse list until end is found  */

    ptr_addback->m_ptr_next = new Node(ptr_addback,ptr_addback->m_ptr_next,num, r_ptr);
 }

 ptr_tmp = ptr_head;
}

////////////////////////////////////////////////////////////
/*

Desc: remove number from front of list
In: none
Out: none

*/

void List::remove_front(void)
{

  ptr_remover = ptr_head; 


/*  check if list is empty  */

  if(ptr_head == NULL)
  {cout<<"Empty List" <<endl; return;}

    if(ptr_head != NULL)
    {
      ptr_head = ptr_head->m_ptr_next;

        if(ptr_head == NULL)
        {
          delete ptr_remover;
          cout<< "Empty list"<< endl;
          return;
        }
      
        ptr_head->m_ptr_prev = NULL;
     }


/*  deallocate memory  */

    delete ptr_remover;


}

////////////////////////////////////////////////////////////
/*

Desc: remove number from back
In: none
Out: none

*/

void List::remove_back(void)
{
  ptr_backrmv = ptr_head;

 
/*  check if list is empty  */

  if(ptr_head == NULL)
  {cout<<"Empty List" <<endl; return;}


/*  while there is not one entry in list  */

  while(ptr_backrmv->m_ptr_next != NULL)
  {
    ptr_backrmv = ptr_backrmv -> m_ptr_next;
  }
  

/*  check if there are only 2 numbers in list  */

  if(ptr_head -> m_ptr_next == NULL)
  {
    ptr_backrmv = ptr_head;
    ptr_head = NULL;
    delete ptr_backrmv;

  }

/*  else traverse list backwards */

  else
  {
   ptr_backrmv->m_ptr_prev->m_ptr_next = NULL;
   delete ptr_backrmv;
  }

}

////////////////////////////////////////////////////////////
/*

Desc: add number to front of list
In: num (number)
Out: none

*/

void List::addfront(Resistor* r_ptr,int num)
{

/*  check if list is empty  */

  if(ptr_head == NULL)
    ptr_head = new Node(NULL,ptr_head,num,r_ptr);

/*  set the nodes  */
  else
  {
   ptr_head = new Node(NULL,ptr_head,num, r_ptr);
   ptr_head->m_ptr_next->m_ptr_prev = ptr_head;
  }

}


////////////////////////////////////////////////////////////
/*

Desc: insert and sort number into list
In: num (number)
Out: none

*/

void List::insert(Resistor* r_ptr, double num)
{

/*------ FRONT INSERTION: EMPTY LIST -----*/
   
  ptr_tmp = ptr_head;

  if(ptr_head == NULL)
  {
    ptr_head = new Node(ptr_head,ptr_head,num, r_ptr);
    ptr_tmp = ptr_head;
    return;
  }

/*------ FRONT INSERTION: BEGINNING -----*/

  if(num < ptr_head->r_ptr->get_value())
  {
    ptr_head = new Node(NULL,ptr_head,num, r_ptr);
    ptr_head->m_ptr_next->m_ptr_prev = ptr_head;
    ptr_tmp = ptr_head;
    return;
  }

/* ----- SAME NUMBER IN FRONT ---- */ 

  if(num == ptr_head->r_ptr->get_value())
  {
    if(ptr_head->m_ptr_next == NULL)
    {
      ptr_head->m_ptr_next = new Node(ptr_head,ptr_head->m_ptr_next,num, r_ptr);
      ptr_head->m_ptr_next->m_ptr_prev = ptr_head;
      return;
    }
    else
    {
      ptr_head->m_ptr_next = new Node(ptr_head,ptr_head->m_ptr_next,num,r_ptr);
      ptr_head->m_ptr_next->m_ptr_next->m_ptr_prev = ptr_head -> m_ptr_next;
      return;
    }
      
  }

/* ----- REAR INSERTION ---- */ 

  if(ptr_head->m_ptr_next == NULL && num > ptr_head->r_ptr->get_value())
  {
    ptr_head->m_ptr_next = new Node(ptr_head,ptr_head->m_ptr_next,num, r_ptr);
    return;
  }

/* ----- FOWARD TRAVERSE ---- */


  while(num > ptr_tmp->r_ptr->get_value() && ptr_tmp -> m_ptr_next != NULL)
  {
    ptr_tmp=ptr_tmp->m_ptr_next;
  }


    if(num == ptr_tmp->r_ptr->get_value())
    {

      /*  check if inserting at end of list */

      if(ptr_tmp->m_ptr_next == NULL)
      {
        ptr_tmp->m_ptr_next = new Node(ptr_tmp,ptr_tmp->m_ptr_next,num, r_ptr);
        return;
      }

      ptr_tmp->m_ptr_next = new Node(ptr_tmp,ptr_tmp->m_ptr_next,num, r_ptr);
      ptr_tmp->m_ptr_next->m_ptr_next->m_ptr_prev = ptr_tmp->m_ptr_next;
      return;
    }


     /*  user number is greater than present number  */

    if(num > ptr_tmp->r_ptr->get_value())
    {
      ptr_tmp->m_ptr_next = new Node(ptr_tmp,ptr_tmp->m_ptr_next,num, r_ptr);
      return;
    }


/* ----- BACKWARDS TRAVERSE ---- */

 /*  user number is less than present number  */

  while(num < ptr_tmp->r_ptr->get_value())
  {
    ptr_tmp=ptr_tmp->m_ptr_prev;
  }

   /*  if user number is equal to current number  */

    if(num == ptr_tmp->r_ptr->get_value())
    {
      ptr_tmp->m_ptr_next = new Node(ptr_tmp,ptr_tmp->m_ptr_next,num, r_ptr);
      ptr_tmp->m_ptr_next->m_ptr_next->m_ptr_prev = ptr_tmp->m_ptr_next;
      return;
    }

   /*  if user number is greater to current number  */

    if(num > ptr_tmp->r_ptr->get_value())
    {
      ptr_tmp->m_ptr_next = new Node(ptr_tmp,ptr_tmp->m_ptr_next,num, r_ptr);
      ptr_tmp=ptr_tmp->m_ptr_next;
      ptr_tmp->m_ptr_next->m_ptr_prev = ptr_tmp;
      return;
    }
  
     
}

////////////////////////////////////////////////////////////
/*

Desc: print list
In: none
Out: none

*/

void List::print()
{
  Node* ptr_print = ptr_head;
  int tracker = 0;

  //empty list check

  if(ptr_head == NULL)
  {
    cout<< "Empty List" << endl;
    return;
  }
  
  while(ptr_print != NULL)
  {
     ptr_print = ptr_print->m_ptr_next;
     tracker++;
  }
   
  ptr_print = ptr_head; //reset ptr
   
   cout<<"\t\t\t******************************************************" << endl;
   cout<<"\t\t\t*                                                    *" << endl;
   cout<<"\t\t\t*                   Resistor Database                *" << endl;
   cout<<"\t\t\t*                                                    *" << endl;
   cout<<"\t\t\t******************************************************" << endl <<endl <<endl;

   cout<<"\t\t\t*              Currently in  stock: " << tracker << "               *" << endl << endl;

  cout<<"______________________________________________________________________________________________________" <<endl<<endl;
  cout<<" Value(ohms)   Quantity    Case      Pwr(watts)       Description        Lim Volt          Part. No" << endl;
  cout<<"______________________________________________________________________________________________________" <<endl << endl << endl;
  
   int flag1 = 0;
   int flag2 = 0;
   int flag3 = 0;
   int flag4 = 0;
   int flag5 = 0;
   int flag6 = 0;

  /*  print and traverse list  */

  while(ptr_print != NULL)
  {
   
    // Seperate decades
    if(ptr_print -> r_ptr ->get_value() == 10 && flag1 == 0)
    {
      cout<<"______________________________________________________________________________________________________" <<endl<<endl;
      flag1 = 1;//set flag to prevent multiple inclusions
    }

    if(ptr_print -> r_ptr ->get_value() == 100 && flag2 == 0)
    {
      cout<<"______________________________________________________________________________________________________" <<endl<<endl;
      flag2 = 1;//set flag to prevent multiple inclusions
    }

    if(ptr_print -> r_ptr ->get_value() == 1000 && flag3 == 0)
    {
      cout<<"______________________________________________________________________________________________________" <<endl<<endl;
      flag3 = 1;//set flag to prevent multiple inclusions
    }

    if(ptr_print -> r_ptr ->get_value() == 10000 && flag4 == 0)
    {
      cout<<"______________________________________________________________________________________________________" <<endl<<endl;
      flag4 = 1;//set flag to prevent multiple inclusions
    }

    if(ptr_print -> r_ptr ->get_value() == 100000 && flag5 == 0)
    {
      cout<<"______________________________________________________________________________________________________" <<endl<<endl;
      flag5 = 1;//set flag to prevent multiple inclusions
    }

    if(ptr_print -> r_ptr ->get_value() == 1000000 && flag6 == 0)
    {
      cout<<"______________________________________________________________________________________________________" <<endl<<endl;
      flag6 = 1;//set flag to prevent multiple inclusions
    }


     cout << " ";
     cout << setprecision(7) << ptr_print -> r_ptr-> get_value() << "       "; 
     cout<<"\t";
     cout<< ptr_print->r_ptr-> get_quant() <<"    ";  
     cout<<"\t  ";
     cout<< ptr_print->r_ptr->get_case() <<"   ";
     cout<<"\t";
     cout<< ptr_print->r_ptr->get_power() <<"   ";
     cout<<"\t    ";
     cout<<ptr_print->r_ptr->get_smd() <<"    ";
     cout<<"\t  ";
     cout<< ptr_print->r_ptr->get_lev() <<"    ";
     cout<<"\t  ";
     cout<< ptr_print->r_ptr->get_partno()<<endl;

     ptr_print = ptr_print->m_ptr_next;

  }


}


////////////////////////////////////////////////////////////
/*

Desc: check if list is empty
In: none
Out: True/False

*/


bool List::empty()
{
   if(ptr_head==NULL)
     return true;
   else
     return false;
}

////////////////////////////////////////////////////////////
/*

Desc: push list to designated ouput file
In: none
Out: none

*/

void List:: pushto_out(fstream& fileout4)
{
 
  Node* ptr_print = ptr_head;

  while(ptr_print != NULL) 
  {
     /* fileout4 outputs everything */
     fileout4 << setprecision(7) << ptr_print -> r_ptr-> get_value();
     fileout4<<"\t";
     fileout4 << ptr_print->r_ptr-> get_quant();
     fileout4<<"\t";
     fileout4 << ptr_print->r_ptr->get_case();
     fileout4<<"\t";
     fileout4 << ptr_print->r_ptr->get_partno();
     fileout4<<"\t";
     fileout4 << ptr_print->r_ptr->get_smd();
     fileout4<<"\t";
     fileout4 << ptr_print->r_ptr->get_lev();
     fileout4<<"\t";
     fileout4 << ptr_print->r_ptr->get_power() << endl;

     ptr_print = ptr_print->m_ptr_next;
  }

}





