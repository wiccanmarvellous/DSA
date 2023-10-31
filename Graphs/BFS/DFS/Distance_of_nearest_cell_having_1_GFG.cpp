#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size(), n = grid[0].size(), dist = 0;
	    vector<vector<int>> mat(m, vector<int>(n, 0));
	    vector<vector<int>> vis(m, vector<int>(n, 0));
	    queue<pair<int, int>> q;
	    for (int i = 0; i < m; i++)
	        for (int j = 0; j < n; j++)
	            if (grid[i][j] == 1) {
	                q.push({i, j});
	                vis[i][j] = 1;
	            }
        int arr[] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                mat[r][c] = dist;
                for (int k = 0; k < 4; k++) {
                    int i = r + arr[k];
                    int j = c + arr[k + 1];
                    if (i >= 0 && i < m && j >= 0 && j < n && vis[i][j] == 0 && grid[i][j] == 0) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
            dist++;
        }
        return mat;
	}
};