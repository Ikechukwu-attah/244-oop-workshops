#include <iostream>
#include <cstring>
#include <iomanip>

#include "Tournament.h"
#include "SoccerTeam.h"

using namespace std;

namespace sdds{

    // ****************************************

void Tournament::setTournament(const char* name, int noOfTeams, const SoccerTeam* soccer)
{
    if (name == nullptr || strlen(name) == 0 || noOfTeams <= 0 || soccer == nullptr)
    {
        m_name = nullptr;
        m_num = 0;
        return;
    }

    m_num = noOfTeams;

    int length = strlen(name);
    m_name = new char[length + 1];
    strcpy(m_name, name);

    m_soccer = new SoccerTeam[m_num];
    for (int i = 0; i < m_num; i++)
    {
        m_soccer[i] = soccer[i];
    }
}

// **********************************************


void Tournament::setEmpty()
{
    delete[] m_name;
    delete[] m_soccer;
    m_name = nullptr;
    m_soccer = nullptr;
    m_num = 0;
}

// ************************


bool Tournament::isEmpty() const
{
return m_name != nullptr && m_soccer != nullptr && m_num > 0;
};

// **********************************************


Tournament& Tournament::match(const SoccerTeam* ls)
{
    for (int i = 0; i < m_num - 1; i++)
    {
        for (int j = i + 1; j < m_num; j++)
        {
            if (m_soccer[i].m_noFouls < m_soccer[j].m_noFouls)
            {
                m_soccer[j].m_noFouls *= 2;
                m_soccer[j].m_fines *= 1.2;
                m_soccer[i].m_goals += 1;
            }
            else if (m_soccer[j].m_noFouls >= MAX_FOUL)
       {
                m_soccer[j].m_noFouls = -1;
            }
        }
    }
    return *this;
};


// ******************

std::ostream& Tournament::display() const
{
    if (isEmpty())
    {
        std::cout << "Invalid Tournament" << std::endl;
        return std::cout;
    }

    std::cout << "Tournament name: " << m_name << std::endl;
    std::cout << "List of the Teams" << std::endl;
    std::cout << std::left << std::setw(45) << "Fines" << std::setw(10) << "Fouls" << std::setw(10) << "Goals" << std::endl;

    for (int i = 0; i < m_num; i++)
    {
        std::cout << std::left << std::setw(45) << m_soccer[i].m_fines << std::setw(10) << m_soccer[i].fouls() << std::setw(10) << m_soccer[i].m_goals << std::endl;
    }

    return std::cout;
}







// ********************

Tournament::~Tournament()
{
    delete [] m_name;
    delete [] m_soccer;
};



}