#include "InputOutput.h"
#include "Zespolona.h"


Zespolona pytaj()
{
    Zespolona liczba(0,0); //inicjalizacja liczby zespolonej

    for (int i = 0; i < 3; ++i) //Trzy szanse na podanie poprawnego formatu
    {
        /* Kontrola błedow */
        try
        {
            std::cout << "Podaj wynik: ";
            std::cin >> liczba;

            return liczba; //Zwroc podana liczbe zespolona w poprawnym formacie
        }
        catch (...)
        {
            std::cout << "Podano zla liczbe zespolona " << std::endl;
        }
    }
}
