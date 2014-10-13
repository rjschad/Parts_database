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
#include "list.h"
#include "Part.h"
//#include "var.h"
#include <fstream>
#include <iostream>

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

Desc: lookup specific part
In: number (double)
Out: none

*/


void List::lookup(Resistor* r_ptr, double num)
{
   ptr_lookup = ptr_head;
   
   if(ptr_head == NULL)
     {
      cout<< "No match found beacuse list is empty." << endl;
      return; 
     }

    //cout<< "here1" << endl;
    //cout<<"ptr: " <<ptr_lookup << endl;
    //cout<<"ptr->m_next: "<< ptr_lookup->m_ptr_next << endl;
   
   while(num > ptr_lookup->r_ptr->get_value() && ptr_lookup->m_ptr_next != NULL)
     ptr_lookup = ptr_lookup->m_ptr_next;
 
    //cout<< "here2" << endl;

    if(ptr_lookup->r_ptr->get_value() == num)
      {  
         //cout<< "here3" << endl;
         cout<< "Match found:" << num << endl;
         return;
      }

   while(num < ptr_lookup->r_ptr->get_value() && ptr_lookup->m_ptr_prev != NULL)
     ptr_lookup = ptr_lookup->m_ptr_prev;
 
    if(ptr_lookup->r_ptr->get_value() == num)
      {  
         cout<< "Match found:" << num << endl;
         return;
      }

    cout<<"Entry not found" << endl;

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

   cout<<"\t\t ------ Resistor Database -------" << endl << endl;

  /*  print and traverse list  */

  while(ptr_print != NULL)
  {
     cout<< "Resistor value (ohms): " << ptr_print -> r_ptr-> get_value();
     cout<<"\t";
     cout<< "Quantity: " << ptr_print->r_ptr-> get_quant();
     cout<<"\t";
     cout<< "Case: " << ptr_print->r_ptr->get_case() << endl;

     ptr_print = ptr_print->m_ptr_next;
     tracker++;

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
     fileout4 << ptr_print -> r_ptr-> get_value();
     fileout4<<"\t";
     fileout4 << ptr_print->r_ptr-> get_quant();
     fileout4<<"\t";
     fileout4 << ptr_print->r_ptr->get_case() << endl;

     ptr_print = ptr_print->m_ptr_next;
  }

}





