#ifndef FUTAS_H_INCLUDED
#define FUTAS_H_INCLUDED

#include "Tevekenyseg.h"
#include <string>

class Futas : public Tevekenyseg
{
protected:
    bool aszfalton;
public:
    ///konstruktor, default értékekkel
    Futas(double mennyiseg = 0, bool aszfalton = false);

    ///Destruktor
    ~Futas();

    ///Getter
    bool getAszfalton() const;

    int goal() const;

};


#endif // FUTAS_H_INCLUDED
