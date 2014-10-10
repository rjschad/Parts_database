#ifndef PART_H
#define PART_H

#include <iostream>

  class Resistor
{
    public:
       Resistor(double, int);// double value, int quantity
       void print();
       double get_value();
       int get_quant();

     private:
       double m_value;
       int m_quant;
};

#endif
