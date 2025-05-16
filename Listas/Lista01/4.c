#include <stdio.h>

int main(){
    int N, X, cria = 0, adol = 0, adul = 0, idos =0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &X);
        if(X < 18){
            if( X < 12){
                cria++;
            }else{
                adol++;
            }
        } else{
            if (X < 60)
            {
                adul++;
            }else{
                idos++;
            }
        }
    }
    printf("Crianças: %d \nAdolescentes: %d \nAdultos: %d \nIdosos:%d \n", cria,adol,adul,idos);
    return 0;
}