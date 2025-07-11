#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *entrada, *saida;
    char nome[100];
    int idade;
    float nota;

    entrada = fopen("arquivo1.txt", "r");
    if (entrada == NULL)
    {
        perror("Erro ao abrir arquivo1.txt");
        return 1;
    }

    saida = fopen("arquivo2.txt", "w");
    if (saida == NULL)
    {
        perror("Erro ao criar arquivo2.txt");
        fclose(entrada);
        return 1;
    }

    while (fscanf(entrada, "%s\t%d\t%f", nome, &idade, &nota) == 3)
    {
        if (idade >= 18 && nota > 6.0)
        {
            fprintf(saida, "%s\t%d\t%.2f\n", nome, idade, nota);
        }
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}
