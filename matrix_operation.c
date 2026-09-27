#include <stdio.h>

#define MAX 10

void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols) {
    int result[MAX][MAX];

    printf("\n===== MATRIX ADDITION =====\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX],
                    int r1, int c1, int c2) {
    int result[MAX][MAX] = {0};

    printf("\n===== MATRIX MULTIPLICATION =====\n");

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("\n===== MATRIX TRANSPOSE =====\n");

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int r1, c1, r2, c2;

    printf("===== MATRIX OPERATIONS =====\n");

    printf("\nEnter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nMatrix A:\n");
    displayMatrix(a, r1, c1);

    printf("\nMatrix B:\n");
    displayMatrix(b, r2, c2);

    if (r1 == r2 && c1 == c2) {
        addMatrix(a, b, r1, c1);
    } else {
        printf("\nMatrix addition is not possible.");
    }

    if (c1 == r2) {
        multiplyMatrix(a, b, r1, c1, c2);
    } else {
        printf("\nMatrix multiplication is not possible.");
    }

    transposeMatrix(a, r1, c1);
    
    return 0;
}