#include "Tevekenyseg.h"
#include <string>

#include "memtrace.h"

Tevekenyseg::Tevekenyseg(std::string mertekegyseg, double mennyiseg)
    : mertekegyseg {mertekegyseg}
    , mennyiseg {mennyiseg} {}


Tevekenyseg::~Tevekenyseg() {}

double Tevekenyseg::getMennyiseg() const { return mennyiseg; }

std::string Tevekenyseg::getMertekegyseg() const { return mertekegyseg; }
