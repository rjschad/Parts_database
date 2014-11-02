#include <fstream>


int main()
{
  std::ifstream src("f1.txt");
  std::ofstream dst("f2.txt");

   dst << src.rdbuf();

}

