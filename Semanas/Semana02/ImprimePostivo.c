#include <stdio.h>
#define TAM 10

int main()
{
    int nums[TAM];
    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &nums[i]);
    }
    printf("Valores positivos: \n");
    for (int i = 0; i < TAM; i++)
    {
        if (nums[i] > 0)
        {
            printf("%d ", nums[i]);
        }
    }
    printf("\n");
    return 0;
}
