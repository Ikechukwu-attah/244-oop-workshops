#ifndef EGG_CARTON_H
#define EGG_CARTON_H



 namespace sdds{
    const int RegularEggWeight = 50; // in grams
    const int JumboEggWeight = 75; // in grams

    class EggCarton {
    // class implementation goes here
    int size;
    int noOfEggs;
    bool jumboSize;

    EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);

    void setBroken();


    std::ostream& display(std::ostream& ostr = std::cout) const;

    std::ostream& displayCarton(int size, int noOfEggs, bool jumbo, std::ostream& ostr) const;

    };
}



#endif // EGG_CARTON_H