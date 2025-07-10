#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pessoas.h"

static int contador_matriculas = 0;

int validarCPF(const char *cpf)
{
    if (strlen(cpf) != 11)
        return 0;
    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(cpf[i]))
            return 0;
    }
    return 1;
}

int validarCEP(const char *cep)
{
    if (strlen(cep) != 8)
        return 0;
    for (int i = 0; i < 8; i++)
    {
        if (!isdigit(cep[i]))
            return 0;
    }
    return 1;
}

int validarPIS(const char *pis)
{
    if (strlen(pis) != 11)
        return 0;
    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(pis[i]))
            return 0;
    }
    return 1;
}

void menuPessoas(Pessoa pessoas[], int *total_alunos, int *total_professores)
{
    int opcao;
    do
    {
        printf("\n--- SISTEMA DE PESSOAS ---\n");
        printf("1 - Cadastrar Pessoa\n");
        printf("2 - Exibir Dados de uma Pessoa\n");
        printf("3 - Alterar Dados de Pessoa\n");
        printf("4 - Remover Pessoa\n");
        printf("5 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            cadastrarPessoa(pessoas, total_alunos, total_professores);
            break;
        case 2:
            exibirPessoa(pessoas, *total_alunos, *total_professores);
            break;
        case 3:
            alterarPessoa(pessoas, *total_alunos, *total_professores);
            break;
        case 4:
            printf("\nRemocao exige acesso as disciplinas.\n");
            break;
        case 5:
            return;
        default:
            printf("\nOpcao inválida.\n");
        }
    } while (opcao != 5);
}

void cadastrarPessoa(Pessoa pessoas[], int *total_alunos, int *total_professores)
{
    char entrada[300];
    printf("Digite os dados da pessoa (formato especificado):\n");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0;

    Pessoa nova;
    char *token = strtok(entrada, ";");
    strcpy(nova.nome, token);

    token = strtok(NULL, ";");
    strcpy(nova.sobrenome, token);

    token = strtok(NULL, ";");
    nova.brasileiro = atoi(token);

    if (nova.brasileiro == 0)
    {
        token = strtok(NULL, ";");
        if (!validarCPF(token))
        {
            printf("\nCPF inválido.\n");
            return;
        }
        strcpy(nova.br.cpf, token);

        token = strtok(NULL, ";");
        strcpy(nova.br.estado, token);
    }
    else
    {
        token = strtok(NULL, ";");
        strcpy(nova.est.passaporte, token);

        token = strtok(NULL, ";");
        strcpy(nova.est.pais_origem, token);
    }

    token = strtok(NULL, "/");
    nova.nascimento.dia = atoi(token);
    token = strtok(NULL, "/");
    nova.nascimento.mes = atoi(token);
    token = strtok(NULL, ";");
    nova.nascimento.ano = atoi(token);

    token = strtok(NULL, ";");
    nova.pcd = atoi(token);

    if (nova.pcd)
    {
        token = strtok(NULL, ";");
        strncpy(nova.laudo, token, 10);
    }
    else
    {
        nova.laudo[0] = '\0';
    }

    token = strtok(NULL, ";");
    if (!validarCEP(token))
    {
        printf("\nCEP inválido.\n");
        return;
    }
    strcpy(nova.cep, token);

    token = strtok(NULL, ";");
    nova.tipo = atoi(token);

    if (nova.tipo == 0)
    { // Aluno
        if (*total_alunos >= MAX_ALUNOS)
        {
            printf("\nLimite de alunos atingido.\n");
            return;
        }
        int ano = nova.nascimento.ano % 100;
        nova.matricula = ano * 1000 + contador_matriculas;
        contador_matriculas++;
        pessoas[*total_alunos] = nova;
        (*total_alunos)++;
        printf("\nAluno cadastrado com matricula %d\n", nova.matricula);
    }
    else
    { // Professor
        token = strtok(NULL, ";");
        if (!validarPIS(token))
        {
            printf("\nPIS inválido.\n");
            return;
        }
        strcpy(nova.pis, token);

        if (*total_professores >= MAX_PROFESSORES)
        {
            printf("\nLimite de professores atingido.\n");
            return;
        }
        pessoas[MAX_ALUNOS + (*total_professores)] = nova;
        (*total_professores)++;
        printf("\nProfessor cadastrado com sucesso.\n");
    }
}

void exibirPessoa(Pessoa pessoas[], int total_alunos, int total_professores)
{
    int tipo;
    printf("A pessoa e: 0 - Aluno, 1 - Professor? ");
    scanf("%d", &tipo);

    if (tipo == 0)
    {
        int matricula;
        printf("Digite a matricula: ");
        scanf("%d", &matricula);
        for (int i = 0; i < total_alunos; i++)
        {
            if (pessoas[i].matricula == matricula)
            {
                printf("\nNome: %s %s\n", pessoas[i].nome, pessoas[i].sobrenome);
                return;
            }
        }
    }
    else
    {
        char pis[12];
        printf("Digite o PIS: ");
        scanf("%s", pis);
        for (int i = 0; i < total_professores; i++)
        {
            if (strcmp(pessoas[MAX_ALUNOS + i].pis, pis) == 0)
            {
                printf("\nNome: %s %s\n", pessoas[MAX_ALUNOS + i].nome, pessoas[MAX_ALUNOS + i].sobrenome);
                return;
            }
        }
    }

    printf("\nPessoa nao encontrada.\n");
}

void alterarPessoa(Pessoa pessoas[], int total_alunos, int total_professores)
{
    int tipo;
    printf("Digite '0' caso seja Aluno ou '1' caso seja Professor: ");
    scanf("%d", &tipo);

    Pessoa *p = NULL;
    if (tipo == 0)
    {
        int matricula;
        printf("Digite a matricula: ");
        scanf("%d", &matricula);
        for (int i = 0; i < total_alunos; i++)
        {
            if (pessoas[i].matricula == matricula)
            {
                p = &pessoas[i];
                break;
            }
        }
    }
    else
    {
        char pis[12];
        printf("Digite o PIS: ");
        scanf("%s", pis);
        for (int i = 0; i < total_professores; i++)
        {
            if (strcmp(pessoas[MAX_ALUNOS + i].pis, pis) == 0)
            {
                p = &pessoas[MAX_ALUNOS + i];
                break;
            }
        }
    }

    if (!p)
    {
        printf("\nPessoa nao encontrada.\n");
        return;
    }

    int opcao;
    printf("1 - Alterar PcD\n2 - Alterar Codigo do Laudo\n3 - Alterar CEP\n");
    scanf("%d", &opcao);
    getchar();

    switch (opcao)
    {
    case 1:
        printf("Nova situacao PcD (0 - Nao, 1 - Sim): ");
        scanf("%d", &p->pcd);
        break;
    case 2:
        printf("Novo codigo do laudo (ate 10 chars): ");
        fgets(p->laudo, 11, stdin);
        p->laudo[strcspn(p->laudo, "\n")] = 0;
        break;
    case 3:
        printf("Novo CEP: ");
        scanf("%s", p->cep);
        break;
    default:
        printf("\nOpcao inválida.\n");
    }

    printf("\nDados atualizados.\n");
}