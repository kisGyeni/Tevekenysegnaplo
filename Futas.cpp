#include "Futas.h"
#include <string>

#include "memtrace.h"

Futas::Futas(double mennyiseg, bool aszfalton)
    : Tevekenyseg {"km", mennyiseg} ///Tevekenyseg osztály konstruktorhívása: ha futás, a mértékegység mindig km lesz
    , aszfalton {aszfalton} {}

Futas::~Futas() {}

bool Futas::getAszfalton() const { return aszfalton; }

int Futas::goal() const { return 0; }
