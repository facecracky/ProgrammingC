#include <stdio.h>
#include <stdlib.h>

// Функция для сложения матриц
double** matrix_add(double** A, double** B, int n) {
    double** C = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        C[i] = malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Функция для вычитания матриц
double** matrix_sub(double** A, double** B, int n) {
    double** C = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        C[i] = malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Функция для умножения матриц
double** matrix_mul(double** A, double** B, int n) {
    double** C = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        C[i] = malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Функция для вывода матрицы
void print_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция для освобождения памяти матрицы
void free_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n;
    printf("N: ");
    scanf("%d", &n);

    // Выделение памяти для матриц A и B
    double **A = malloc(n * sizeof(double*));
    double **B = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        A[i] = malloc(n * sizeof(double));
        B[i] = malloc(n * sizeof(double));
    }

    // Ввод матрицы A
    printf(" A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    // Ввод матрицы B
    printf(" B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &B[i][j]);

    // Выбор операции
    char op;
    printf("Opciya (+, -, *): ");
    scanf(" %c", &op);
    
    double **C = NULL;
    
    // Выполнение операции в зависимости от выбора пользователя
    switch(op) {
        case '+':
            C = matrix_add(A, B, n);
            break;
        case '-':
            C = matrix_sub(A, B, n);
            break;
        case '*':
            C = matrix_mul(A, B, n);
            break;
        default:
            printf("Nepravilnaya opciya!\n");
            return 1;
    }

    // Вывод результата
    printf("matritsa:\n");
    print_matrix(C, n);

    // Освобождение памяти
    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);

    return 0;
}