#include <stdio.h>

int main(){
    int X, Y;
    scanf("%d %d", &X, &Y);
    if (X < Y)
    {
        for(int i = X; i <= Y; i++){
            if(i % 2 == 0){
                printf("%d ", i);
            }
        }
    } else if (X > Y)
    {
        for(int i = Y; i <= X; i++){
            if(i % 2 == 0){
                printf("%d ", i);
            }
        }
    }
    else if (X% 2 == 0)
    {
        printf("%d", X);
    }
    printf("\n");
    return 0;
}