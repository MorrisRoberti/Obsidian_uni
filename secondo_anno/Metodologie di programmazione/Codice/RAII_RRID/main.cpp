#include "ResourceHandler.cpp"
#include <iostream>

int main()
{
    char c = 'h';
    {
        ResourceHandler r1(10, 20, &c);
        std::cout << "the object is -> x: " << r1.getResource().x() << ", y: " << r1.getResource().y() << ", char: " << *(r1.getResource().charptr()) << std::endl;
    }

    return 0;
}