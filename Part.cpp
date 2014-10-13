#include <iostream>
#include <string>
using namespace std;

#include "Part.h"

/*  CONSTRUCTOR  */

Resistor::Resistor(double value, int quant, string casetype, string partno)
{
   m_case = casetype;
   m_value = value;
   m_quant = quant;
   m_partno = partno;
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

int Resistor::get_quant()
{
  double quant = m_quant;
  return quant;
}

string Resistor::get_case()
{
  string casetype = m_case; 
  return casetype;
}

string Resistor::get_partno()
{
  string partno = m_partno;
  return partno;
}
