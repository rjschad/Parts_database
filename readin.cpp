#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{

 double number = 0.00;
 ifstream input("output1.txt");

 input >> number;

 while(input)
  {
    cout << "number: " << number << endl;
    input >> number;
  }

 
 return 0;

}

