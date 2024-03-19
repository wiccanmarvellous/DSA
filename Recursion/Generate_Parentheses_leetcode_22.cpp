#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int o, int c, string s, vector<string> &ans) {
        if (o == 0 && c == 0) {
            ans.push_back(s);
            return;
        }
        if (o > 0) {
            dfs(o - 1, c, s + "(", ans);
        }
        if (c > 0 && c > o) {
            dfs(o, c - 1, s + ")", ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        dfs(n, n, s, ans);
        return ans;
    }
};