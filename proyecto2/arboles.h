
#include<conio.h>
#define MAXNOM 50

struct figura
{
    int id;
    char nom[20];
    float coor[8];
};

struct indice
{
    int id, nrr;
};

struct nodoarbol
{
    struct indice reg;
    struct nodoarbol *izqnodo;
    struct nodoarbol *dernodo;
};
typedef struct nodoarbol NODO;
typedef NODO *ARBOL;

void insertanodonuevo(ARBOL *,struct indice);
void inorden(ARBOL, int);


void insertanodonuevo(ARBOL *rarbol,struct indice nuevo)
{
    if(*rarbol==NULL)
    {
        *rarbol=(NODO *)malloc(sizeof(NODO));
        if(*rarbol!=NULL)
        {
            (*rarbol)->reg=nuevo;
            (*rarbol)->izqnodo =NULL;
            (*rarbol)->dernodo=NULL;
        }
        else
        printf("\nญญญญ Memoria No Disponible !!!!\n");
    }
    else
        if(nuevo.id<(*rarbol)->reg.id)
            insertanodonuevo(&((*rarbol)->izqnodo),nuevo);
        else if(nuevo.id>(*rarbol)->reg.id)
            insertanodonuevo(&((*rarbol)->dernodo),nuevo);
}
void inorden(ARBOL rarbol, int ind)
{
    if(rarbol!=NULL)
    {
        inorden(rarbol->izqnodo, ind);
        write(ind, &rarbol->reg, sizeof(struct indice));
        inorden(rarbol->dernodo, ind);
    }
}
