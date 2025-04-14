#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("N: ");
    scanf("%d", &n);

    double **A = malloc(n * sizeof(double*));
    double **B = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        A[i] = malloc(n * sizeof(double));
        B[i] = malloc(n * sizeof(double));
    }

    printf(" A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    printf(" B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &B[i][j]);

    char op;
    printf("Opciya (+, -, *): ");
    scanf(" %c", &op);
    
    double **C = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
        C[i] = malloc(n * sizeof(double));
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (op == '+') C[i][j] = A[i][j] + B[i][j];
            else if (op == '-') C[i][j] = A[i][j] - B[i][j];
            else if (op == '*') {
                C[i][j] = 0;
                for (int k = 0; k < n; k++)
                    C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("matritsa:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%lf ", C[i][j]);
        printf("\n");
    }


    return 0;
}