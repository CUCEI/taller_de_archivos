#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int des;
    des = creat("C:\\tmp\\archivo",764);
    if(des>0)
        printf("creacion exitosa");
    else
        perror(" ");
    return 0;
}
