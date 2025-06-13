#include <stdio.h>
#include <string.h>
#include "turmas.h"
#include "alunos.h"

int main()
{
    char turmas[MAX_TURMAS][TAM_NOME];
    char alunos[MAX_TURMAS][MAX_ALUNOS][TAM_NOME];

    inicializarTurmas(turmas);
    inicializarAlunos(alunos);

    int opcao;
    do
    {
        printf("\n1 - Cadastrar Turmas\n2 - Cadastrar Aluno em uma Turma\n3 - Excluir Aluno de uma Turma\n4 - Exibir Alunos de uma Turma\n5 - Sair\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            cadastrarTurma(turmas);
            break;
        case 2:
            cadastrarAluno(alunos, turmas);
            break;
        case 3:
            excluirAluno(alunos, turmas);
            break;
        case 4:
            exibirAlunos(alunos, turmas);
            break;
        case 5:
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
