#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
            return {{1}};
        if (numRows == 2)
            return {{1}, {1, 1}};
        vector<vector<int>> ans{{1}, {1, 1}};
        for (int i = 2; i < numRows; i++) {
            vector<int> temp{1};
            for (int j = 0; j < ans[i - 1].size() - 1; j++) {
                int a = ans[i - 1][j] + ans[i - 1][j + 1];
                temp.push_back(a);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return  ans;
    }
};

class Solution {
public:

    int nCr(int n, int r) {
    long long res = 1;

    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int row = 1; row <= numRows; row++) {
        vector<int> tempLst; 
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
    }
};

int main() {
    int numRows;
    cin >> numRows;
    Solution obj;
    vector<vector<int>> v = obj.generate(numRows);
    for (auto i : v)
        for (auto j : i)
            cout << j << ' ';
}