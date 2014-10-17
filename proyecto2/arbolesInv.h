#define MAX 50

struct indiceInv
{
    char nombre[20];
    int total;
    int lista[MAX];
};

struct nodoarbolInv
{
    struct indiceInv reg;
    struct nodoarbolInv *izqnodo;
    struct nodoarbolInv *dernodo;
};
typedef struct nodoarbolInv NODOI;
typedef NODOI *ARBOLI;

void insertanodonuevoInv(ARBOLI *,struct indiceInv);
void inordenInv(ARBOLI, int);


void insertanodonuevoInv(ARBOLI *rarbol,struct indiceInv nuevo)
{
    if(*rarbol==NULL)
    {
        *rarbol=(NODOI *)malloc(sizeof(NODOI));
        if(*rarbol!=NULL)
        {
            (*rarbol)->reg=nuevo;
            (*rarbol)->izqnodo =NULL;
            (*rarbol)->dernodo=NULL;
        }
        else
        printf("\nญญญญ Memoria No Disponible !!!!\n");
    }
    else{}
    //    if(nuevo.id<(*rarbol)->reg.id)
     //       insertanodonuevo(&((*rarbol)->izqnodo),nuevo);
     //   else if(nuevo.id>(*rarbol)->reg.id)
       //     insertanodonuevo(&((*rarbol)->dernodo),nuevo);
}
void inordenInv(ARBOLI rarbol, int ind)
{
    if(rarbol!=NULL)
    {
        inorden(rarbol->izqnodo, ind);
        write(ind, &rarbol->reg, sizeof(struct indiceInv));
        inorden(rarbol->dernodo, ind);
    }
}
