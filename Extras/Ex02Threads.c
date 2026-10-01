#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//tudo funcionando adequadamente

void *funcao_threads(void *arg)
{
    int id = *(int *)arg;
    printf("Thread %d:\n     Iniciada.\n", id);
    printf("     pthread_self(): %lu\n", (unsigned long)pthread_self());
    printf("     Terminada.\n\n");
    return NULL;
}

int main()
{
    int N;
    do
    {
        printf("Digite o numero N de threads:\n");
        scanf("%d", &N);
        if (N <= 0)
        {
            printf("Digite um N maior que 0.\n");
        }

    } while (N <= 0);
    pthread_t *threads = malloc(N * sizeof(pthread_t));
    int *ids = malloc(N * sizeof(int));

    if (threads == NULL || ids == NULL)
    {
        printf("ERRO!\n");
        free(threads);
        free(ids);
    }
    for (int i = 0; i < N; i++)
    {
        ids[i] = i;
        int resultado = pthread_create(&threads[i], NULL, funcao_threads, &ids[i]);
        if (resultado != 0)
        {
            printf("ERRO! Thread numero: %d.\n", i);
            for (int j = 0; j < i; j++)
            {
                pthread_join(threads[j], NULL);
            }
            free(threads);
            free(ids);
        }
    }
    for (int i = 0; i < N; i++)
    {
        pthread_join(threads[i], NULL);
    }
    printf("Thread principal finalizada.\n");
    free(threads);
    free(ids);
}