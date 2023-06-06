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

int main() {
    int numRows;
    cin >> numRows;
    Solution obj;
    vector<vector<int>> v = obj.generate(numRows);
    for (auto i : v)
        for (auto j : i)
            cout << j << ' ';
}