#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void agregar();
void mostrar();
void buscar();

int main()
{
    int sal, opc, des;

    des = open("archivo.txt",O_CREAT | O_RDWR);
    if(des>0)
    {
        do
        {
            printf("1 - Agregar\n");
            printf("2 - Mostrar\n");
            printf("3 - Buscar\n");
            printf("Elige una opcion:");
            scanf("%i", &opc);
            switch(opc)
            {
                case 1:
                    system("cls");
                    agregar(des);
                    break;
                case 2:
                    system("cls");
                    mostrar(des);
                    break;
                case 3:
                    system("cls");
                    buscar(des);
                    break;
                default:
                    printf("opcion incorrecta, escoge otra vez\n");
            }
            printf("\nSalir? si=1, no=0");
            scanf("%i", &sal);
        }while(sal!=1);
    }
    else
        perror(" ");
    return 0;
}

void agregar(int des)
{
    int finDes, mciu, temp, i=0, j=1, z=1, cont=0, regEsc=0, finArc, total=0, resComp, actual=-1, abc;
    char nombre[21]="", pais[100] = "", sisseg[200], cadComp[21] = " ", car=' ';

    temp = open("temp.txt",O_CREAT | O_RDWR);
    lseek(des, 0, 0);

        if(temp>0)
        {
            //si en la primera lectura no tiene registros, agregar 1 para que el algoritmo funcione
            total = lseek(des, 0, 2);

            lseek(des, 0, 0);
            printf("Dame el nombre de la compania a agregar: ");
            fflush(stdin);
            gets(nombre);
            cont = strlen(nombre);
            while(cont<20)
            {
              nombre[cont]=' ';
              cont++;
            }
            nombre[20]='\0';

            while(actual<total)
            {
                cadComp[0] = '\0';
                finArc = lseek(des, 0, 1);
                finDes = read(des, cadComp, 20);
                if(total==0)
                {
                    finDes=1;
                }
                if(finDes<1  && finArc!=total)
                {
                    lseek(des, actual-20, 0);
                }
                else
                {
                    cadComp[20]='\0';
                    actual = lseek(des, 0, 1);

                    resComp = strcmp(nombre, cadComp);

                    //si ya existe
                    if(resComp==0 )
                    {
                        printf("\nYa existe el registro");
                        break;
                    }

                    //si nombre nuevo es mayor
                    finArc = lseek(des, 0, 1);
                    if(((resComp>0 && total>1) || regEsc==1) && finArc!=total)
                    {
                        if(finArc==total && regEsc==1)
                        {
                            break;
                        }
                        write(temp, cadComp, strlen(cadComp));
                        car=' ';
                        while(car!='\n')
                        {
                            read(des, &car, 1);
                            write(temp, &car, 1);
                        }
                        finArc = lseek(des, 0, 1);


                    }

                    //si nombre nuevo es menor
                    if((resComp<0 && regEsc==0) || total==0 || (actual==total && regEsc==0))
                    {
                        j=1;

                        write(temp, nombre, strlen(nombre));
                        //agregar paises
                        for(i=0 ; i<3; i++)
                        {
                            if(i>0)
                            {
                                printf("\nQuieres agregar mas paises? (si:1 no:0): ");
                                scanf("%i", &mciu);
                                if(mciu==0)
                                {
                                    if(i==1)
                                    {
                                        write(temp, "||", 2);
                                    }
                                    if(i==2)
                                    {
                                        write(temp, "|", 1);
                                    }
                                    break;
                                }

                            }
                            printf("\nDame el pais:");
                            fflush(stdin);
                            gets(pais);
                            write(temp, pais, strlen(pais));
                            write(temp, "|", 1);
                        }

                        //agregar sistema de seguridad
                        while(j!=0)
                        {
                            printf("\nAgrega sistema de seguridad: ");
                            fflush(stdin);
                            gets(sisseg);
                            write(temp, sisseg, strlen(sisseg));
                            write(temp, "#", 1);
                            printf("\nQuieres agregar mas Sistemas de seguridad? (si:1 no:0): ");
                                scanf("%i", &j);
                            if(j==0)
                            {
                                write(temp, "\n", 1);
                            }
                        }
                        abc = lseek(temp, 0, 1);
                        if(total>0)
                        {
                            write(temp, cadComp, strlen(cadComp));
                        }
                        car=' ';
                        while(car!='\n')
                        {
                            abc = read(des, &car, 1);
                            if(abc==0)
                            {
                                break;
                            }
                            write(temp, &car, 1);
                        }
                        regEsc=1;
                    }
                    /*
                    if(regEsc==0)
                    {
                        car=' ';
                        while(car!='\n')
                        {
                            abc = read(des, &car, 1);
                        }
                    }
                    */
                }
            }

        }
        else
        {
            perror(" ");
        }
        lseek(temp, 0, 0);
        lseek(des, 0, 0);
        while(read(temp, &car, 1)>0)
        {
            write(des, &car, 1);
        }


}

void mostrar(int des)
{
    int total, actual, readysis;
    char nombre[21], car;

    total=lseek(des,0,2);
    lseek(des, 0, 0);
    do
    {
        car = ' ';
        readysis=0;
        //leer nombre
        read(des, nombre, 20);
        nombre[20] = '\0';
        printf("%s", nombre);
        while(car!='\n')
        {
            read(des, &car, 1);
            if(car == '#')
            {
                printf("\n \t");
            }
            if(readysis == 3 && car != '#')
            {
                printf("%c", car);
            }
            if(car == '|')
            {
                readysis++;
                if(readysis == 3)
                {
                    printf("\n \t");
                }
            }
        }
        actual = lseek(des, 0, 1);
    }while(actual < total);
}

void buscar(int des)
{
    int i=0, j=0, k=0, regPos=0, comEnc[100]={0}, resComp, finArc=1, readysis=0;
    char pais[100], car=' ', buscando[100];

    lseek(des, 0, 0);
    printf("Dame el pais a buscar: ");
    fflush(stdin);
    gets(buscando);
    printf("\nBuscando...");

    do
    {
        lseek(des, 20, 1);
        while(finArc>0)
        {
            finArc = read(des, &car, 1);
            if(car=='|')
            {
                j++;
                if(i==0 && j<=3)
                {
                    i=strlen(buscando);
                }
                pais[i] = '\0';
                resComp = strncmp(pais, buscando, i);
                if(j==3 || resComp==0)
                {
                    j=0;
                    if(resComp==0)
                    {
                        comEnc[k]= regPos;
                        k++;
                    }
                    while(car!='\n')
                    {
                        read(des, &car, 1);
                        regPos = lseek(des, 0, 1);
                    }
                    i=0;
                    break;
                }
                i=0;
                continue;
            }
            else
            {
                pais[i]=car;
                i++;
            }
        }
        if(finArc==0)
        {
            comEnc[k]= -1;
        }
    }
    while(finArc>0);

    printf("\nSe encontro el pais en los siguientes registros: \n\n");
    for(i=0; i<k; i++)
    {
        readysis=0;
        lseek(des, comEnc[i], 0);
        read(des, pais, 20);
        pais[20] = '\0';
        printf("%s", pais);
        while(read(des, &car, 1)>0)
        {
            if(car == '#')
            {
                printf("\n \t");
            }
            if(readysis == 3 && car != '#')
            {
                printf("%c", car);
            }
            if(car == '|')
            {
                readysis++;
                if(readysis == 3)
                {
                    printf("\n \t");
                }
            }
            if(car == '\n')
            {
                break;
            }
        }
    }
}
