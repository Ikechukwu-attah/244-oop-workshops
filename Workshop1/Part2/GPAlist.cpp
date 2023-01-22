 /*
*****************************************************************************
 <assessment name example: Workshop - #1 (Part-2)>
Full Name : ATTAH IKECHUKWU ANTHONY
Student ID#: 175441211
Email : iattah@myseneca.ca
Section : PART-2
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************


 */
#include "GPAlist.h"
#include "File.h"
#include "File.cpp"
#include "GPA.h"

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
      bool ok = 0;
      if(openFile("students.csv")){
        while(ok && studentNumber < 100){
            ok = readStudentName(gpa.name) && readStudentNumber(&gpa.stno) && readStudentGpa(&gpa.gpa);

            if(ok)
                gpaValue[studentNumber++] = gpa;
        }
         closeFile();
      }
      return studentNumber == 100;
 }
