#include <stdio.h>
#define TAM 10

int main()
{
    int nums[TAM];
    int entrada;
    char op;
    printf("Bem vindo, digite 'a' para inserir um vetor ou 'd' para sair do programa. \n");
    do
    {
        scanf("%c", &op);
        switch (op)
        {
        case 'a':
            printf("Digite ate 10 numeros:\n");
            for (int i = 0; i < TAM; i++)
            {
                scanf("%d", &nums[i]);
            }
            printf("\n");
            printf("Digite:\n 'a'- para sobrescrever o vetor;\n 'b'- para zerar um elemento do vetor; \n 'c'- para imprimir o vetor; \n 'd'- para sair do programa; \n");
            break;

        case 'b':
            printf("digite o numero a ser removido de seu vetor:\n");
            scanf("%d", &entrada);
            for (int i = 0; i < TAM; i++)
            {
                if (nums[i] == entrada)
                {
                    nums[i] = 0;
                }
            }
            printf("\n");
            printf("Digite:\n 'a'- para sobrescrever o vetor;\n 'b'- para zerar um elemento do vetor; \n 'c'- para imprimir o vetor; \n 'd'- para sair do programa; \n");
            break;

        case 'c':
            for (int i = 0; i < TAM; i++)
            {
                printf("%d ", nums[i]);
            }
            printf("\n \n");
            printf("Digite:\n 'a'- para sobrescrever o vetor;\n 'b'- para zerar um elemento do vetor; \n 'c'- para imprimir o vetor; \n 'd'- para sair do programa; \n");
            break;
        default:
            break;
        }
    } while (op != 'd');
    return 0;
}
