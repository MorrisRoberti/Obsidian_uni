#include <iostream>

class Resource
{
private:
    int m_x;
    int m_y;
    char *m_charptr;

public:
    Resource(int val_x, int val_y, char *char_p) : m_x(val_x), m_y(val_y), m_charptr(new char(*char_p))
    {
        std::cout << "Resource Constructor" << std::endl;
    }

    // copy constructor
    Resource(const Resource &other)
    {
        m_x = other.m_x;
        m_y = other.m_y;
        char *tmp = new char(*other.m_charptr); // potenziale errore
        m_charptr = tmp;
        std::cout << "Resource Copy Constructor" << std::endl;
    }

    // assignment operator
    Resource &operator=(const Resource &other)
    {
        m_x = other.m_x;
        m_y = other.m_y;

        // libero la memoria
        delete m_charptr;
        m_charptr = new char(*other.m_charptr);

        return *this;
    }

    // destructor
    ~Resource()
    {
        delete m_charptr;
        std::cout << "Resource Destructor" << std::endl;
    }

    const int x() const
    {
        return m_x;
    }

    const int y() const
    {
        return m_y;
    }

    const char *charptr() const
    {
        return m_charptr;
    }
};