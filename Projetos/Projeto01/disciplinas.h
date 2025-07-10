#ifndef DISCIPLINAS_H
#define DISCIPLINAS_H

#include "estruturas.h"

void menuDisciplinas(Disciplina disciplinas[], int *total_disciplinas, Pessoa pessoas[], int total_alunos, int total_professores);
void cadastrarDisciplina(Disciplina disciplinas[], int *total_disciplinas, Pessoa pessoas[], int total_professores);
void alterarProfessorDisciplina(Disciplina disciplinas[], int total_disciplinas, Pessoa pessoas[], int total_professores);
void adicionarAlunoDisciplina(Disciplina disciplinas[], int total_disciplinas, Pessoa pessoas[], int total_alunos);
void removerAlunoDisciplina(Disciplina disciplinas[], int total_disciplinas);
void exibirDisciplina(Disciplina disciplinas[], int total_disciplinas);

#endif
