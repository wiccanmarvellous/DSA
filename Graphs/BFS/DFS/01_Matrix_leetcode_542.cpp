#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
        int arr[] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int r = q.front().first.first;
                int c = q.front().first.second;
                int step = q.front().second;
                q.pop();
                dist[r][c] = step;
                for (int k = 0; k < 4; k++) {
                    int i = r + arr[k];
                    int j = c + arr[k + 1];
                    if (i >= 0 && i < m && j >= 0 && j < n && vis[i][j] == 0) {
                        q.push({{i, j}, step + 1});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        return dist;
    }
};