#include <stdio.h>
#include <math.h>
#define TAM 10

int main()
{
    double nums[TAM], contador = 0, media, diferenca = 0, raiz;
    for (int i = 0; i < TAM; i++)
    {
        scanf("%lf", &nums[i]);
        contador = contador + nums[i];
    }
    media = contador / TAM;
    for (int i = 0; i < TAM; i++)
    {
        diferenca = diferenca + pow((nums[i] - media), 2);
    }
    raiz = sqrt(diferenca / TAM);
    printf("%lf \n", raiz);
    return 0;
}
