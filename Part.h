#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>

using namespace std;

  class Resistor
{
    public:
       Resistor(double, int, string, string);// double value, int quantity
       void print();

       double get_value();
       int get_quant();
       string get_case();
       string get_partno();

     private:
       double m_value;
       int m_quant;
       string m_case;
       string m_partno;
};

#endif
