#include <iostream>
#include <fstream>
using namespace std;

#define MAX_SIZE 100

class StringSet
{
private:
    int s;
    string elements[MAX_SIZE];

public:
    StringSet() {}

    StringSet(string V[], int n) : StringSet() {}

    bool contains(string x) const
    {
        bool isPresent = false;
        for (int i = 0; i < this->s; i++)
        {
            if (this->elements[i] == x)
            {
                isPresent = true;
            }
        }
        return isPresent;
    }

    void add(string x)
    {
        if (this->contains(x))
        {
            cout << "L'elemento e' gia' presente";
            return;
        }

        if (this->s == MAX_SIZE)
        {
            cout << "L'insieme e' pieno";
            return;
        }

        this->elements[this->s + 1] = x;
        this->s++;
        return;
    }

    int size() const
    {
        return this->s;
    }

    // essere sottoinsiseme
    bool operator<(const StringSet &S2) const
    {
        if (this->size() > S2.size())
        {
            return false;
        }

        // itero sugli elementi e vedo se hanno gli stessi
        for (int i = 0; i < this->size(); i++)
        {
            if (!S2.contains(this->elements[i]))
            {
                return false;
            }
        }
        return true;
    }

    // unione di insiemi
    StringSet operator+(const StringSet &S2) const
    {
        StringSet result;

        for (int i = 0; i < this->size(); i++)
        {
            result.add(this->elements[i]);
        }

        for (int i = 0; i < S2.size(); i++)
        {
            result.add(S2.elements[i]);
        }

        return result;
    }

    void print(ostream &dest) const
    {
        dest << "{";
        for (int i = 0; i < this->s; i++)
        {
            if (i != this->s - 1)
            {
                dest << ", ";
            }
        }
        dest << "}";
    }
};

ostream &operator<<(ostream &dest, const StringSet &S)
{
    S.print(dest);
    return dest;
}

int main() {}