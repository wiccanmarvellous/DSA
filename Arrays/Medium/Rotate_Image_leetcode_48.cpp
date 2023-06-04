#include <bits/stdc++.h>
using namespace std;

// Brute        TC O(n * n)     SC O(n * n)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = matrix[n - 1 - j][i];
            }
        }
        matrix = ans;
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j)
                    swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};