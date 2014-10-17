#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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
    int num1, opc;
    float num2;

    lseek(des, 0, 2);

    printf("Dame un numero entero a agregar: ");
    scanf("%i", &num1);
     write(des, &num1, sizeof(int));
    printf("Dame un numero real a agregar: ");
    scanf("%f", &num2);
     write(des, &num2, sizeof(float));

    printf("deceas agregar otro numero?");
    scanf("%i", &opc);
     if(opc==1)
     {
         capturar(des);
     }
}

void mostrar(int des)
{
    int num1, fin, actual;
    float num2, mult = 0;

    system("cls");
    fin = lseek(des, 0, 2);
    lseek(des, 0, 0);
    do
    {
        read(des, &num1, sizeof(int));
        read(des, &num2, sizeof(float));
        mult = num1 * num2;
        printf("%i \t %f \t %f \n", num1, num2, mult);
        actual = lseek(des, 0, 1);
    }
    while(fin>actual);
    system("pause");
}
