#include "trigo.h"

int main()
{
    int opcao = 0;
    double x, rad;

    do
    {
        printf("1 - Converter Graus para Radianos\n2 - Cosseno.\n3 - Seno\n4 - Tangente\n5 - Sair\n");
        scanf("%d", &opcao);
        if (opcao >= 1 && opcao <= 4)
        {
            printf("Digite o valor de X em graus: ");
            scanf("%lf", &x);
            rad = converteGrausParaRadiano(x);
        }

        switch (opcao)
        {
        case 1:
            printf("\nResultado: %.6lf radianos\n", rad);
            break;
        case 2:
            printf("\nCosseno(%.2lf graus) = %.6lf\n", x, cosseno(rad));
            break;
        case 3:
            printf("\nSeno(%.2lf graus) = %.6lf\n", x, seno(rad));
            break;
        case 4:
            tangente(rad);
            break;
        case 5:
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}