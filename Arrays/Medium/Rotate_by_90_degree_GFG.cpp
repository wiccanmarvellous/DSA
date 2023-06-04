#include <bits/stdc++.h>
using namespace std;

//      TC O(n * n / 2)     SC O(1)
class Solution
{   
    public:
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        for (int i = 0; i < n - 1; i ++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        reverse(matrix.begin(), matrix.end());
    } 
};