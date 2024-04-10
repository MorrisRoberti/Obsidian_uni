// classe Data
// costruttore senza parametri
// costruttore 3 parametri: d, m, a
// overloading operatori di estrazione e inserimento

// Data la classe Data vista a lezione, si sovraccarichi l"operatore <
// in modo tale che il metodo corrispondente ritorni true se la data dell"oggetto d"invocazione
//  è antecedente alla data passata come parametro, false altrimenti.
#include <iostream>
#include <fstream>
using namespace std;

class Data
{
private:
    int day;
    int month;
    int year;

public:
    Data()
    {
        this->day = 1;
        this->month = 1;
        this->year = 1970;
    }

    Data(int day, int month, int year) : Data()
    {
        if (month > 0 && month < 13)
        {
            switch (month)
            {
            case 4:
            case 6:
            case 9:
            case 11:
                if (day > 0 && day <= 30)
                {
                    this->day = day;
                }
                else
                {
                    cout << "Errore: giorno non valido" << endl;
                }

            //  non conto gli anni bisestili
            case 2:
                if (day > 0 && day <= 29)
                {
                    this->day = day;
                }
                else
                {
                    cout << "Errore: per giorno di Febbraio!" << endl;
                }

            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (day > 0 && day <= 31)
                {
                    this->day = day;
                }
                else
                {
                    cout << "Errore: giorno non valido" << endl;
                }
            }
            this->month = month;
            this->year = year;
        }
        else
        {
            cout << "Il mese non puo essere negativo!" << endl;
        }
    }

    void stampa() const
    {
        cout << this->day << "/" << this->month << "/" << this->year << endl;
    }

    bool operator!=(const Data &other) const
    {
        return this->year != other.year || this->month != other.month || this->day != other.day;
    }
    bool operator==(const Data &other) const
    {
        other.stampa();
        return (this->year == other.year && this->month == other.month && this->day == other.day);
    }

    bool operator<(const Data &other) const
    {
        if (*this == other)
        {
            return false;
        }
        return (this->year <= other.year && this->month <= other.month && this->day <= other.day);
    }
};

int main()
{
    Data d(23, 10, 2001);
    Data d_equal(23, 10, 2001);
    cout << (d < d_equal) << endl; // false

    Data d2(23, 10, 2003);
    cout << (d < d2) << endl; // true

    Data d3(23, 9, 1999);
    cout << (d < d3) << endl; // false

    Data d4(23, 9, 2001);
    cout << (d < d4) << endl; // false

    Data d5(22, 10, 2001);
    cout << (d < d5) << endl; // false

    Data d6(23, 11, 2001);
    cout << (d < d6) << endl; // true

    Data d7(24, 10, 2001);
    cout << (d < d7) << endl; // true

    return 0;
}