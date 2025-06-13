#include <stdio.h>
#include <string.h>
#include "turmas.h"
#include "alunos.h"

void inicializarAlunos(char alunos[][MAX_ALUNOS][TAM_NOME])
{
    for (int i = 0; i < MAX_TURMAS; i++)
    {
        for (int j = 0; j < MAX_ALUNOS; j++)
        {
            alunos[i][j][0] = '\0';
        }
    }
}

void cadastrarAluno(char alunos[][MAX_ALUNOS][TAM_NOME], char turmas[][TAM_NOME])
{
    char nomeTurma[TAM_NOME];
    char nomeAluno[TAM_NOME];

    printf("Digite o nome da turma: ");
    fgets(nomeTurma, TAM_NOME, stdin);
    nomeTurma[strcspn(nomeTurma, "\n")] = '\0';

    int idx = turmaExiste(turmas, nomeTurma);
    if (idx == -1)
    {
        printf("Turma inexistente\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    fgets(nomeAluno, TAM_NOME, stdin);
    nomeAluno[strcspn(nomeAluno, "\n")] = '\0';

    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if (alunos[idx][i][0] == '\0')
        {
            strcpy(alunos[idx][i], nomeAluno);
            printf("Aluno cadastrado com sucesso.\n");
            return;
        }
    }

    printf("Número máximo de alunos atingido para essa turma.\n");
}

void excluirAluno(char alunos[][MAX_ALUNOS][TAM_NOME], char turmas[][TAM_NOME])
{
    char nomeTurma[TAM_NOME];
    char nomeAluno[TAM_NOME];

    printf("Digite o nome da turma: ");
    fgets(nomeTurma, TAM_NOME, stdin);
    nomeTurma[strcspn(nomeTurma, "\n")] = '\0';

    int idx = turmaExiste(turmas, nomeTurma);
    if (idx == -1)
    {
        printf("Turma inexistente\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    fgets(nomeAluno, TAM_NOME, stdin);
    nomeAluno[strcspn(nomeAluno, "\n")] = '\0';

    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if (strcmp(alunos[idx][i], nomeAluno) == 0)
        {
            alunos[idx][i][0] = '\0';
            printf("Aluno excluído com sucesso.\n");
            return;
        }
    }

    printf("Aluno inexistente\n");
}

void exibirAlunos(char alunos[][MAX_ALUNOS][TAM_NOME], char turmas[][TAM_NOME])
{
    char nomeTurma[TAM_NOME];

    printf("Digite o nome da turma: ");
    fgets(nomeTurma, TAM_NOME, stdin);
    nomeTurma[strcspn(nomeTurma, "\n")] = '\0';

    int idx = turmaExiste(turmas, nomeTurma);
    if (idx == -1)
    {
        printf("Turma inexistente\n");
        return;
    }

    printf("Alunos da turma %s:\n", nomeTurma);
    int temAluno = 0;
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if (alunos[idx][i][0] != '\0')
        {
            printf("- %s\n", alunos[idx][i]);
            temAluno = 1;
        }
    }
    if (!temAluno)
    {
        printf("Nenhum aluno matriculado.\n");
    }
}
