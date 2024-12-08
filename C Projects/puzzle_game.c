#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void print_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int check_puzzle(int matrix[SIZE][SIZE]) {
    int value = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] != value++) {
                return 0;
            }
        }
    }
    return 1;
}

void shuffle_matrix(int matrix[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = SIZE - 1; j > 0; j--) {
            int x = rand() % (i + 1);
            int y = rand() % (j + 1);
            int temp = matrix[i][j];
            matrix[i][j] = matrix[x][y];
            matrix[x][y] = temp;
        }
    }
}

int main() {
    int matrix[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    shuffle_matrix(matrix);
    int moves = 0;
    while (1) {
        printf("Moves: %d\n", moves);
        print_matrix(matrix);
        if (check_puzzle(matrix)) {
            printf("You won in %d moves!\n", moves);
            break;
        }
        int x1, y1, x2, y2;
        printf("Enter the first number to swap (row column): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the second number to swap (row column): ");
        scanf("%d %d", &x2, &y2);
        int temp = matrix[x1][y1];
        matrix[x1][y1] = matrix[x2][y2];
        matrix[x2][y2] = temp;
        moves++;
    }
    return 0;
}