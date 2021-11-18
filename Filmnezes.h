#ifndef FILMNEZES_H_INCLUDED
#define FILMNEZES_H_INCLUDED

#include "Tevekenyseg.h"
#include <string>

class Filmnezes : public Tevekenyseg
{
protected:
    short ertekeles;
public:
    ///Konstruktor, default értékekkel
    Filmnezes(double mennyiseg = 0, short ertekeles = 0);

    ///Destruktor
    ~Filmnezes();

    ///Getter
    short getErtekeles() const;

    int goal() const;

};

#endif // FILMNEZES_H_INCLUDED
