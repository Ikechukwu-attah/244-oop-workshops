#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Tools.h"
#include "Package.h"

FILE* fp;

namespace sdds {
    int openFile_r(const char filename[]) { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int noOfTraces() {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }
    

    // To Do: read functions (4 overloaded read functions)
    
    
    int read(char Package_Name[61]) {
        char p_name[61];
        if(fscanf(fp, "%60[^\n]\n", Package_Name) == 1){
            
            return 1;
        }else{
            return 0;
        }
    }
    int read(int& idTime ) {

        return fscanf(fp, "%d,",idTime )==1;
        
    }
    int read(double& timeinhours) {
        return fscanf(fp, "%lf,", timeinhours)==1;
        
    }
    int read(char& dayofweek) {
        return fscanf(fp, "%[^ \t\n\r\v\f,]%*c", dayofweek) == 1;
    }

    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }
    
    void strCpy(char* str1, const char* str2) { // Fully provided 
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }

}