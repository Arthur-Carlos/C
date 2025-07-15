#include <stdio.h>
#include "pessoas.h"
#include "disciplinas.h"

int main()
{
    Pessoa pessoas[MAX_ALUNOS + MAX_PROFESSORES];
    Disciplina disciplinas[MAX_DISCIPLINAS];
    int total_alunos = 0, total_professores = 0, total_disciplinas = 0;

    int opcao;
    do
    {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Sistema de Pessoas\n");
        printf("2 - Sistema de Disciplinas\n");
        printf("3 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            menuPessoas(pessoas, &total_alunos, &total_professores);
            break;
        case 2:
            menuDisciplinas(disciplinas, &total_disciplinas, pessoas, total_alunos, total_professores);
            break;
        case 3:
            printf("\nEncerrando o sistema...\n");
            break;
        default:
            printf("\nOpcao invalida.\n");
        }

    } while (opcao != 3);

    return 0;
}
