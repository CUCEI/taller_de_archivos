#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void capturar();
void mostrar();
void incrementar();


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
            printf("3- Incrementar\n");
            printf("4- Salir\n\n");
            printf("Opcion: \n");
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
                    incrementar(des);
                    break;
                case 4:
                    return 0;
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

void capturar(int des)
{
    int codigo, opc;
    float precio;

    system("cls");
    lseek(des, 0, 2);
    printf("Codigo: ");
    scanf("%i", &codigo);
    write(des, &codigo, sizeof(int));
    printf("Precio: ");
    scanf("%f", &precio);
    write(des, &precio, sizeof(float));

    fflush(stdin);
    printf("¿Decea agregar otro producto? (si=1 no =0): ");
    scanf("%i", &opc);
    if(opc == 1)
    {
        capturar(des);
    }
    else{}
}

void mostrar(int des)
{
    int codigo, actual, fin;
    float precio;

    system("cls");
    fin = lseek(des, 0, 2);
    lseek(des, 0, 0);
    do
    {
        read(des, &codigo, sizeof(int));
        read(des, &precio, sizeof(float));
        printf("%i \t\t %f \n", codigo, precio);
        actual = lseek(des, 0, 1);
    }
    while(fin>actual);
    system("pause");
}

void incrementar(int des)
{
    float porcentaje, precio;
    int codigo, posPrecAct;

    system("cls");
    fflush(stdin);
    lseek(des, 0, 0);
    printf("dame el porcentaje a incrementar (solo numero): ");
    scanf("%f", &porcentaje);

    porcentaje= (porcentaje/100)+1;
    //porcentaje = (porcentaje/100)+1;

    while( read(des, &codigo, sizeof(int))>0 )
    {
        posPrecAct = lseek(des, 0, 1);
        read(des, &precio, sizeof(float));
        lseek(des, posPrecAct, 0);

        precio = precio * porcentaje;
        write(des, &precio, sizeof(float));
    }
}
