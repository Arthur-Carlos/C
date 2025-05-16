#include <stdio.h>

int main() {
    int N, i, j ,k = 0;
    scanf("%d", &N);
    for (i = 0; i <= N; i++, k = 0){
        for(j = 0; j < N-i; j++){
            printf(" ");
        }
        for(k = 0; k < 2* i-1; k++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
