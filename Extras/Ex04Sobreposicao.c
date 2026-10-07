#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

//A versao multithread e mais rapida pois enquanto uma thread esta bloqueada esperando uma operação de E/S, outra thread pode executar.
//Porem ainda temos o "custo" de criar uma thread, logo devemos sempre avaliar quando sera melhor utilizar um Multithread ou um Sequencial

#define TEMPO_LEITURA 2
#define TEMPO_GRAVACAO 2
#define ITERACOES 500000000LL

double calcular_tempo(struct timespec inicio, struct timespec fim)
{
    return (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
}

void processamento()
{
    volatile unsigned long long resultado = 0;

    for (unsigned long long i = 0; i < ITERACOES; i++)
    {
        resultado += (i % 100);
    }

    printf("Processamento concluido. Resultado: %llu\n", resultado);
}

void leitura()
{
    printf("Leitura iniciada...\n");

    sleep(TEMPO_LEITURA);

    printf("Leitura concluida.\n");
}

void gravacao()
{
    printf("Gravacao iniciada...\n");

    sleep(TEMPO_GRAVACAO);

    printf("Gravacao concluida.\n");
}

void executar_sequencial()
{
    printf("\nSEQUENCIAL\n");
    leitura();
    processamento();
    gravacao();
}

void *thread_leitura(void *arg)
{
    (void)arg;
    leitura();
    return NULL;
}

void *thread_processamento(void *arg)
{
    (void)arg;
    processamento();
    return NULL;
}

void *thread_gravacao(void *arg)
{
    (void)arg;
    gravacao();
    return NULL;
}

void executar_multithread()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;

    printf("\nMULTITHREAD\n");
    if (pthread_create(&thread1, NULL, thread_leitura, NULL) != 0)
    {
        perror("Erro de leitura");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread2, NULL, thread_processamento, NULL) != 0)
    {
        perror("Erro de processamento");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread3, NULL, thread_gravacao, NULL) != 0)
    {
        perror("Erro de gravacao");
        exit(EXIT_FAILURE);
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("Todas as threads terminaram.\n");
}

int main()
{
    struct timespec inicio, fim;

    double tempo_sequencial;
    double tempo_multithread;

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    executar_sequencial();
    clock_gettime(CLOCK_MONOTONIC, &fim);

    tempo_sequencial = calcular_tempo(inicio, fim);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    executar_multithread();
    clock_gettime(CLOCK_MONOTONIC, &fim);

    tempo_multithread = calcular_tempo(inicio, fim);

    printf("\nResultados:\n");
    printf("Tempo sequencial:  %.4f segundos\n", tempo_sequencial);
    printf("Tempo multithread: %.4f segundos\n", tempo_multithread);

    if (tempo_multithread < tempo_sequencial)
    {
        double ganho = ((tempo_sequencial - tempo_multithread) / tempo_sequencial) * 100.0;

        printf("Ganho aproximado: %.2f%%\n", ganho);
    }
    else if (tempo_multithread > tempo_sequencial)
    {
        double perda = ((tempo_multithread - tempo_sequencial) / tempo_sequencial) * 100.0;

        printf("Custo adicional: %.2f%%\n", perda);
    }
    else
    {
        printf("Os tempos foram praticamente iguais.\n");
    }

    return 0;
}