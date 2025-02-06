#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& board, int n, int row, vector<vector<vector<int>>>& ans,
    vector<bool>& colUsed, vector<bool>& diag1, vector<bool>& diag2) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (!colUsed[col] && !diag1[row + col] && !diag2[row - col + (n - 1)]) {
            board[row][col] = 1;
            colUsed[col] = diag1[row + col] = diag2[row - col + (n - 1)] = true;

            helper(board, n, row + 1, ans, colUsed, diag1, diag2);

            board[row][col] = 0; // Backtracking
            colUsed[col] = diag1[row + col] = diag2[row - col + (n - 1)] = false;
        }
    }
}

bool nQueen(int n) {
    if (n < 4) return false;

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<vector<int>>> ans;

    vector<bool> colUsed(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);

    helper(board, n, 0, ans, colUsed, diag1, diag2);

    for (int i = 0; i < ans.size(); i++) {
        cout << "Solution: " << i + 1 << endl;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                cout << ans[i][row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return true;
}

int main() {
    nQueen(6);  // Solving for 8x8 board
    return 0;
}
