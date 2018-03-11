#include <iostream>
#include <cmath>
#include "Zespolona.h"
#include <fstream>
#include <getopt.h>

using namespace std;

Zespolona pytaj()
{
    Zespolona liczba(0,0);

    for (int i = 0; i < 3; ++i)
    {
        try
        {
            cout << "Podaj wynik: ";
            cin >> liczba;

            return liczba;
        }
        catch (...)
        {
            cout << "Podano zla liczbe zespolona " << endl;
        }
    }
}

int main(int argc, char **argv)
{
    Zespolona z1(0,0);
    Zespolona z2(0,0);
    Zespolona wynik(0,0);
    Zespolona poprawnyWynik(0,0);
    int sumaPytan = 0;
    int poprawne = 0;
    char ope;
    int c;
    bool czyPoprawnyWynik;
    ifstream bazaPytan;

    while ((c = getopt (argc, argv, "lt")) != -1)
        switch (c) /* c - wczytany argument */
        {
            case 'l':
                bazaPytan.open( "BazaLatwa2.txt");
                break;

            case 't':
                bazaPytan.open( "BazaTrudna.txt");
                break;

            default:
                cout << "Podano zly parametr" << endl;
                break;
        }

    if(bazaPytan.is_open())
    {
        cout << "OTWARTO PLIK" << endl;

        while (!bazaPytan.eof())
        {
            try
            {
                bazaPytan >> z1;
                bazaPytan >> ope;
                bazaPytan >> z2;
            }
            catch (...)
            {
                cout << "Blad wczytywania liczby zespolonej" << endl;
            }

            sumaPytan++;
            cout << z1 << ope << z2 << endl;

            pytaj();

                switch (ope)
                {
                    case '+':
                        poprawnyWynik = z1 + z2;
                        czyPoprawnyWynik = (wynik == poprawnyWynik);
                        break;

                    case '-':
                        poprawnyWynik = z1 - z2;
                        czyPoprawnyWynik = (wynik == poprawnyWynik);
                        break;

                    case '/':
                        poprawnyWynik = z1 / z2;
                        czyPoprawnyWynik = (wynik == poprawnyWynik);
                        break;

                    case '*':
                        poprawnyWynik = z1 * z2;
                        czyPoprawnyWynik = (wynik == poprawnyWynik);
                        break;

                    default:
                        cout << "Bledny operator";
                        break;
                }

                if(czyPoprawnyWynik)
                {
                    cout << "Poprawny wynik" << endl << endl;
                    poprawne++;
                } else
                {
                    cout << "Bledny wynik" << endl;
                    cout << "Poprawny wynik to: " << poprawnyWynik << endl << endl;
                }

        }
    }
    bazaPytan.close();

    cout << "Suma pytan: " << sumaPytan << endl;
    cout << "Poprawne odpowiedzi: " << poprawne << endl;

    return 0;
}