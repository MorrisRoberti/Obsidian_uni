
namespace MyNamespace
{
    // dichiarazioni pure di tipi
    struct MyType;
    struct T;

    // OK: utilizzo il puntatore opaco mytype_obj
    MyType *mytype_ptr;

    // ERRORE: Il tipo e' incompleto
    //  T t_ptr;
}

namespace MyNamespace
{

    void initializeMyType(MyType *obj, int x);

    void initializeT(T obj, int x);

}