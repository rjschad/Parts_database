#include <iostream>
#include <string>
using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void load_file();
void user_choice();
void clr_scrn(void);
void empty();
double parser(void);
int Display(void);
char* adv_search(string thepartNo);
bool userPart_srch(char* ptr1, string datapart);

/* CASE: INSERT  */
void insert_case(void);
void search_case(void);

#endif
