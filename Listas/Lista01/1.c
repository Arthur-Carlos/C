#include <stdio.h>

int main(){
    float preco, pagamento;
    scanf("%f %f", &preco, &pagamento);
    if(preco > pagamento){
        printf("falta %.2f \n", preco-pagamento);
    } else if(preco < pagamento){
        printf("troco %.2f \n", pagamento-preco);
    } else{
        printf("valor correto \n");
    }
    return 0;
}