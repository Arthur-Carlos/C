#include <stdio.h>
#include <math.h>
#include <string.h>
#define TAM 101

void inverter(char frase[], int ini, int fim)
{
    while (ini < fim)
    {
        char temp = frase[ini];
        frase[ini] = frase[fim];
        frase[fim] = temp;
        ini++;
        fim--;
    }
}

int main()
{
    char string[TAM];
    int i = 0, j = 0;
    fgets(string, TAM, stdin);
    string[strcspn(string, "\n")] = '\0';
    do
    {
        if (string[i] == ' ')
        {
            inverter(string, j, i - 1);
            j = i + 1;
        }
        i++;
    } while (string[i] != '\0');

    inverter(string, j, i - 1);

    printf("%s\n", string);
    return 0;
}
