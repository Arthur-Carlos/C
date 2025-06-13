#include "trigo.h"

double potencia(double base, int expoente)
{
    double resultado = 1;
    for (int i = 0; i < expoente; i++)
    {
        resultado *= base;
    }
    return resultado;
}

double converteGrausParaRadiano(double x)
{
    return x * (PI / 180.0);
}

double fatorial(int n)
{
    double resultado = 1;
    for (int i = 2; i <= n; i++)
    {
        resultado *= i;
    }
    return resultado;
}

double seno(double x)
{
    double termo, soma = 0;
    int n = 0;
    do
    {
        termo = (n % 2 == 0 ? 1 : -1) * (potencia(x, 2 * n + 1)) / fatorial(2 * n + 1);
        soma += termo;
        n++;
    } while (termo > PRECISAO || termo < -PRECISAO);
    return soma;
}

double cosseno(double x)
{
    double termo, soma = 0;
    int n = 0;
    do
    {
        termo = (n % 2 == 0 ? 1 : -1) * (potencia(x, 2 * n)) / fatorial(2 * n);
        soma += termo;
        n++;
    } while (termo > PRECISAO || termo < -PRECISAO);
    return soma;
}

double tangente(double x)
{
    double cos = cosseno(x);
    if (cos == 0)
    {
        printf("Erro: tangente indefinida (divisão por zero).\n");
        return 0;
    }
    return seno(x) / cos;
}
