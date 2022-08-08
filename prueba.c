#include <stdio.h>


int main()
{
    int a, b, c;
    printf("Ingrese el primer numero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);
    c = a * b;
    printf("El producto de los dos numeros es: %d\n", c);
    return 0;
}