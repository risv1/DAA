#include <stdio.h>
 
void strassenMultiply(int n, int A[][n], int B[][n], int C[][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
 
    int newSize = n / 2;
 
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize], P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];
 
    // Divide matrices A and B into 4 submatrices
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
 
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
 
    // Calculate the 7 products recursively
    strassenMultiply(newSize, A11, B11, P1);
    strassenMultiply(newSize, A12, B21, P2);
    strassenMultiply(newSize, A11, B12, P3);
    strassenMultiply(newSize, A12, B22, P4);
    strassenMultiply(newSize, A21, B11, P5);
    strassenMultiply(newSize, A22, B21, P6);
    strassenMultiply(newSize, A21, B12, P7);
 
    // Calculate the resulting submatrices
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C11[i][j] = P1[i][j] + P2[i][j];
            C12[i][j] = P3[i][j] + P4[i][j];
            C21[i][j] = P5[i][j] + P6[i][j];
            C22[i][j] = P7[i][j] + P1[i][j] - P3[i][j] + P5[i][j];
        }
    }
 
    // Combine the resulting submatrices into the final matrix C
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}
 
int main()
{
    int n;
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);
 
    // Check if n is not a multiple of 2
    if (n % 2 != 0)
    {
        printf("Error: Size of matrices should be a multiple of 2.\n");
        return 0;
    }
 
    int A[n][n], B[n][n], C[n][n];
 
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
 
    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
 
    strassenMultiply(n, A, B, C);
 
    printf("The result of matrix multiplication is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}