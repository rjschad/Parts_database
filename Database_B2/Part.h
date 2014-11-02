#ifndef PART_H
#define PART_H

#include <iostream>

  class Resistor
{
    public:
       Resistor(double, int);// double value, int quantity
       void print();
       double get_value();

     private:
       double m_value;
       int m_quant;
};

#endif
