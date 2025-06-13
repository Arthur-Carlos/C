#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removerVogais(char *original, char *semVogais)
{
    int i;
    for (i = 0; original[i] != '\0'; i++)
    {
        char c = tolower(original[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            semVogais[i] = ' ';
        }
        else
        {
            semVogais[i] = original[i];
        }
    }
    semVogais[i] = '\0';
}

int main()
{
    char entrada[51], entrada_semVogais[51];

    fgets(entrada, sizeof(entrada), stdin);
    size_t len = strlen(entrada);

    if (len > 0 && entrada[len - 1] == '\n')
    {
        entrada[len - 1] = '\0';
    }

    removerVogais(entrada, entrada_semVogais);

    printf("\n%s\n", entrada_semVogais);
    printf("\n%s\n", entrada);

    return 0;
}
