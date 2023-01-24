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
#include <iomanip>
#define PRECISION 0.05
#define ADDZERO 0.00001

#include "GPAlist.h"
#include "File.h"
// #include "File.cpp"
#include "GPA.h"
using namespace std;

 namespace sdds{

 bool gpaQuery(const char *filename){
      openFile(filename);
      closeFile();
      return true;
 };


 GPA gpaValue[100];
 bool loadStudent()
 {
      
      GPA gpa;
      int studentNumber = 0;
      bool ok = true;
      if(openFile("students.csv")){
      
        while(ok && studentNumber < 100){
            ok = readStudentName(gpa.name) && readStudentNumber(&gpa.stno) && readStudentGpa(&gpa.gpa);
      
            if (ok)
                 gpaValue[studentNumber++] = gpa;
        }
         closeFile();
      }
      
      return studentNumber == 100;
 }


void displayStudent(const char operation, const double value){
      int i = 0;
      int j = 1;
   
      for (i = 0; i < 100; i++)
      {
         if (operation == '>')
         {
            if (gpaValue[i].gpa > value && strlen(gpaValue[i].name))
            {
                cout << "[" << j << "] " << gpaValue[i].stno  << ": " << fixed << setprecision(1)<< gpaValue[i].gpa+ADDZERO << " (" << gpaValue[i].name << ")\n";
                j++;
               }
          }
          
          else if (operation == '<')
          {
               if (gpaValue[i].gpa < value && strlen(gpaValue[i].name))
               {
                      cout << "[" << j << "] " << gpaValue[i].stno << ": " << fixed << setprecision(1) << gpaValue[i].gpa+ ADDZERO << " (" << gpaValue[i].name << ")\n";
                      j++;
               }
          }
        
          else if (operation == '~')
          {
               if (gpaValue[i].gpa >= value - PRECISION && gpaValue[i].gpa <= value + PRECISION && strlen(gpaValue[i].name))
               {
                      cout << "[" << j << "] " << gpaValue[i].stno << ": " << fixed << setprecision(1) << gpaValue[i].gpa + ADDZERO << " (" << gpaValue[i].name << ")\n";
                      j++;
               }
          }

         
      }
}

}