#ifndef TEVEKENYSEG_H_INCLUDED
#define TEVEKENYSEG_H_INCLUDED

#include <string>

class Tevekenyseg
{
protected:
    std::string mertekegyseg;
    double mennyiseg;
public:
    /**
    *   Konstruktor, default értékkel
    *   Note:
    *       - Ha gyerek osztály hívja meg, mindkét paraméter adott.
    *       - Ha külön akarunk Tevekenyseg objektumot, a mértékegységet nekünk kell megadni
    **/
    Tevekenyseg(std::string mertekegyseg, double mennyiseg = 0);

    ///Destruktor
    ~Tevekenyseg();

    ///Getterek
    double getMennyiseg() const;
    std::string getMertekegyseg() const;

    virtual int goal() const = 0;
};

#endif // TEVEKENYSEG_H_INCLUDED
