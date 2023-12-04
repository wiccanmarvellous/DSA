#include <bits/stdc++.h>
using namespace std;

//TC O(n x m)   SC O(n x m)

class Solution {
private:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int arr[],int i, int j, int m, int n) {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int r = i + arr[k];
            int c = j + arr[k + 1];
            if (r >= 0 && c >= 0 && r < m && c < n && board[r][c] == 'O' && vis[r][c] == 0)
                dfs(board, vis, arr, r, c, m, n);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int arr[] = {-1, 0, 1, 0, -1};

        for (int i = 0; i < m; i++)
            if (board[i][0] == 'O' && vis[i][0] == 0)
                dfs(board, vis, arr, i, 0, m, n);

        for (int j = 0; j < n; j++)
            if (board[0][j] == 'O' && vis[0][j] == 0)
                dfs(board, vis, arr, 0, j, m, n);

        for (int i = 0; i < m; i++)
            if (board[i][n - 1] == 'O' && vis[i][n - 1] == 0)
                dfs(board, vis, arr, i, n - 1, m, n);

        for (int j = 0; j < n; j++)
            if (board[m - 1][j] == 'O' && vis[m - 1][j] == 0)
                dfs(board, vis, arr, m - 1, j, m, n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
        return;
    }
};