#include <iostream>
using namespace std;

//Definire una classe Point2D che rappresenti un punto nel piano cartesiano.
// Sovraccarica gli operatori + e - per sommare o sottrarre due numeri.
// Inoltre, sovraccarica l'operatore << per consentire la stampa di un punto nel formato "(x, y)".

class Point2D {

private:

    int x;
    int y;

    Point2D somma(const Point2D& other) {
        Point2D result;
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        return result;
    }

public:

    Point2D() {
        this->x = 0;
        this->y = 0;
    }

    Point2D operator+(const Point2D& other) {
        return this->somma(other);
    }

    void leggi(istream& input) {
        input >> this->x >> this->y;
    }

    void stampa(ostream& output) const {
        output << "(" << this->x << ", " << this->y << ")" << endl;
    }

};

istream& operator>>(istream& in, Point2D& p) {
    p.leggi(in);
    return in;
}

ostream& operator<<(ostream& out, const Point2D& p) {
    p.stampa(out);
    return out;
}

int main() {
    Point2D p1;
    Point2D p2;
    cout << "Inserisci coordinate del primo punto e del secondo punto: ";
    cin >> p1 >> p2;
    Point2D p3 = p1 + p2;
    cout << p1 << p2 << p3;
    return 0;
}