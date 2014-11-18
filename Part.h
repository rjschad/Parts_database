#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>

using namespace std;

  class Resistor
{
    public:
       Resistor(double, int, string, string, string, double, string);
       void print();
       double get_value();
       int get_quant();
       string get_case();
       string get_partno();
       string get_smd();
       double get_lev();
       string get_power();
       void edit_quant(int changeValue);
       void edit_case(string changeCase);
       void edit_partno(string changePartno);
       void edit_smd(string changeSmd);
       void edit_pwr(string changePwr);
       void edit_lev(double changeLev);

     private:
       double m_value;
       int m_quant;
       string m_case;
       string m_partno;
       string m_smd;
       string m_power;
       double m_lev;
};

#endif
