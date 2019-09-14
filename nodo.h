#ifndef nodo_h
#define nodo_h

struct nodo
{
    char *nombre;
    nodo *anterior;
    nodo *siguiente;

    nodo()
    {
        anterior = 0;
        siguiente = 0;
        nombre = (char *)' ';
    }
};
void insertar(nodo **, char *);
void imprimir(nodo **);
void insertarAlInicio(nodo **, char *);
void insertarAlFinal(nodo **, char *);
void Ordenar(nodo **);
void guardarenArchivo(nodo **, char *);
void cargarDesdeArchivo(char *);
bool BuscarElemento(nodo **, char *);
#endif
