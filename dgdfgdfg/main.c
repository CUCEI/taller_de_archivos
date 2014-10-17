#include <stdio.h>
#include <stdlib.h>

int main()
{
    float u;
printf("Ingrese Su Promedio Escolar: ");
scanf("%f", &u);
if(u>=100)
  {
    printf("%f: Tu Promedio Es Excelente",&u);
  }
if(u>=90&&u<100)
  {
    printf("%f: Tu Promedio Es Muy Bueno:",&u);
  }
if(u>=80&&u<90)
  {
    printf("%f: Tu Promedio Es Bueno",&u);
  }
 if(u>=70&&u<80)
  {
    printf("%f: Tu Promedio Es Regular",&u);
  }
if(u>=60&&u<70)
  {
    printf("%f: Tu Promedio Es Malo",&u);
  }
if(u<60)
  {
    printf("%f Es Necesario Estudiar Mas o Abandonar Cucei",&u);
  }
    return 0;
}
