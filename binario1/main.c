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
    int num, opc;

    lseek(des, 0, 2);

    printf("Dame un numero a agregar: ");
    scanf("%i", &num);

    write(des, &num, sizeof(int));

    printf("deceas agregar otro numero?");
    scanf("%i", &opc);
     if(opc==1)
     {
         capturar(des);
     }
}

void mostrar(int des)
{
    int num, sum = 0;

    lseek(des, 0, 0);

    while( read(des, &num, sizeof(int)) > 0 )
    {
        printf(" %i\n", num);
        sum = sum + num;
    }
    printf("\nSuma: %i\n", sum);
    system("pause");
}
