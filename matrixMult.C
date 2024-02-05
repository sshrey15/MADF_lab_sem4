#include <stdio.h>
#include <stdlib.h>

void Madd(int* A, int* B, int* C, int n, int x) {
    int i, j, m = x > 0 ? n / 2 : n;

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            *(C + i * m + j) = *(A + i * n + j) + *(B + i * n + j);
        }
    }
}

void Msub(int* A, int* B, int* C, int n, int x) {
    int i, j, m = x > 0 ? n / 2 : n;

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            *(C + i * m + j) = *(A + i * n + j) - *(B + i * n + j);
        }
    }
}

void strassen(int* A, int* B, int* C, int n) {
    if (n == 2) {
        int P = (*A + *(A + n + 1)) * (*B + *(B + n + 1));
        int Q = (*(A + n) + *(A + n + 1)) * (*B);
        int R = (*A) * (*(B + 1) - *(B + n + 1));
        int S = (*(A + n + 1)) * (*(B + n) - *B);
        int T = (*A + *(A + 1)) * (*(B + n + 1));
        int U = (*(A + n) - *A) * (*B + *(B + 1));
        int V = (*(A + 1) - *(A + n + 1)) * (*(B + n) + *(B + n + 1));
        *C = P + S - T + V;
        *(C + 1) = R + T;
        *(C + n) = Q + S;
        *(C + n + 1) = P + R - Q + U;
    } else {
        int m = n / 2;
        int x[m][m], y[m][m], o[n][n], P[m][m], Q[m][m], V[m][m] ,  S[m][m] , W[m][m] , R[m][m], T[m][m] ,  X[m][m];
        int i, j;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                o[i][j] = 0;
            }
        }

        Madd(A, A + m * (n + 1), *x, n, 1);
        Madd(B, B + m * (n + 1), *y, n, 1);
        strassen(*x, *y, *P, m);

        Madd(A + m * n, A + m * (n + 1), *x, n, 1);
        Msub(B, *o, *y, n, 1);
        strassen(*x, *y, *Q, m);

        Msub(*P, *Q, *V, m, 0);
        Madd(*S, *V, *y, m, 0);
        Madd(*P, *y, *W, m, 0);

        Msub(*R, *T, *x, m, 0);
        strassen(*x, *T, *X, m);
    }
}

int main() {
    int n, i, j;

    printf("Enter the size of square matrices: ");
    scanf("%d", &n);

    int* A = (int*)malloc(n * n * sizeof(int));
    int* B = (int*)malloc(n * n * sizeof(int));
    int* C = (int*)malloc(n * n * sizeof(int));

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i * n + j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i * n + j]);
        }
    }

    strassen(A, B, C, n);

    printf("Matrix C = A * B:\n");
    for (i = 0; i < n; i++) {
       for (j = 0; j < n; j++) {
            printf("%d ", C[i * n + j]);
        }
        printf("\n");
    }

    free(A);
    free(B);
    free(C);

    return 0;
}
