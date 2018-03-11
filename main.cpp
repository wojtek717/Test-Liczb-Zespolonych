#include <iostream>
#include <cmath>
#include "Zespolona.h"
#include <fstream>

using namespace std;

int main()
{
    Zespolona z1(0,0);
    Zespolona z2(0,0);
    Zespolona wynik(0,0);
    Zespolona poprawnyWynik(0,0);
    int sumaPytan = 0;
    int poprawne = 0;
    char ope;
    bool czyPoprawnyWynik;
    ifstream bazaLatwa;


    bazaLatwa.open( "BazaLatwa2.txt");

    if(bazaLatwa.is_open())
    {
        cout << "OTWARTO PLIK" << endl;

        while (!bazaLatwa.eof())
        {
            try
            {
                bazaLatwa >> z1;
                bazaLatwa >> ope;
                bazaLatwa >> z2;

                sumaPytan++;

                cout << z1 << ope << z2 << endl;

                cout << "Podaj wynik: ";
                cin >> wynik;


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
            catch (...)
            {
                cout << "Blad wczytywania liczby zespolonej" << endl;
            }
        }
    }
    bazaLatwa.close();

    cout << "Suma pytan: " << sumaPytan << endl;
    cout << "Poprawne odpowiedzi: " << poprawne << endl;

    return 0;
}