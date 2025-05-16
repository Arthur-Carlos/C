#include <stdio.h>
#define TAM 10

int main()
{
    int nums[TAM];
    int entrada;
    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &nums[i]);
    }
    entrada = sizeof(nums) / sizeof(nums[0]);

    for (int i = 1; i < entrada; i++)
    {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }

    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
