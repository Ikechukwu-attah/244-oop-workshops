#ifndef SDDS_TOURNAMENT_H_
#define SDDS_TOURNAMENT_H_
 #include "SoccerTeam.h"


namespace sdds {


class Tournament
{
    char* m_name;
    int m_num;
    SoccerTeam* m_soccer = nullptr;

    public:
     void setTournament(const char* name, int noOfTeams, const SoccerTeam* soccer);


void setEmpty();

bool isEmpty() const;

Tournament& match(const SoccerTeam* ls);

 ostream& display() const;

~Tournament();

};







}

#endif // !SDDS_TOURNAMENT_H_