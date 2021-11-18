#ifndef FORMATTING_H_INCLUDED
#define FORMATTING_H_INCLUDED

#include <iostream>
#include <sstream>
#include "Honap.hpp"

#ifndef CPORTA
    #include <windows.h>
#endif // CPORTA

const int h = 9;
const int w = 22;

enum menustate {fomenu, uj, ujback, melyiknap, melyikadat, ujcel, melyikceladat, celertek, statsdisplay, stats, kilep};

menustate nextstate(char selection, menustate src_state);

void clearmenuselection();

menustate menu(menustate state);

void honapnev(int ho);

void gotoxy( int column, int line );

void cellarajzol(int x, int y, bool ma, bool shiftdown);

void adatbeir(int nap, int shift, bool shiftdown, Atlagok cellaadat);

void adatbeir(int nap, int shift, bool shiftdown, std::string szoveg, int hova);

void statpos();


#endif // FORMATTING_H_INCLUDED
