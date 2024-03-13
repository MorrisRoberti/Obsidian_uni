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
    StringSet()
    {
        this->s = 0;
        this->elements[0] = "";
    }

    StringSet(string V[], int n) : StringSet()
    {
        this->s = 0;
        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                this->add(V[i]);
            }
        }
    }

    void remove(string x)
    {
        if (this->contains(x))
        {
            for (int i = 0; i < this->s; i++)
            {
                if (this->elements[i] == x)
                {
                    this->elements[i] = this->elements[this->s - 1];
                    this->s--;
                    return;
                }
            }
        }
    }

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

        this->elements[this->s] = x;
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

    bool operator==(const StringSet &S2) const
    {
        return *this < S2 && S2 < *this;
    }

    // unione di insiemi
    StringSet &operator+(const StringSet &S2)
    {

        for (int i = 0; i < S2.size(); i++)
        {
            if (!this->contains(S2.elements[i]))
                this->add(S2.elements[i]);
        }

        return *this;
    }

    StringSet &operator-(const StringSet &S2)
    {
        for (int i = 0; i < S2.s; i++)
        {
            this->remove(S2.elements[i]);
        }
        return *this;
    }

    void print(ostream &dest) const
    {
        dest << "{";
        for (int i = 0; i < this->s; i++)
        {
            dest << this->elements[i];
            if (i != this->s - 1)
            {
                dest << ", ";
            }
        }
        dest << "}" << endl;
    }
};

ostream &operator<<(ostream &dest, const StringSet &S)
{
    S.print(dest);
    return dest;
}

int main()
{
    StringSet empty_set;
    cout << empty_set;

    int n = 2;
    string V[n] = {"hello", "world"};
    StringSet new_set = StringSet(V, n);
    cout << new_set;

    cout << (empty_set < new_set) << endl;

    empty_set.add("hello");

    cout << (empty_set < new_set) << endl;

    empty_set.add("!");
    cout << empty_set;

    cout << (empty_set < new_set) << endl;

    StringSet union_set = (empty_set + new_set);

    cout << union_set;

    cout << (union_set == new_set);

    return 0;
}