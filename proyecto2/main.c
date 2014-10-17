#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "arboles.h"
#include "arbolesInv.h"

int capturar(int, int);
void mostrar(int, int);
int consultar(int);
void buscar(int, int);

int main()
{
    int des, opc, indInv;
    des = open("productos.txt", O_BINARY | O_CREAT | O_RDWR);
    ind = open("indices.txt", O_BINARY | O_CREAT | O_RDWR);
    indInv = open("indiceInv.txt", O_BINARY | O_CREAT | O_RDWR);
    if(des>0)
    {
        do{
            system("cls");
            printf("Selecciona una opcion:\n");
            printf("1- Capturar\n");
            printf("2- Consultar\n");
            printf("3- Mostrar\n");
            printf("4- Salir\n\n");
            printf("Opcion: ");
            scanf("%i", &opc);


            switch(opc)
            {
                case 1:

                    capturar(des, ind);
                    break;
                case 2:
                    consultar(des);
                    break;
                case 3:
                    mostrar(des, ind);
                    break;
                case 4:
                    break;
                default:
                    printf("Opcion incorrecta, elige  otra vez.");
            }
        }while(opc != 4);
    }
    else
    {
        perror("");
    }
    return 0;
}

int capturar(int des, int ind)
{
    ARBOL raiz=NULL;
    struct figura figNueva;
    struct figura figLeida;
    struct indice indi;
    int opc, i;
    char opcs;
    float num;

    system("cls");

    printf("Escribe un ID nuevo para la figura: ");
    fflush(stdin);
    scanf("%i", &figNueva.id);

    lseek(des, 0, 0);
    //buscar si existe id
    fflush(stdin);
    while( read(des, &figLeida, sizeof(figLeida)) > 0)
    {

        if( figNueva.id == figLeida.id )
        {
            printf("ya existe la ID, por favor escoge otra");
            system("pause");
            capturar(des, ind);
            return 0;
        }
    }

    printf("¿que figura quieres guardar?");

    printf("Selecciona una opcion:\n");
    printf("1- Linea\n");
    printf("2- Triangulo\n");
    printf("3- Cuadrado\n\n");

    printf("Opcion: ");
    scanf("%i", &opc);

    do
    {
        switch(opc)
        {
            case 1:
                strcpy(figNueva.nom, "Linea");
                printf("escribe las coordenadas de los 2 vertices:\n");
                for(i=0; i<4; i++)
                {
                    if( i%2==0 )
                    {
                    printf("\nDame la coordenada x de el vertice %i y presiona enter: ", i+1);
                    scanf("%f", &num);
                    figNueva.coor[i] = num;
                    }
                    else
                    {
                    printf("Dame la coordenada Y de el vertice %i y presiona enter: ", i-1);
                    scanf("%f", &num);
                    figNueva.coor[i] = num;
                    }
                }
                break;
            case 2:
                strcpy(figNueva.nom, "Triangulo");
                printf("escribe las coordenadas de los 3 vertices:\n");
                for(i=0; i<6; i++)
                {
                    if( i%2==0 )
                    {
                    printf("\nDame la coordenada x de el vertice %i y presiona enter: ", i+1);
                    scanf("%f", &num);
                    figNueva.coor[i] = num;
                    }
                    else
                    {
                    printf("Dame la coordenada Y de el vertice %i y presiona enter: ", i-1);
                    scanf("%f", &num);
                    figNueva.coor[i] = num;
                    }
                }
                break;
            case 3:
                strcpy(figNueva.nom, "Cuadrado");
                printf("escribe las coordenadas de los 4 vertices:\n");
                for(i=0; i<8; i++)
                {
                    if( i%2==0 )
                    {
                    printf("\nDame la coordenada x de el vertice %i y presiona enter: ", i+1);
                    scanf("%f", &num);
                    figNueva.coor[i] = num;
                    }
                    else
                    {
                    printf("Dame la coordenada Y de el vertice %i y presiona enter: ", i-1);
                    scanf("%f", &num);
                    figNueva.coor[i] = num;
                    }
                }
                break;
            default:
                printf("Opcion incorrecta, elige  otra vez.");
        }
    }while(opc >= 3 && opc < 0);

    write(des, &figNueva, sizeof(figNueva));

    lseek(des, 0, 0);
    i=0;
    while( read(des, &figLeida, sizeof(figLeida)) > 0 )
    {
        indi.id=figLeida.id;
        indi.nrr=i;
        i++;
        insertanodonuevo(&raiz, indi);
    }

    lseek(ind, 0, 0);
    inorden(raiz, ind);

    printf("Deseas agregar otra figura? (s/n):");
    fflush(stdin);
    scanf("%c", &opcs);
    if(opcs=='s')
    {
        capturar(des, ind);
    }
    return 0;
}

int consultar(int des)
{
    struct figura figLeida;
    char llave[30], opcs;
    int opc;

    system("cls");
    lseek(des, 0, 0);

    printf("Dame la llave primaria de el registro a buscar");
    fflush(stdin);

    gets(llave);

    while(read(des, &figLeida, sizeof(figLeida)) > 0)
    {
        if(strcmp(llave, figLeida.id)==0)
        {
            printf("registro encontrado:\n");
            if(strcmp(figLeida.nom, "Linea")==0)
            {
                printf("ID: %s\nNombre: %s\ncoor: %f, %f, %f, %f\n\n", figLeida.id, figLeida.nom, figLeida.coor[0], figLeida.coor[1], figLeida.coor[2], figLeida.coor[3]);
            }
            else if(strcmp(figLeida.nom, "Triangulo")==0)
            {
                printf("ID: %s\nNombre: %s\ncoor: %f, %f, %f, %f, %f, %f\n\n", figLeida.id, figLeida.nom, figLeida.coor[0], figLeida.coor[1], figLeida.coor[2], figLeida.coor[3], figLeida.coor[4], figLeida.coor[5]);
            }
            else if(strcmp(figLeida.nom, "Cuadrado")==0)
            {
                printf("ID: %s\nNombre: %s\ncoor: %f, %f, %f, %f, %f, %f, %f, %f\n\n", figLeida.id, figLeida.nom, figLeida.coor[0], figLeida.coor[1], figLeida.coor[2], figLeida.coor[3], figLeida.coor[4], figLeida.coor[5], figLeida.coor[6], figLeida.coor[7]);
            }
            system("pause");
            return 0;
        }
    }

    printf("Figura no encontrada");
    printf("Deseas buscar otra figura? (s/n): ");
    scanf("%c", &opcs);
    if(opcs=='s')
    {
        consultar(des);
    }

    return 0;
}


void mostrar(int des, int ind)
{
    struct figura figLeida;
    struct indice indLeido;

    system("cls");
    lseek(des, 0, 0);
    lseek(ind, 0, 0);

    fflush(stdin);
    printf("ID\tNombre\t\tcoordenadas\n\n");
    while( read(ind, &indLeido, sizeof(struct indice)) > 0)
    {
        lseek(des, sizeof(struct figura)*indLeido.nrr, 0);
        read(des, &figLeida, sizeof(struct figura));
        if(strcmp(figLeida.nom, "Linea")==0)
        {
            printf("%i\t%s\t\t%f, %f, %f, %f\n\n", figLeida.id, figLeida.nom, figLeida.coor[0], figLeida.coor[1], figLeida.coor[2], figLeida.coor[3]);
        }
        else if(strcmp(figLeida.nom, "Triangulo")==0)
        {
            printf("%i\t%s\t%f, %f, %f, %f, %f, %f\n\n", figLeida.id, figLeida.nom, figLeida.coor[0], figLeida.coor[1], figLeida.coor[2], figLeida.coor[3], figLeida.coor[4], figLeida.coor[5]);
        }
        else if(strcmp(figLeida.nom, "Cuadrado")==0)
        {
            printf("%i\t%s\t%f, %f, %f, %f, %f, %f, %f, %f\n\n", figLeida.id, figLeida.nom, figLeida.coor[0], figLeida.coor[1], figLeida.coor[2], figLeida.coor[3], figLeida.coor[4], figLeida.coor[5], figLeida.coor[6], figLeida.coor[7]);
        }
    }
    system("pause");
}

void buscar(int des, int indInv)
{
    ARBOL raiz=NULL;
    struct figura figLeida;
    struct indiceInv indLeido;
    struct indiceInv indNuevo;
    int i=0, j, indEnc=0;

    lseek(des, 0, 0);


    while( read(des, &figLeida, sizeof(struct figura)) > 0 )
    {
        lseek(ind, 0, 0);
        while( read(indInv, &indLeido, sizeof(struct indiceInv)) > 0 )
        {
            if( strcmp(figLeida.nom, indLeido.nombre) == 0 )
            {
                for(j=0; j<indLeido.total;j++)
                {
                    if(i==indLeido.lista[j])
                        indEnc=1;
                        break;
                }
                if(indEnc==0)
                {
                    indLeido.lista[indLeido.total]=i;
                    indLeido.total=indLeido.total+1;
                }
                break;
            }
        }

    }
}
