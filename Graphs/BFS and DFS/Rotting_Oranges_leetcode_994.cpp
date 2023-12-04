#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }

        int count = -1;
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, -1, 0, 1};

        while (!q.empty()) {
            int size = q.size();
            while(size--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int i = r + row[k];
                    int j = c + col[k];
                    if (i >= 0 && j >= 0 && i < n && j < m && 
                        grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({i, j});
                        fresh--;
                    }
                }
            }
            count++;
        }
        if (fresh > 0)
            return -1;
        if (count == -1)
            return 0;
        return count;
    }
};