#include <stdio.h>
#define INT_MAX 99999999

void printDPMatrix(int n, int m[n][n]) {
    int i, j;
    printf("\nDP Matrix (minimum multiplication costs):\n");
    printf("      ");
    for (i = 1; i < n; i++)
        printf("M%-6d", i);
    printf("\n");

    for (i = 1; i < n; i++) {
        printf("M%-6d", i);
        for (j = 1; j < n; j++) {
            if (j < i)
                printf("       ");
            else
                printf("%-7d", m[i][j]);
        }
        printf("\n");
    }
}

int matrixChainMultiplication(int dims[], int n) {
    int m[n][n];
    int i, j, k, L, cost;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                cost = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    printDPMatrix(n, m);
    return m[1][n - 1];
}

int main() {
    int dims[5] = {40, 20, 30, 10, 30};
    int n = 5;
    int result;
    int i;

    printf("Matrix dimensions: ");
    for (i = 0; i < n; i++)
        printf("%d ", dims[i]);
    printf("\n");

    result = matrixChainMultiplication(dims, n);

    printf("\nMinimum number of multiplications is %d\n", result);

    return 0;
}

