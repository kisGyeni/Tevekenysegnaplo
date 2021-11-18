#ifndef CPORTA
    #if       _WIN32_WINNT < 0x0500
        #undef  _WIN32_WINNT
        #define _WIN32_WINNT 0x0500
    #endif
    #include <windows.h>
    #include "formatting.h"
#else
    #include "gtest_lite.h"
    using namespace gtest_lite;
    #include "memtrace.h"
#endif // CPORTA

#include <iostream>
#include <sstream>
#include "Nap.h"
#include "Honap.hpp"
#include "celok.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;


int main()
{

    #ifdef CPORTA
{
    TEST(Futas, tevekenyseg_subclass_ctor) {
        EXPECT_NO_THROW(Futas());
    } END

    TEST(Nap, nap_class_ctor) {
        EXPECT_NO_THROW(Nap(Futas(), Olvasas(), Filmnezes()));
    } END

    TEST(Nap, nap_class_can_call_member_method) {
        Nap teszt(0, 0, 0);
        EXPECT_NO_THROW(teszt.olvasott(12, true, "Konyv"));
        EXPECT_NO_THROW(teszt.futott(0.5));
    } END
    TEST(Honap, honap_ctors)
    {
        Honap<Nap> teszt(3);
        TEST(Honap, no_args_ctr)
        {
            EXPECT_NO_THROW(Honap<Olvasas>()); // no args with Olvasas class
        } END
        TEST(Honap, size_ctr)
        {
            EXPECT_NO_THROW(Honap<int>(4)); // size arg with int primitive_type
        } END
        TEST(Honap, copy_ctr)
        {
            EXPECT_NO_THROW(Honap<Nap>(teszt)); // copy ctr with Nap class
        } END
        TEST(Honap, ctr_values)
        {
            Honap<Nap> valuetest;
            valuetest.push_back(Nap(Futas(13, true), Olvasas(20, "Konyvcim"), Filmnezes(122, 4)));
            Honap<Nap> compare(valuetest);
            EXPECT_EQ(teszt.size(), Honap<Nap>(teszt).size());
            EXPECT_EQ(valuetest[0].getOlvasas().getCim(), compare[0].getOlvasas().getCim());

        } END
    } END

    TEST(Mertekegysegek, getter) {
        EXPECT_EQ("km", Futas().getMertekegyseg());
        EXPECT_EQ("oldal", Olvasas().getMertekegyseg());
        EXPECT_EQ("perc", Filmnezes().getMertekegyseg());

    } END

    TEST(Virtual, overrides)
    {
        EXPECT_NE(Futas().goal(), Olvasas().goal());
        EXPECT_NE(Futas().goal(), Filmnezes().goal());
        EXPECT_NE(Olvasas().goal(), Filmnezes().goal());
        //a goal virtualis tagfuggvenyre minden leszarmazott mas erteket ad vissza
    } END

    TEST(goals, setting)
    {
        EXPECT_NO_THROW(setgoal("nev", {124, 42, 22}));
        EXPECT_NO_THROW(setgoal("nev", Olvasas(), 100));
        EXPECT_NO_THROW(resetgoal("nev", Futas()));
    } END
    TEST(Honap, values)
    {
        Honap<Nap> egyikhonap, masikhonap;
        Nap egyik(Futas(13, true), Olvasas(20, "Konyvcim"), Filmnezes(122, 4));
        Nap masik(Futas(10), Olvasas(20, "Masik Konyvcim"), Filmnezes(57, 1));
        egyikhonap.push_back(egyik);
        masikhonap.push_back(masik);

        TEST(Honap, compare_nested_data)
        {
            EXPECT_NE(egyikhonap[0].getFutas().getAszfalton(), masikhonap[0].getFutas().getAszfalton());
            EXPECT_GT(egyikhonap[0].getFilmnezes().getErtekeles(), masikhonap[0].getFilmnezes().getErtekeles());
            EXPECT_EQ(egyik.getOlvasas().getMennyiseg(), masik.getOlvasas().getMennyiseg());
        } END

        TEST(Honap, modify_and_overwrite_data)
        {
            egyikhonap[0].olvasott(5);
            masikhonap[0].olvasott(25, true, "Konyvcim");
            EXPECT_EQ(egyikhonap[0].getOlvasas().getMennyiseg(), masikhonap[0].getOlvasas().getMennyiseg());
            EXPECT_EQ(egyikhonap[0].getOlvasas().getCim(), masikhonap[0].getOlvasas().getCim());
        } END

        TEST(Honap, stats_return_and_compare)
        {
            Atlagok atl1 = egyikhonap.atlag();
            Atlagok atl2 = masikhonap.atlag();
            EXPECT_NE(atl1.napifilmnezes, atl2.napifilmnezes);
            EXPECT_EQ(atl1.napiolvasas, atl2.napiolvasas);
        } END

    } END

}
    #else
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    int w = desktop.right;
    int h = desktop.bottom;
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, w, h, TRUE);

    time_t most = time(0);
    tm* ido = localtime(&most);
    int cells = 0; //hány cellát kell kirajzolni
    if (ido->tm_mon == 1) cells = 28;
    else if (ido->tm_mon == 3 || ido->tm_mon == 5 || ido->tm_mon == 8 || ido->tm_mon == 10 || ido->tm_mon == 12) cells = 30;
    else cells = 31;
    int napos = cells;

    std::string username; // ilyen nevu fajlt hoz letre az .EV/HONAP/FELHASZNALONEV.txt útvonalon
    cout << "Adja meg a felhasznalonevet: ";
    getline(cin, username);

    honapnev(ido->tm_mon);

    int eltol = 7-((ido->tm_mday-ido->tm_wday+7)%7); //mai nap-vasarnap ota eltelt ido(+7 ha negativ lenne a kulonbseg) 7-tel valo osztasi maradeka nap van a honap elso heteben. 7 minusz ennyit kell tehat az elso sort bentebb kezdeni
    int shift = eltol;
    bool shiftdown = true;
    if ((eltol >= 2 && !(ido->tm_mon == 7 || ido->tm_mon == 8 || ido->tm_mon == 10 || ido->tm_mon == 11)) || (eltol >= 3)) shiftdown = false;
    while (++eltol <= 7)
    {
        if (ido->tm_mday+cells == napos+1) cellarajzol(eltol, 1, true, shiftdown);

        else cellarajzol(eltol, 1, false, shiftdown);
        cells--;
    }
    int sor = 2;
    while (cells > 0)
    {
        for (int i = 0; i < 7; i++)
        {
            if (ido->tm_mday+cells == napos+1) cellarajzol(i+1, sor, true, shiftdown);
            else cellarajzol(i+1, sor, false, shiftdown);
            if (--cells == 0) break;
        }
        sor++;
    }

    Honap<Nap> mostho(username); // konstruktorhívás felhasználónév alapján

    menustate state = fomenu;
    double tevmenny;
    int tevtipus, tevnap = -1;
    std::ostringstream beleir;
    Atlagok cellaadat;
    for(int i = 0; i < napos; ++i)
    {
        cellaadat.napifutas = mostho[i].getFutas().getMennyiseg();
        cellaadat.napiolvasas = mostho[i].getOlvasas().getMennyiseg();
        cellaadat.napifilmnezes = mostho[i].getFilmnezes().getMennyiseg();

        adatbeir(i+1, shift, shiftdown, cellaadat);
    }
    while (state != kilep)
    {


        switch(state)
        {
        case fomenu:
            state = menu(state);
            break;
        case melyikadat:
            cin >> tevtipus;
            state = menu(state);
            cin >> tevmenny;
            if (tevnap == -1) tevnap = ido->tm_mday; //ha nincs beallitott adat, a mai napra vegyuk fel az adatot
            beleir.str(std::string());
            beleir << tevmenny;
            adatbeir(tevnap, shift, shiftdown, beleir.str(), tevtipus);
            switch(tevtipus)
            {
            case 1:
                mostho[tevnap-1].futott(tevmenny, true);
                break;
            case 2:
                mostho[tevnap-1].olvasott(tevmenny, true);
                break;
            case 3:
                mostho[tevnap-1].filmezett(tevmenny, true);
                break;
            default:
                break;
            }
            mostho.elment(username);
            tevnap = -1;
            break;
        case melyiknap:
            cin >> tevnap;
            break;

        case melyikceladat:
            cin >> tevtipus;
            state = menu(state);
            cin >> tevmenny;
            switch(tevtipus)
            {
            case 1:
                if (tevmenny <= 0)
                    resetgoal(username, Futas());
                else
                    setgoal(username, Futas(), tevmenny);
                break;
            case 2:
                if (tevmenny <= 0)
                    resetgoal(username, Olvasas());
                else
                    setgoal(username, Olvasas(), tevmenny);
                break;
            case 3:
                if (tevmenny <= 0)
                    resetgoal(username, Filmnezes());
                else
                    setgoal(username, Filmnezes(), tevmenny);
                break;
            }
            break;

        case stats:
            statpos();
            mostho.kiertekel(username);
            cin.ignore();
            getchar();
            break;

        default:
            break;
        }

        state = menu(state);

    }

    mostho.elment(username); // .EV/HONAP/FELHASZNALONEV.txt fájlba írás


    /**

    Nap egy     (
                Futas(10, true),
                Olvasas(44, "Harry Potter"),
                Filmnezes(120, 5)
                );

    Nap ketto   (
                1,
                Olvasas(33, "Hobbit"),
                Filmnezes(10, 1)
                );


    mostho.felvesz(egy, 4); //felveszi az egy változó adatait negyedikére
    mostho.felvesz(ketto); // felveszi a ketto változó adatait mára

    setgoal(nev, {50, 100, 150}); // beállítja mindhárom célt
    setgoal(nev, Futas(), 6.4); // beállítja a futás célt
    resetgoal(nev, Filmnezes()); // eltávolítja a filmnézés célt

    //cout << "=====================\nA honapban felvett olvasott oldalak atlaga: " << mostho.atlag().napiolvasas << " " << mostho[0].getOlvasas().getMertekegyseg() << endl << endl;
    //mostho.kiertekel(nev); // kiértékeli a célokat

    mostho[3].olvasott(123); // negyedikén olvasott még 123 oldalt

    //cout << "=====================\nA honapban felvett olvasott oldalak atlaga: " << mostho.atlag().napiolvasas << " " << mostho[0].getOlvasas().getMertekegyseg() << endl << endl;
    //mostho.kiertekel(nev); // kiértékeli a célokat

    */


    #endif // TESZTEL
    return 0;
}
