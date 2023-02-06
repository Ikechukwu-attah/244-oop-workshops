#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {



  void Department::updateName(const char *newname){

         if(newname != nullptr && strlen(newname)>0){
             delete[] name;
             int nameLength = strlen(newname);
             name = new char[nameLength + 1];
             strcpy(name, newname);
         }
  };

   void Department::updateBudget(double change){
      if (change > 0)
        {
            Department::budget += change;
        }

        //  budget += change;
   };

    bool Department::addProject(Project &newproject){
        if(newproject.m_cost <= budget){
            if(number_of_Projects == 0 ){

                projects = new Project[1];
                projects[0] = newproject;
                number_of_Projects++;
            }else{
                Project *temp = new Project[number_of_Projects + 1];
                for (int i = 0; i < number_of_Projects;i++){
                    temp[i] = projects[i];
                }
                temp[number_of_Projects] = newproject;
                number_of_Projects++;
                delete[] projects;
                projects = new Project[number_of_Projects];
                for (int i = 0; i < number_of_Projects; i++){
                    projects[i] = temp[i];
                }
                delete[] temp;
            };
            return true;
        }else{
            return false;
        }
    };

    void Department:: createDepartment(const char *newname, Project &newproject, double change){
        Department::updateName(newname);
        Department::addProject(newproject);
        Department::updateBudget(change);
    };



    Project* Department::fetchProjects() const{
        return Department::projects;
    };

    int Department::fetchNumProjects()const{
        return Department::number_of_Projects;
    };

      double Department::fetchBudget() const{
        return Department::budget;
      };

      char* Department::fetchName() const{
        return Department::name;
      };


        double Department::totalexpenses(){
        double expenses = 0;
        for (int i = 0; i < number_of_Projects;i++){
            expenses += projects[i].m_cost;
        }
        return expenses;
        };


         double Department::remainingBudget(){
            return budget - Department::totalexpenses();
         };


           void Department::clearDepartment(){
             delete[] Department::name;
            Department::name = nullptr;
            delete[] Department::projects;
            Department::projects = nullptr;
            number_of_Projects = 0;
            budget = 0.0;
           }

    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    };

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();
            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

}