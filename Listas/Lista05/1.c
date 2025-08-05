#include <stdio.h>

int potencia(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        printf("Erro\n");
        return 0;
    }
    else
    {
        return x * potencia(x, n - 1);
    }
}

int main()
{
    int x, n;
    scanf("%d", &x);
    scanf("%d", &n);
    int resultado = potencia(x, n);

    if (n >= 0)
    {
        printf("%d\n", resultado);
    }

    return 0;
}
