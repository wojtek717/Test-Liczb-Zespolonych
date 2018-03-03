#include <iostream>
#ifndef ZESPOLONE_ZESPOLONA_H
#define ZESPOLONE_ZESPOLONA_H


class Zespolona
{
public:
    /* Konstruktor tworzacy nowe obiekty o klasie Zespolona
     * [IN](float) rzeczywista - rzeczywista wartosc liczby zespolonej
     * [IN](float) urojona - urojona wartosc liczby zespolonej */
    Zespolona(float rzeczywista, float urojona);

    /* Metoda obliczajaca modul liczby zespolonej
     * [RETURN](float) modul liczby zespolonej */
    float Modul();

    /* Metoda oblicza sprzezenie liczby zespolonej
     * [RETURN](Zespolona) Sprzezona liczba zespolona */
    Zespolona Sprzezenie();

    /* Metody pozwalajace wczytac lub odczytac wartosc rzeczywista liczby zespolonej */
    float GetReal();
    void SetReal(float);

    /* Metody pozwalajace wczytac lub odczytac wartosc urojona liczby zespolonej */
    float GetImaginary();
    void SetImaginary(float);

private:
    float real; // wartosc rzeczywista liczby zespolonej
    float imaginary; // wartosc urojona liczby zespolonej
};

/* Przeciazenia operatorow dla dzialan na liczbach zespolonych */
Zespolona operator + (Zespolona, Zespolona); // Dodoawania dwoch liczb zespolonych
Zespolona operator - (Zespolona, Zespolona); // Odejmowanie dwoch liczb zespolonych
Zespolona operator * (Zespolona, Zespolona); // Mnozenie dwoch liczb zespolonych
Zespolona operator / (Zespolona, float); // Dzielenie liczby zespolonej przez naturalna
Zespolona operator / (Zespolona, Zespolona); // Dzielenie dwoch liczb zespolonych
std::ostream & operator<< (std::ostream &wyjscie, Zespolona); // Wypisywanie liczby zespolonej
std::istream& operator>> (std::istream& is, Zespolona&); // Wczytywanie liczby zespolonej
bool operator == (Zespolona, Zespolona); // Porownanie dwoch liczb zespolonych


#endif //ZESPOLONE_ZESPOLONA_H
