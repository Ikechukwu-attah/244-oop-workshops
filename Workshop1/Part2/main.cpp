
 /*
*****************************************************************************
 <assessment name example: Workshop - #1 (Part-2)>
Full Name : ATTAH IKECHUKWU ANTHONY
Student ID#: 175441211
Email : iattah@myseneca.ca
Section : NFF
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************


 */

#include <iostream>
#include "GPAlist.h"
#include "UI.h"

 using namespace std;
 using namespace sdds;

 int main()
 {
   

      if (!gpaQuery("students.csv"))
      {
          std::cout << "This should have worked, fix the problem!" << std::endl;
   }else{
          
          loadStudent();

           search();
   };

    cout << "Goodbye!" << std::endl;

    return 0;
 };
