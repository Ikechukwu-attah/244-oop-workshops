#ifndef SDDS_TOYS_H_
#define SDDS_TOYS_H_

#define MAX_TNAME 31

namespace sdds 
{


 class Toy{
    public:
     char m_tname[MAX_TNAME];
     int m_sku;
     double m_price;
     int m_age;
     bool m_onSale;
 };
};

#endif // !SDDS_TOYS_H_