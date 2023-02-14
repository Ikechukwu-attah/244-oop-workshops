#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_

namespace sdds {

    class NameTag {
  private:
    std::string name;
    int extension;
  public:
    NameTag();
    NameTag(const std::string& name);
    NameTag(const std::string& name, int extension);
    ~NameTag();
    NameTag& read();
    void print() const;
};
}




#endif // !SDDS_NAMETAG_H_