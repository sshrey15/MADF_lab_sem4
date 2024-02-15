#include <stdio.h>
#define N 4

void printArray(int arr[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void add(int a[][N], int b[][N], int c[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void subtract(int a[][N], int b[][N], int c[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void strassen(int A[][N], int B[][N], int C[][N], int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int mid = n / 2;
    int A11[N][N], A12[N][N], A21[N][N], A22[N][N];
    int B11[N][N], B12[N][N], B21[N][N], B22[N][N];
    int C11[N][N], C12[N][N], C21[N][N], C22[N][N];
    int P1[N][N], P2[N][N], P3[N][N], P4[N][N], P5[N][N], P6[N][N], P7[N][N];
    int temp1[N][N], temp2[N][N];

    // Splitting into submatrices
    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }
    subtract(B12, B22, temp1, mid);
    strassen(A11, temp1, P1, mid);
    add(A11, A12, temp1, mid);
    strassen(temp1, B22, P2, mid);
    add(A21, A22, temp1, mid);
    strassen(temp1, B11, P3, mid);
    subtract(B21, B11, temp1, mid);
    strassen(A22, temp1, P4, mid);
    add(A11, A22, temp1, mid);
    add(B11, B22, temp2, mid);
    strassen(temp1, temp2, P5, mid);
    subtract(A12, A22, temp1, mid);
    add(B21, B22, temp2, mid);
    strassen(temp1, temp2, P6, mid);
    subtract(A11, A21, temp1, mid);
    add(B11, B12, temp2, mid);
    strassen(temp1, temp2, P7, mid);
    add(P5, P4, temp1, mid);
    subtract(temp1, P2, temp2, mid);
    add(temp2, P6, C11, mid);
    add(P1, P2, C12, mid);
    add(P3, P4, C21, mid);
    subtract(P5, P3, temp1, mid);
    subtract(temp1, P7, temp2, mid);
    add(temp2, P2, C22, mid);
    if (mid == 2)
    {
        printf("P1:\n");
        printArray(P1, mid);
        printf("P2:\n");
        printArray(P2, mid);
        printf("P3:\n");
        printArray(P3, mid);
        printf("P4:\n");
        printArray(P4, mid);
        printf("P5:\n");
        printArray(P5, mid);
        printf("P6:\n");
        printArray(P6, mid);
        printf("P7:\n");
        printArray(P7, mid);
    }
    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
}

int main()
{
    int A[N][N] = {{3, -8, -7, -1},
                   {-6, 1, 5, 6},
                   {2, 10, 3, -3},
                   {-5, 4, 9, 2}};

    int B[N][N] = {{8, -7, 3, -1},
                   {-9, 6, 2, 4},
                   {5, 11, 6, -5},
                   {1, 8, 10, -3}};

    int C[N][N];
    int n = N;
    strassen(A, B, C, n);
    printf("Matrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("Matrix B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }
    printf("Resultant Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}