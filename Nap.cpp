#include "Nap.h"

#include "memtrace.h"

Nap::Nap(double futas, double olvasas, double filmnezes)
    : futas {futas}
    , olvasas {olvasas}
    , filmnezes {filmnezes} {}

Nap::Nap()
    : Nap {0, 0, 0} {}

Nap::Nap(Futas futas, Olvasas olvasas, Filmnezes filmnezes)
    : futas {futas}
    , olvasas {olvasas}
    , filmnezes {filmnezes} {}

Nap::~Nap() {}

Futas Nap::getFutas() const { return futas; }
Olvasas Nap::getOlvasas() const { return olvasas; }
Filmnezes Nap::getFilmnezes() const { return filmnezes; }

void Nap::futott(double mennyit, bool felulir, bool aszf)
{
    if (felulir)
        futas = Futas(mennyit, aszf);
    else
        futas = Futas(mennyit+futas.getMennyiseg(), futas.getAszfalton());
}

void Nap::olvasott(double mennyit, bool felulir, std::string cim)
{
    if (felulir)
        olvasas = Olvasas(mennyit, cim);
    else
        olvasas = Olvasas(mennyit+olvasas.getMennyiseg(), olvasas.getCim());
}

void Nap::filmezett(double mennyit, bool felulir, short ert)
{
    if (felulir)
        filmnezes = Filmnezes(mennyit, ert);
    else
        filmnezes = Filmnezes(mennyit+filmnezes.getMennyiseg(), filmnezes.getErtekeles());
}
