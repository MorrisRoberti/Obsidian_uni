// Si consideri la classe Razionale vista durante la lezione del 20/02/2024.
// Si aggiunga un metodo semplifica che riduce ai minimi termini il razionale su cui viene invocato il metodo.
using namespace std;
#include <iostream>

class Razionale
{
private:
    int n;
    int d;

public:
    Razionale(int n, int d)
    {
        this->n = n;
        if (d != 0)
        {
            this->d = d;
        }
        else
        {
            cout << "Valore non valido per il denominatore, verra' posto a 1";
            this->d = 1;
        }
    }

    void semplifica()
    {
        // se sono entrambi pari li divido entrambi per 2 fin quando non sono ridotti al minimo
        int j = 2;
        while (j <= this->n && j <= this->d)
        {
            while (this->n % j == 0 && this->d % j == 0)
            {
                this->n = this->n / j;
                this->d = this->d / j;
            }
            j++;
        }
    }

    void stampa()
    {
        cout << this->n;
        if (this->d != 1)
        {

            cout << " / " << this->d << endl;
        }
    }
};

int main()
{
    int n, d;
    cout << "Numeratore: ";
    cin >> n;
    cout << endl
         << "Denominatore: ";
    cin >> d;
    Razionale r(n, d);
    r.semplifica();
    r.stampa();
    return 0;
}