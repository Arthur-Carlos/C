#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQ_LENGTH 1000
#define MAX_ID_LENGTH 200

float calcular_conteudo_gc(const char *sequencia)
{
    int count_gc = 0;
    int total = 0;

    for (int i = 0; sequencia[i] != '\0'; i++)
    {
        if (sequencia[i] == 'G' || sequencia[i] == 'C')
        {
            count_gc++;
        }
        total++;
    }

    return ((float)count_gc / total) * 100;
}

int main()
{
    FILE *file;
    char linha[1024];
    char id[MAX_ID_LENGTH];
    char sequencia[MAX_SEQ_LENGTH] = "";
    file = fopen("arquivo2.fasta", "r");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    while (fgets(linha, sizeof(linha), file) != NULL)
    {
        linha[strcspn(linha, "\n")] = '\0';
        if (linha[0] == '>')
        {
            if (strlen(sequencia) > 0)
            {
                float gc_content = calcular_conteudo_gc(sequencia);
                printf("ID: %s, Conteúdo GC: %.2f%%\n", id, gc_content);
                memset(sequencia, 0, sizeof(sequencia));
            }

            strncpy(id, linha + 1, MAX_ID_LENGTH - 1);
        }
        else
        {
            strncat(sequencia, linha, MAX_SEQ_LENGTH - strlen(sequencia) - 1);
        }
    }

    if (strlen(sequencia) > 0)
    {
        float gc_content = calcular_conteudo_gc(sequencia);
        printf("ID: %s, Conteúdo GC: %.2f%%\n", id, gc_content);
    }

    fclose(file);

    return 0;
}
