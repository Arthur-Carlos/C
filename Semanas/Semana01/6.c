#include <stdio.h>

int main() {
    float N, X, Y, contador = 1, valor = 1;
    scanf("%f", &N);
    do
    {
        valor = contador * contador * contador;
        printf("%0.f %.0f\n", valor, contador);
        contador++;
    }    while (valor < N);
    X = valor;
    Y = (contador-2) * (contador-2) * (contador-2);
    if(valor == N){
        printf("%.0f\n", contador-1);
    } else if((N-Y)<(X-N)){
        printf("%.0f\n", contador-2);
    } else{
        printf("%.0f\n", contador-1);
    }

    return 0;
}
