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
#include "File.h"

using namespace std;

namespace sdds{
   
   FILE* fptr;       

// opens the data file and returns true if successful
bool openFile(const char filename[]){
    fptr = fopen(filename, "r");
     return fptr != NULL;
}



void closeFile() {
   if (fptr) fclose(fptr);
}

// read student name from the file
bool readStudentName(char name[]){
   return fscanf(fptr, "%[^,],", name)==1;
}

// read student number from file
bool readStudentNumber(int *num){
   return fscanf(fptr, "%d,", num)==1;
}

// reading student GPA
bool readStudentGpa(double *gpa){
   return fscanf(fptr, "%lf\n", gpa)==1;
}

void flushkeys() {
   while (cin.get() != '\n');
}

}
