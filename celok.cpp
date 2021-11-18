#include "celok.h"
#include "memtrace.h"

void setgoal(std::string nev, const Tevekenyseg& melyik, double mire)
{

    std::ifstream be;
    be.open("celok/" + nev + ".txt");
    std::string temp[3];
    be >> temp[0] >> temp[1] >> temp[2];
    be.close();

    std::ofstream ki;
    ki.open("celok/" + nev + ".txt", std::ofstream::out | std::ofstream::trunc);
    for (int i = 0; i < 3; i++)
    {
        if (i != melyik.goal())
            ki << temp[i] << " ";
        else
            ki << mire << " ";

    }
    ki.close();
}

void setgoal(std::string nev, Atlagok ujcelok)
{
    std::ofstream ki;
    ki.open("celok/" + nev + ".txt", std::ofstream::out | std::ofstream::trunc);
    ki << ujcelok.napifutas << ' ' << ujcelok.napiolvasas << ' ' << ujcelok.napifilmnezes;
    ki.close();
}

void resetgoal(std::string nev, const Tevekenyseg& melyik)
{
    setgoal(nev, melyik, -1);
}
