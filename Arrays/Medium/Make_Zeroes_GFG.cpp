#include <bits/stdc++.h>
using namespace std;

//        TC O(n * m)     SC O(n * m)
class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        int sum = 0, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dup(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum = 0;
                if (matrix[i][j] == 0) {
                    sum += i != 0 ? matrix[i - 1][j] : 0;
                    sum += i != n - 1 ? matrix[i + 1][j] : 0;
                    sum += j != 0 ? matrix[i][j - 1] : 0;
                    sum += j != m - 1 ? matrix[i][j + 1] : 0;
                    dup[i][j] = sum;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dup[i][j] != 0) {
                    if (i != 0) {
                        matrix[i - 1][j] = 0;
                    }
                    if (i != n - 1) {
                        matrix[i + 1][j] = 0;
                    }
                    if (j != 0) {
                        matrix[i][j - 1] = 0;
                    }
                    if (j != m - 1) {
                        matrix[i][j + 1] = 0;
                    }
                    matrix[i][j] = dup[i][j];
                }
            }
        }
    }
};