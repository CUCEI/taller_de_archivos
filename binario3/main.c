#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void capturar();
void mostrar();

int main()
{
    int des, opc;
    des = open("productos.txt", O_BINARY | O_CREAT | O_RDWR);
    if(des>0)
    {
        do{
            system("cls");
            printf("Selecciona una opcion:\n");
            printf("1- Capturar\n");
            printf("2- Mostrar\n");
            printf("3- Salir\n\n");
            printf("Opcion: ");
            scanf("%i", &opc);


            switch(opc)
            {
                case 1:
                    capturar(des);
                    break;
                case 2:
                    mostrar(des);
                    break;
                case 3:
                    break;
                default:
                    printf("Opcion incorrecta, elige  otra vez.");
            }
        }while(opc != 3);
    }
    else
    {
        perror("");
    }
    return 0;
}

void capturar(int des)
{
    int opc, tam;
    char nombre[100];

    lseek(des, 0, 2);

    printf("Dame un numeroentero a agregar: ");
    fflush(stdin);
    gets(nombre);
    tam = strlen(nombre);
    write(des, &tam, sizeof(int));
    write(des, nombre, strlen(nombre));

    printf("deceas agregar otro numero?");
    scanf("%i", &opc);
     if(opc==1)
     {
         capturar(des);
     }
}

void mostrar(int des)
{
    int fin, actual, tam;
    char nombre[100];

    system("cls");
    fin = lseek(des, 0, 2);
    lseek(des, 0, 0);
    do
    {
        read(des, &tam, sizeof(int));
        read(des, nombre, tam);
        nombre[tam] = '\0';
        printf("%s \n", nombre);
        actual = lseek(des, 0, 1);
    }
    while(fin>actual);
    system("pause");
}

