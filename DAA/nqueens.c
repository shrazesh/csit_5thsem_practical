#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int board[MAX][MAX], N;

void printBoard() {
    int i, j;
    printf("\n=== N-Queens Solution ===\n\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf(board[i][j] ? " Q " : " . ");
        }
        printf("\n");
    }
    printf("\n=========================\n");
}

bool isSafe(int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i]) return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j]) return false;

    return true;
}

bool solve(int col) {
    if (col == N) return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            if (solve(col + 1)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    printf("Enter number of queens (N): ");
    scanf("%d", &N);

    if (N < 1 || N > MAX) {
        printf("Invalid N (1 to %d only)\n", MAX);
        return 1;
    }

    if (solve(0))
        printBoard();
    else
        printf("No solution exists for N = %d\n", N);

    return 0;
}

