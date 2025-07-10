#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define MAX_ALUNOS 50
#define MAX_PROFESSORES 5
#define MAX_DISCIPLINAS 5
#define MAX_ALUNOS_DISC 10

typedef struct
{
    int dia, mes, ano;
} Data;

typedef struct
{
    char nome[50];
    char sobrenome[50];
    int brasileiro;

    union
    {
        struct
        {
            char cpf[12];
            char estado[3];
        } br;

        struct
        {
            char passaporte[20];
            char pais_origem[30];
        } est;
    };

    Data nascimento;
    int pcd;
    char laudo[11];
    char cep[9];
    int tipo; // 0 - aluno, 1 - professor

    union
    {
        int matricula;
        char pis[12];
    };

} Pessoa;

typedef struct
{
    char codigo[10];
    char nome[50];
    int carga_horaria;
    Pessoa *professor;
    Pessoa *alunos[MAX_ALUNOS_DISC];
    int total_alunos;
} Disciplina;

#endif
