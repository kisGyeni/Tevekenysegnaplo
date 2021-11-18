#ifndef HONAP_HPP_INCLUDED
#define HONAP_HPP_INCLUDED

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#ifndef CPORTA
    #include <direct.h>
#endif
#include "Nap.h"

#include "memtrace.h"

struct Atlagok
    {
        double napifutas, napiolvasas, napifilmnezes;
    };

template<typename T>
class Honap
{
    T *adat;
    size_t meret;
public:
    explicit Honap(size_t meret = 0)
        :adat(new T[meret])
        ,meret(meret) {}

    Honap(const Honap &source)
        :Honap(source.meret)
    {
        if(meret > 0) // Ha a meret == 0 akkor a source.meret == 0, tehat nincs benne másolandó adat. Nem is lenne értelmes se a *adat se a *source.adat, mert érvénytelen memóriaterületre mutatnak.
            *adat = *source.adat;
    }

    #ifndef CPORTA
    Honap(std::string nev) :Honap()
    {
        time_t most = time(0);
        tm* ido = localtime(&most);

        std::ostringstream ev; //output stream
        ev << ido->tm_year+1900; // 2020
        char * cev = &ev.str()[0]; // cev ramutat arra a stringre h "2020"
        mkdir(cev); // csinal egy olyan mappat h "2020" ha meg nem letezik

        ev << "/" << ido->tm_mon+1; // 2020- hoz hozzafuzi hogy / es hogy 4 -> 2020/4
        cev = &ev.str()[0]; //cev ramutat arra a stringre hogy "2020/4"
        mkdir(cev); //csinal egy olyan mappat h 4 a 2020 mappaban ha meg nem letezik

        ev << "/" << nev << ".txt"; // hozzafuzi hogy / es hogy gyeni es hogy .txt
        std::string path = ev.str(); //letrehozok egy stringet amiben eltarolom a teljes utvonalat, es belekerul hogy "2020/4/gyeni.txt"
        cev = &path[0]; //cev ramutat a teljes path nevet tartalmazo stringre

        //std::cout << path;
        std::ifstream be;
        be.open("celok/" + nev + ".txt");
        if(!be.is_open()) //ha uj felhasznalo
        {
            std::ofstream ki;
            mkdir("celok");
            ki.open("celok/" + nev + ".txt");
            ki << "-1 -1 -1";
            ki.close();
        }
        else
            be.close();

        be.open(cev);

        if(!be.is_open()) // ha nem letezik
        {
            std::ofstream ki;
            ki.open(cev); //letrehozzuk
            int napos;
            if (ido->tm_mon == 1) napos = 28;
            else if (ido->tm_mon == 3 || ido->tm_mon == 5 || ido->tm_mon == 8 || ido->tm_mon == 10 || ido->tm_mon == 12) napos = 30;
            else napos = 31;
            for (int i = 0; i < napos; i++)
            {
                ki << "-1 0\t-1 \t-1 0";
                if(i+1<napos) ki << std::endl;
            }
            ki.close();


            be.open(cev); //majd ujra megprobaljuk megnyitni olvasasra
            if(!be.is_open())
            {
                ///
            }
        }
        int i = 0;
        while(!be.eof())
        {
            double menny_fut, menny_olv, menny_film;
            bool aszfalton;
            std::string cim;
            int ertekeles;

            be >> menny_fut >> aszfalton >> menny_olv;
            be.ignore();
            std::getline(be, cim, '\t');
            be >> menny_film >> ertekeles;

            //std::cout << menny_fut << " " << aszfalton << " " << menny_olv << " " << cim << " " << menny_film << " " << ertekeles << std::endl;

            this->push_back(T(
                              Futas(menny_fut, aszfalton),
                              Olvasas(menny_olv, cim),
                              Filmnezes(menny_film, ertekeles)
                              )
                            );
            i++;
        }
        be.close();
    }


    void elment(std::string nev)
    {
        time_t most = time(0);
        tm* ido = localtime(&most);

        std::ostringstream ev; //output stream
        ev << ido->tm_year+1900; // 2020
        char * cev = &ev.str()[0]; // cev ramutat arra a stringre h "2020"
        mkdir(cev); // csinal egy olyan mappat h "2020" ha meg nem letezik

        ev << "/" << ido->tm_mon+1; // 2020- hoz hozzafuzi hogy / es hogy 4 -> 2020/4
        cev = &ev.str()[0]; //cev ramutat arra a stringre hogy "2020/4"
        mkdir(cev); //csinal egy olyan mappat h 4 a 2020 mappaban ha meg nem letezik

        ev << "/" << nev << ".txt"; // hozzafuzi hogy / es hogy gyeni es hogy .txt
        std::string path = ev.str(); //letrehozok egy stringet amiben eltarolom a teljes utvonalat, es belekerul hogy "2020/4/gyeni.txt"
        cev = &path[0]; //cev ramutat a teljes path nevet tartalmazo stringre

        //std::cout << path;
        std::ofstream ki;
        ki.open(cev);
        //std::cout << adat[0].getFutas().getMennyiseg();
        for(unsigned int i = 0; i < meret; i++)
        {
            ki << adat[i].getFutas().getMennyiseg() << ' ' << adat[i].getFutas().getAszfalton() << '\t' << adat[i].getOlvasas().getMennyiseg() << ' ' << adat[i].getOlvasas().getCim() << '\t' << adat[i].getFilmnezes().getMennyiseg() << ' ' << adat[i].getFilmnezes().getErtekeles();
            if(i+1<meret) ki << std::endl;
        }

        ki.close();
    }
    #endif

    ~Honap() { delete[] adat; }

    size_t size() const { return meret; }

    T const& operator[](size_t index) const {
        return adat[index];
    }

    T& operator[](size_t index) {
        return adat[index];
    }

    void push_back(T const &uj_ertek) {
        T *uj_adat = new T[meret + 1];
        for(size_t i = 0; i < meret; ++i)
            uj_adat[i] = adat[i];
        uj_adat[meret] = uj_ertek;
        delete[] adat;
        adat = uj_adat;
        ++meret;
    }
    /**
    ** @note
    **
    **  obj.felvesz(Nap(
    **                  Futas(obj.adat->getFutas().getMennyiseg(), obj.adat->getFutas().getAszfalton()),
    **                  Olvasas(obj.adat->getOlvasas().getMennyiseg(), "Biblia"),
    **                  Filmnezes(obj.adat->getFilmnezes().getMennyiseg(), obj.adat->getFilmnezes.getErtekeles())
    **                  ), 2
    **              );
    **
    **      A felvesz tagfüggvény megerőszakolható úgy, hogy például egy adott napon,
    **      csak az aznap olvasott könyv címe változzon, ha minden más - a konstruktor
    **      által várt - értéket saját magából visszanyerünk, de ezt elég mazohista
    **      leírni, és amúgy a Nap osztálynak van olvasott tagfüggvénye, ami inkább
    **      erre van, de az se teljesen. A következő kód, hatásában egyenértékű:
    **
    **  obj[1].olvasott(obj[1].getOlvasas().getMennyiseg(), true, "Biblia");
    **
    **      Valljuk be ez se kifejezetten guztusos, de valójában az olvasott tagfüggvény
    **      se épp erre van kitalálva, hiszen általában ugyanazt a könyvet olvassuk tovább
    **      néhány oldallal, nem pedig egy azonos oldalszámmal felvenni egy teljesen más
    **      könyvet az előző helyett, de mindenesetre szórakoztató volt ezeket dokumentálni.
    **/
    void felvesz(T const &ertek, int napra = 0)
    {
        if (napra == 0) //ha nem jelöljük ki melyik napra, az aktualis nap az alapertelmezett
        {
            time_t most = time(0);
            tm* ido = localtime(&most);
            napra = ido->tm_mday;
        }
        adat[--napra] = ertek;
    }

    Atlagok atlag() const
    {
        if (meret == 0)
            return Atlagok {0, 0, 0};
        double fut_ossz = 0, olv_ossz = 0, film_ossz = 0;
        int fut_valid = 0, olv_valid = 0, film_valid = 0;
        for(unsigned int i = 0; i < meret; i++)
        {
            if (adat[i].getFutas().getMennyiseg() >= 0)
            {
                fut_ossz += adat[i].getFutas().getMennyiseg();
                fut_valid++;
            }
            if (adat[i].getOlvasas().getMennyiseg() >= 0)
            {
                olv_ossz += adat[i].getOlvasas().getMennyiseg();
                olv_valid++;
            }
            if (adat[i].getFilmnezes().getMennyiseg() >= 0)
            {
                film_ossz += adat[i].getFilmnezes().getMennyiseg();
                film_valid++;
            }
        }
        return Atlagok {
                        fut_valid == 0 ? -1 : fut_ossz/fut_valid,
                        olv_valid == 0 ? -1 : olv_ossz/olv_valid,
                        film_valid == 0 ? -1 : film_ossz/film_valid
                        };
    }
private:
    Atlagok cel(std::string nev) const
    {
        Atlagok ertek;
        std::ifstream be;
        be.open("celok/" + nev + ".txt");
        be >> ertek.napifutas >> ertek.napiolvasas >> ertek.napifilmnezes;
        return ertek;
    }

    bool teljesitett (double eredmeny, double cel) const
    {
        std::cout << eredmeny << '/' << cel << " ";
        return (eredmeny >= cel);
    }

    void hasonlit (double eredmeny, double cel, std::string mertekegyseg) const
    {
        if (cel <= 0)
            std::cout << eredmeny << " " << mertekegyseg << std::endl << "Nem volt kituzott celod!" << std::endl << std::endl;
        else if (teljesitett(eredmeny, cel))
            std::cout << mertekegyseg << std::endl << "Ezzel teljesitetted a celod!" << std::endl << std::endl;
        else
            std::cout << mertekegyseg << std::endl << "Ezzel sajnos nem erted el a celod!" << std::endl << std::endl;
    }
public:
    void kiertekel (std::string nev)
    {
        Atlagok data = atlag();
        Atlagok celok = cel(nev);
        std::cout << "Futas: atlagosan napi ";
        hasonlit(data.napifutas, celok.napifutas, adat->getFutas().getMertekegyseg());
        std::cout << "Olvasas: atlagosan  napi ";
        hasonlit(data.napiolvasas, celok.napiolvasas, adat->getOlvasas().getMertekegyseg());
        std::cout << "Filmnezes: atlagosan  napi ";
        hasonlit(data.napifilmnezes, celok.napifilmnezes, adat->getFilmnezes().getMertekegyseg());

    }
};

#endif // HONAP_HPP_INCLUDED
