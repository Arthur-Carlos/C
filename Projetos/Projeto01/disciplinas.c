#include <stdio.h>
#include <string.h>
#include "disciplinas.h"

void menuDisciplinas(Disciplina disciplinas[], int *total_disciplinas, Pessoa pessoas[], int total_alunos, int total_professores)
{
    int opcao;
    do
    {
        printf("\n--- SISTEMA DE DISCIPLINAS ---\n");
        printf("1 - Cadastrar Disciplina\n");
        printf("2 - Alterar Professor de uma Disciplina\n");
        printf("3 - Adicionar Aluno a uma Disciplina\n");
        printf("4 - Remover Aluno de uma Disciplina\n");
        printf("5 - Exibir Dados de uma Disciplina\n");
        printf("6 - Voltar ao menu principal\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            cadastrarDisciplina(disciplinas, total_disciplinas, pessoas, total_professores);
            break;
        case 2:
            alterarProfessorDisciplina(disciplinas, *total_disciplinas, pessoas, total_professores);
            break;
        case 3:
            adicionarAlunoDisciplina(disciplinas, *total_disciplinas, pessoas, total_alunos);
            break;
        case 4:
            removerAlunoDisciplina(disciplinas, *total_disciplinas);
            break;
        case 5:
            exibirDisciplina(disciplinas, *total_disciplinas);
            break;
        case 6:
            return;
        default:
            printf("\nOpcao invalida.\n");
        }
    } while (opcao != 6);
}

void cadastrarDisciplina(Disciplina disciplinas[], int *total_disciplinas, Pessoa pessoas[], int total_professores)
{
    if (*total_disciplinas >= MAX_DISCIPLINAS)
    {
        printf("\nLimite de disciplinas atingido.\n");
        return;
    }

    Disciplina nova;
    char pis[12];

    printf("Digite os dados (codigo;nome;carga_horaria;PIS): \n");
    scanf(" %[^;];%[^;];%d;%s", nova.codigo, nova.nome, &nova.carga_horaria, pis);

    for (int i = 0; i < *total_disciplinas; i++)
    {
        if (strcmp(disciplinas[i].codigo, nova.codigo) == 0)
        {
            printf("\nDisciplina ja cadastrada.\n");
            return;
        }
    }

    nova.professor = NULL;
    for (int i = 0; i < total_professores; i++)
    {
        if (strcmp(pessoas[MAX_ALUNOS + i].pis, pis) == 0)
        {
            nova.professor = &pessoas[MAX_ALUNOS + i];
            break;
        }
    }

    if (!nova.professor)
    {
        printf("\nProfessor com PIS %s nao encontrado.\n", pis);
        return;
    }

    nova.total_alunos = 0;
    disciplinas[*total_disciplinas] = nova;
    (*total_disciplinas)++;
    printf("\nDisciplina cadastrada com sucesso!\n");
}

void alterarProfessorDisciplina(Disciplina disciplinas[], int total_disciplinas, Pessoa pessoas[], int total_professores)
{
    char codigo[10], pis[12];
    printf("Digite o codigo da disciplina: \n");
    scanf("%s", codigo);

    Disciplina *d = NULL;
    for (int i = 0; i < total_disciplinas; i++)
    {
        if (strcmp(disciplinas[i].codigo, codigo) == 0)
        {
            d = &disciplinas[i];
            break;
        }
    }

    if (!d)
    {
        printf("\nDisciplina nao encontrada.\n");
        return;
    }

    printf("Digite o PIS do novo professor: \n");
    scanf("%s", pis);

    for (int i = 0; i < total_professores; i++)
    {
        if (strcmp(pessoas[MAX_ALUNOS + i].pis, pis) == 0)
        {
            d->professor = &pessoas[MAX_ALUNOS + i];
            printf("\nProfessor atualizado com sucesso.\n");
            return;
        }
    }

    printf("\nProfessor com PIS %s nao encontrado.\n", pis);
}

void adicionarAlunoDisciplina(Disciplina disciplinas[], int total_disciplinas, Pessoa pessoas[], int total_alunos)
{
    char codigo[10];
    int matricula;

    printf("Digite o codigo da disciplina: \n");
    scanf("%s", codigo);
    Disciplina *d = NULL;

    for (int i = 0; i < total_disciplinas; i++)
    {
        if (strcmp(disciplinas[i].codigo, codigo) == 0)
        {
            d = &disciplinas[i];
            break;
        }
    }

    if (!d)
    {
        printf("\nDisciplina nao encontrada.\n");
        return;
    }

    if (d->total_alunos >= MAX_ALUNOS_DISC)
    {
        printf("\nLimite de alunos na disciplina atingido.\n");
        return;
    }

    printf("Digite a matricula do aluno: \n");
    scanf("%d", &matricula);

    for (int i = 0; i < d->total_alunos; i++)
    {
        if (d->alunos[i]->matricula == matricula)
        {
            printf("\nAluno ja matriculado na disciplina.\n");
            return;
        }
    }

    for (int i = 0; i < total_alunos; i++)
    {
        if (pessoas[i].matricula == matricula)
        {
            d->alunos[d->total_alunos] = &pessoas[i];
            d->total_alunos++;
            printf("\nAluno adicionado com sucesso.\n");
            return;
        }
    }

    printf("\nAluno com matricula %d nao encontrado.\n", matricula);
}

void removerAlunoDisciplina(Disciplina disciplinas[], int total_disciplinas)
{
    char codigo[10];
    int matricula;

    printf("Digite o codigo da disciplina: \n");
    scanf("%s", codigo);

    Disciplina *d = NULL;
    for (int i = 0; i < total_disciplinas; i++)
    {
        if (strcmp(disciplinas[i].codigo, codigo) == 0)
        {
            d = &disciplinas[i];
            break;
        }
    }

    if (!d)
    {
        printf("\nDisciplina nao encontrada.\n");
        return;
    }

    printf("Digite a matricula do aluno a remover: \n");
    scanf("%d", &matricula);

    for (int i = 0; i < d->total_alunos; i++)
    {
        if (d->alunos[i]->matricula == matricula)
        {
            for (int j = i; j < d->total_alunos - 1; j++)
            {
                d->alunos[j] = d->alunos[j + 1];
            }
            d->total_alunos--;
            printf("\nAluno removido com sucesso.\n");
            return;
        }
    }

    printf("Aluno com matricula %d nao encontrado na disciplina.\n", matricula);
}

void exibirDisciplina(Disciplina disciplinas[], int total_disciplinas)
{
    char codigo[10];
    printf("Digite o codigo da disciplina: \n");
    scanf("%s", codigo);

    for (int i = 0; i < total_disciplinas; i++)
    {
        if (strcmp(disciplinas[i].codigo, codigo) == 0)
        {
            printf("\nCodigo: %s\n", disciplinas[i].codigo);
            printf("Nome: %s\n", disciplinas[i].nome);
            printf("Carga horaria: %d horas\n", disciplinas[i].carga_horaria);
            printf("Professor: %s %s\n", disciplinas[i].professor->nome, disciplinas[i].professor->sobrenome);
            printf("Alunos:\n");
            for (int j = 0; j < disciplinas[i].total_alunos; j++)
            {
                printf("  %d - %s %s\n", disciplinas[i].alunos[j]->matricula, disciplinas[i].alunos[j]->nome, disciplinas[i].alunos[j]->sobrenome);
            }
            return;
        }
    }

    printf("\nDisciplina nao encontrada.\n");
}
