
#include "NameTag.h"
#include <iostream>
#include <string>

using namespace std;

namespace sdds
{
    



NameTag::NameTag() : name("EMPTY NAMETAG!"), extension(0) {}

NameTag::NameTag(const std::string& name) : name(name), extension(0) {
  if (name.length() > 40) {
    this->name = name.substr(0, 40);
  } else if (name.length() < 20) {
    this->name = std::string(20 - name.length(), ' ') + name;
  }
}

NameTag::NameTag(const std::string& name, int extension) : name(name), extension(extension) {
  if (name.length() > 40) {
    this->name = name.substr(0, 40);
  } else if (name.length() < 20) {
    this->name = std::string(20 - name.length(), ' ') + name;
  }
}

NameTag::~NameTag() {}

// NameTag& NameTag::read(const std::string& name, int extension) {
//   this->name = name;
//   if (name.length() > 40) {
//     this->name = name.substr(0, 40);
//   } else if (name.length() < 20) {
//     this->name = std::string(20 - name.length(), ' ') + name;
//   }

//   std::cout << "Do you want to enter an extension number (y/n)? ";
//   char answer;
//   std::cin >> answer;

//   if (answer == 'y') {
//     this->extension = extension;
//     std::cin >> this->extension;
//     while (this->extension < 10000 || this->extension > 99999) {
//       std::cout << "Invalid extension number, enter again: ";
//       std::cin >> this->extension;
//     }
//   } else {
//     this->extension = 0;
//   }

//   return *this;
// }



NameTag& NameTag::read(){
    string input;
    cout << "Enter the name (Max 40 characters): ";
    cin >> input;

    if(input.length() > 40){
        input = input.substr(0, 40);
    }

    name = input;

    char extensionChoice;
    cout << "Do you want to enter an extension number? (y/n): ";
    cin >> extensionChoice;

    if(extensionChoice == 'y'){
        while(true){
            cout << "Enter the extension (5 digits): ";
            int extensionNumber;
            cin >> extensionNumber;

            if(to_string(extensionNumber).length() == 5){
                extension = extensionNumber;
                break;
            }
            else{
                cout << "Invalid Extension! Not a 5 digit number." << endl;
            }
        }
    }
    else if(extensionChoice == 'n'){
        extension = -1;
    }
    else{
        cout << "Invalid input! Extension not entered." << endl;
    }

    return *this;
}










void NameTag::print() const {
  std::cout << "+" << std::string(41, '-') << "+" << std::endl;
  std::cout << "| " << name << " |" << std::endl;
  std::cout << "|" << std::string(41, ' ') << "|" << std::endl;
  std::cout << "| " << (extension ? std::to_string(extension) : "N/A") << "     |" << std::endl;
  std::cout << "+" << std::string(41, '-') << "+" << std::endl;
}






} // namespace sdds
