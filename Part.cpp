#include <iostream>
#include <string>
using namespace std;

#include "Part.h"

/*  CONSTRUCTOR  */

Resistor::Resistor(double value, int quant)
{
   m_value = value;
   m_quant = quant;
}

void Resistor::print()
{
   cout<< "Value: " << m_value << endl;
   cout<< "Quantity: " << m_quant << endl;
}

double Resistor::get_value()
{
  double value = m_value; 
  return value;
}
