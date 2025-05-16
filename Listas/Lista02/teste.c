#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char mat[3][5];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("linha %d, coluna %d: \n", i+1, j+1);
            scanf("%c", &mat[i][j]);
            getchar();
        }
    }

    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
