#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k;
    char op;
    
    // Ввод размера матрицы
    printf("Введите размер матрицы N: ");
    scanf("%d", &n);
    
    // Создание матриц A, B и C
    double **A = (double**)malloc(n * sizeof(double*));
    double **B = (double**)malloc(n * sizeof(double*));
    double **C = (double**)malloc(n * sizeof(double*));
    
    for (i = 0; i < n; i++) {
        A[i] = (double*)malloc(n * sizeof(double));
        B[i] = (double*)malloc(n * sizeof(double));
        C[i] = (double*)malloc(n * sizeof(double));
    }
    
    // Ввод матрицы A
    printf("Введите матрицу A (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    
    // Ввод матрицы B
    printf("Введите матрицу B (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &B[i][j]);
        }
    }
    
    // Выбор операции
    printf("Выберите операцию (+, -, *): ");
    scanf(" %c", &op);  // пробел перед %c чтобы пропустить "лишние" символы
    
    // Выполнение выбранной операции
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (op == '+') {
                C[i][j] = A[i][j] + B[i][j];  // Сложение матриц
            }
            else if (op == '-') {
                C[i][j] = A[i][j] - B[i][j];  // Вычитание матриц
            }
            else if (op == '*') {
                C[i][j] = 0;  // Умножение матриц
                for (k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
    
    // Вывод результата
    printf("Результат:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f ", C[i][j]);  // Выводим с 2 знаками после запятой
        }
        printf("\n");
    }
    
    // Освобождение памяти
    for (i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    
    return 0;
}