#include "nodo.h"
#include <iostream>

using namespace std;
int main()
{
    nodo *raiz = 0;
    char *nombre = (char *)" ";
    int opciones{0};
    do
    {
        cout << "****PROGRAMA****" << endl;
        cout << "1. Insertar Al Inicio" << endl;
        cout << "2. Insertar Al Final" << endl;
        cout << "3. Ordenar" << endl;
        cout << "4. Imprimir" << endl;
        cout << "5. Guardar A Archivo" << endl;
        cout << "6. Leer De Archivo" << endl;
        cout << "7. Buscar Elemento" << endl;
        cout << "8. Salir" << endl;
        cin >> opciones;
        switch (opciones)
        {
        case 1:
            cout << "Ingrese Nombre A Ingresar: " << endl;
            cin >> nombre;
            insertarAlInicio(&raiz, nombre);
            break;
        case 2:
            cout << "Ingrese Nombre A Ingresar: " << endl;
            cin >> nombre;
            insertarAlFinal(&raiz, nombre);
            break;
        case 3:
            cout << "Ordenando" << endl;
            Ordenar(&raiz);
            break;
        case 4:
            cout << " Imprimiendo " << endl;
            imprimir(&raiz);
            break;
        case 5:
            cout << "Ponga el Nombre Del Archivo: " << endl;
            cin >> nombre;
            guardarArchivo(&raiz, nombre);
            break;
        case 6:
            cout << "Ponga el Nombre Del Archivo: " << endl;
            cin >> nombre;
            cargarDesdeArchivo(nombre);
            break;
        case 7:
            cout << "Ingrese Nombre A Buscar: " << endl;
            cin >> nombre;
            switch (BuscarElemento(&raiz, nombre))
            {
            case 0:
                cout << "Nombre No Existe" << endl;
                break;
            case 1:
                cout << "Nombre Existe" << endl;
                break;
            }
            break;
        case 8:
            cout << "Saliendo Programa." << endl;
            break;
        default:
            cout << "Eliga una opción del 1-8" << endl;
            break;
        }
    } while (opciones != 8);
}
