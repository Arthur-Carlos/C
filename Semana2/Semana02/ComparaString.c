#include <stdio.h>
#define TAM 50

int main()
{
    char string[TAM], copia[TAM];
    int contador = 0;
    scanf("%[^\n]s", string);
    getchar();
    scanf("%[^\n]s", copia);
    printf("\n");
    for (int i = 0; i < TAM; i++)
    {

        if (copia[i] != string[i])
        {
            contador++;
            break;
        }
    }

    if (contador == 0)
    {
        printf("Iguais. \n");
    }
    else
    {
        printf("Diferentes. \n");
    }
    return 0;
}
