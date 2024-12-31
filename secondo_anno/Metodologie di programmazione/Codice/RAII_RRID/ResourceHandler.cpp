#include <iostream>
#include "Resource.cpp"
class ResourceHandler
{

private:
    Resource *m_resource;

public:
    ResourceHandler(int x, int y, char *charptr) : m_resource(new Resource(x, y, charptr))
    {
        std::cout << "ResourceHandler Constructor" << std::endl;
    }

    // rimuovo il copy constructor e il costruttore di default in quanto non voglio dare all'utente la possibilita' di passare le risorse in modo arbitrario
    // ne di costruire un handler che non gestisce risorse
    ResourceHandler(const ResourceHandler &other) = delete;
    ResourceHandler() = delete;

    ~ResourceHandler()
    {
        delete m_resource;
        std::cout << "ResourceHandler Destructor" << std::endl;
    }

    const Resource &getResource() const
    {
        return *m_resource;
    }
};