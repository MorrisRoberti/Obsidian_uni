#include "TestClass.hpp"

// struct MyNamespace::MyType
// {
//     int k;
// };

// OK: perche' il parametro e' di tipo "puntatore a MyType" quindi il compilatore non ha bisogno della definizione
// ATTENZIONE: se pero' andiamo ad accedere a campi di obj, si ha un errore
void MyNamespace::initializeMyType(MyNamespace::MyType *obj, int x)
{
    // Scommentare per vedere l'errore
    // obj->k = x;
    return;
}

// // SCOMMENTARE PER VEDERE L'ERRORE: Il tipo e' incompleto
// void MyNamespace::initializeT(MyNamespace::T obj, int x)
// {
//     return;
// }
