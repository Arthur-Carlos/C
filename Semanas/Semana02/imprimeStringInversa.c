#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
#define NOME 50

int main()
{
    char aluno[TAM][NOME], copia[TAM][NOME];
    int i;
    for (i = 0; i < TAM; i++)
    {
        scanf("%[^\n]s", aluno[i]);
        getchar();
    }

    for (i = TAM; i >= 0; i--)
    {
        printf("%s\n", aluno[i]);
    }

    return 0;
}
