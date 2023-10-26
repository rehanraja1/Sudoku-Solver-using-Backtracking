#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_sudoku(int sudoku[9][9]) {
    printf("The Sudoku contains:\n");
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 9; i++) {
            printf("%d  ", sudoku[j][i]);
        }
        printf("\n");
    }
}

int check_square(int sudoku[9][9], int num, int row, int col) {
    int row_start = row - row % 3;
    int col_start = col - col % 3;
    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (sudoku[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int check_sudoku(int sudoku[9][9], int num, int row, int col) {
    for (int i = 0; i < 9; i++) {
        if (num == sudoku[i][col]) {
            return 0;
        }
    }
    for (int j = 0; j < 9; j++) {
        if (num == sudoku[row][j]) {
            return 0;
        }
    }
    if (check_square(sudoku, num, row, col) == 0) {
        return 0;
    }
    return 1;
}

int solved(int sudoku[9][9], int *rows, int *columns) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                *(rows) = i;
                *(columns) = j;
                return 0;
            }
        }
    }
    return 1;
}

int sudoku_solver_pro(int sudoku[9][9], int depth) {
    int rows;
    int columns;
    if (solved(sudoku, &rows, &columns) == 1) {
        return 1;
    }
    for (int i = 1; i <= 9; i++) {
        if (check_sudoku(sudoku, i, rows, columns) == 1) {
            sudoku[rows][columns] = i;
            if (sudoku_solver_pro(sudoku, depth)) {
                return 1;
            }
            sudoku[rows][columns] = 0;
        }
    }
    return 0;
}

void solve_sudoku(int sudoku[9][9], int depth) {
    sudoku_solver_pro(sudoku, depth);
}

int main() {
    int Sudoku[9][9];

    printf("Enter the Sudoku puzzle (9x9 grid) using 0 for empty cells:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &Sudoku[i][j]);
        }
    }

    printf("Input puzzle is:\n");
    print_sudoku(Sudoku);

    solve_sudoku(Sudoku, 0);

    printf("Solution is:\n");
    print_sudoku(Sudoku);

    return 0;
}
