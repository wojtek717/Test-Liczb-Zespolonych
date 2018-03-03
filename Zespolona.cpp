#include "Zespolona.h"
#include <cmath>
#include <iostream>

Zespolona::Zespolona(float real, float imaginary)
{
    this->real = real; //Przypisz pierwszy argument konstruktora do wartosci rzeczywistej liczby zespolonej
    this->imaginary = imaginary; //Przypisz drugi argument konstruktora do wartosci urojonej liczby zespolonej
}

float Zespolona::GetReal()
{
    return real; // Zwroc wartosc rzeczywista liczby zespolonej
}

void Zespolona::SetReal(float _real)
{
    real = _real; // Przypisz podany argument do wartosci rzeczywistej liczby zespolonej
}

float Zespolona::GetImaginary()
{
    return imaginary; // Zwroc wartosc urojona liczby zespolonej
}

void Zespolona::SetImaginary(float _imaginary)
{
    imaginary = _imaginary; //Przypisz podany argument do wartosci urojonej liczby zespolonej
}

float Zespolona::Modul()
{
    /* Zwroc modul liczby zespolonej wg. wzoru
     * pierwiastek(czescRzeczywista^2 + czescUrojona^2)*/
    return(
            sqrtf( // Funckja obliczajaca pierwiastek
                    (real * real) +
                    (imaginary * imaginary)
            )
    );
}

Zespolona Zespolona::Sprzezenie()
{
    Zespolona sprzezona(real, (-1 * imaginary));

    return sprzezona; // Zwroc sprzezenie liczby zespolonej
}

Zespolona operator + (Zespolona z1, Zespolona z2)
{
    Zespolona wynik(0,0);

    wynik.SetReal(z1.GetReal() + z2.GetReal()); // Dodaj czesci rzeczywiste
    wynik.SetImaginary(z1.GetImaginary() + z2.GetImaginary()); // Dodaj czesci urojone

    return wynik; // Zwroc wynik dodawania
}

Zespolona operator - (Zespolona z1, Zespolona z2)
{
    Zespolona wynik(0,0);

    wynik.SetReal(z1.GetReal() - z2.GetReal()); // Odejmij czesci rzeczywiste
    wynik.SetImaginary(z1.GetImaginary() - z2.GetImaginary()); // Odejmij czesci urojone

    return wynik; // Zwroc wynik odejmowania
}

Zespolona operator * (Zespolona z1, Zespolona z2)
{
    Zespolona wynik(0,0);

    /* Obliczenie czesci rzeczywistej */
    wynik.SetReal((z1.GetReal() * z2.GetReal()) - (z1.GetImaginary() * z2.GetImaginary()));
    /* Obliczenie czesci urojonej */
    wynik.SetImaginary((z1.GetReal() * z2.GetImaginary()) + (z1.GetImaginary() * z2.GetReal()));

    return wynik; // Zwroc wynik mnozenia
}

Zespolona operator / (Zespolona z1, float num)
{
    Zespolona wynik(0,0);

    /* Sprawdz czy nie dzielimy przez 0 */
    if(num != 0)
    {
        wynik.SetReal(z1.GetReal() / num); // Obliczenie czesci rzeczywistej
        wynik.SetImaginary(z1.GetImaginary() / num); // Obliczenie czesci urojonej

        return wynik; // Zwroc wynik dzielenia
    } else
    {
        std::cout << "Nie dziel przez zero"; // Powiadom o bledzie

        return z1; // Zwroc wartosc wyjsciowa
    }
}

Zespolona operator / (Zespolona z1, Zespolona z2)
{
    Zespolona wynik(0,0);

    /* Sprawdz czy nie dzielimy przez 0 */
    if (z2.Modul() != 0)
    {
        wynik = (z1 * z2.Sprzezenie()) / (z2.Modul() * z2.Modul()); // Obliczenie wyniku dzielenia

        return wynik; // Zwroc wynik dzielenia
    } else
    {
        std::cout << "Nie dziel przez zero"; // Powiadom o bledzie

        return z1; // Zwroc wartosc wyjsciowa
    }
}

std::ostream & operator<< (std::ostream &wyjscie, Zespolona z1)
{
    /* Sprawdz czy czesc urojona jest mniejsza od 0 */
    if (z1.GetImaginary() < 0)
    {
        /* Zwroc liczbe zespolona, w ktorej czesc urojona wystepuje ze znakiem - */
        return wyjscie << "(" << z1.GetReal() << z1.GetImaginary() << "i" << ")";
    } else
    {
        /* Zwroc liczbe zespolona, w ktorej czesc urojona wystepuje ze znakiem + */
        return wyjscie << "(" << z1.GetReal() << "+" << z1.GetImaginary() << "i" << ")";
    }
}

std::istream& operator>> (std::istream &is, Zespolona &z1)
{
    char c; // wczytywany znak
    float tmp; // zmienna przechowujaca wartosc tymczasowa

    is >> c; // Wczytaj znak z podanego strumienia
    /* Sprawdz czy podana liczba zespolona jest wpisana w poprawnym formacie
*   Podana liczba zespolona musi zawierać znaak "(" na poczatki */
    if (c != '(')
    {
        throw "zla liczba zespolona"; // Jesli nie - poinformuj o bledzie
    }

    /* Wczytaj czesc rzeczywista z podanego strumienia */
    is >> tmp;
    z1.SetReal(tmp);

    /* Wczytaj czesc urojona z podanego strumienia */
    is >> tmp;
    z1.SetImaginary(tmp);

    is >> c; // Wczytaj nastepny znak
    /* Sprawdz czy podana liczba zespolona jest wpisana w poprawnym formacie
     * Podana liczba zespolona musi zawierać znak "i" przy czesci urojonej
     * np. (4+4i)*/
    if (c != 'i')
    {
        throw "zla liczba zespolona"; // Jesli nie - poinformuj o bledzie
    }

    is >> c; // Wczytaj nastepny znak
    /* Sprawdz czy podana liczba zespolona jest wpisana w poprawnym formacie
    * Podana liczba zespolona musi zawierać znaak ")" na końcu */
    if (c != ')')
    {
        throw "zla liczba zespolona"; // Jesli nie - poinformuj o bledzie
    }
}

bool operator == (Zespolona z1, Zespolona z2)
{
    /* Zwroc wynik porownania dwoch liczb zespolonych */
    return (
            (z1.GetReal() == z2.GetReal()) && // Porownaj czesci rzeczywiste
           (z2.GetImaginary() == z2.GetImaginary()) // Porownaj czesci urojone
    );
}