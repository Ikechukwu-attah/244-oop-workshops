#include <iostream>
#include "SoccerTeam.h"
using namespace std;



namespace sdds{

 void SoccerTeam::setTeam(const SoccerTeam &team){

    strcpy(m_teamName, team.m_teamName);
    m_noFouls = team.m_noFouls;
    m_fines = team.m_fines;
    m_goals = team.m_goals;
 };


 void SoccerTeam::setName(const char *tname){

        if (tname != nullptr)
    {
        strcpy(m_teamName, tname);
    }
 };



 void SoccerTeam::setFine(double fines, int fouls){

    if (fines >= 0 && fouls >= 0)
    {
        m_fines = fines;
        m_noFouls = fouls;
    }
    else
    {
        m_teamName[0] = '\0';
        m_fines = 0.0;
        m_noFouls = 0;
        m_goals = 0;
    }


 };

 void SoccerTeam::setEmpty(){

    m_teamName[0] = '\0';
    m_fines = -1.0;
    m_noFouls = -1;
    m_goals = 0;

 };

bool SoccerTeam::isEmpty() const
{
    return (m_teamName[0] == '\0' || m_fines <= 0 || m_noFouls <= 0);
};


 void SoccerTeam::calFines(){
   m_fines *= 1.2;
 };

 int SoccerTeam::fouls() const
 {
      return m_noFouls;
 };


SoccerTeam::SoccerTeam()
{
    setEmpty();
}


SoccerTeam::SoccerTeam(const char* tname, double fines, int foul)
{
    SoccerTeam team;
    team.setName(tname);
    team.setFine(fines, foul);

    if (!team.isEmpty())
    {
        setTeam(team);
    }
    else
    {
        setEmpty();
    }
}



}