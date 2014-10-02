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

    void lookup(double num); // lookup specific part
    void print();            // print list
    void insert(double num); // insert in order
    bool empty();            // check if list is empty
    void addfront(int num);  // add to front of list
    void addback(int num);   // add to back of list
    void remove_front(void); // remove from front of list
    void remove_back(void);  // remove from back of list
    int  track;              // track number of elements in list

  private:   

   class Node
    {
     public:
       Node(Node* prev, Node* next, double num)
       {
         m_ptr_prev = prev; // pointer to next node
         m_ptr_next = next; // pointer to previous node
         m_num = num;
       }

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
