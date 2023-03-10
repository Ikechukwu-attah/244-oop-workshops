 /*
*****************************************************************************
 <assessment name example: Workshop - #1 (Part-2)>
Full Name : ATTAH IKECHUKWU ANTHONY
Student ID#: 175441211
Email : iattah@myseneca.c
Section : PART-2
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************


 */

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds
{
    bool openFile(const char filename[]);
void closeFile();
bool readStudentName(char name[]);
bool readStudentNumber(int *num);
bool readStudentGpa(double *gpa);
void flushkeys();
} 




#endif // !SDDS_FILEDFF_H