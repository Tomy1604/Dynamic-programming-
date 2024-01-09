#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error! Factorial of a negative number doesn't exist.\n");
        return 0;
    }

    unsigned long long *fact = (unsigned long long *)calloc(n + 1, sizeof(unsigned long long));
    fact[0] = 1;

    for (i = 1; i <= n; i++) {
        fact[i] = i * fact[i - 1];
    }

    printf("Factorial of %d = %llu\n", n, fact[n]);

    free(fact);

    return 0;
}
