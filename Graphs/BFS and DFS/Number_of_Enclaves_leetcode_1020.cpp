#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int arr[], 
            int i, int j, int m, int n) {
            vis[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                int r = i + arr[k];
                int c = j + arr[k + 1];
                if (r >= 0 && c >= 0 && r < m && c < n && 
                grid[r][c] == 1 && vis[r][c] == 0) {
                    dfs(grid, vis, arr, r, c, m, n);
                }
            }
        }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> vis(m,vector<int>(n, 0));
        int arr[] = {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && vis[i][0] == 0)
                dfs(grid, vis, arr, i, 0, m, n);
            if (grid[i][n - 1] == 1 && vis[i][n - 1] == 0)
                dfs(grid, vis, arr, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1 && vis[0][j] == 0)
                dfs(grid, vis, arr, 0, j, m, n);
            if (grid[m - 1][j] == 1 && vis[m - 1][j] == 0)
                dfs(grid, vis, arr, m - 1, j, m, n);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) 
                    ans++;
            }
        }
        return ans;
    }
};