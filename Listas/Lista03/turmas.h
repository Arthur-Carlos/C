#ifndef TURMAS_H
#define TURMAS_H

#define MAX_TURMAS 3
#define TAM_NOME 31

void inicializarTurmas(char turmas[][TAM_NOME]);
int cadastrarTurma(char turmas[][TAM_NOME]);
int turmaExiste(char turmas[][TAM_NOME], const char *nome);

#endif
