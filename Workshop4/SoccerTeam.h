#ifndef SDDS_SOCCERTEAM_H_
#define SDDS_SOCCERTEAM_H_

#include <iostream>



namespace sdds {


const int MAX_FOUL = 4;

struct SoccerTeam
{
    char m_teamName[41];
    int m_noFouls;
    double m_fines;
    int m_goals;

  void setName(const char *tname);
    //member functions
    void setTeam(const SoccerTeam &team);

    void setFine(double fines, int fouls);

    void setEmpty();

    bool isEmpty() const;

    void calFines();

    int fouls() const;
    
    SoccerTeam();

    SoccerTeam(const char *tname, double fines, int foul);

   std::ostream& display()const;
};

}

#endif // !SDDS_SOCCERTEAM_H_