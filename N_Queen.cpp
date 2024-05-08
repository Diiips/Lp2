#include <iostream>

using namespace std;

bool isSafe(int board[][10], int row, int col, int N) {
    // Check if there is a queen in the same row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on right[] side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool solveNQueensUtil(int board[10][10], int col, int N) {

    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1, N)) {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

void solveNQueens(int N) {
    int board[10][10] = {0};

    if (!solveNQueensUtil(board, 0, N)) {
        cout << "Solution does not exist";
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
