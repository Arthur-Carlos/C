#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_LENGTH 200
#define MAX_CPF_LENGTH 14

typedef struct
{
    char nome[MAX_NOME_LENGTH];
    int idade;
    char cpf[MAX_CPF_LENGTH];
} Pessoa;

int main()
{
    FILE *file_ptr = fopen("log.bin", "rb");
    if (file_ptr == NULL)
    {
        perror("Erro");
        return 1;
    }

    Pessoa pessoa;

    while (fread(&pessoa, sizeof(pessoa), 1, file_ptr) == 1)
    {
        printf("Nome: %s\nIdade: %d\nCPF:%s\n", pessoa.nome, pessoa.idade, pessoa.cpf);
    }

    fclose(file_ptr);
    return 0;
}
