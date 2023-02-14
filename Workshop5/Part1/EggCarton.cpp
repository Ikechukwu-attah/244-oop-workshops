#include <iostream>
#include "EggCarton.h"
using namespace std;




namespace sdds{

    void EggCarton::setBroken() {
    size = -1;
    noOfEggs = -1;
    jumboSize = false;
}


EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) {
    if (size < 6 || size > 36 || size % 6 != 0 || noOfEggs < 0 || noOfEggs > size) {
        setBroken();
    } else {
        size= size;
        noOfEggs = noOfEggs;
        jumboSize = jumboSize;
    }
}

ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr) const {
    int cartonWidth = size == 6 ? 3 : 6;
    for (int i = 0; i < size; i++) {
        ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
        ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
    }
    return ostr;
}


EggCarton::operator bool() const {
  return (size!= -1) && (noOfEggs>= 0) && (noOfEggs <= size);
}



ostream& EggCarton::display(ostream& ostr) const {
    if (*this) {  // check if carton is not broken
        ostr << "Egg Carton (" << size << " eggs, " << (jumboSize ? "Jumbo" : "Regular") << "):\n";
        displayCarton(size ,noOfEggs, jumboSize, ostr);
    } else {
        ostr << "Broken Egg Carton!" << endl;
    }
    return ostr;
}


istream& EggCarton::read(istream& istr) {
  char jumboChar;
  istr >> jumboChar;
  jumboSize = (jumboChar == 'J');

  istr.ignore(1);

  int size, noOfEggs;
  char comma;

  istr >> size >> comma >> noOfEggs;

  if(size < 6 || size > 36 || size % 6 != 0 || noOfEggs < 0 || noOfEggs > size) {
    setBroken();
  }
  else {
    size = size;
    noOfEggs = noOfEggs;
  }

  return istr;
}




EggCarton::operator int() const {
    if (*this) {
        return noOfEggs;
    } else {
        return -1;
    }
}


EggCarton::operator double() const {
    if (!*this) {
        return -1.0;
    }

    int totalWeight = (jumboSize) ? (noOfEggs * JumboEggWeight) : (noOfEggs * RegularEggWeight);
    return static_cast<double>(totalWeight) / 1000.0;
}

EggCarton& EggCarton::operator--() {
  if (*this && noOfEggs > 0) {
    noOfEggs--;
  }
  return *this;
}


EggCarton& EggCarton::operator++() {
    if (noOfEggs < size) {
        noOfEggs++;
        if (noOfEggs > size) setBroken();
    } else {
        setBroken();
    }
    return *this;
}

EggCarton EggCarton::operator--(int) {
  EggCarton temp = *this;
  --(*this);
  return temp;
}


EggCarton EggCarton::operator++(int) {
    EggCarton temp(*this);
    ++(*this);
    return temp;
}


EggCarton& EggCarton::operator=(int value) {
    if(value < 0 || value > size) {
        setBroken();
    }
    else {
        noOfEggs = value;
    }
    return *this;
}


EggCarton& EggCarton::operator+=(int value) {
    if (*this && value >= 0) {  
        int totalEggs = noOfEggs + value;
        if (totalEggs > size) {  
            setBroken();
        }
        else {
            noOfEggs = totalEggs;
        }
    }
    return *this;
}


EggCarton& EggCarton::operator+=(EggCarton& right) {
    int totalEggs = noOfEggs + right.noOfEggs;
    if (totalEggs > size) {
        setBroken();
        return *this;
    }
    noOfEggs = totalEggs;
    right.noOfEggs = (totalEggs - size) > 0 ? (totalEggs - size) : 0;
    return *this;
};


bool EggCarton::operator==(const EggCarton& right) const {
    double weightDiff = size * noOfEggs - right.size * right.noOfEggs;
    return weightDiff > -0.001 && weightDiff < 0.001;
}

}