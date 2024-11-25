#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int board[MAX][MAX];

void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j]) return false;
    }
    return true;
}

bool solveNQueen(int col, int n) {
    if (col >= n) {
        printSolution(n);
        return true;
    }
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1;
            found = solveNQueen(col + 1, n) || found;
            board[i][col] = 0;
        }
    }
    return found;
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid value of N. Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    if (!solveNQueen(0, n)) {
        printf("No solution exists for N = %d\n", n);
    }

    return 0;
}


