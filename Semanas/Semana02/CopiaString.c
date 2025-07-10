#include <stdio.h>
#define TAM 50

int main()
{
    char string[TAM], copia[TAM];
    printf("s1 = ");
    fgets(string, TAM, stdin);
    for (int i = 0; i < TAM; i++)
    {
        copia[i] = string [i];
        if(string[i] == '\0'){
            break;
        }
    }
    printf("\ns2 = ''\n\n");
    printf("s1 = %s\ns2 = %s", string, copia);
    return 0;
}
