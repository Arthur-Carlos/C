#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

int main()
{
    char string[TAM], copia[TAM];
    int i = 0;
    printf("Bem vindo, digite:\n1 para inserir uma string e saber seu tamanho;\n2 para inserir duas strings e comparalas;\n3 para inserir uma string e copia-la em outra string;\n4 para inserir duas strings e concatena-las;\n5 para inserir uma string de numeros e receber ela em inteiros;\n'9' para sair do programa.\n");
    do
    {
        scanf("%d", &i);
        getchar();
        switch (i)
        {
        case 1:
            printf("Digite sua String: ");
            scanf("%[^\n]s", string);
            int tamanho = strlen(string);
            printf("Tamanho da sua String: %d\n", tamanho);
            printf("\nDigite a próxima entrada: ");
            break;

        case 2:
            printf("Digite sua primeira String: ");
            scanf("%[^\n]s", string);
            getchar();
            printf("\nDigite a próxima entrada: ");
            scanf("%[^\n]s", copia);
            int teste = strcmp(string, copia);
            if (teste == 0)
            {
                printf("Iguais.");
            }
            else
            {
                printf("Diferentes");
            }
            printf("\n");
            printf("\nDigite a próxima entrada: ");
            break;

        case 3:
            printf("Digite sua String a ser copiada: ");
            scanf("%[^\n]s", string);
            strcpy(copia, string);
            printf("Copia :%s\n", copia);
            printf("\nDigite a próxima entrada: ");
            break;

        case 4:
            printf("Digite a primeira parte da String: ");
            scanf("%[^\n]s", string);
            getchar();
            printf("Digite a segunda parte da String: ");
            scanf("%[^\n]s", copia);
            strcat(string, copia);
            printf("%s\n", string);
            printf("\nDigite a próxima entrada: ");
            break;

        case 5:
            printf("Digite sua String em numeros: ");
            scanf("%[^\n]s", string);
            teste = atoi(string);
            printf("%d\n", teste);
            printf("\nDigite a próxima entrada: ");
            break;

        default:
            break;
        }
    } while (i != 9);
    return 0;
}
