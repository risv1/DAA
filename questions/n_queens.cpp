#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed in a particular position
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check for queens in the same column
    for (int i = 0; i < row; ++i)
        if (board[i][col])
            return false;

    // Check for queens in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // Check for queens in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j)
        if (board[i][j])
            return false;

    return true;
}

// Function to solve N Queens problem using backtracking
bool solveNQueensUtil(vector<vector<int>>& board, int row, int n) {
    if (row == n)
        return true;

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;

            if (solveNQueensUtil(board, row + 1, n))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

// Function to solve N Queens problem and print the solution
void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueensUtil(board, 0, n)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    solveNQueens(n);

    return 0;
}
