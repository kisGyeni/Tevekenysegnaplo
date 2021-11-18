#ifndef CELOK_H_INCLUDED
#define CELOK_H_INCLUDED

#include <string>
#include "Tevekenyseg.h"
#include "Honap.hpp"

void setgoal(std::string nev, const Tevekenyseg& melyik, double mire);

void setgoal(std::string nev, Atlagok ujcelok);

void resetgoal(std::string nev, const Tevekenyseg& melyik);


#endif // CELOK_H_INCLUDED
