#include <stdio.h>

int main(){
    float preço, pagamento;
    scanf("%f %f", &preço, &pagamento);
    if(preço > pagamento){
        printf("falta %.2f \n", preço-pagamento);
    } else if(preço < pagamento){
        printf("troco %.2f \n", pagamento-preço);
    } else{
        printf("valor correto \n");
    }
    return 0;
}