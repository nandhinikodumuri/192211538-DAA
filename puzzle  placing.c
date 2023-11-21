#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 10 // Maximum chessboard size

int board[N][N];

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int row, int col, int n) {
    int i, j;

    // Check the left side of the current row
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve N-Queens problem
bool solveNQueensUtil(int col, int n) {
    if (col == n) {
        // All queens are placed successfully, print the solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1; // Place the queen at board[i][col]

            // Recur to place the rest of the queens
            res = solveNQueensUtil(col + 1, n) || res;

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then remove the queen from board[i][col]
            board[i][col] = 0;
        }
    }

    return res;
}

// Function to solve N-Queens problem and print solutions
void solveNQueens(int n) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (!solveNQueensUtil(0, n)) {
        printf("No solution exists for the given board size.\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the chessboard (n): ");
    scanf("%d", &n);

    solveNQueens(n);

    return 0;
}
