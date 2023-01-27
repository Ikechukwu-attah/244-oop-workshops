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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include "UI.h"
#include "GPAlist.h"
#include "File.h"
// #include "GPAlist.cpp"
 using namespace std;

namespace sdds{
 
      bool search()
 {
     
     double gpaNumber = 0;
     char options;
   
    
     int flag = false;
     char answer;

     while (!flag)
     {
    cout << "? ";
    cin >> options;
      if(options == '!'){
                  flag = true;
                  cout << "Exit the program? (Y)es/(N)o: ";
                  cin >> answer ;
                  if(answer == 'Y' || answer == 'y'){
                    //   cout << "Goodbye!";
                      return 0;
                  }else{
                      flag = true;
                  }

                  //  cout << endl;
         }
     cin >> gpaNumber;
         if(options == '>' || options =='<' || options =='~' || options == '!'){
            
             displayStudent(options, gpaNumber);
           

             }

             
         else
         {
             cout << "Syntax error: ? [Op][value]<ENTER>\n";
             cout << "Op: [>,<,~,!]\n";
             cout << "value: GPA value\n\n";
         };


//   loadStudent();

        
     }
    

     return true;
 }

 
}

