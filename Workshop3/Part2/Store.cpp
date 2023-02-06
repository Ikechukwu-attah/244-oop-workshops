#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Store.h"

using namespace std;
namespace sdds 
{
    // setStore function
    void Store::setStore(const char* sName, int no){
      if(sName != nullptr && strlen(sName) <= MAX_SNAME && no > 0){
          strcmp(m_sName, sName);
          m_noOfToys = no; 
      }else{
          m_sName[0] = '\0';
          m_noOfToys = 0;
      }
    };

//    setToys function
    void Store::setToys(const char* tname, int sku, double price,int age){
        if(m_addToys < m_noOfToys){
            //    strcpy(m_toy[m_addToys].m_tName, tname);
          strcpy(m_toy[m_addToys].m_tname, tname);
          m_toy[m_addToys].m_sku = sku;
          m_toy[m_addToys].m_price = price;
          m_toy[m_addToys].m_age = age;
          ++m_addToys;

        }
    }


    void Store::display()const{
        if(m_sName[0] == '\0'){
            cout << "Invalid Store" << endl;

        }else{
            cout << setfill('*') << setw(60) << "*" << endl;
            cout << m_sName << endl;
            cout << setfill('*') << setw(60) << "*" << endl;
            cout << "List of the toys" << endl;
        }
    }
}