#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to find the length of the longest common subsequence
int lcs(char X[], char Y[], int m, int n, char lcsStr[])
{
    int L[MAX_LEN + 1][MAX_LEN + 1];
    int i, j;

    // Building the L[m+1][n+1] table
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // Length of LCS is L[m][n]
    int index = L[m][n];
    lcsStr[index] = '\0'; // Set the null terminator

    // Traverse the 2D array from the bottom-right corner
    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        // If current character in X and Y are same, then it belongs to LCS
        if (X[i - 1] == Y[j - 1])
        {
            lcsStr[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        // If not same, then find the larger of two and go in the direction of larger value
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return L[m][n];
}

int main()
{
    char X[MAX_LEN];
    char Y[MAX_LEN];
    char lcsStr[MAX_LEN];

    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", lcs(X, Y, m, n, lcsStr));
    printf("Longest Common Subsequence is: %s\n", lcsStr);

    return 0;
}