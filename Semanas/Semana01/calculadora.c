#include <stdio.h>

int main(){
    float n1, n2;
    char op;
    scanf("%f", &n1);
    do{
        getchar();
        scanf("%c", &op);
        switch (op)
        {
        case '+':
            scanf("%f", &n2);
            n1 = n1 + n2;
            break;
        
        case '-':
            scanf("%f", &n2);
            n1 = n1 - n2;
            break;
    
        case '*':
            scanf("%f", &n2);
            n1 = n1 * n2;
            break;
    
        case '/':
            scanf("%f", &n2);
            n1 = n1 / n2;
            break;
    
        case '=':
            printf("%f", n1);
            return 0;
            break;

        default:
            break;
        }
    }while (op != '=');
    printf("%f", n1);
    return 0;
}