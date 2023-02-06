


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds 
{
    //fully provided for students to display details of a project
    void display(const Project& project) 
    {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

     void Department::updateName(const char *newname){

         if(newname != nullptr && strlen(newname)>0){
             delete[] name;
             int nameLength = strlen(newname);
             name = new char[nameLength + 1];
             strcpy(name, newname);
         }
  };

    void Department::updateBudget(double change)
    {
        //std::cout << "updateBudget function called" << std::endl;
        if (change > 0)
        {
            Department::budget += change;
        }
        
    }

    bool Department::addProject(Project& newproject)
    {
        //std::cout << "addProject function called" << std::endl;
        double budget = remainingBudget();
        if (newproject.m_cost <= budget)
        {   
            if (no_proj == 0)
            {
                //std::cout << "addProject allowed" << std::endl;
                proj = new Project[1];
                proj[0] = newproject;
                no_proj++;
                return true;
            }
            else
            {
                Project* buff = new Project[no_proj + 1];
                for (int i = 0; i < no_proj; i++)
                {
                    buff[i] = proj[i];
                }
                buff[no_proj] = newproject;
                no_proj++;

                if (proj != nullptr)
                {
                    delete[]proj;
                    proj = nullptr;
                }

                proj = new Project[no_proj];

                for (int i = 0; i < no_proj; i++)
                {
                    proj[i] = buff[i];
                }

                if (buff != nullptr)
                {
                    delete[]buff;
                    buff = nullptr;
                }
                return true;
            }
        }
        else
        {
            //std::cout << "addProject denied" << std::endl;
            return false;
        }
    }

    void Department::createDepartment(const char* newname, Project& newproject, double change)
    {
        //std::cout << "createDepartment function called" << std::endl;
        Department::updateName(newname);
        Department::addProject(newproject);
        Department::updateBudget(change);
        //std::cout << "createDepartment function ended" << std::endl;
    }

    Project* Department::fetchProjects() const
    {
        //std::cout << "fetchProjects called" << std::endl;
        return Department::proj;
    }

    int Department::fetchNumProjects() const
    {
        //std::cout << "fetchNumProjects called" << std::endl;
        return Department::no_proj;
    }

    double Department::fetchBudget() const
    {
        //std::cout << "fetchBudget called" << std::endl;
        return Department::budget;
    }

    char* Department::fetchName() const
    {
        //std::cout << "fetchName called" << std::endl;
        return Department::name;
    }

    double Department::totalexpenses()
    {
        //std::cout << "totalexpenses called" << std::endl;
        double totalexpenses = 0.0;
        for (int i = 0; i < no_proj; i++)
        {
            totalexpenses += proj[i].m_cost;
        }
        //std::cout << "totalexpenses = " << totalexpenses << std::endl;
        return totalexpenses;
    }

    double Department::remainingBudget()
    {
        //std::cout << "remainingBudget called" << std::endl;
        double budget;
        double remaining;
        budget = Department::totalexpenses();
        remaining = Department::budget - budget;
        //std::cout << "remaining = " << remaining << std::endl;
        return remaining;
    }

    void Department::clearDepartment()
    {
        //std::cout << "clearDepartment called" << std::endl;
        if (Department::name != nullptr)
        {
            delete[]Department::name;
            Department::name = nullptr;
        }
        if (Department::proj != nullptr)
        {
            delete[]Department::proj;
            Department::proj = nullptr;
        }
        no_proj = 0;
        budget = 0.0;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) 
    {
        Project* temp = department.fetchProjects();
        int projects = department.fetchNumProjects();
        cout << "Department " << department.fetchName() << " details:" << endl;
        cout << "Budget: " << department.fetchBudget()
            << " and the number of projects in progress is: " << projects << endl;
        cout << "Below are the details of the projects we are currently working on: " << endl;
        for (int i = 0; i < projects; i++) 
        {
            display(temp[i]);
        }
    }
}





