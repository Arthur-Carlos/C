#include <stdio.h>
#include <string.h>
#include "turmas.h"

void inicializarTurmas(char turmas[][TAM_NOME])
{
    for (int i = 0; i < MAX_TURMAS; i++)
    {
        turmas[i][0] = '\0';
    }
}

int cadastrarTurma(char turmas[][TAM_NOME])
{
    for (int i = 0; i < MAX_TURMAS; i++)
    {
        if (turmas[i][0] == '\0')
        {
            printf("Digite o nome da turma: ");
            fgets(turmas[i], TAM_NOME, stdin);
            turmas[i][strcspn(turmas[i], "\n")] = '\0';
            return 1;
        }
    }
    printf("Máximo de turmas já cadastradas\n");
    return 0;
}

int turmaExiste(char turmas[][TAM_NOME], const char *nome)
{
    for (int i = 0; i < MAX_TURMAS; i++)
    {
        if (strcmp(turmas[i], nome) == 0)
        {
            return i;
        }
    }
    return -1;
}
