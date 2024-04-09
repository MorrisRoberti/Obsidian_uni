// Si consideri la classe Razionale vista durante la lezione del 26/02/2024. 
// Si sovraccarichino gli operatori == e != in modo tale che controllino, rispettivamente, se due razionali sono uguali o diversi.
#include <iostream>
using namespace std;

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

    bool operator==(Razionale other) {
        return this->n == other.n && this->d == other.d;
    }


    bool operator!=(Razionale other) {
        return this->n != other.n && this->d != other.d;
    }
};

int main() {
    int n, d;
    cout << "Numeratore: ";
    cin >> n;
    cout << "Denominatore: ";
    cin >> d;
    Razionale r(n, d);

    int c, k;
    cout << "Numeratore: ";
    cin >> c;
    cout << "Denominatore: ";
    cin >> k;
    Razionale r2(c, k);


    if(r == r2){
        cout << "Uguali" << endl;
    }

    if(r != r2) {
        cout << "Diversi" << endl;
    }

    return 0;
}