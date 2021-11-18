#ifndef OLVASAS_H_INCLUDED
#define OLVASAS_H_INCLUDED

#include "Tevekenyseg.h"
#include <string>

class Olvasas : public Tevekenyseg
{
protected:
    std::string cim;
public:
    ///Konstruktor, default értékekkel
    Olvasas(double mennyiseg = 0, std::string cim = "");

    ///Destruktor
    ~Olvasas();

    ///Getter
    std::string getCim() const;

    int goal() const;

};

#endif // OLVASAS_H_INCLUDED
