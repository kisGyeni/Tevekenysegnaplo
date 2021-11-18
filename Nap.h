#ifndef NAP_H_INCLUDED
#define NAP_H_INCLUDED

#include "Futas.h"
#include "Olvasas.h"
#include "Filmnezes.h"

class Nap
{
    Futas futas;
    Olvasas olvasas;
    Filmnezes filmnezes;
public:
    Nap(Futas futas, Olvasas olvasas, Filmnezes filmnezes);
    Nap(double futas, double olvasas, double filmnezes);
    Nap();
    ~Nap();

    Futas getFutas() const;
    Olvasas getOlvasas() const;
    Filmnezes getFilmnezes() const;

    void futott(double mennyit, bool felulir = false, bool aszf = false);
    void olvasott(double mennyit, bool felulir = false, std::string cim = "");
    void filmezett(double mennyit, bool felulir = false, short ert = 0);
};


#endif // NAP_H_INCLUDED
