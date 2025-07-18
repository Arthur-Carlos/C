#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 1000
#define TAM_LINHA 201

int main()
{
    FILE *arquivoOriginal, *arquivoTemp;
    char *linhas[MAX_LINHAS];
    char buffer[TAM_LINHA];
    int count = 0;

    arquivoOriginal = fopen("arquivo6.txt", "r");
    if (arquivoOriginal == NULL)
    {
        perror("Erro ao abrir arquivo6.txt");
        return 1;
    }

    while (fgets(buffer, TAM_LINHA, arquivoOriginal) != NULL && count < MAX_LINHAS)
    {
        linhas[count] = strdup(buffer);
        count++;
    }
    fclose(arquivoOriginal);

    arquivoTemp = fopen("temp.txt", "w");
    if (arquivoTemp == NULL)
    {
        perror("Erro ao criar temp.txt");
        return 1;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        fputs(linhas[i], arquivoTemp);
        free(linhas[i]);
    }
    fclose(arquivoTemp);

    if (remove("arquivo6.txt") != 0)
    {
        perror("Erro ao remover arquivo6.txt");
        return 1;
    }

    if (rename("temp.txt", "arquivo6.txt") != 0)
    {
        perror("Erro ao renomear temp.txt para arquivo6.txt");
        return 1;
    }

    printf("Arquivo invertido com sucesso.\n");
    return 0;
}
