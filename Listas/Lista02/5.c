#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome[5][61];
    int valor[5];
    int i;

    for (i = 0; i < 5; i++)
    {
        scanf("%s", nome[i]);
        scanf("%d", &valor[i]);
    }

    printf("\n");

    for (int pos = 1; pos <= 5; pos++)
    {
        for (i = 0; i < 5; i++)
        {
            if (valor[i] == pos)
            {
                switch (pos)
                {
                case 1:
                case 2:
                    printf("%s armador\n", nome[i]);
                    break;
                case 3:
                case 4:
                    printf("%s ala\n", nome[i]);
                    break;
                case 5:
                    printf("%s pivô\n", nome[i]);
                    break;
                default:
                    break;
                }
            }
        }
    }

    printf("\n");
    return 0;
}
