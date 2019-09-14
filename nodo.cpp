#include "nodo.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void imprimir(nodo **raiz)
{
    if (*raiz == 0)
    {
        return;
    }
    std::cout << " [ " << (*raiz)->nombre << " ] ";
    imprimir(&(*raiz)->siguiente);
}

void insertarAlFinal(nodo **raiz, char *nombre)
{
    nodo *nuevo = new nodo;
    nuevo->nombre = new char[strlen(nombre)];
    strcpy(nuevo->nombre, nombre);
    if (*raiz == 0)
    {
        *raiz = nuevo;
        return;
    }
    nodo *actual = *raiz;
    while (actual != 0)
    {
        if (actual->siguiente == 0)
        {
            nuevo->anterior = actual;
            actual->siguiente = nuevo;
            return;
        }
        actual = actual->siguiente;
    }
}
void insertarAlInicio(nodo **raiz, char *nombre)
{
    nodo *nuevo = new nodo;
    nuevo->nombre = new char[strlen(nombre)];
    strcpy(nuevo->nombre, nombre);
    if (*raiz == 0)
    {
        *raiz = nuevo;
        return;
    }
    (*raiz)->anterior = nuevo;
    nuevo->siguiente = *raiz;
    *raiz = nuevo;
    return;
}
void guardarenArchivo(nodo **raiz, char *Nombre)
{
    ofstream myfile;
    myfile.open(Nombre);
    nodo *actual = *raiz;
    while (actual != 0)
    {
        myfile << actual->nombre << std::endl;
        actual = actual->siguiente;
    }
    myfile.close();
}
void cargarDesdeArchivo(char *arch)
{
    ifstream read(arch);
    if (!read.is_open())
    {
        cout << "No se pudo abrir el Archivo: " << arch << endl;
        return;
    }
    string line;
    nodo *raiz = 0;
    while (getline(read, line))
    {
        char *cstr = &line[0];
        insertarAlFinal(&raiz, cstr);
    }
}
int getSize(nodo **raiz)
{
    nodo *actual = *raiz;
    int numero = 0;
    while (actual != 0)
    {
        numero++;
        actual = actual->siguiente;
    }
    return numero;
}

bool checkSort(nodo **raiz)
{
    nodo *actual = new nodo;
    actual = (*raiz);
    while (true)
    {
        if (actual->siguiente == 0)
        {
            return true;
        }
        if (strcmp(actual->nombre, actual->siguiente->nombre) > 0)
        {
            return false;
        }

        actual = actual->siguiente;
    }
    return true;
}
void Ordenar(nodo **raiz)
{
    nodo *actual = (*raiz);
    nodo *tempAnte;
    nodo *tempSig;
    nodo *tempSigSig;
    int i = 0;
    while (!checkSort(raiz))
    {
        if (strcmp(actual->nombre, actual->siguiente->nombre) > 0 && actual->siguiente != 0)
        {
            if (actual->anterior == 0)
            {
                tempAnte = 0;
                tempSig = actual->siguiente;
                tempSigSig = actual->siguiente->siguiente;
                tempSig->siguiente = actual;
                actual->anterior = tempSig;
                tempSigSig->anterior = actual;
                actual->siguiente = tempSigSig;
                (*raiz) = tempSig;
                (*raiz)->siguiente = actual;
                (*raiz)->anterior = 0;
                (*raiz)->siguiente->siguiente = tempSigSig;
            }
            else if (actual->siguiente->siguiente == 0)
            {
                tempAnte = actual->anterior;
                tempSig = actual->siguiente;
                tempAnte->siguiente = tempSig;
                tempSig->anterior = tempAnte;
                tempSig->siguiente = actual;
                actual->anterior = tempSig;
                actual->siguiente = 0;
            }
            else
            {
                tempAnte = actual->anterior;
                tempSig = actual->siguiente;
                tempSigSig = actual->siguiente->siguiente;
                tempAnte->siguiente = tempSig;
                tempSigSig->anterior = actual;
                actual->anterior = tempSig;
                tempSig->siguiente = actual;
                tempSig->anterior = tempAnte;
                actual->siguiente = tempSigSig;
            }
        }
        else if (strcmp(actual->nombre, actual->siguiente->nombre) < 0)
        {
            actual = actual->siguiente;
        }
        if (actual->siguiente == 0)
        {
            tempAnte = actual->anterior;
            tempSig = 0;
            tempSigSig = 0;
            actual = (*raiz);
        }
    }
}

bool BuscarElemento(nodo **raiz, char *persona)
{
    nodo *actual = (*raiz);
    while (actual != 0)
    {
        if (strcmp(actual->nombre, persona) == 0)
        {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}