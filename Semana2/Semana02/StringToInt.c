#include <stdio.h>
#include <stdlib.h>
#define TAM 50
//não consegui sem a função da STDLIB.h
int main()
{
    char string[TAM];
    int teste;
    scanf("%[^\n]s", string);
    teste = atoi(string);
    printf("%d\n", teste);
    return 0;
}
