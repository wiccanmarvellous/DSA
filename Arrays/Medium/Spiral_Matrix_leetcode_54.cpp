#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size() - 1, n = matrix[0].size() - 1, a = 0, b = 0;
        vector<int> ans;
        while (a <= m && b <= n) {
            for (int i = a, j = b; j <= n; j++)
                ans.push_back(matrix[i][j]);
            a++;
        
            for (int i = a, j = n; i <= m; i++)
                ans.push_back(matrix[i][j]);
            n--;
        
            if (a <= m) {
                for (int i = m, j = n; j >= b; j--)
                    ans.push_back(matrix[i][j]);
                m--;
            }
            if (b <= n) {
                for (int i = m, j = b; i >= a ; i--)
                    ans.push_back(matrix[i][j]);
                b++;
            }
        }
        return ans;
    }
};