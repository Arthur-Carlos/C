#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//como o "contador_global" foi declarado fora da "funcao_threads" ele possui um espaço reservado em memória, e sempre que ele é solicitado
//pelas Threads, elas retornam a este espaço, enquanto o "contador_local" é declarado dentro da própria função e alterado conforme ela é executada.
//Na parte de "Resultados" vemos que existe uma diferença entre o esperado e o obtido, isso se dá pois não existe sincronização entre as threads, ou seja
// o que é executado em uma, pode ser sobreescrito por outra que esteja executando o mesmo processo enquanto o incremento acaba sendo "gasto".

#define NUM_THREADS 4
#define INCREMENTO 100000

int contador_global = 0;

void *funcao_threads(void *arg)
{
    int id = *(int *)arg;
    int contador_local = 0;
    for (int i = 0; i < INCREMENTO; i++)
    {
        contador_global++;
        contador_local++;
    }
    printf("Thread %d:\n", id);
    printf("    &contador_global = %p\n", (void *)&contador_global);
    printf("    &contador_local  = %p\n", (void *)&contador_local);
    printf("    contador_local   = %d\n\n", contador_local);
    return NULL;

    return NULL;
}

int main()
{
    pthread_t trheads[NUM_THREADS];
    int ids[NUM_THREADS];
    printf("\nEndereco atual da variavel global antes das threads:\n");
    printf("    &contador_global = %p\n\n", (void *)&contador_global);
    for (int i = 0; i < NUM_THREADS; i++)
    {
        ids[i] = i;
        int resultado = pthread_create(&trheads[i], NULL, funcao_threads, &ids[i]);
        if (resultado != 0)
        {
            fprintf(stderr, "ERRO! Thread %d.\n", i);
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < NUM_THREADS; i++)
    {
        if (pthread_join(trheads[i], NULL) != 0)
        {
            fprintf(stderr, "ERRO! Thread %d.\n", i);
            return EXIT_FAILURE;
        }
    }
    int valor = NUM_THREADS * INCREMENTO;
    printf("\nResultados:\n");
    printf("    valor esperado : %d\n", valor);
    printf("    valor obtido   : %d\n", contador_global);
}