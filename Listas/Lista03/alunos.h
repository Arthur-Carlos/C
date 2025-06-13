#ifndef ALUNOS_H
#define ALUNOS_H

#define MAX_ALUNOS 9
#define TAM_NOME 31

void inicializarAlunos(char alunos[][MAX_ALUNOS][TAM_NOME]);
void cadastrarAluno(char alunos[][MAX_ALUNOS][TAM_NOME], char turmas[][TAM_NOME]);
void excluirAluno(char alunos[][MAX_ALUNOS][TAM_NOME], char turmas[][TAM_NOME]);
void exibirAlunos(char alunos[][MAX_ALUNOS][TAM_NOME], char turmas[][TAM_NOME]);

#endif