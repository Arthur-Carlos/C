#include <stdio.h>

void fib(int n, int anterior1, int anterior2) {
    if (n < 3) {
        return;
    }
    
    int atual = anterior1 + anterior2;
    printf("%d ", atual);
  
    return fib(n - 1, anterior2, atual);
}

void printFib(int n) {
    if (n <= 0) {
        printf("0");
    }
    else if (n == 1) {
        printf("%d ", 0);
    }
    else if (n == 2) {
        printf("%d %d", 0, 1);
    }
    else {
        printf("%d %d ", 0, 1);
        fib(n, 0, 1);
    }
    return;
}


int main() {
    int n;
    scanf("%d", &n);
    printFib(n);
    printf("\n");
    return 0;
}