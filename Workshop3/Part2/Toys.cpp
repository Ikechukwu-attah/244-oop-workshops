#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Toys.h"
using namespace std;

namespace sdds 
{

    void Toy::calSale(){
        m_price = 0.8 * m_price;
    };



    void Toy::addToys(const char *tname, int sku, double price, int age){

        if(tname == nullptr || tname[0] == '\0' || sku <= 0 || price <= 0 || age <= 0)
  {
         *m_tname = '\0';
        m_sku = 0;
        m_price = 0;
        m_age = 0;
        m_onSale = false;
        return;

        
  }

   strcpy(m_tname, tname);
    m_sku = sku;
    m_price = price;
    m_age = age;
    m_onSale = false;

    };

    void Toy::isSale(bool sale){
        m_onSale = sale;
    };




    void Toy::display()const{

        if (*m_tname == '\0') {
        cout << "Invalid Toy" << endl;
        return;
    }

    cout << setw(15) << left << m_tname << setw(10) << m_sku << setw(6) << m_age;
    cout << setw(12) << fixed << setprecision(2) << m_price;

    if (m_onSale) {
        cout << setw(10) << "On Sale";
    } else {
        cout << setw(8) << " ";
    }
    cout << endl;

    }



    void Toy::setEmpty(){
          m_tname[0] = '\0';
          m_sku = 0;
          m_price = 0.0;
          m_age = 0;
          m_onSale = false;

    }
}