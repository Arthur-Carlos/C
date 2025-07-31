#include <stdio.h>
#include <stdlib.h>

void merge(int vetor[], int inicio, int meio, int fim)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *esquerda = (int *)malloc(n1 * sizeof(int));
    int *direita = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        esquerda[i] = vetor[inicio + i];
    for (int j = 0; j < n2; j++)
        direita[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2)
    {
        if (esquerda[i] <= direita[j])
        {
            vetor[k] = esquerda[i];
            i++;
        }
        else
        {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    free(esquerda);
    free(direita);
}

void mergeSort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

int main()
{
    int entrada;

    printf("Digite o tamanho da entrada:\n");
    scanf("%d", &entrada);

    int vetor[entrada];
    printf("Digite os %d elementos do vetor:\n", entrada);
    for (int i = 0; i < entrada; i++)
    {
        scanf("%d", &vetor[i]);
    }

    mergeSort(vetor, 0, entrada - 1);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < entrada; i++)
    {
        printf("%d", vetor[i]);
        if (i < entrada - 1)
            printf(", ");
    }
    printf("\n");

    return 0;
}
