#include <stdio.h>

int board[20], n, count = 0;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||
            board[i] - i == col - row ||
            board[i] + i == col + row)
            return 0;
    }
    return 1;
}

void solve(int row) {
    if (row == n) {
        count++;
        printf("\nSolution %d:\n", count);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    printf("Enter N: ");
    scanf("%d", &n);

    solve(0);

    printf("\nTotal Solutions = %d\n", count);

    return 0;
}