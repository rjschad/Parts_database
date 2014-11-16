#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using namespace std;


int main()
{
        int track = 1;
        int flag = 0;

        double value = 0.00;
        int quant = 0;
        string casetype;
        string getinfo;
        char buffer[10];
  
        string str;
        char* cstr = new char[str.length()];

	/* Load data into array */
	fstream ifile("output4.txt",ios::in);
	fstream ifile2("output4.txt",ios::in);
  

      while(ifile2)
      {
        ifile2>> getinfo;
        flag++;
      }
      cout<<"flag: " << flag << endl;
      // break value
       int stop = flag -1; 

      // reset flag
      flag = 0;

       cout << endl; 

      while(ifile)
       {
          ifile>> str;
          strcpy(cstr, str.c_str()); // cstr contains a cstyle string copr of str

          if(track == 1)
            {
             value = atof(cstr);
//             cout << "value: " << value << endl;
            }
          if(track == 2)
            {
             quant = atoi(cstr);
//             cout << "quant: " << quant << endl;
            }
          if(track == 3)
            {
             casetype = cstr;

             cout << "value: " << value << endl;
             cout << "quant: " << quant << endl;
             cout << "case: " << casetype << endl << endl;

             track = 0; // reset
            }

          track++;
          flag++;

          if(flag == stop)
           break;
       }


   
       delete[] cstr;
 

        /* display c-style characters */
        /*
          cout<< *cstr << endl;
          cout<< *(cstr+1) << endl;
          cout<< *(cstr+2) << endl;
          cout<< *(cstr+3) << endl;
          cout<< *(cstr+4) << endl;
        */


        /* convert c style string to double */
        /*
         value = atof(cstr);
         cout << "value: " << value << endl;
        */
      
return 0;
}

