#include <bits/stdc++.h>
using namespace std;


// Brute    TC O(m * n * (m + n) + (m * n))    SC O(n * m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dupMat(matrix);
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (dupMat[i][j] == 0) 
                {
                    for (int I = 0; I < m; I++)
                        matrix[I][j] = 0;
                    for (int J = 0; J < n; J++)
                        matrix[i][J] = 0;
                }
            }
        }
    }
};

// Better       TC O(m * n)     SC O(m + n)
// Using set
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> r, c;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for (auto i : r)
            for (int j = 0; j < m; j++)
                matrix[i][j] = 0;
        for (auto j : c)
            for (int i = 0; i < n; i++)
                matrix[i][j] = 0;
    }
};

// Better       TC O(2(m * n))     SC O(m + n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> r(m, 0), c(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (r[i] == 1 || c[j] == 1)
                    matrix[i][j] = 0;
            }
    }
};


// Optimal      TC O(n * m)     SC O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int c = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j == 0)
                        c = 0;
                    else
                        matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        
        if (matrix[0][0] == 0)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;

        if (c == 0)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};