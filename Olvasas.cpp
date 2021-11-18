#include "Olvasas.h"
#include <string>

#include "memtrace.h"

Olvasas::Olvasas(double mennyiseg, std::string cim)
    : Tevekenyseg {"oldal", mennyiseg} ///Tevekenyseg osztály konstruktorhívása: ha olvasás, a mértékegység mindig oldal lesz
    , cim {cim} {}

Olvasas::~Olvasas() {}

std::string Olvasas::getCim() const { return cim; }

int Olvasas::goal() const { return 1; }
