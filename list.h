/*
 * =====================================================================================
 *
 *   Program name:  list.h
 *         Author:  Raymond Schad (Rio)
 *      Course No:  CSCI 311
 *
 *   Project Desc:  Define List Class
 *
 *        Created:  09/12/2014 15:13:04
 *       Compiler:  gcc 4.8.2
 *
 * =====================================================================================
 */

#ifndef LIST_H
#define LIST_H

#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "Part.h"
using namespace std;

////////////////////////////////////////////////////////////
/*

Desc: Define Class "List"
In: None
Out: None

*/

class List
{
  public:

    List(); // contructor
   ~List(); // destructor
   
    void pushto_out(fstream& filoeout4);
    void lookup(Resistor* r_ptr, double num); // lookup specific part by value
    void lookup_bycase(string casetype); // lookup specific part by case
    void lookup_bypartnum(Resistor* r_ptr, string partnum); // lookup specific part by case
    void print();                             // print list
    void insert(Resistor* r_ptr, double num); // insert in order
    bool empty();                             // check if list is empty
    void addfront(Resistor* r_ptr, int num);  // add to front of list
    void addback(Resistor* r_ptr, int num);   // add to back of list
    void remove_front(void);                  // remove from front of list
    void remove_back(void);                   // remove from back of list
    int  track;                               // track number of elements in list

  private:   

   class Node
    {
     public:
       Node(Node* prev, Node* next, double num, Resistor* res_ptr)
       {
         m_ptr_prev = prev; // pointer to next node
         m_ptr_next = next; // pointer to previous node
         m_num = num; // this is getting moved to the Resistor class
         r_ptr = res_ptr;
       }

       Resistor* r_ptr;
       Node* m_ptr_prev; // previous pointer
       Node* m_ptr_next; // next pointer
       double m_num;        // number stores in node

    };

 Node* ptr_head;    // pointer to head of list
 Node* ptr_tmp;     // temp pointer for travsersing and inserting
 Node* ptr_print;   // pointer for printer function
 Node* ptr_back;    // pointer to last node
 Node* ptr_remover; // pointer removes front numbers
 Node* ptr_backrmv; // pointer removes back numbers
 Node* ptr_addback; // pointer adds numbers to back of list
 Node* ptr_lookup;  // pointer used for lookup

};


#endif
