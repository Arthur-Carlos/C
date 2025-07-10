#ifndef PESSOAS_H
#define PESSOAS_H

#include "estruturas.h"

void menuPessoas(Pessoa pessoas[], int *total_alunos, int *total_professores);
void cadastrarPessoa(Pessoa pessoas[], int *total_alunos, int *total_professores);
void exibirPessoa(Pessoa pessoas[], int total_alunos, int total_professores);
void alterarPessoa(Pessoa pessoas[], int total_alunos, int total_professores);
void removerPessoa(Pessoa pessoas[], int *total_alunos, int *total_professores, Disciplina disciplinas[], int total_disciplinas);

#endif
