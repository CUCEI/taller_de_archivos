#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void capturar();
int consultar();

struct datos{
    int key;
    char car;
    float real;
};

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
            printf("2- Consultar\n");
            printf("3- Salir\n\n");
            printf("Opcion: ");
            scanf("%i", &opc);


            switch(opc)
            {
                case 1:
                    capturar(des);
                    break;
                case 2:
                    consultar(des);
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
    struct datos d;
    int opc;

    lseek(des, 0, 2);

    fflush(stdin);
    printf("Dame la llave primaria de el registro: ");
    scanf("%i", &d.key);
    printf("Dame un caracter: ");
    fflush(stdin);
    scanf("%c", &d.car);
    printf("Dame un numero real: ");
    scanf("%f", &d.real);

    write(des, &d, sizeof(d));

    printf("deceas agregar otro numero?");
    scanf("%i", &opc);
     if(opc==1)
     {
         capturar(des);
     }
}

int consultar(int des)
{
    struct datos d;
    int llave, opc;

    system("cls");
    lseek(des, 0, 0);

    printf("Dame la llave primaria de el registro a buscar");
    scanf("%i", &llave);

    while(read(des, &d, sizeof(d)) > 0)
    {
        if(llave == d.key)
        {
            printf("registro encontrado:\n");
            printf("Llave: %i\nCaracter: %c\nReal: %f\n", d.key, d.car, d.real);
            system("pause");
            return 0;
        }
    }

    printf("Registro no encontrado");
    printf("Deceas buscar otro registro?: ");
    scanf("%i", &opc);
    if(opc==1)
    {
        consultar(des);
    }

    return 0;
}

