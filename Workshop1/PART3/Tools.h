#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds {
	int openFile_r(const char filename[]); // Provided
	void closefile(); // Provided
	int noOfTraces(); // Provided

	// ADD: Declare read prototypes (4 prototypes)

	int read(char* Package_Name);
	int read(int nums);
	int read(double timeinhours);


	void strCpy(char* des, const char* src); // Provided
	int strLen(const char* s); // Provided
}
#endif 