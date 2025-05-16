#include <stdio.h>
#define TAM 50

int main()
{
    char string[TAM];
    int entrada = -1;
    fgets(string, TAM, stdin);
    for (int i = 0; i < TAM; i++)
    {
        if(string[i] == '\0'){
            break;
        }
        entrada++;
    }
    printf("\n");
    printf("%d", entrada);
    printf("\n");
    return 0;
}
