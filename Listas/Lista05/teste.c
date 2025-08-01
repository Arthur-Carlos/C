#include <stdio.h>

void fib(int x, int n, int z) {
    if (n < 1) {
        printf("%d\n", z);
        return;
    }
    int y = x * x;
    z = y + z;
    return fib(x, n-1,z);
}

void printFib(int x, int n) {
    if (n = 0) {
        printf("1");
        return;
    }
    else if (n == 1) {
        printf("%d", x);
        return;
    }
    else{
        fib(x, n, 0);
    }
    return;
}


int main() {
    int x, n;
    scanf("%d %d", &x, &n);
    printFib(x, n);
    return 0;
}