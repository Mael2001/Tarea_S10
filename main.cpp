#include "nodo.h"
#include <iostream>

int main()
{
    nodo *raiz = 0;
    insertarAlInicio(&raiz, (char *)"PoPoPoPoncho");
    insertarAlInicio(&raiz, (char *)"Braian");
    insertarAlInicio(&raiz, (char *)"Anuel");
    insertarAlFinal(&raiz, (char *)"Recio");
    imprimir(&raiz);
    std::cout << BuscarElemento(&raiz, (char *)"Braian");
}