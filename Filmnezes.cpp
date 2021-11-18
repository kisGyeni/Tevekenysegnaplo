#include "Filmnezes.h"
#include <string>

#include "memtrace.h"

Filmnezes::Filmnezes(double mennyiseg, short ertekeles)
    : Tevekenyseg {"perc", mennyiseg} ///Tevekenyseg osztály konstruktorhívása: ha filmnézés, a mértékegység mindig perc lesz
    , ertekeles {ertekeles}
{
    if (ertekeles > 5)
        this->ertekeles = 5;
}

Filmnezes::~Filmnezes() {}

short Filmnezes::getErtekeles() const { return ertekeles; }

int Filmnezes::goal() const { return 2; }
