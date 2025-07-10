#include <stdio.h>
#define TAM 50

int main()
{
    char string[TAM], copia[TAM];
    scanf( "%[^\n]s", string);
    getchar();
    scanf( "%[^\n]s", copia);
    printf("\n");
    printf("%s %s\n", string, copia);
    return 0;
}
