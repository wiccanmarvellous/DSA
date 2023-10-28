#include <bits/stdc++.h>
using namespace std;

//DFS
class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int n , int m, int prevColor) {
        image[sr][sc] = color;
        int arr[] = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int i = sr + arr[k];
            int j = sc + arr[k + 1];
            if (i >= 0 && i < n && j >= 0 && j < m && image[i][j] == prevColor)
                dfs(image, i, j, color, n, m, prevColor);
        }
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color)
            return image;
        int prevColor = image[sr][sc];
        dfs(image, sr, sc, color, image.size(), image[0].size(), prevColor);
        return image;
    }
};

//BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color)
            return image;
        vector<vector<int>> mat = image;
        int m = image.size(), n = image[0].size(), prevColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        mat[sr][sc] = color;
        int arr[] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int i = r + arr[k];
                    int j = c + arr[k + 1];
                    if (i >= 0 && i < m && j >= 0 && j < n && mat[i][j] == prevColor) {
                        mat[i][j] = color;
                        q.push({i, j});
                    } 
                }
            }
        }
        return mat;
    }
};