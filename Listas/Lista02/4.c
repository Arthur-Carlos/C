#include <stdio.h>
#include <math.h>
#include <string.h>
#define TAM 501

int main()
{
    char string[TAM];
    int i = 0, j = 0;
    fgets(string, TAM, stdin);
    do
    {
        if (string[i] == '.' && string[i+1] == ' ')
        {
            string[i + 1] = '\n'; // estou assumindo que após todo ponto terá um espaço em branco.
        }
        i++;
    } while (string[i+1] != '\0');
    printf("%s\n", string);
    return 0;
}
