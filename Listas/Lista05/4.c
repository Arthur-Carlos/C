#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int vetor[], int inicio, int fim, int x)
{
    if (inicio > fim)
    {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == x)
    {
        return meio;
    }
    else if (x < vetor[meio])
    {
        return buscaBinaria(vetor, inicio, meio - 1, x);
    }
    else
    {
        return buscaBinaria(vetor, meio + 1, fim, x);
    }
}

int main()
{
    FILE *arquivo = fopen("numeros.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int vetor[1000];
    int n = 0;

    while (fscanf(arquivo, "%d", &vetor[n]) == 1)
    {
        n++;
    }

    fclose(arquivo);

    int x;
    printf("Digite o numero a ser buscado: ");
    scanf("%d", &x);

    int posicao = buscaBinaria(vetor, 0, n - 1, x);

    if (posicao != -1)
    {
        printf("Numero encontrado na posicao: %d\n", posicao + 1);
    }
    else
    {
        printf("Numero %d nao encontrado no arquivo.\n", x);
    }
    return 0;
}
