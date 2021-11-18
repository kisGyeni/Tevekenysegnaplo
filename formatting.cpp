#include "formatting.h"
#ifndef CPORTA


using std::cout;
using std::cin;


menustate nextstate(char selection, menustate src_state)
{
    switch (src_state)
    {
    case fomenu:
        switch (selection)
        {
        case '+':
            return uj;
        case 'r':
            return ujback;
        case 'c':
            return ujcel;
        case 's':
            return statsdisplay;
        case 'x':
            return kilep;
        default:
            return fomenu;
        }
        break;
    case uj:
        return melyikadat;
        break;
    case ujback:
        return melyiknap;
        break;
    case melyiknap:
        return melyikadat;
        break;
    case melyikadat:
        return fomenu;
        break;
    case ujcel:
        return melyikceladat;
        break;
    case melyikceladat:
        return celertek;
        break;
    case celertek:
        return fomenu;
        break;
    case statsdisplay:
        return stats;
        break;
    case stats:
        return fomenu;
        break;
    case kilep:
        return kilep;
        break;
    default:
        return fomenu;
        break;
    }
}

menustate menu(menustate state)
{
    char selection;
    clearmenuselection();

    switch(state)
    {
    case fomenu:
        gotoxy(5*w+2, 5*h+1);
        cout << "Tevekenyseg felvetele - +";
        gotoxy(5*w+2, 5*h+3);
        cout << "Tevekenyseg visszamenoleges felvetele - r";
        gotoxy(5*w+2, 5*h+5);
        cout << "Uj cel kituzese - c";
        gotoxy(5*w+2, 5*h+7);
        cout << "Havi statisztika megtekintese - s";
        gotoxy(5*w+2, 5*h+9);
        cout << "Kilepes - x";

        gotoxy(0, 6*h);
        cin >> selection;
        break;

    case uj:
        gotoxy(5*w+2, 5*h+1);
        cout << "Melyik adatot szeretned felvenni?";
        gotoxy(5*w+2, 5*h+3);
        cout << "Futas - 1";
        gotoxy(5*w+2, 5*h+5);
        cout << "Olvasas - 2";
        gotoxy(5*w+2, 5*h+7);
        cout << "Filmnezes - 3";
        break;

    case ujback:
        gotoxy(5*w+2, 5*h+1);
        cout << "A honap hanyadik napjanak tevekenyseget szeretned modositani?";

        break;

    case melyikadat:
        gotoxy(5*w+2, 5*h+1);
        cout << "Add meg a beallitando erteket!";
        break;

    case melyiknap:
        gotoxy(5*w+2, 5*h+1);
        cout << "Melyik adatot szeretned felvenni?";
        gotoxy(5*w+2, 5*h+3);
        cout << "Futas - 1";
        gotoxy(5*w+2, 5*h+5);
        cout << "Olvasas - 2";
        gotoxy(5*w+2, 5*h+7);
        cout << "Filmnezes - 3";
        break;

    case ujcel:
        gotoxy(5*w+2, 5*h+1);
        cout << "Melyik tevekenyseg celjat szeretned modositani?";
        gotoxy(5*w+2, 5*h+3);
        cout << "Futas - 1";
        gotoxy(5*w+2, 5*h+5);
        cout << "Olvasas - 2";
        gotoxy(5*w+2, 5*h+7);
        cout << "Filmnezes - 3";
        break;

    case melyikceladat:
        gotoxy(5*w+2, 5*h+1);
        cout << "Mennyi legyen a napi atlagos cel?";
        break;

    case statsdisplay:
        gotoxy(5*w+2, 5*h+1);
        cout << "Havi statisztika: ";
        break;

    case stats:
        statpos();
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                std::cout << ' ';
            }
            std::cout << std::endl;
        }
        break;

    default:
        break;
    }

    gotoxy(0, 0);
    gotoxy(0, 6*h);
    //getchar();
    return nextstate(tolower(selection), state);
}

void clearmenuselection()
{
        gotoxy(0, 6*h);
        cout << "                                                             ";
        gotoxy(5*w+2, 5*h+1);
        cout << "                                                             ";
        gotoxy(5*w+2, 5*h+3);
        cout << "                                                             ";
        gotoxy(5*w+2, 5*h+5);
        cout << "                                                             ";
        gotoxy(5*w+2, 5*h+7);
        cout << "                                                             ";
        gotoxy(5*w+2, 5*h+9);
        cout << "                                                             ";
}

void honapnev(int ho)
{
    switch(ho)
    {
    case 0: cout << "\n         _                     __\n        | |                   /_/\n        | | __ _ _ __  _   _  __ _ _ __\n    _   | |/ _` | '_ \\| | | |/ _` | '__|\n   | |__| | (_| | | | | |_| | (_| | |\n    \\____/ \\__,_|_| |_|\\__,_|\\__,_|_|"; break;
    case 1: cout << "\n    ______   _                  __\n   |  ____| | |                /_/\n   | |__ ___| |__  _ __ _   _  __ _ _ __\n   |  __/ _ \\ '_ \\| '__| | | |/ _` | '__|\n   | | |  __/ |_) | |  | |_| | (_| | |\n   |_|  \\___|_.__/|_|   \\__,_|\\__,_|_|"; break;
    case 2: cout << "\n    __  __   __           _\n   |  \\/  | /_/          (_)\n   | \\  / | __ _ _ __ ___ _ _   _ ___\n   | |\\/| |/ _` | '__/ __| | | | / __|\n   | |  | | (_| | | | (__| | |_| \\__ \\\n   |_|  |_|\\__,_|_|  \\___|_|\\__,_|___/"; break;
    case 3: cout << "\n       __              _ _ _\n      /_/             (_) (_)\n      / \\   _ __  _ __ _| |_ ___\n     / _ \\ | '_ \\| '__| | | / __|\n    / ___ \\| |_) | |  | | | \\__ \\\n   /_/   \\_\\ .__/|_|  |_|_|_|___/\n           | |\n           |_|"; break;
    case 4: cout << "\n    __  __   __  _\n   |  \\/  | /_/ (_)\n   | \\  / | __ _ _ _   _ ___\n   | |\\/| |/ _` | | | | / __|\n   | |  | | (_| | | |_| \\__ \\\n   |_|  |_|\\__,_| |\\__,_|___/\n               _/ |\n              |__/"; break;
    case 5: cout << "\n         _   __        _\n        | | /_/       (_)\n        | |_   _ _ __  _ _   _ ___\n    _   | | | | | '_ \\| | | | / __|\n   | |__| | |_| | | | | | |_| \\__ \\\n    \\____/ \\__,_|_| |_|_|\\__,_|___/"; break;
    case 6: cout << "\n         _   __  _ _\n        | | /_/ | (_)\n        | |_   _| |_ _   _ ___\n    _   | | | | | | | | | / __|\n   | |__| | |_| | | | |_| \\__ \\\n    \\____/ \\__,_|_|_|\\__,_|___/\n"; break;
    case 7: cout << "\n                                      _\n       /\\                            | |\n      /  \\  _   _  __ _ _   _ ___ ___| |_ _   _ ___\n     / /\\ \\| | | |/ _` | | | / __|_  / __| | | / __|\n    / ____ \\ |_| | (_| | |_| \\__ \\/ /| |_| |_| \\__ \\\n   /_/    \\_\\__,_|\\__, |\\__,_|___/___|\\__|\\__,_|___/\n                   __/ |\n                  |___/"; break;
    case 8: cout << "\n     _____              _                 _\n    / ____|            | |               | |\n   | (___ _______ _ __ | |_ ___ _ __ ___ | |__   ___ _ __\n    \\___ \\_  / _ \\ '_ \\| __/ _ \\ '_ ` _ \\| '_ \\ / _ \\ '__|\n    ____) / /  __/ |_) | ||  __/ | | | | | |_) |  __/ |\n   |_____/___\\___| .__/ \\__\\___|_| |_| |_|_.__/ \\___|_|\n                 | |\n                 |_|"; break;
    case 9: cout << "\n     ____  _    _    __  _\n    / __ \\| |  | |  /_/ | |\n   | |  | | | _| |_ ___ | |__   ___ _ __\n   | |  | | |/ / __/ _ \\| '_ \\ / _ \\ '__|\n   | |__| |   <| || (_) | |_) |  __/ |\n    \\____/|_|\\_\\\\__\\___/|_.__/ \\___|_|"; break;
    case 10: cout << "\n    _   _                          _\n   | \\ | |                        | |\n   |  \\| | _____   _____ _ __ ___ | |__   ___ _ __\n   | . ` |/ _ \\ \\ / / _ \\ '_ ` _ \\| '_ \\ / _ \\ '__|\n   | |\\  | (_) \\ V /  __/ | | | | | |_) |  __/ |\n   |_| \\_|\\___/ \\_/ \\___|_| |_| |_|_.__/ \\___|_|"; break;
    case 11: cout << "\n    _____                          _\n   |  __ \\                        | |\n   | |  | | ___  ___ ___ _ __ ___ | |__   ___ _ __\n   | |  | |/ _ \\/ __/ _ \\ '_ ` _ \\| '_ \\ / _ \\ '__|\n   | |__| |  __/ (_|  __/ | | | | | |_) |  __/ |\n   |_____/ \\___|\\___\\___|_| |_| |_|_.__/ \\___|_|"; break;

    default:
        cout << "Invalid"; break;
    }
}

void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

void cellarajzol(int x, int y, bool ma, bool shiftdown)
{
    y = (y-1)*h;
    if (shiftdown) y+=9;
    x = (x-1)*w;

    gotoxy(x, y);
    if (ma) cout << (char)201;
    else cout << (char)218;
    {
    for (int i = 0; i < w-2; i++)
        if (ma) cout << (char)205;
        else cout << (char)196;
    }
    if (ma) cout << (char)187;
    else cout << (char)191;
    gotoxy(x, y+1);
    for (int i = 0; i < h-2; i++)
    {
        if (ma) cout << (char)186;
        else cout << (char)179;
        for (int j = 0; j < w-2; j++)
        {
            if (ma) cout << (char)176;
            else cout << " ";
        }
        if (ma) cout << (char)186;
        else cout << (char)179;
        gotoxy(x, y+i+2);
    }
    if (ma) cout << (char)200;
    else cout << (char)192;
    for (int i = 0; i < w-2; i++)
    {
        if (ma) cout << (char)205;
        else cout << (char)196;
    }
    if (ma) cout << (char)188;
    else cout << (char)217;
}

void adatbeir(int nap, int shift, bool shiftdown, Atlagok cellaadat)
{
    std::ostringstream beir;
    std::string szoveg;
    int x, y;
    if (cellaadat.napifutas >= 0)
    {
        beir << cellaadat.napifutas << " km";
        szoveg = beir.str();
        x = ((nap+shift-1)%7)*w+w/2-szoveg.length()/2;
        y = (nap+shift-1)/7*h+h/2-2;
        if (shiftdown) y+=9;
        gotoxy(x, y);
        cout << szoveg;
        beir.str(std::string());
    }

    if(cellaadat.napiolvasas >= 0)
    {
        beir << cellaadat.napiolvasas << " oldal";
        szoveg = beir.str();
        x = ((nap+shift-1)%7)*w+w/2-szoveg.length()/2;
        y = (nap+shift-1)/7*h+h/2;
        if (shiftdown) y+=9;
        gotoxy(x, y);
        cout << szoveg;
        beir.str(std::string());
    }

    if (cellaadat.napifilmnezes >= 0)
    {
        beir << cellaadat.napifilmnezes << " perc";
        szoveg = beir.str();
        x = ((nap+shift-1)%7)*w+w/2-szoveg.length()/2;
        y = (nap+shift-1)/7*h+h/2+2;
        if (shiftdown) y+=9;
        gotoxy(x, y);
        cout << szoveg;
        beir.str(std::string());
    }
}

void adatbeir(int nap, int shift, bool shiftdown, std::string szoveg, int hova)
{
    std::ostringstream beir;
    beir << szoveg;
    switch(hova)
    {
    case 1:
        beir << " km";
        break;

    case 2:
        beir << " oldal";
        break;

    case 3:
        beir << " perc";
        break;

    }
    szoveg = beir.str();
    hova = (hova-2)*2;
    int x = ((nap+shift-1)%7)*w+w/2-szoveg.length()/2;
    int y = (nap+shift-1)/7*h+h/2+hova;
    if (shiftdown) y+=9;
    gotoxy(x, y);
    cout << szoveg;
}

void statpos()
{
    gotoxy(0, 7*h);
}

#endif // CPORTA
