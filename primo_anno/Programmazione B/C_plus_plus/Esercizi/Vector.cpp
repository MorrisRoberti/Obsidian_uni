#include <iostream>
#include <math.h>
using namespace std;

// Implementa una classe Vector che rappresenti un vettore matematico in R^3.
// Sovraccarica gli operatori +, -, * (prodotto scalare) e [] (per l'accesso agli elementi del vettore).
// Aggiungi un metodo per calcolare la norma (lunghezza) del vettore.

class Vector {

private:

    int x;
    int y;
    int z;

    Vector somma(const Vector& other) {
        Vector v;
        v.x = this->x + other.x;
        v.y = this->y + other.y;
        v.z = this->z + other.z;
        return v;
    }

    Vector sottrazione(const Vector& other) {
        Vector v;
        v.x = this->x - other.x;
        v.y = this->y - other.y;
        v.z = this->z - other.z;
        return v;
    }

    int prodottoSc(Vector& other) {
        return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
    }

public:

    Vector() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Vector(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void read(istream& read) {
        read >> this->x >> this->y >> this->z;
    }

    void print(ostream& out) const {
        out << "(" << this->x << ", " << this->y << ", " << this->z << ")" << endl;
    }

    Vector operator+(const Vector& other) {
        return somma(other);
    }

    Vector operator-(const Vector& other) {
        return sottrazione(other);
    }

    int operator*(Vector& other) {
        return prodottoSc(other);
    }

    int& operator[](int i) {
        if (i < 0 || i > 3)
            throw string("Error");
        else if (i == 1)
            return this->x;
        else if (i == 2)
            return this->y;
        else
            return this->z;
    }

    float norma() {
        return sqrt(this->prodottoSc(*this));
    }

};

ostream& operator<<(ostream& out, const Vector& v) {
    v.print(out);
    return out;
}

istream& operator>>(istream& in, Vector& v) {
    v.read(in);
    return in;
}

int main() {
    Vector v1;
    cout << "Inserisci primo vett: ";
    cin >> v1;
    Vector v2(1, 2, 3);
    cout << "v1: " << v1;
    cout << "v2: " << v2;
    cout << "v1[2]: ";
    cout << v1[2] << endl;
    cout << "Somma: " << v1 + v2;
    cout << "Differenza: " << v1 - v2;
    cout << "Prodotto Scalare: " << v1 * v2 << endl;
    cout << "Norma: " << v1.norma();
    return 0;
}
