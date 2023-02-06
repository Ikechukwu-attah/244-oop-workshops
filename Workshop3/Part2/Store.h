#ifndef SDDS_STORE_H_
#define SDDS_STORE_H_

#define MAX_SNAME 31
#define MAX_NUM_TOYS 10
#include "Toys.h"



namespace sdds 
{

    class Store{
        char m_sName[MAX_SNAME];
        int m_noOfToys;
        int m_addToys;
        Toy m_toy[MAX_NUM_TOYS];

        public:
        void setStore(const char* sName, int no);
        void setToys(const char* tname, int sku, double price,int age);
        void display()const;



};

}

#endif // !SDDS_STORE_H_
