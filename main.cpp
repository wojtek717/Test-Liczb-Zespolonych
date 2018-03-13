#include <iostream>
#include <cmath>
#include "Zespolona.h"
#include "InputOutput.h"
#include <fstream>
#include <getopt.h>

using namespace std;


int main(int argc, char **argv)
{
    /* Inicjalizacja zmiennych i obiektow */
    Zespolona z1(0,0);
    Zespolona z2(0,0);
    Zespolona wynik(0,0);
    Zespolona poprawnyWynik(0,0);
    int sumaPytan = 0;
    int poprawne = 0;
    int c;
    char ope;
    bool czyPoprawnyWynik;
    ifstream bazaPytan;

    /* Sprawdzenie podanego parametru przy wywolaniu programu */
    while ((c = getopt (argc, argv, "lt")) != -1)
        switch (c) /* c - wczytany argument */
        {
            case 'l': // parametr -l - otworz latwa baze pytan
                bazaPytan.open( "BazaLatwa.txt");
                break;

            case 't': // parametr -t = otworz trudna baze pytan
                bazaPytan.open( "BazaTrudna.txt");
                break;

            default: // inny parametr
                cout << "Podano zly parametr" << endl;
                return 2; //zakoncz dzialanie programu
        }

    if(bazaPytan.is_open()) //Sprawdz czy poprawnie otwarto plik .txt z pytaniami
    {
        cout << "OTWARTO PLIK: " << endl;

        /* Petla przeprowadzajaca test. Wykonuje sie do konca podanego pliku .txt z pytaniami */
        while (!bazaPytan.eof())
        {
            /* Kontrola bledow */
            try
            {
                /* Wczytaj wyrazenie zespolone z bazy pytan */
                bazaPytan >> z1; //Wczytaj pierwsza liczbe zespolona
                bazaPytan >> ope; //Wczytaj operator
                bazaPytan >> z2; // Wczytaj druga liczbe zespolona
            }
            catch (...)
            {
                cout << "Blad wczytywania liczby zespolonej" << endl;
            }

            sumaPytan++;
            cout << z1 << ope << z2 << endl; //Wypisz wyrazenie zespolone na ekran

            wynik = pytaj(); //Zapytaj uzytkownika o wynik podanego wyrazenia

            /* W zaleznosci od operatora oblicz poprawny wynik i sprawdz czy jest
             * zgodny z podanym wynikiem przez uzytkownika */
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
                    czyPoprawnyWynik = false;
                    break;
            }

            if(czyPoprawnyWynik) //Jezeli uzytkownik podal poprawny wynik
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
    bazaPytan.close(); //Zamknij plik z pytaniami

    cout << "Suma pytan: " << sumaPytan << endl;
    cout << "Poprawne odpowiedzi: " << poprawne << endl;

    return 0;
}