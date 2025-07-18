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

void salvar_registro(const char *nome_arquivo, Pessoa *pessoa)
{
    FILE *file = fopen(nome_arquivo, "ab");
    if (file == NULL)
    {
        perror("Erro");
        return;
    }
    size_t escrito = fwrite(pessoa, sizeof(Pessoa), 1, file);
    if (escrito != 1)
    {
        perror("Erro");
    }

    fclose(file);
}

int main()
{
    Pessoa pessoa;
    printf("Nome: ");
    fgets(pessoa.nome, MAX_NOME_LENGTH, stdin);
    pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &pessoa.idade);

    printf("CPF: ");
    scanf("%s", pessoa.cpf);

    salvar_registro("log.bin", &pessoa);

    printf("Registro salvo com sucesso!\n");

    return 0;
}
