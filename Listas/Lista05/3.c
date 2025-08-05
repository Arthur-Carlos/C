#include <stdio.h>
#include <ctype.h>
#include <string.h>

void minuscula(char *original, char *tratada)
{
    int j = 0;
    for (int i = 0; original[i] != '\0'; i++)
    {
        if (original[i] != ' ')
        {
            tratada[j++] = tolower(original[i]);
        }
    }
    tratada[j] = '\0';
}

int palindromo(char *str, int inicio, int fim)
{
    if (inicio >= fim)
    {
        return 1;
    }
    if (str[inicio] != str[fim])
    {
        return 0;
    }
    return palindromo(str, inicio + 1, fim - 1);
}

int main()
{
    char entrada[101];
    char tratada[101];
    fgets(entrada, sizeof(entrada), stdin);

    entrada[strcspn(entrada, "\n")] = '\0';

    minuscula(entrada, tratada);

    int tamanho = strlen(tratada);
    if (palindromo(tratada, 0, tamanho - 1))
    {
        printf("Palindromo\n");
    }
    else
    {
        printf("Nao Palindromo\n");
    }

    return 0;
}
