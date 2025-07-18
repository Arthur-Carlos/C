#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 100

void escrever_no_arquivo(const char *mensagem, const char *executavel)
{
    FILE *arquivo = fopen("conversa.txt", "a");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    char comando[256];
    snprintf(comando, sizeof(comando), "%s: %s\n", executavel, mensagem);

    if (fwrite(comando, sizeof(char), strlen(comando), arquivo) != strlen(comando))
    {
        perror("Erro ao escrever no arquivo");
        fclose(arquivo);
        exit(1);
    }

    fclose(arquivo);
}

int verificar_ultima_mensagem(const char *executavel)
{
    FILE *arquivo = fopen("conversa.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    char linha[256];
    char ultima_mensagem[256];
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        strcpy(ultima_mensagem, linha);
    }

    fclose(arquivo);

    if (strlen(ultima_mensagem) > 0)
    {
        char nome_exec[256];
        sscanf(ultima_mensagem, "%255[^:]", nome_exec);

        if (strcmp(nome_exec, executavel) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Uso: %s <mensagem>\n", argv[0]);
        return 1;
    }

    if (verificar_ultima_mensagem(argv[0]) == 1)
    {
        fprintf(stderr, "Espere o seu amigo responder sua última mensagem!!\n");
        return 1;
    }

    escrever_no_arquivo(argv[1], argv[0]);

    return 0;
}
