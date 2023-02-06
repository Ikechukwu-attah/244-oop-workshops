 /*
*****************************************************************************
 <assessment name example: Workshop - #3 (Part-1)>
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




#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_
namespace sdds {

    const int MAX_TOPIC_LENGTH = 25;

    struct Project {
        char m_topic[MAX_TOPIC_LENGTH+1];
        double m_cost;
    };

	//class Department does here

    class Department{

        char *name;
        Project *projects;
       int number_of_Projects;
        double budget =  15345.99;

      public:
        void updateName(const char *newname);
        void updateBudget(double change);
        bool addProject(Project &newproject);
        void createDepartment(const char* newname, Project& newproject, double change);
        Project *fetchProjects() const;
        int fetchNumProjects() const;
        double fetchBudget() const;
        char *fetchName() const;
        double totalexpenses();
        double remainingBudget();
        void clearDepartment();
    };

    //helper functions - do not belong inside the class
    void display(const Project& project);
    void display(const Department& department);

}
#endif // !SDDS_DEPARTMENT_H_
