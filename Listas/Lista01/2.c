#include <stdio.h>

int main(){
    float N, valor, total;
    total = 0;
    scanf("%f", &N);
    for(int i = 0; i < N; i++){
        scanf("%f", &valor);
        total = total + valor;
    };
    total = total / N;
    printf("%.2f\n", total);
    return 0;
}